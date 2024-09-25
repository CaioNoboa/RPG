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

std::string Character::GetName()
{
  return name;
}

void Character::GetNewElement(EnumDifficultyLevel difficultyLevel)
{
  Element newElement;
  int entry;

  newElement.GetElement(difficultyLevel, newElement);
  std::cout << "Voce encontrou um novo elemento!" << std::endl;
  newElement.PrintElement();
  std::cout << "-------------------" << std::endl;
  std::cout << "Voce pode guardar este elemento ou apenas ignora-lo." << std::endl;
  std::cout << "Digite 1 para guardar este elemento;" << std::endl;
  std::cout << "Digite 2 para apenas ignora-lo." << std::endl;
  std::cin >> entry;

  if (entry == 1)
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
    std::cout << "-------------------" << std::endl;
    std::cout << "Escolha o que gostaria de fazer:" << std::endl;
    std::cout << "Digite 1 para listar itens do cinto;" << std::endl;
    std::cout << "Digite 2 para listar item do topo da mochila;" << std::endl;
    std::cout << "Digite 3 para guardar no cinto;" << std::endl;
    std::cout << "Digite 4 para guardar na mochila." << std::endl;
    std::cin >> entry;

    switch (entry)
    {
    case 1:
      belt.ListBeltElements();
      break;
    case 2:
      backpack.Top(topBackpackElement, true);
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
    std::cout << "Digite 5 para nao fazer nada." << std::endl;
    std::cin >> entry;

    switch (entry)
    {
    case 1:
      belt.ListBeltElements();
      break;
    case 2:
      backpack.Top(topBackpackElement, true);
      break;
    case 3:
      userChoseElement = belt.Delete(element);
      break;
    case 4:
      userChoseElement = backpack.Pop(element);
      break;
    default:
      return false;
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

    std::cout << "-------------------" << std::endl;
    std::cout << "Voce utilizou uma pocao de cura! Seus pontos de vida agora sao " << healthPoints << '!' << std::endl;
  }

  return true;
}

bool Character::IsOurHeroAlive()
{
  return (healthPoints > 0);
}

void Character::PrintHeroInformations()
{
  std::cout << "-------------------" << std::endl;
  std::cout << "Dados do nosso heroi" << std::endl;
  std::cout << "Nome: " << name << std::endl;
  std::cout << "Pontos de vida: " << healthPoints << std::endl;
  std::cout << "-------------------" << std::endl;
}

void Character::OurHeroGotAttacked(Enemy enemy)
{
  int enemyPower = enemy.GetEnemyPower();
  std::cout << "-------------------" << std::endl;
  std::cout << "Voce foi atacado e perdeu " << enemyPower << " pontos de vida!" << std::endl;
  healthPoints -= enemyPower;
}

void Character::PrintBasicInformations()
{
  Element element;
  std::string topBackpackElementName = "Mochila vazia";

  if (!backpack.Empty())
  {
    backpack.Top(element, false);
    topBackpackElementName = element.GetElementName();
  }
  std::cout << "-------------------" << std::endl;
  std::cout << "Conteudo total do cinto: " << belt.Size() << '/' << MaxBeltItems << ". Peso: " << belt.Weight() << '/' << MaxBeltWeight << '.' << std::endl;
  std::cout << "Elemento do topo da mochila: " << topBackpackElementName << ". Conteudo total: " << backpack.Size() << '.' << std::endl;
  std::cout << "Pontos de vida de " << name << ": " << healthPoints << '.' << std::endl;
  std::cout << "-------------------" << std::endl;
}

#endif