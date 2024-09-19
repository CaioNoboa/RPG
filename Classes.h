// Caio Salvador Noboa - 2201926

#include <iostream>

// class Backpack;
// class Belt;
// class Character;
// class Element;
// class Enemy;
// class Game;

enum EnumDifficultyLevel
{
  LOW = 1,
  HIGH = 2
};

enum EnumElementType
{
  WEAPONS = 1,
  POTIONS = 2,
};

class Element
{
public:
  Element();
  Element(EnumElementType newElementType, std::string newName, int newWeight, int newPower);
  void GetElement(EnumDifficultyLevel difficultyLevel, Element &element);
  void PrintElement();
  EnumElementType elementType;
  std::string name;
  int weight;
  int power;

private:
  Element sortElement(EnumDifficultyLevel difficultyLevel);
};

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

class Character
{
public:
  Character();
  void SetName(std::string newName);
  void GetName(std::string &characterName);
  void GetNewElement(EnumDifficultyLevel difficultyLevel);
  void StoreElement(Element element);
  void UseElement(Element &element);

private:
  std::string name;
  int healthPoints;
  Belt belt;
  Backpack backpack;
};

class Enemy
{
public:
  Enemy(std::string newName, int newHealthPoints, int newPower);
  void GetEnemy(EnumDifficultyLevel difficultyLevel, Enemy &enemy, bool boss);

private:
  std::string name;
  int healthPoints;
  int power;
  Enemy SortEnemy(EnumDifficultyLevel difficultyLevel, bool boss);
};

class Game
{
  /*
    Níveis
    Mapa
    Elementos
    Heroi
  */

public:
  void Start();

private:
  Character character;
  EnumDifficultyLevel difficultyLevel;

  void SetDifficultyLevel();
  void SetCharacterName();
  void PlayInitialLevels();
  void PlayMiddleLevels();
  void PlayFinalLevels();
  void PlayBossLevel();
  void KillOrBeKilled();
  void MainCharacterTurn();
  void EnemyTurn();
  void EmptySQM();
};
