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
  StoreElement(newElement);
}

void Character::StoreElement(Element element)
{
  Element topBackpackElement;
  int entry;

  if (belt.Full())
  {
    std::cout << "Como seu cinto esta lotado, precisara ou substituir por um item ou guardar na mochila" << std::endl;
  }

  std::cout << "Escolha o q qr fazer:" << std::endl;
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
    std::cout << "Elemento topo: " << std::endl;
    topBackpackElement.PrintElement();
    break;
  case 3:
    belt.Insert(element);
    break;
  case 4:
    backpack.Push(element);
    break;
  default:
    std::cout << "Valor invalido, vamos tentar novamente" << std::endl;
    StoreElement(element);
    break;
  }
}

void Character::UseElement(Element &element)
{
  Element topBackpackElement;
  int entry;

  if (belt.Empty() && backpack.Empty())
  {
    std::cout << "Cinto e Mochila vazios" << std::endl;
    return;
  }

  std::cout << "Escolha o q qr fazer:" << std::endl;
  std::cout << "Digite 1 para listar itens cinto;" << std::endl;
  std::cout << "Digite 2 para listar item do topo da mochila;" << std::endl;
  std::cout << "Digite 3 para usar item do cinto;" << std::endl;
  std::cout << "Digite 4 para usar item da mochila;" << std::endl;
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
    break;
  case 4:
    backpack.Pop(element);
    break;
  default:
    std::cout << "Valor invalido, vamos tentar novamente" << std::endl;
    UseElement(element);
    break;
  }
}

#endif