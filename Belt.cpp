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
        std::cout << "O cinto está cheio e não possui espaço para o novo elemento!" << std::endl;
        std::cout << "Digite 1 para verificar seu cinto e substituir um item pelo novo eleemnto;" << std::endl;
        std::cout << "Digite 2 para retornar." << std::endl;
        std::cin >> entry;

        switch (entry)
        {
        case 1:
            return Replace(element);
            break;
        default:
            return false;
            break;
        }
    }

    int position = GetElementPosition(false);

    if ((position < 1) || (position > (count + 1)))
    {
        std::cout << "Posição inválida" << std::endl;
        return false;
    }

    for (int i = count; i >= position; i--)
    {
        BeltElements[i + 1] = BeltElements[i];
    }

    BeltElements[position] = element;
    weightCount += element.weight;
    count++;
    return true;
}

void Belt::Delete(Element &element)
{
    int position = GetElementPosition(false);

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
    weightCount -= element.weight;
    count--;

    for (int i = position; i < count; i++)
    {
        BeltElements[i] = BeltElements[i + 1];
    }
}

// void Belt::Retrieve(Element &element)
// {
//     int position = GetElementPosition();

//     if (position < 1 || position > count)
//     {
//         std::cout << "Posição inválida" << std::endl;
//         return;
//     }

//     element = BeltElements[position];
// }

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

void Belt::Clear()
{
    count = 0;
    weightCount = 0;
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

#endif