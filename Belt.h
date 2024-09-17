// Caio Salvador Noboa - 2201926

#include "Element.h"

const int MaxBelt = 5;

class Belt
{
public:
  Belt();
  ~Belt();
  bool Full();
  bool Empty();
  void Insert(Element element);
  void Delete(Element &element);
  void Retrieve(Element &element);
  void Replace(Element element);
  int Size();
  void Clear();
  void ListBeltElements();
  int GetElementPosition();

private:
  int count;
  Element BeltElements[MaxBelt + 1];
};