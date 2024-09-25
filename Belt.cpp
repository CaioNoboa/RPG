// Caio Salvador Noboa - 2201926

#include "Classes.h"

#ifndef BELT_H
#define BELT_H

Belt::Belt()
{
  count = 0;
  weightCount = 0;
}

Belt::~Belt()
{
  Clear();
}

bool Belt::Full(Element element)
{
  return ((count == MaxBeltItems) || ((element.weight + weightCount) > MaxBeltWeight));
}

bool Belt::Empty()
{
  return (count == 0);
}

bool Belt::Insert(Element element)
{
  if (Full(element))
  {
    int entry;
    std::cout << "O cinto esta cheio e nao possui espaco para o novo elemento!" << std::endl;
    std::cout << "Digite 1 para verificar seu cinto e substituir um item pelo novo elemento;" << std::endl;
    std::cout << "Digite 2 para retornar." << std::endl;
    std::cin >> entry;

    if (entry == 1)
      return Replace(element);
    else
      return false;
  }

  int position = GetInsertPosition();

  if ((position < 1) || (position > (count + 1)))
  {
    std::cout << "Posição inválida" << std::endl;
    return false;
  }

  for (int i = count; i >= position; i--)
    BeltElements[i + 1] = BeltElements[i];

  BeltElements[position] = element;
  weightCount += element.weight;
  count++;
  return true;
}

bool Belt::Delete(Element &element)
{
  if (Empty())
  {
    std::cout << "Cinto vazio!" << std::endl;
    return false;
  }

  int position = GetElementPosition(false);
  if (position < 1 || position > count)
  {
    std::cout << "Posição inválida" << std::endl;
    return false;
  }

  element = BeltElements[position];
  weightCount -= element.weight;
  count--;

  for (int i = position; i < count; i++)
  {
    BeltElements[i] = BeltElements[i + 1];
  }

  return true;
}

bool Belt::Replace(Element element)
{
  int position = GetElementPosition(true);

  if (position < 1 || position > count)
  {
    std::cout << "Posição inválida" << std::endl;
    return false;
  }

  BeltElements[position] = element;
  return true;
}

int Belt::Size()
{
  return count;
}

int Belt::Weight()
{
  return weightCount;
}

void Belt::Clear()
{
  count = 0;
  weightCount = 0;
}

void Belt::ListBeltElements()
{
  if (Empty())
  {
    std::cout << "Cinto vazio!" << std::endl;
    return;
  }

  std::cout << "------ CINTO ------" << std::endl;
  for (int i = 1; i <= count; i++)
  {
    std::cout << "Elemento da posicao " << i << ':' << std::endl;
    BeltElements[i].PrintElement();
    std::cout << "-------------------" << std::endl;
  }
}

int Belt::GetElementPosition(bool replace)
{
  int entry = 0;

  while (entry < 1 || entry > count)
  {
    ListBeltElements();

    if (replace)
      std::cout << "Informe a posicao do elemento que deseja substituir: " << std::endl;
    else
      std::cout << "Informe a posicao do elemento que deseja utilizar: " << std::endl;

    std::cin >> entry;
  }

  return entry;
}

int Belt::GetInsertPosition()
{
  int entry = 0;

  while (entry < 1 || entry > (count + 1))
  {
    std::cout << "-------------------" << std::endl;
    std::cout << "Informe a posicao do cinto ao qual deseja adicionar o novo elemento. Posicoes disponiveis: " << std::endl;

    for (int i = 1; i <= (count + 1); i++)
      std::cout << "Digite " << i << " para escolher a posicao " << i << '.' << std::endl;

    std::cin >> entry;
  }

  return entry;
}

#endif