#include "position.h"
#include "strategy.h"
#include "utils.h"
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

int main() {

  // Get the coins
  const auto prices = get_prices();
  // std::cout << strategies.size() << " strategies\n";
  std::cout << prices.size() << " coins updated in the last minute\n";

  // Get the positions
  const std::vector<trade_position> positions(get_positions("positions.csv"));
  std::cout << positions.size() << " positions\n\n";

  // Initialise results with all strategies
  std::map<std::string, double> ins, outs, trades;

  // Close all positions
  for (const auto &pos : positions) {
    const auto strategy = pos.strategy;
    ins[strategy] += 100.0;
    outs[strategy] += pos.yield;
    ++trades[strategy];
  }

  // Individual strategy performance
  std::cout << "STRATEGY\t\t% RETURN\t$ IN\t\t$ OUT\n\n";
  for (const auto &i : ins) {
    const std::string strategy = i.first;
    const double in = ins[strategy];
    const double out = outs[strategy];
    const double yield = 100.0 * out / (in > 0 ? in : 1);

    std::cout << strategy << "\t" << std::fixed << yield << "\t" << in << "\t"
              << out << "\n";
  }

  // Strategy summary
  const double in_sum =
      std::accumulate(ins.cbegin(), ins.cend(), 0.0,
                      [](auto sum, const auto &i) { return sum + i.second; });

  const double out_sum =
      std::accumulate(outs.cbegin(), outs.cend(), 0.0,
                      [](auto sum, const auto &i) { return sum + i.second; });

  const double overall_yield = 100.0 * out_sum / (in_sum > 0.0 ? in_sum : 1.0);
  std::cout << "\nTOTAL\t\t\t" << overall_yield << "\t" << in_sum << "\t"
            << out_sum << "\t\t\t"
            << "\n";
}
