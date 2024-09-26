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
      Element(EnumElementType::POTIONS, "Pocao Vitalicia Menor", hardMode ? 15 : 10, hardMode ? 15 : 20),
      Element(EnumElementType::POTIONS, "Elixir Revigorante", hardMode ? 15 : 10, hardMode ? 20 : 25),
      Element(EnumElementType::POTIONS, "Essencia Restauradora", hardMode ? 20 : 15, hardMode ? 25 : 30),
      Element(EnumElementType::POTIONS, "Frasco da Vitalidade", hardMode ? 20 : 15, hardMode ? 30 : 50),
      Element(EnumElementType::POTIONS, "Elixir da Vida Plena", hardMode ? 20 : 15, hardMode ? 50 : 75),
      Element(EnumElementType::POTIONS, "Nectar da Cura Suprema", hardMode ? 20 : 15, 100),
      Element(EnumElementType::WEAPONS, "Espada de Aco Simples", hardMode ? 15 : 10, hardMode ? 15 : 20),
      Element(EnumElementType::WEAPONS, "Adaga de Ferro Rustica", hardMode ? 15 : 10, hardMode ? 20 : 25),
      Element(EnumElementType::WEAPONS, "Martelo de Batalha", hardMode ? 15 : 10, hardMode ? 25 : 30),
      Element(EnumElementType::WEAPONS, "Espada Longa", hardMode ? 20 : 15, hardMode ? 30 : 35),
      Element(EnumElementType::WEAPONS, "Lanca de Guerra", hardMode ? 20 : 15, hardMode ? 35 : 40),
      Element(EnumElementType::WEAPONS, "Machado de Batalha", hardMode ? 20 : 15, hardMode ? 40 : 45),
      Element(EnumElementType::WEAPONS, "Espada do Guardiao", hardMode ? 20 : 15, hardMode ? 45 : 50),
      Element(EnumElementType::WEAPONS, "Lamina Runica", hardMode ? 20 : 15, hardMode ? 50 : 55),
      Element(EnumElementType::WEAPONS, "Gladio da Sombra", hardMode ? 20 : 15, hardMode ? 55 : 60),
      Element(EnumElementType::WEAPONS, "Espada do Aniquilador", hardMode ? 25 : 20, hardMode ? 60 : 70),
      Element(EnumElementType::WEAPONS, "Martelo do Juizo Final", hardMode ? 25 : 20, hardMode ? 65 : 80),
      Element(EnumElementType::WEAPONS, "Lamina do Apocalipse", hardMode ? 25 : 20, hardMode ? 70 : 90),
      Element(EnumElementType::WEAPONS, "Frasco de Fogo Menor", hardMode ? 25 : 20, hardMode ? 60 : 70),
      Element(EnumElementType::WEAPONS, "Frasco de Fogo Crepitante", hardMode ? 25 : 20, hardMode ? 65 : 80),
      Element(EnumElementType::WEAPONS, "Frasco da Chama Infernal", hardMode ? 25 : 20, hardMode ? 70 : 90),
  };

  srand(time(0));
  int index = 0 + (rand() % 21);
  return elementList[index];
}

#endif
