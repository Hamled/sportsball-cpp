#include <mettle.hpp>
using namespace mettle;

#include "sportsball.hpp"

suite<> sportsball("sportsball", [](auto &_) {
  _.test("is a class", []() {
    expect(std::is_class<Sportsball>::value, equal_to(true));
  });
 });
