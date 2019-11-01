#include <string>

class Sportsball {
public:
  std::string getScore();
  void addEntry(int entry);
private:
  int runners;
  int unscored;
};
