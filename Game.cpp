// Caio Salvador Noboa - 2201926

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include "Classes.h"

#ifndef GAME_H
#define GAME_H

Game::Game()
{
  playerName = "";
  levelCounter = 0;
  numberOfInitialLevels = 7;
  numberOfMiddleLevels = 3;
  numberOfFinalLevels = 3;
  totalLevels = numberOfInitialLevels + numberOfMiddleLevels + numberOfFinalLevels + 1;
}

void Game::Start()
{
  std::cout << "Inicio do jogo" << std::endl;
  SetDifficultyLevel();
  SetNames();

  for (int i = 1; i <= numberOfInitialLevels; i++)
  {
    PauseAndCleanConsole();
    std::cout << "Fase I " << i << '!' << std::endl;
    character.PrintBasicInformations();
    PlayInitialLevel();
    levelCounter++;
  }

  for (int i = 1; i <= numberOfMiddleLevels; i++)
  {
    PauseAndCleanConsole();
    std::cout << "Fase M " << (i + numberOfInitialLevels) << '!' << std::endl;
    character.PrintBasicInformations();
    PlayMiddleLevel();
    levelCounter++;
  }

  for (int i = 1; i <= numberOfFinalLevels; i++)
  {
    PauseAndCleanConsole();
    std::cout << "Fase F " << (i + numberOfInitialLevels + numberOfMiddleLevels) << '!' << std::endl;
    character.PrintBasicInformations();
    PlayFinalLevel();
    levelCounter++;
  }

  PauseAndCleanConsole();
  std::cout << "Voce chegou a ultima fase!" << std::endl;
  character.PrintBasicInformations();
  PlayBossLevel();
}

void Game::SetDifficultyLevel()
{
  int entry;
  std::cout << "Escolha o nivel de dificuldade para o jogo:" << std::endl;
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

void Game::SetNames()
{
  std::string name = "";

  std::cout << "Informe seu nome: ";
  std::cin.ignore();
  getline(std::cin, playerName);

  std::cout << "Escolha o nome do personagem: ";
  getline(std::cin, name);

  character.SetName(name);
}

void Game::PlayInitialLevel()
{
  srand(time(0));
  int chanceOfGettingNewElement = 0 + (rand() % 101);

  if (chanceOfGettingNewElement >= 30)
    character.GetNewElement(difficultyLevel);
  else
    EmptySQM();
}

void Game::PlayMiddleLevel()
{
  srand(time(0));
  int chanceOfGettingNewElementOrAtLeastNotFacingEnemy = 0 + (rand() % 101);

  if (chanceOfGettingNewElementOrAtLeastNotFacingEnemy >= 50)
    character.GetNewElement(difficultyLevel);
  else if (chanceOfGettingNewElementOrAtLeastNotFacingEnemy >= 40)
    EmptySQM();
  else
    KillOrBeKilled(false);
}

void Game::PlayFinalLevel()
{
  srand(time(0));
  int chanceOfGettingNewElementOrAtLeastNotFacingEnemy = 0 + (rand() % 101);

  if (chanceOfGettingNewElementOrAtLeastNotFacingEnemy >= 60)
    character.GetNewElement(difficultyLevel);
  else if (chanceOfGettingNewElementOrAtLeastNotFacingEnemy >= 50)
    EmptySQM();
  else
    KillOrBeKilled(false);
}

void Game::PlayBossLevel()
{
  KillOrBeKilled(true);

  if (character.IsOurHeroAlive())
  {
    levelCounter++;
    RegisterScore();
    std::cout << "Voce sobreviveu ao desafio!" << std::endl;
    std::cout << "Parabens!" << std::endl;
  }
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

  if (!character.IsOurHeroAlive())
  {
    RegisterScore();
    std::cout << "Opa, voce nao sobreviveu ao desafio..." << std::endl;
    std::cout << "Boa sorte da proxima vez!" << std::endl;
    std::cout << "GAME OVER" << std::endl;
    abort();
  }
}

void Game::EmptySQM()
{
  Element element;
  bool userChoseElement = false;
  int entry;

  std::cout << "Nao ha nada por aqui..." << std::endl;
  std::cout << "Mas voce pode vericar o que possui no cinto e mochila, utilizar algum elemento." << std::endl;
  std::cout << "-------------------" << std::endl;
  std::cout << "Escolha o que gostaria de fazer:" << std::endl;
  std::cout << "Digite 1 para verificar e usar seus itens;" << std::endl;
  std::cout << "Digite 2 para nao fazer nada;" << std::endl;
  std::cin >> entry;

  if (entry == 1)
    character.UseElement(element);
}

void Game::RegisterScore()
{
  std::string archiveName = "high_scores.txt";
  std::time_t data = std::time(nullptr);
  std::tm *currentData = std::localtime(&data);
  std::ofstream archive(archiveName, std::ios::app);

  if (!archive.is_open())
  {
    std::cout << "Erro ao abrir o arquivo " << archiveName << '.' << std::endl;
    exit(-1);
  }

  archive << "Jogador " << playerName << ", na data " << std::put_time(currentData, "%d/%m/%Y") << ", alcançou nivel " << levelCounter << ", do total de " << totalLevels << std::endl;
  archive.close();
}

void Game::PauseAndCleanConsole()
{
  std::cout << "Aperte 'enter' para iniciar a proxima fase!" << std::endl;
  system("pause");
  system("cls");
}

#endif