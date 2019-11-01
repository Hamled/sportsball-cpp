#include <string>

class Sportsball {
public:
  Sportsball();
  std::string getScore();
  void addEntry(int entry);

private:
  int score();
  void resetFrame();

  const static auto BASES = 3;
  int runners;
  int unscored;

  int outs;
  bool is_away;
  int away;
  int home;
};
