// Caio Salvador Noboa - 2201926

#include "Element.h"

class Backpack
{
public:
  Backpack();
  ~Backpack();
  bool Empty();
  void Push(Element element);
  void Pop(Element &element);
  int Size();
  void Clear();
  void Top(Element &element);

private:
  struct BackpackNode
  {
    Element Element;
    BackpackNode *NextNode; // ponteiro para próximo nó
  };
  typedef BackpackNode BackpackNode;

  BackpackNode *top; // ponteiro para o topo da pilha
  int count;
};