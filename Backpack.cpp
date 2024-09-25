// Caio Salvador Noboa - 2201926

#include <iostream>
#include <iomanip>
#include "Classes.h"

#ifndef BACKPACK_H
#define BACKPACK_H

Backpack::Backpack()
{
  top = NULL;
};

Backpack::~Backpack()
{
  Clear();
}

bool Backpack::Empty()
{
  return top == NULL;
}

bool Backpack::Push(Element element)
{
  BackpackNode *pointer = new BackpackNode;

  if (pointer == NULL)
  {
    std::cout << "Sem capacidade de armazenamento!" << std::endl;
    return false;
  }

  pointer->Element = element;
  pointer->NextNode = top;
  top = pointer;
  count++;
  return true;
}

bool Backpack::Pop(Element &element)
{
  bool userChoseBackpackElement = false;
  int entry;

  while (!userChoseBackpackElement)
  {
    if (Empty())
    {
      std::cout << "Mochila vazia!" << std::endl;
      return false;
    }

    element = top->Element;
    BackpackNode *pointer = top;
    top = top->NextNode;
    delete pointer;
    count--;

    std::cout << "-------------------" << std::endl;
    std::cout << "Elemento do topo da mochila:" << std::endl;
    element.PrintElement();
    std::cout << "-------------------" << std::endl;
    std::cout << "Digite 1 para usa-lo;" << std::endl;
    std::cout << "Digite 2 para descarta-lo e buscar novo elemento na mochila." << std::endl;
    std::cin >> entry;

    if (entry == 1)
      userChoseBackpackElement = true;
  }

  return true;
}

int Backpack::Size()
{
  return count;
}

void Backpack::Clear()
{
  Element element;
  while (!Empty())
  {
    Pop(element);
  }
}

void Backpack::Top(Element &element, bool print)
{
  if (Empty())
  {
    std::cout << "Mochila vazia!" << std::endl;
    return;
  }

  element = top->Element;

  if (print)
  {
    std::cout << "----- MOCHILA -----" << std::endl;
    std::cout << "Elemento topo: " << std::endl;
    element.PrintElement();
    std::cout << "-------------------" << std::endl;
  }
}

#endif