#ifndef POSITION
#define POSITION

#include <istream>
#include <ostream>
#include <string>

// A stucture to represent a trade
struct trade_position {

  std::string name = "name";
  unsigned long timestamp = 0;
  unsigned long duration = 0;
  double buy_price = 0.0;
  double sell_price = 0.0;
  std::string strategy = "strategy";
  double yield = 0.0;
  std::string notes = "default";

  // Streaming out
  friend std::ostream &operator<<(std::ostream &os, const trade_position &p) {
    return os << std::fixed << p.timestamp << " " << p.duration << " " << p.name
              << "\t" << p.yield << "\t" << p.strategy << " " << p.notes << " "
              << p.buy_price << " " << p.sell_price << "\n";
  }

  // Streaming in
  friend std::istream &operator>>(std::istream &is, trade_position &p) {
    return is >> p.timestamp >> p.duration >> p.name >> p.yield >> p.strategy >>
           p.notes >> p.buy_price >> p.sell_price;
  }
};

#endif
