#include "FileLoader.h"
#include "Debug.h"
FileLoader::FileLoader(string file)
{
	Load(file);
}

FileLoader::~FileLoader()
{
}

//loads the file and parsees it into sections
void FileLoader::Load(string filename)
{
	string str;
	file.open(filename);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			if (line[0] == '/')
			{
				continue;
			}
			else if (line.empty())
			{
				continue;
			}
			else
			{
				
			}
		}
	}
	
}
