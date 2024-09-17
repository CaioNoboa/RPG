// Caio Salvador Noboa - 2201926

#include <iostream>
#include "Belt.h"
#include "Backpack.h"

class Character
{
public:
  Character();
  void SetName(std::string newName);
  void GetName(std::string &characterName);
  void GetNewElement(EnumDifficultyLevel difficultyLevel);
  void StoreElement(Element element);
  void UseElement(Element &element);

private:
  std::string name;
  int healthPoints;
  Belt belt;
  Backpack backpack;
};