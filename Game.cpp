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

  for (int i = 0; i < 3; i++)
  {
    PlayInitialLevels();
  }

  for (int i = 0; i < 3; i++)
  {
    PlayMiddleLevels();
  }

  for (int i = 0; i < 3; i++)
  {
    PlayFinalLevels();
  }

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
    KillOrBeKilled();
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
    KillOrBeKilled();
}

void Game::PlayBossLevel()
{
  /*
    Tem inimigo
  */
}

void Game::KillOrBeKilled()
{
  // Fazer um personagem inimigo

  // while os dois personagens continuam vivos
  // Fica alternando turnos
}

void Game::MainCharacterTurn()
{
  int entry;
  std::cout << "Digite o que gostaria de fazer: " << std::endl;
  std::cout << "Digite 1 para atacar;" << std::endl;
  std::cout << "Digite 2 para usar pocao;" << std::endl;
  std::cout << "Digite 3 para ;" << std::endl;
  std::cin >> entry;

  switch (entry)
  {
  }
}

void Game::EnemyTurn()
{
}

void Game::EmptySQM()
{
  std::cout << "Nao ha nada por aqui..." << std::endl;
  std::cout << "Mas voce pode vericar o que possui no cinto e mochila, se curar se necessario..." << std::endl;

  // TODO
}

#endif