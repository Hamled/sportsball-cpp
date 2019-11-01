#include <string>

class Sportsball {
public:
  std::string getScore();
  void addEntry(int entry);

private:
  const static auto BASES = 3;
  int runners;
  int unscored;
};
