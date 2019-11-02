#include <string>
#include <boost/format.hpp>

#include "sportsball.hpp"

std::string Sportsball::getScore() const {
  return (boost::format("Home: 0 Away: %1%") % (runners - unscored)).str();
}

void Sportsball::addEntry(int entry) {
  runners++;
  unscored = std::min(BASES - entry, unscored) + 1;
}
