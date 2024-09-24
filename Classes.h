// Caio Salvador Noboa - 2201926

#include <iostream>

const int MaxBeltItems = 5;
const int MaxBeltWeight = 100;
const int MaxHealthPoints = 100;

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
  std::string GetElementName();
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
  bool Push(Element element);
  void Pop(Element &element);
  int Size();
  void Clear();
  void Top(Element &element, bool print);

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

class Belt
{
public:
  Belt();
  ~Belt();
  bool Full(Element element);
  bool Empty();
  bool Insert(Element element);
  void Delete(Element &element);
  bool Replace(Element element);
  int Size();
  int Weight();
  void Clear();
  void ListBeltElements();
  int GetElementPosition(bool replace);
  int GetInsertPosition();

private:
  int count;
  int weightCount;
  Element BeltElements[MaxBeltItems + 1];
};

class Enemy
{
public:
  Enemy();
  Enemy(std::string newName, int newHealthPoints, int newPower);
  void GetEnemy(EnumDifficultyLevel difficultyLevel, Enemy &enemy, bool boss);
  bool IsEnemyAlive();
  void PrintEnemyInformations();
  void EnemyGotAttacked(Element element);
  int GetEnemyPower();

private:
  std::string name;
  int healthPoints;
  int power;
  Enemy SortEnemy(EnumDifficultyLevel difficultyLevel, bool boss);
};

class Character
{
public:
  Character();
  void SetName(std::string newName);
  void GetName(std::string &characterName);
  void GetNewElement(EnumDifficultyLevel difficultyLevel);
  void StoreElement(Element element);
  bool UseElement(Element &element);
  bool IsOurHeroAlive();
  void PrintHeroInformations();
  void OurHeroGotAttacked(Enemy enemy);
  void PrintBasicInformations();

private:
  std::string name;
  int healthPoints;
  Belt belt;
  Backpack backpack;
};

class Game
{
public:
  Game();
  void Start();

private:
  std::string playerName;
  Character character;
  EnumDifficultyLevel difficultyLevel;
  int levelCounter;
  int totalLevels;
  int numberOfInitialLevels;
  int numberOfMiddleLevels;
  int numberOfFinalLevels;
  void SetDifficultyLevel();
  void SetNames();
  void PlayInitialLevel();
  void PlayMiddleLevel();
  void PlayFinalLevel();
  void PlayBossLevel();
  void KillOrBeKilled(bool boss);
  void MainCharacterTurn(Enemy &enemy);
  void EnemyTurn(Enemy enemy);
  void EmptySQM();
  void RegisterScore();
  void PauseAndCleanConsole();
};
