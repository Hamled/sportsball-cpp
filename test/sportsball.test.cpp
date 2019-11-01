#include <mettle.hpp>
using namespace mettle;

#include <string>
#include "sportsball.hpp"

suite<> sportsball("sportsball", [](auto &_) {
  _.test("is a class", []() {
    expect(std::is_class<Sportsball>::value, equal_to(true));
  });
  _.test("has a getScore method", []() {
    expect(
        std::is_member_function_pointer<decltype(&Sportsball::getScore)>::value,
        equal_to(true));
  });
  _.test("has an addEntry method", []() {
    expect(
        std::is_member_function_pointer<decltype(&Sportsball::addEntry)>::value,
        equal_to(true));
  });
  _.subsuite("getScore", [](auto &_) {
    _.test("scores 0 points for no runners", []() {
      Sportsball sb{};
      auto result = sb.getScore();
      expect(result, equal_to(std::string{"Home: 0 Away: 0"}));
    });
    _.test("scores points for 0+ runners before home run", []() {
      Sportsball sb{};
      sb.addEntry(3);
      sb.addEntry(2);
      sb.addEntry(1);
      sb.addEntry(4);
      sb.addEntry(3);
      sb.addEntry(2);
      sb.addEntry(1);

      expect(sb.getScore(), equal_to(std::string{"Home: 0 Away: 4"}));
    });
    _.test("scores points for 1+ runners before triple", []() {
      Sportsball sb{};
      sb.addEntry(3);
      sb.addEntry(2);
      sb.addEntry(1);
      sb.addEntry(3);
      sb.addEntry(2);
      sb.addEntry(1);

      expect(sb.getScore(), equal_to(std::string{"Home: 0 Away: 3"}));
    });
  });
 });
