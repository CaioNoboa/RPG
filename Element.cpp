// Caio Salvador Noboa - 2201926

#include "Classes.h"

#ifndef ELEMENT_H
#define ELEMENT_H

Element::Element()
{
}

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

  if (elementType == EnumElementType::POTIONS)
    std::cout << "Poder de cura: " << power << std::endl;
  else
    std::cout << "Poder de ataque: " << power << std::endl;

  std::cout << "Peso: " << weight << std::endl;
}

std::string Element::GetElementName()
{
  return name;
}

Element Element::sortElement(EnumDifficultyLevel difficultyLevel)
{
  bool hardMode = (difficultyLevel == EnumDifficultyLevel::HIGH);

  Element elementList[21] = {
      Element(EnumElementType::POTIONS, "Pocao de cura basica 1", hardMode ? 15 : 10, hardMode ? 15 : 20),
      Element(EnumElementType::POTIONS, "Pocao de cura basica 2", hardMode ? 15 : 10, hardMode ? 20 : 25),
      Element(EnumElementType::POTIONS, "Pocao de cura intermediaria 1", hardMode ? 20 : 15, hardMode ? 25 : 30),
      Element(EnumElementType::POTIONS, "Pocao de cura intermediaria 2", hardMode ? 20 : 15, hardMode ? 30 : 50),
      Element(EnumElementType::POTIONS, "Pocao de cura complexa 1", hardMode ? 20 : 15, hardMode ? 50 : 75),
      Element(EnumElementType::POTIONS, "Pocao de cura complexa 2", hardMode ? 20 : 15, 100),
      Element(EnumElementType::WEAPONS, "Arma basica 1", hardMode ? 15 : 10, hardMode ? 15 : 20),
      Element(EnumElementType::WEAPONS, "Arma basica 2", hardMode ? 15 : 10, hardMode ? 20 : 25),
      Element(EnumElementType::WEAPONS, "Arma basica 3", hardMode ? 15 : 10, hardMode ? 25 : 30),
      Element(EnumElementType::WEAPONS, "Arma intermediaria 1", hardMode ? 20 : 15, hardMode ? 30 : 35),
      Element(EnumElementType::WEAPONS, "Arma intermediaria 2", hardMode ? 20 : 15, hardMode ? 35 : 40),
      Element(EnumElementType::WEAPONS, "Arma intermediaria 3", hardMode ? 20 : 15, hardMode ? 40 : 45),
      Element(EnumElementType::WEAPONS, "Arma complexa 1", hardMode ? 20 : 15, hardMode ? 45 : 50),
      Element(EnumElementType::WEAPONS, "Arma complexa 2", hardMode ? 20 : 15, hardMode ? 50 : 55),
      Element(EnumElementType::WEAPONS, "Arma complexa 3", hardMode ? 20 : 15, hardMode ? 55 : 60),
      Element(EnumElementType::WEAPONS, "Arma destruidora 1", hardMode ? 25 : 20, hardMode ? 60 : 70),
      Element(EnumElementType::WEAPONS, "Arma destruidora 2", hardMode ? 25 : 20, hardMode ? 65 : 80),
      Element(EnumElementType::WEAPONS, "Arma destruidora 3", hardMode ? 25 : 20, hardMode ? 70 : 90),
      Element(EnumElementType::WEAPONS, "Pocao de fogo 1", hardMode ? 25 : 20, hardMode ? 60 : 70),
      Element(EnumElementType::WEAPONS, "Pocao de fogo 2", hardMode ? 25 : 20, hardMode ? 65 : 80),
      Element(EnumElementType::WEAPONS, "Pocao de fogo 3", hardMode ? 25 : 20, hardMode ? 70 : 90),
  };

  srand(time(0));
  int index = 0 + (rand() % 21);
  return elementList[index];
}

#endif
