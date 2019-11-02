#include <string>

class Sportsball {
private:
  int runners = 0;
  int unscored = 0;

public:
  std::string getScore() const;
  void addEntry(int entry);
};
