#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>	
using namespace std;

//A file is composed of Sections which are divided into tokens and subsections
//A section is marked by {key}<entry>
//A token is marked by [key](Value)
/*Units
**	{Unit1}
**	<
**		[Name](Bob)
**		[Level](1)
**		[Health](100)
**		[Mana](100)
**		[Equipment]
**		<
**			[Weapon](ItemID)
**			[Armor](ItemID)
**			[Slot1](ItemID)
**			[Slot2](ItemID)
**			[Slot3](ItemID)
**			[Slot4](ItemID)
**		>
**		[Jobs]
**		<
**			[Warrior](1)
**			[Mage](2)
**		>
**		Spells
**		<
**			[Spell](Fire)
**			[Spell](Ice)
**		>
**	>
*/


class Token
{
	vector<string> lineTokens;
};


class Section
{
	//Section name
	string name;
	//Other Sections
	map<string, Section*> subsections;
	map<string, string> tokens;
};
class FileLoader
{
public:
	FileLoader(string File);
	~FileLoader();

	void Load(string file);

	

	//conversion functions
	static bool TokenToInt(string s, int & value)
	{
		bool success = true;

		//if something goes wrong, it does not mess up value
		int tmp = -1;
		try
		{

			tmp = std::stoi(s);
			
		}
		catch (const std::exception&)
		{
			//s was not a integer
			success = false;
		}
		if (success)
		{
			value = tmp;
		}

		return success;
	}
	static bool TokenToDouble(string s, double & value)
	{
		bool success = true;
		//if something goes wrong, it does not mess up value
		double tmp = -1;
		try
		{
			tmp = std::stod(s);
		}
		catch (const std::exception&)
		{
			//s was not a integer
			success = false;
		}
		if (success)
		{
			value = tmp;
		}

		return success;
	}

private:
	ifstream file;
};

