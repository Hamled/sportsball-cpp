#include <string>
#include <boost/format.hpp>

#include "sportsball.hpp"

Sportsball::Sportsball() {
  resetFrame();
}

std::string Sportsball::getScore() const {
  const int cur_away = is_away ? away + score() : away;
  const int cur_home = is_away ? home : home + score();
  return (boost::format("Home: %1% Away: %2%") % cur_home % cur_away).str();
}

void Sportsball::addEntry(int entry) {
  if(!entry) {
    if(++outs > 2) {
      if(is_away)
        away += score();
      else
        home += score();

      resetFrame();
    }
    return;
  }

  runners++;
  unscored = std::min(BASES - entry, unscored) + 1;
}

int Sportsball::score() const {
  return runners - unscored;
}

void Sportsball::resetFrame() {
  runners = unscored = outs = 0;
  is_away = !is_away;
}
