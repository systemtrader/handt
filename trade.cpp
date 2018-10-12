#include "trade.h"
#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <numeric>
#include <vector>

// Take a directory name, read all the files and return a container of prices
// for all coins

double trade_t::mean_variance() {

  // Calculate the diffs
  std::vector<double> d(prices.size());
  std::adjacent_difference(prices.begin(), prices.end(), d.data());

  // Pop the large first value off the front
  d.front() = d.back();
  d.pop_back();

  // Absolute diffs
  std::for_each(d.begin(), d.end(),
                [](auto &element) { element = std::fabs(element); });

  return d.size() > 0 ? std::accumulate(d.cbegin(), d.cend(), 0.0) / d.size()
                      : 0.0;
}

std::vector<trade_t> get_trades() {

  std::vector<trade_t> trades;

  // Fetch list of price files (check the file extension)
  std::vector<std::string> currency_pairs;
  for (const auto &file : std::filesystem::directory_iterator("tmp"))
    if (std::string(file.path()).find(".csv") != std::string::npos)
      currency_pairs.emplace_back(file.path());

  // Extract prices from each file
  for (const auto &file : currency_pairs) {

    // Open prices and get the trade info
    std::ifstream in(file);
    std::string from_symbol, to_symbol, exchange;
    in >> from_symbol >> to_symbol >> exchange;

    // Get the latest prices and run the strategies over them
    const std::vector<double> prices{std::istream_iterator<double>(in), {}};

    // Only store prices if the parse was successful
    if (!prices.empty())
      trades.push_back({from_symbol, to_symbol, exchange, prices});
  }

  return trades;
}
