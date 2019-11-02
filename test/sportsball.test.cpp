#include <mettle.hpp>
using namespace mettle;

#include "sportsball.hpp"

suite<> sportsball("Sportsball", [](auto &_) {
  _.test("is a class", []() {
    expect(std::is_class<Sportsball>::value, equal_to(true));
  });
  _.test("has a getScore method", []() {
    expect(std::is_member_function_pointer<decltype(&Sportsball::getScore)>::value, equal_to(true));
  });
});
