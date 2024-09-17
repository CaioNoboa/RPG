// Caio Salvador Noboa - 2201926

#include <iostream>
#include "Enums.h"

class Enemy
{
public:
  Enemy(std::string newName, int newHealthPoints, int newPower);
  void GetEnemy(EnumDifficultyLevel difficultyLevel, Enemy &enemy, bool boss = false);

private:
  std::string name;
  int healthPoints;
  int power;
  Enemy sortEnemy(EnumDifficultyLevel difficultyLevel, bool boss = false);
};
