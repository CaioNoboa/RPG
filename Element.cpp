// Caio Salvador Noboa - 2201926

#include "Element.h"

#ifndef ELEMENT_H
#define ELEMENT_H

Element::Element(EnumElementType newElementType, std::string newName, int newWeight, int newPower)
{
  elementType = newElementType;
  name = newName;
  weight = newWeight;
  power = newPower;
}

void Element::GetElement(EnumDifficultyLevel difficultyLevel, Element &element)
{
  element = sortElement(difficultyLevel);
}

void Element::PrintElement()
{
  std::cout << "Nome: " << name << std::endl;

  if (elementType == EnumElementType::potions)
    std::cout << "Poder de cura: " << power << std::endl;
  else
    std::cout << "Poder de ataque: " << power << std::endl;

  std::cout << "Peso: " << weight << std::endl;
}

Element Element::sortElement(EnumDifficultyLevel difficultyLevel)
{
  bool hardMode = (difficultyLevel == EnumDifficultyLevel::HIGH);

  Element elementList[5] = {
      Element(EnumElementType::potions, "Element1", hardMode ? 5 : 10, hardMode ? 5 : 10),
      Element(EnumElementType::potions, "Element1", hardMode ? 5 : 10, hardMode ? 5 : 10),
      Element(EnumElementType::potions, "Element1", hardMode ? 5 : 10, hardMode ? 5 : 10),
      Element(EnumElementType::potions, "Element1", hardMode ? 5 : 10, hardMode ? 5 : 10),
      Element(EnumElementType::potions, "Element1", hardMode ? 5 : 10, hardMode ? 5 : 10),
  };

  srand(time(0));
  int index = 0 + (rand() % 4);
  return elementList[index];
}

#endif
