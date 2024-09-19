// Caio Salvador Noboa - 2201926

/*
  g++ driver.cpp Backpack.cpp Belt.cpp Character.cpp Element.cpp Game.cpp Belt.cpp Enemy.cpp -o teste.exe
*/

#include "Classes.h"
#include <iomanip>

int main()
{
  Game game;
  game.Start();

  // std::cout << std::setiosflags(std::ios::left)
  //           << std::setw(15) << "element.name"
  //           << std::setw(15) << 10
  //           << std::setw(15) << std::setprecision(2) << std::resetiosflags(std::ios::left)
  //           << std::setiosflags(std::ios::fixed | std::ios::showpoint) << 5 << '\n';

  return 0;
}
