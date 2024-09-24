// Caio Salvador Noboa - 2201926

#include <iostream>
#include <string>
#include "Classes.h"

#ifndef GAME_H
#define GAME_H

void Game::Start()
{
  std::cout << "Inicio do jogo" << std::endl;
  std::cout << "Vamos iniciar setando a dificuldade do jogo:" << std::endl;
  SetDifficultyLevel();
  SetCharacterName();
  int numberOfInitialLevels = 3;
  int numberOfMiddleLevels = 3;
  int numberOfFinalLevels = 3;

  for (int i = 1; i <= numberOfInitialLevels; i++)
  {
    std::cout << "Fase I " << i << '!' << std::endl;
    PlayInitialLevels();
  }

  for (int i = 1; i <= numberOfMiddleLevels; i++)
  {
    std::cout << "Fase M " << (i + numberOfInitialLevels) << '!' << std::endl;
    PlayMiddleLevels();
  }

  for (int i = 1; i <= numberOfFinalLevels; i++)
  {
    std::cout << "Fase F " << (i + numberOfInitialLevels + numberOfMiddleLevels) << '!' << std::endl;
    PlayFinalLevels();
  }

  std::cout << "Parabens, voce chegou a ultima fase!" << std::endl;
  PlayBossLevel();
}

void Game::SetDifficultyLevel()
{
  int entry;
  std::cout << "Escolha o nivel de dificuldade:" << std::endl;
  std::cout << "Digite 1 para escolher nivel facil;" << std::endl;
  std::cout << "Digite 2 para escolher nivel dificil;" << std::endl;
  std::cin >> entry;

  switch (entry)
  {
  case static_cast<int>(EnumDifficultyLevel::LOW):
    difficultyLevel = EnumDifficultyLevel::LOW;
    break;
  case static_cast<int>(EnumDifficultyLevel::HIGH):
    difficultyLevel = EnumDifficultyLevel::HIGH;
    break;
  default:
    SetDifficultyLevel();
    break;
  }
}

void Game::SetCharacterName()
{
  std::string name = "";
  std::cout << "Escolha o nome do personagem: ";
  std::cin.ignore();
  getline(std::cin, name);

  character.SetName(name);
}

void Game::PlayInitialLevels()
{
  srand(time(0));
  int chanceOfGettingNewElement = 0 + (rand() % 101);

  if (chanceOfGettingNewElement >= 30)
    character.GetNewElement(difficultyLevel);
  else
    EmptySQM();
}

void Game::PlayMiddleLevels()
{
  srand(time(0));
  int chanceOfGettingNewElementOrAtLeastNotFacingEnemy = 0 + (rand() % 101);

  if (chanceOfGettingNewElementOrAtLeastNotFacingEnemy >= 70)
    character.GetNewElement(difficultyLevel);
  else if (chanceOfGettingNewElementOrAtLeastNotFacingEnemy >= 50)
    EmptySQM();
  else
    KillOrBeKilled(false);
}

void Game::PlayFinalLevels()
{
  srand(time(0));
  int chanceOfGettingNewElementOrAtLeastNotFacingEnemy = 0 + (rand() % 101);

  if (chanceOfGettingNewElementOrAtLeastNotFacingEnemy >= 80)
    character.GetNewElement(difficultyLevel);
  else if (chanceOfGettingNewElementOrAtLeastNotFacingEnemy >= 70)
    EmptySQM();
  else
    KillOrBeKilled(false);
}

void Game::PlayBossLevel()
{
  KillOrBeKilled(true);
}

void Game::KillOrBeKilled(bool boss)
{
  Enemy enemy;
  enemy.GetEnemy(difficultyLevel, enemy, boss);

  while (enemy.IsEnemyAlive() && character.IsOurHeroAlive())
  {
    character.PrintHeroInformations();
    enemy.PrintEnemyInformations();
    MainCharacterTurn(enemy);

    if (enemy.IsEnemyAlive())
      EnemyTurn(enemy);
  }
}

void Game::MainCharacterTurn(Enemy &enemy)
{
  Element element;

  std::cout << "Verifique e use seus itens para atacar o inimigo ou se curar!" << std::endl;
  character.UseElement(element);

  if (element.elementType == EnumElementType::WEAPONS)
    enemy.EnemyGotAttacked(element);
}

void Game::EnemyTurn(Enemy enemy)
{
  character.OurHeroGotAttacked(enemy);
}

void Game::EmptySQM()
{
  Element element;
  bool userChoseElement = false;
  int entry;

  std::cout << "Nao ha nada por aqui..." << std::endl;
  std::cout << "Mas voce pode vericar o que possui no cinto e mochila, utilizar algum elemento." << std::endl;
  std::cout << "Escolha o que gostaria de fazer:" << std::endl;
  std::cout << "Digite 1 para verificar e usar seus itens;" << std::endl;
  std::cout << "Digite 2 para nao fazer nada;" << std::endl;
  std::cin >> entry;

  switch (entry)
  {
  case 1:
    character.UseElement(element);
    break;
  default:
    return;
    break;
  }
}

#endif