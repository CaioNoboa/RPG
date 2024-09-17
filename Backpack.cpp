// Caio Salvador Noboa - 2201926

#include <iostream>
#include <iomanip>
#include "Backpack.h"

#ifndef BACKPACK_H
#define BACKPACK_H

Backpack::Backpack()
{
  top = NULL;
};

bool Backpack::Empty()
{
  return top == NULL;
}

void Backpack::Push(Element element)
{
  BackpackNode *pointer = new BackpackNode;

  if (pointer == NULL)
  {
    std::cout << "Sem capacidade de armazenamento!" << std::endl;
    abort();
  }

  pointer->Element = element;
  pointer->NextNode = top;
  top = pointer;
  count++;
}

void Backpack::Pop(Element &element)
{
  if (Empty())
  {
    std::cout << "Pilha ja esta vazia!" << std::endl;
    abort();
  }

  element = top->Element;
  BackpackNode *pointer = top;
  top = top->NextNode;
  delete pointer;
  count--;
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

void Backpack::Top(Element &element)
{
  element = top->Element;

  // std::cout << std::setiosflags(std::ios::left)
  //           << std::setw(10) << element.name
  //           << std::setw(30) << element.power
  //           << std::setw(10) << std::setprecision(2) << std::resetiosflags(std::ios::left)
  //           << std::setiosflags(std::ios::fixed | std::ios::showpoint) << element.weight << '\n';
}

Backpack::~Backpack()
{
  Clear();
}

#endif