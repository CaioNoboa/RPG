// Caio Salvador Noboa - 2201926

#include <iostream>
#include "Enums.h"

class Element
{
public:
  Element(EnumElementType newElementType, std::string newName, int newWeight, int newPower);
  void GetElement(EnumDifficultyLevel difficultyLevel, Element &element);
  void PrintElement();
  EnumElementType elementType;
  std::string name;
  int weight;
  int power;

private:
  Element sortElement(EnumDifficultyLevel difficultyLevel);
};