// Caio Salvador Noboa - 2201926

#include <iostream>
#include <string>
#include "Game.h"

#ifndef GAME_H
#define GAME_H

void Game::start()
{
  std::cout << "Inicio do jogo" << std::endl;
  std::cout << "Vamos iniciar setando a dificuldade do jogo:" << std::endl;
  setDifficultyLevel();
  setCharacterName();

  for (int i = 0; i < 3; i++)
  {
    playInitialLevels();
  }

  for (int i = 0; i < 3; i++)
  {
    playMiddleLevels();
  }

  for (int i = 0; i < 3; i++)
  {
    playFinalLevels();
  }

  playBossLevel();
}

void Game::setDifficultyLevel()
{
  int entry;
  std::cout << "Escolha o nivel de dificuldade:" << std::endl;
  std::cout << "Digite 1 para escolher nivel facil;" << std::endl;
  std::cout << "Digite 2 para escolher nivel medio;" << std::endl;
  std::cout << "Digite 3 para escolher nivel dificil;" << std::endl;
  std::cin >> entry;

  switch (entry)
  {
  case static_cast<int>(EnumDifficultyLevel::LOW):
    difficultyLevel = EnumDifficultyLevel::LOW;
    break;
  case static_cast<int>(EnumDifficultyLevel::MEDIUM):
    difficultyLevel = EnumDifficultyLevel::MEDIUM;
    break;
  case static_cast<int>(EnumDifficultyLevel::HIGH):
    difficultyLevel = EnumDifficultyLevel::HIGH;
    break;
  default:
    setDifficultyLevel();
    break;
  }
}

void Game::setCharacterName()
{
  std::string name = "";
  std::cout << "Escolha o nome do personagem: ";
  std::cin.ignore();
  getline(std::cin, name);

  character.SetName(name);
}

void Game::playInitialLevels()
{
  /*
    Não tem nada
    Ou tem elemento
  */

  // Faço um sorteio para ver se encontrará algo ou nao
  srand(time(0));
  int chanceOfGettingNewElement = 0 + (rand() % 101);
  if (chanceOfGettingNewElement >= 30)
  {
    character.GetNewElement(difficultyLevel);
  }
  else
  {
    // Vazio
  }
}

void Game::playMiddleLevels()
{
  /*
    Não tem nada
    Ou tem elemento
    Ou tem inimigo
  */

  srand(time(0));
  int chanceOfGettingNewElement = 0 + (rand() % 101);
  if (chanceOfGettingNewElement >= 70)
  {
    character.GetNewElement(difficultyLevel);
  }
  else if (chanceOfGettingNewElement >= 50)
  {
    // Vazio
  } else {
    // Inimigo
    killOrBeKilled();
  }


  // Element newElement = element.sortElement(difficultyLevel);
}

void Game::playFinalLevels()
{
  /*
    Não tem nada
    Ou tem elemento
    Ou tem inimigo
  */
  srand(time(0));
  int chanceOfGettingNewElement = 0 + (rand() % 101);
  if (chanceOfGettingNewElement >= 80)
  {
    character.GetNewElement(difficultyLevel);
  }
  else if (chanceOfGettingNewElement >= 70)
  {
    // Vazio
  } else {
    // Inimigo
  }}

void Game::playBossLevel()
{
  /*
    Tem inimigo
  */
}

void Game::killOrBeKilled()
{
  // Fazer um personagem inimigo

  // while os dois personagens continuam vivos
  // Fica alternando turnos

}

void Game::mainCharacterTurn()
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

void Game::enemyTurn()
{
}

#endif