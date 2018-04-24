#include "handt.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

int main() {

  // Configure debug
  std::stringstream out;
  out.precision(2);
  out << std::fixed;

  // Get some data to play with
  const auto &open = handt::get_final_positions();
  const auto &closed = handt::get_closed_positions();
  const auto &symbols = handt::get_symbols().size();
  const unsigned long batch_size = 80UL;

  // Get the HTML template
  std::string index_template = handt::get_index_html();

  // Substitute some real stats
  std::string index_subst = std::regex_replace(
      index_template, std::regex("STATS"), std::to_string(handt::get_stats()));
  index_subst = std::regex_replace(index_subst, std::regex("BATCH"),
                                   std::to_string(batch_size));
  index_subst = std::regex_replace(index_subst, std::regex("SYMBOLS"),
                                   std::to_string(symbols));
  index_subst = std::regex_replace(index_subst, std::regex("MINUTES"),
                                   std::to_string(symbols / batch_size));
  index_subst = std::regex_replace(index_subst, std::regex("SELL"),
                                   std::to_string(static_cast<unsigned long>(
                                       handt::sell_threshold * 100.0)));
  index_subst = std::regex_replace(index_subst, std::regex("CUT"),
                                   std::to_string(static_cast<unsigned long>(
                                       handt::cut_losses_threshold * 100.0)));

  out << index_subst;

  // Structure for reporting strategy performance
  struct strategy_summary {
    std::string name;
    double yield;
    std::vector<double> returns;
    std::map<std::string, unsigned long> symbols;

    // Calculate average yield of all the positions created by current strategy
    double average_yield() const {
      return std::accumulate(returns.cbegin(), returns.cend(), 0.0,
                             [](auto &sum, const auto &y) { return sum + y; }) /
             (returns.size() > 0 ? returns.size() : 1);
    }

    // Return list of symbols that matured under current strategy
    std::string symbol_list() const {

      std::stringstream symbol_string;
      for (const auto &symbol : symbols)
        symbol_string << symbol.first << ' ';

      return symbol_string.str();
    }
  };

  // Iterate over all closed positions and create strategy summary
  std::vector<strategy_summary> all_coins;
  for (const auto &position : closed) {
    const auto strategy = position.strategy;
    const auto it =
        find_if(all_coins.begin(), all_coins.end(),
                [&strategy](const auto &s) { return strategy == s.name; });

    // If strategy record doesn't exist, create a new one and insert it
    if (it == all_coins.end()) {
      strategy_summary strat;
      strat.name = strategy;
      strat.returns.push_back(position.yield());

      // Only store symbol if it's matured
      if (position.yield() > .90) // handt::sell_threshold)
        strat.symbols[position.symbol] = 1;

      all_coins.emplace_back(strat);
    } else {
      // Otherwise just update the position count
      it->returns.push_back(position.yield());

      // Only store symbol if it's matured
      if (position.yield() > handt::sell_threshold)
        ++it->symbols[position.symbol];
    }
  }

  // Iterate over Coinbase closed positions and create strategy summary
  std::vector<strategy_summary> coinbase;
  for (const auto &position : closed) {

    // We're only interested in currency you can buy on Coinbase
    if (position.symbol == "ETH" || position.symbol == "BTC" ||
        position.symbol == "BCH" || position.symbol == "LTC") {

      const auto strategy = position.strategy;
      const auto it =
          find_if(coinbase.begin(), coinbase.end(),
                  [&strategy](const auto &s) { return strategy == s.name; });

      // If strategy record doesn't exist, create a new one and insert it
      if (it == coinbase.end()) {

        strategy_summary strat;
        strat.name = strategy;
        strat.returns.push_back(position.yield());

        // Only store symbol if it's matured
        if (position.yield() > handt::sell_threshold)
          strat.symbols[position.symbol] = 1;

        coinbase.emplace_back(strat);
      } else {
        // Otherwise just update the position count
        it->returns.push_back(position.yield());

        // Only store symbol if it's matured
        if (position.yield() > handt::sell_threshold)
          ++it->symbols[position.symbol];
      }
    }
  }

  // Sort strategy summaries by number of positions - an indicator of confidence
  // in the return: a high yield with few closed positions suggests a low
  // confidence
  std::sort(all_coins.begin(), all_coins.end(),
            [](const auto &a, const auto &b) {
              return a.returns.size() > b.returns.size();
            });

  std::sort(coinbase.begin(), coinbase.end(), [](const auto &a, const auto &b) {
    return a.returns.size() > b.returns.size();
  });

  // Print succesful strategy summary for all coins
  out << "<h1>All coins strategy summary</h1>\n";
  out << "<p>" << open.size() << " open positions, " << closed.size()
      << " closed</p>\n";
  out << "<pre>\n";
  out << "STRATEGY\t\tPOS\t%\t\tMATURED SYMBOLS\n";
  for (const auto &strategy : all_coins)
    if (strategy.average_yield() > handt::sell_threshold)
      out << strategy.name << '\t' << strategy.returns.size() << '\t'
          << 100.0 * strategy.average_yield() << "\t\t"
          << strategy.symbol_list() << '\n';
  out << "</pre>\n";

  // Print strategy summary for Coinbase coins
  out << "<h1>Coinbase strategy summary</h1>\n";
  out << "<pre>\n";
  for (const auto &strategy : coinbase)
    if (strategy.average_yield() > handt::sell_threshold)
      out << strategy.name << '\t' << strategy.returns.size() << '\t'
          << 100.0 * strategy.average_yield() << "\t\t"
          << strategy.symbol_list() << '\n';
  out << "</pre>\n";

  // Extract open Coinbase positions
  std::vector<handt::position> coinbase_open;
  for (const auto &position : open)
    if (position.symbol == "ETH" || position.symbol == "BTC" ||
        position.symbol == "BCH" || position.symbol == "LTC")
      coinbase_open.push_back(position);

  // Sort open positions for display
  std::sort(
      coinbase_open.begin(), coinbase_open.end(),
      [](const auto &a, const auto &b) { return a.timestamp > b.timestamp; });

  // Print open Coinbase positions
  out << "<h1>Coinbase open positions</h1>\n";
  out << "<pre>\n";
  out << "SYMBOL\t%\tSTRATEGY\t\tBUY\tTIMEOUT (HOURS)\n";
  for (const auto &position : coinbase_open)
    out << position.symbol << '\t' << position.yield() * 100.0 << '\t'
        << position.strategy << '\t' << position.buy_price << '\t'
        << 24.0 - (handt::get_timestamp() - position.timestamp) / 3600.0
        << '\n';
  out << "</pre>\n";

  std::cout << out.str();
}
