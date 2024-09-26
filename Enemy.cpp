// Caio Salvador Noboa - 2201926

#include "Classes.h"

#ifndef ENEMY_H
#define ENEMY_H

Enemy::Enemy()
{
  name = "";
  healthPoints = 0;
  power = 0;
}

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

bool Enemy::IsEnemyAlive()
{
  return (healthPoints > 0);
}

void Enemy::PrintEnemyInformations()
{
  std::cout << "Dados do inimigo" << std::endl;
  std::cout << "Nome: " << name << std::endl;
  std::cout << "Pontos de vida: " << healthPoints << std::endl;
  std::cout << "Pontos de ataque: " << power << std::endl;
  std::cout << "-------------------" << std::endl;
}

void Enemy::EnemyGotAttacked(Element element)
{
  healthPoints -= element.power;

  if (!IsEnemyAlive())
  {
    std::cout << "-------------------" << std::endl;
    std::cout << "Muito bem, voce venceu o inimigo " << name << '!' << std::endl;
    std::cout << "-------------------" << std::endl;
  }
}

int Enemy::GetEnemyPower()
{
  return power;
}

Enemy Enemy::SortEnemy(EnumDifficultyLevel difficultyLevel, bool boss)
{
  bool hardMode = (difficultyLevel == EnumDifficultyLevel::HIGH);

  if (boss)
    return Enemy("Balrog", 200, hardMode ? 30 : 20);

  Enemy enemiesList[9] = {
      Enemy("Guerreiro Goblin", hardMode ? 15 : 10, hardMode ? 10 : 5),
      Enemy("Ladrao da Floresta", hardMode ? 20 : 15, hardMode ? 10 : 5),
      Enemy("Soldado Desgarrado", hardMode ? 25 : 20, hardMode ? 10 : 5),
      Enemy("Capitao Orc", hardMode ? 30 : 25, hardMode ? 15 : 10),
      Enemy("Mago Sombrio", hardMode ? 35 : 30, hardMode ? 15 : 10),
      Enemy("Assassino das Sombras", hardMode ? 40 : 35, hardMode ? 15 : 10),
      Enemy("Senhor dos Mortos", hardMode ? 45 : 40, hardMode ? 20 : 15),
      Enemy("Guardiao do Abismo", hardMode ? 50 : 50, hardMode ? 20 : 15),
      Enemy("Lorde da Destruicao", hardMode ? 70 : 60, hardMode ? 20 : 15),
  };

  srand(time(0));
  int index = 0 + (rand() % 9);
  return enemiesList[index];
}

#endif