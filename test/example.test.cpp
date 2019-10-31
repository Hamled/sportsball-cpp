#include <mettle.hpp>
using namespace mettle;

#include "example.hpp"

suite<> first("my first suite", [](auto &_) {
  _.test("my first test", []() {
    expect(example(), equal_to(true));
  });
});
