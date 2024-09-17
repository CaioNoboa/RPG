// Caio Salvador Noboa - 2201926

// std::cout << std::setiosflags(std::ios::left)
//      << std::setw(10) <<
//      << std::setw(30) << c.nome
//      << std::setw(10) << std::setprecision(2) << std::resetiosflags(std::ios::left)
//      << std::setiosflags(std::ios::fixed | std::ios::showpoint) << c.saldo << '\n';

#include "Classes.h"

#ifndef BELT_H
#define BELT_H

Belt::Belt()
{
    count = 0;
}

Belt::~Belt()

{
    Clear();
}

bool Belt::Full()
{
    return (count == MaxBelt);
}

bool Belt::Empty()
{
    return (count == 0);
}

void Belt::Insert(Element element)
{
    int position = GetElementPosition();

    if (Full())
    {
        std::cout << "Lista Cheia" << std::endl;
        return;
    }

    if ((position < 1) || (position > (count + 1)))
    {
        std::cout << "Posição inválida" << std::endl;
        return;
    }

    for (int i = count; i >= position; i--)
    {
        BeltElements[i + 1] = BeltElements[i];
    }

    BeltElements[position] = element;
    count++;
}

void Belt::Delete(Element &element)
{
    int position = GetElementPosition();

    if (Empty())
    {
        std::cout << "Lista Vazia" << std::endl;
        return;
    }

    if (position < 1 || position > count)
    {
        std::cout << "Posição inválida" << std::endl;
        return;
    }

    element = BeltElements[position];
    count--;

    for (int i = position; i < count; i++)
    {
        BeltElements[i] = BeltElements[i + 1];
    }
}

void Belt::Retrieve(Element &element)
{
    int position = GetElementPosition();

    if (position < 1 || position > count)
    {
        std::cout << "Posição inválida" << std::endl;
        return;
    }

    element = BeltElements[position];
}

void Belt::Replace(Element element)
{
    int position = GetElementPosition();

    if (position < 1 || position > count)
    {
        std::cout << "Posição inválida" << std::endl;
        return;
    }

    BeltElements[position] = element;
}

int Belt::Size()
{
    return count;
}

void Belt::Clear()
{
    count = 0;
}

void Belt::ListBeltElements()
{
    if (Empty())
    {
        std::cout << "Lista Vazia" << std::endl;
        return;
    }

    for (int i = 1; i <= count; i++)
    {
        std::cout << "Nome elemento da posicao " << i << ':' << std::endl;
        BeltElements[i].PrintElement();
    }
}

int Belt::GetElementPosition()
{
    int entry = 0;

    while (entry < 1 || entry > count)
    {
        ListBeltElements();
        std::cout << "Informe a posicao do elemento que deseja utilizar: " << std::endl;
        std::cin >> entry;
    }

    return entry;
}

#endif