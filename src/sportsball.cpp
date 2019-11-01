#include <algorithm>
#include <string>
#include <boost/format.hpp>
#include "sportsball.hpp"

std::string Sportsball::getScore() {
  return (boost::format("Home: 0 Away: %1%") % (this->runners - this->unscored)).str();
}

void Sportsball::addEntry(int entry) {
  ++this->runners;
  this->unscored = std::min(BASES - entry, this->unscored) + 1;
}
