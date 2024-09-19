// Caio Salvador Noboa - 2201926

#include "Classes.h"

#ifndef ENEMY_H
#define ENEMY_H

Enemy::Enemy(std::string newName, int newHealthPoints, int newPower)
{
  name = newName;
  healthPoints = newHealthPoints;
  power = newPower;
}

void Enemy::GetEnemy(EnumDifficultyLevel difficultyLevel, Enemy &enemy, bool boss)
{
  enemy = SortEnemy(difficultyLevel, boss);
}

Enemy Enemy::SortEnemy(EnumDifficultyLevel difficultyLevel, bool boss)
{
  bool hardMode = (difficultyLevel == EnumDifficultyLevel::HIGH);

  if (boss)
  {
    return Enemy("Boss", hardMode ? 100 : 50, hardMode ? 20 : 10);
  }

  Enemy enemiesList[5] = {
      Enemy("1", hardMode ? 100 : 50, hardMode ? 20 : 10),
      Enemy("2", hardMode ? 100 : 50, hardMode ? 20 : 10),
      Enemy("3", hardMode ? 100 : 50, hardMode ? 20 : 10),
      Enemy("4", hardMode ? 100 : 50, hardMode ? 20 : 10),
      Enemy("5", hardMode ? 100 : 50, hardMode ? 20 : 10),
  };

  srand(time(0));
  int index = 0 + (rand() % 4);
  return enemiesList[index];
}

#endif