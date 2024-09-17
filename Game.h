// Caio Salvador Noboa - 2201926

#include "Character.h"
#include "Enums.h"

class Game
{
  /*
    Níveis
    Mapa
    Elementos
    Heroi
  */

public:
  void start();

private:
  Character character;
  EnumDifficultyLevel difficultyLevel;

  void setDifficultyLevel();
  void setCharacterName();
  void playInitialLevels();
  void playMiddleLevels();
  void playFinalLevels();
  void playBossLevel();
  void killOrBeKilled();
  void mainCharacterTurn();
  void enemyTurn();
};