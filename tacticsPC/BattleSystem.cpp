#include "BattleSystem.h"
#include <iostream>
#include <stack>
using	namespace std;




BattleSystem::BattleSystem(): BattleSystem(10, 10)
{
	ActiveUnit = nullptr;
}
BattleSystem::BattleSystem(int w, int h) : grid(w, h)
{
	LoadParty();
	LoadMap();
	loadEnemies();
	LoadDebug();

	ActiveUnit = nullptr;
}

void BattleSystem::LoadDebug()
{
	Unit * TestUnit = new Unit();
	TestUnit->id = "test1";
	units.push_back(TestUnit);
	TeleportUnit(TestUnit, 5, 5);
	

}

void BattleSystem::LoadParty()
{
}

void BattleSystem::LoadMap()
{
	//grid.printID();
}

void BattleSystem::loadEnemies()
{
}

void BattleSystem::DragUnit(Unit * unit, int x, int y)
{
	if (unit == nullptr)
	{
		unit = ActiveUnit;
	}
	if (unit == nullptr)
	{
		return;
	}
	int uX = unit->X + x;
	int uY = unit->Y + y;
	if (grid.Get(uX, uY) == nullptr)
	{
		cout << "Not a tile";
		return;
	}
	if (grid.Get(uX, uY)->unit != nullptr)
	{
		cout << "already occupied";
		return;
	}
	grid.Get(unit->X, unit->Y)->unit = nullptr;
	unit->X = uX;
	unit->Y = uY;
	grid.Get(uX, uY)->unit = unit;
	
}

void BattleSystem::MoveUnit(Unit * unit, int x, int y)
{
	//not yet implemented
}



struct coordinate
{
	int x, y;
	int MovementCostScore;
	int CombinedScore;
	int HeuristicScore;
	coordinate * parent = nullptr;
	void SetDistance(coordinate *Target)
	{
		//using manhattan distance
		int dX = abs(x - Target->x);
		int dY = abs(y - Target->y);
		HeuristicScore = dX + dY;
	}

	void SetGScore()
	{
		CombinedScore = MovementCostScore + HeuristicScore;
	}


	void print()
	{
		cout << "\n";
		cout << "<" << x << "," << y << ">" << endl;
	}
};

void FindNeighbors(coordinate * coord, vector<coordinate*>& open, vector<coordinate*>& closed, coordinate * goal, Grid grid);

coordinate* getLowest(vector<coordinate*> list)
{
	coordinate *c = list[0];
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->MovementCostScore < c->MovementCostScore)
		{
			c = list[i];
		}
	}
	return c;
}

int getIndex(vector<coordinate*> list, coordinate *coord)
{
	int index = -1;

	for (int i = 0; i < list.size(); i++)
	{
		//found match, we are done
		if (list[i]->x == coord->x && list[i]->y == coord->y)
		{
			return i;
		}
	}
	//no match
	return index;
}

stack<coordinate*>  Astar(coordinate *start, coordinate *end, Grid grid)
{
	vector<coordinate*> openList;
	vector<coordinate*> closedList;
	openList.push_back(start);
	start->MovementCostScore = 0;
	start->SetDistance(end);
	start->SetGScore();
	start->parent = nullptr;
	bool found = false;
	while (openList.size() != 0 && !found)
	{
		coordinate * currentCoordinate = getLowest(openList);
		currentCoordinate->SetDistance(end);
		//move current to closed list
		closedList.push_back(currentCoordinate);
		openList.erase(openList.begin() + getIndex(openList, currentCoordinate));
		
		if (currentCoordinate->HeuristicScore == 0)
		{
			stack<coordinate*> fin;
			fin.push(currentCoordinate);
			while (currentCoordinate != nullptr)
			{
				currentCoordinate = currentCoordinate->parent;
				fin.push(currentCoordinate);
				
			}
			return fin;
		}
		FindNeighbors(currentCoordinate, openList, closedList, end, grid);
		
	}
}

bool IsWalkable(coordinate *coord, Grid g)
{
	int x = coord->x;
	int y = coord->y;
	if (g.Get(x, y) == nullptr) //if coordinate is off the map, you cannot walk there
	{
		return false;
	}
	if (g.Get(x, y)->unit != nullptr || !g.Get(x, y)->walkable) // if the coordinate is not walkable or is already occupied, you cannot walk there
	{
		return false;
	}

	return true;
}

bool vectorContains(coordinate *coord, vector<coordinate*> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (coord->x == list[i]->x && coord->y == list[i]->y)
		{
			return true;	//match found
		}
	}
	return false;//no match
}

