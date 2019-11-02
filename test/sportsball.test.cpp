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
  _.test("has an addEntry method", []() {
    expect(std::is_member_function_pointer<decltype(&Sportsball::addEntry)>::value, equal_to(true));
  });
  _.subsuite("getScore", [](auto &_) {
    _.test("scores 0 points for no runners", []() {
      Sportsball sb;

      expect(sb.getScore(), equal_to("Home: 0 Away: 0"));
    });
  });
});
