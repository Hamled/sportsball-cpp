#include <string>

class Sportsball {
private:
  static const int BASES = 3;
  int runners = 0;
  int unscored = 0;
  int outs = 0;
  int away = 0;
  int home = 0;
  int is_away = false;

  int score() const;
  void resetFrame();

public:
  Sportsball();
  std::string getScore() const;
  void addEntry(int entry);
};