void AddNeighbor(coordinate * parent, coordinate *coord, vector< coordinate*>&open, vector<coordinate*> &closed, Grid grid)
{
	//if the tile is walkable and not on the closed list, make sure it is on the open list
	if (IsWalkable(coord, grid) && !vectorContains(coord, closed))
	{
		//if it is already on the open list, check to see if the gscore is lower with the current tile
		if (vectorContains(coord, open))
		{
			//original instance of coordinate
			coordinate * oldOpen = open[getIndex(open, coord)];

			//lower gscore means it is quicker, and so replaces the current version
			if (oldOpen->CombinedScore > coord->CombinedScore)
			{
				cout << "replacing"; coord->print();
				coord->parent = parent;
				open[getIndex(open, coord)] = coord;

			}


		}
		//if it is not on the list add it
		else
		{
			coord->parent = parent;
			open.push_back(coord);
		}
		
	}
}

void FindNeighbors(coordinate *coord, vector<coordinate*> &open, vector<coordinate*>&closed, coordinate * goal, Grid grid)
{
	//get coordinates we are working with
	coordinate * North = new coordinate();
	North->x = coord->x;
	North->y = coord->y - 1;
	North->MovementCostScore = coord->MovementCostScore + 10;
	North->SetDistance(goal);
	North->SetGScore();

	coordinate * South = new coordinate();
	South->x = coord->x;
	South->y = coord->y + 1;
	South->MovementCostScore = coord->MovementCostScore + 10;
	South->SetDistance(goal);
	South->SetGScore();

	coordinate * East = new coordinate();
	East->x = coord->x + 1;
	East->y = coord->y;
	East->MovementCostScore = coord->MovementCostScore + 10;
	East->SetDistance(goal);
	East->SetGScore();

	coordinate * West = new coordinate();
	West->x = coord->x - 1;
	West->y = coord->y;
	West->MovementCostScore = coord->MovementCostScore + 10;
	West->SetDistance(goal);
	West->SetGScore();

	//North
	AddNeighbor(coord, North, open, closed, grid);
	AddNeighbor(coord, South, open, closed, grid);
	AddNeighbor(coord, East, open, closed, grid);
	AddNeighbor(coord, West, open, closed, grid);
	

}
//uses a* path finding
void BattleSystem::MoveUnitNoAnimation(Unit * unit, int x, int y)
{
	//easier to reference
	int startX = unit->X;
	int startY = unit->Y;
	coordinate * s = new coordinate();
	s->x = startX;
	s->y = startY;

	//destination
	coordinate * d = new coordinate();
	d->x = x;
	d->y = y;

	stack<coordinate*> v = Astar(s, d, grid);
	while (!v.empty())
	{
		if (v.top() != nullptr)
		{
			v.top()->print();
			
		}v.pop();
	}

}

void BattleSystem::TeleportUnit(Unit * unit, int x, int y)
{
	if (unit == nullptr)
	{
		unit = ActiveUnit;
	}
	if (unit == nullptr)
	{
		return;
	}
	if (grid.Get(x, y) == nullptr)
	{
		cout << "Not a tile";
		return;
	}
	if (grid.Get(x, y)->unit != nullptr)
	{
		cout << "already occupied";
		return;
	}

	grid.Get(unit->X, unit->Y)->unit = nullptr;
	unit->X = x;
	unit->Y = y;
	grid.Get(x, y)->unit = unit;
}

void BattleSystem::SelectNextUnit(int threshhold)
{

	if (units.size() == 0)
	{
		return;
	}
	//increases each units turn counter until threshhold is crossed.
	bool end = false;
	while (!end)
	{	
		for each (Unit* unit in units)
		{
			unit->TurnCounter++;

			if (unit->TurnCounter > threshhold)
			{

				bool success = unit->Activate();
				if (!success) //if for whatever reason the unit did not activate(such as if it was dead)
				{
					unit->TurnCounter = 0;
				}
				else
				{
					if (ActiveUnit != nullptr)
					{
						ActiveUnit->unitState = UnitState::Idle;
					}
					ActiveUnit = unit;	//unit is ready to take its turn.
					end = true;
					break;
				}
			}
		}
	}
}

void BattleSystem::CastSpell(Unit * caster, int spellid, int x, int y)
{
}

void BattleSystem::Update()
{
	if (ActiveUnit == nullptr || ActiveUnit->unitState == UnitState::Idle)
	{
		SelectNextUnit();
	}
	Draw();
}

void BattleSystem::Draw()
{
	DrawPrint();
}

//print map to console with units
void BattleSystem::DrawPrint()
{
	for (int i = 0; i < grid.getWidth(); i++)
	{
		for (int j = 0; j < grid.getHeight(); j++)
		{
			if (grid.Get(i, j)->unit == nullptr)
			{
				cout << grid.Get(i, j)->z << " ";
			}
			else
			{
				cout << "X" << " ";
			}
		}
		cout << "\n";
	}
}
