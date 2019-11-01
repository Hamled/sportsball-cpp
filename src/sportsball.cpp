#include <algorithm>
#include <string>
#include <boost/format.hpp>
#include "sportsball.hpp"

Sportsball::Sportsball() {
  this->away = 0;
  this->home = 0;

  this->resetFrame();
}

std::string Sportsball::getScore() {
  const int cur_away = this->is_away ? this->away + this->score() : this->away;
  const int cur_home = this->is_away ? this->home : this->home + this->score();
  return (boost::format("Home: %1% Away: %2%") % cur_home % cur_away).str();
}

void Sportsball::addEntry(int entry) {
  if(!entry) {
    if(++outs > 2) {
      this->is_away
        ? this->away += this->score()
        : this->home += this->score();
      this->resetFrame();
    }
    return;
  }

  ++this->runners;
  this->unscored = std::min(BASES - entry, this->unscored) + 1;
}

int Sportsball::score() {
  return this->runners - this->unscored;
}

void Sportsball::resetFrame() {
  this->runners = this->unscored = this->outs = 0;
  this->is_away = !this->is_away;
}
