// Caio Salvador Noboa - 2201926

#include "Classes.h"

#ifndef CHARACTER_H
#define CHARACTER_H

Character::Character()
{
  name = "";
  healthPoints = 100;
}

void Character::SetName(std::string newName)
{
  name = newName;
}

void Character::GetName(std::string &characterName)
{
  characterName = name;
}

void Character::GetNewElement(EnumDifficultyLevel difficultyLevel)
{
  Element newElement;
  newElement.GetElement(difficultyLevel, newElement);
  std::cout << "Voce encontrou um novo elemento!" << std::endl;
  newElement.PrintElement();
  std::cout << "Agora precisa guardar este elemento!" << std::endl;
  StoreElement(newElement);
}

void Character::StoreElement(Element element)
{
  Element topBackpackElement;
  bool userChoseHowToStore = false;
  int entry;

  if (belt.Full(element))
  {
    std::cout << "Como seu cinto esta lotado, precisara ou substituir por um item ou guardar na mochila" << std::endl;
  }

  while (!userChoseHowToStore)
  {
    std::cout << "Escolha o que gostaria de fazer:" << std::endl;
    std::cout << "Digite 1 para listar itens do cinto;" << std::endl;
    std::cout << "Digite 2 para listar item do topo da mochila;" << std::endl;
    std::cout << "Digite 3 para guardar no cinto;" << std::endl;
    std::cout << "Digite 4 para guardar na mochila;" << std::endl;
    std::cin >> entry;

    switch (entry)
    {
    case 1:
      belt.ListBeltElements();
      break;
    case 2:
      backpack.Top(topBackpackElement);
      std::cout << "Elemento topo:" << std::endl;
      topBackpackElement.PrintElement();
      break;
    case 3:
      userChoseHowToStore = belt.Insert(element);
      break;
    case 4:
      userChoseHowToStore = backpack.Push(element);
      break;
    default:
      std::cout << "Valor invalido, vamos tentar novamente." << std::endl;
      break;
    }
  }
}

bool Character::UseElement(Element &element)
{
  Element topBackpackElement;
  bool userChoseElement = false;
  int entry;

  if (belt.Empty() && backpack.Empty())
  {
    std::cout << "Cinto e Mochila vazios! Nao ha elementos disponiveis!" << std::endl;
    return false;
  }

  while (!userChoseElement)
  {
    std::cout << "Escolha o que gostaria de fazer:" << std::endl;
    std::cout << "Digite 1 para listar itens cinto;" << std::endl;
    std::cout << "Digite 2 para listar item do topo da mochila;" << std::endl;
    std::cout << "Digite 3 para usar item do cinto;" << std::endl;
    std::cout << "Digite 4 para usar item da mochila;" << std::endl;
    std::cout << "Digite 5 para retornar." << std::endl;
    std::cin >> entry;

    switch (entry)
    {
    case 1:
      belt.ListBeltElements();
      break;
    case 2:
      backpack.Top(topBackpackElement);
      std::cout << "Elemento topo: " << std::endl;
      topBackpackElement.PrintElement();
      break;
    case 3:
      belt.Delete(element);
      userChoseElement = true;
      break;
    case 4:
      backpack.Pop(element);
      userChoseElement = true;
      break;
    case 5:
      return false;
      break;
    default:
      std::cout << "Valor invalido, vamos tentar novamente." << std::endl;
      break;
    }
  }

  if (element.elementType == EnumElementType::POTIONS)
  {
    int newHealthPoints = healthPoints + element.power;

    if (newHealthPoints >= MaxHealthPoints)
      healthPoints = MaxHealthPoints;
    else
      healthPoints = newHealthPoints;
  }

  return true;
}

bool Character::IsOurHeroAlive()
{
  return (healthPoints > 0);
}

void Character::PrintHeroInformations()
{
  std::cout << "Dados do nosso heroi" << std::endl;
  std::cout << "Nome: " << name << std::endl;
  std::cout << "Pontos de vida: " << healthPoints << std::endl;
}

#endif