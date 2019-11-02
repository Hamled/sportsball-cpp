#include <string>

class Sportsball {
private:
  static const int BASES = 3;
  int runners = 0;
  int unscored = 0;

public:
  std::string getScore() const;
  void addEntry(int entry);
};
