#pragma once
#include <iostream>
#include <string>
#include <map>
#include <Windows.h>
#include <fstream>
#include <sstream>
using namespace std;

namespace ErrorCodes
{
	enum ErrorCodes
	{
		UNKNOWN = 0,	//unknown error
		WINDOW_NO_CREATION, //window could not be created
		FILE_NOT_FOUND,			//could not load master file
		FILE_READ_ERROR,
		ARRAY_OUT_OF_BOUNDS
	};
}



enum ErrorServerity
{
	message = 1,	//will not be displayed if debug mode is disabled
	warning = 2,	//Will always be logged
	severe = 3,		//wILL create a dialog box without crashing
	fatal = 4		//Will crash the program
};

class Debug
{
public:
	static void Log(string Message)
	{
		//Write to file as well
		cout << Message << endl;
	}
	static void Initiate(string file)
	{
		getInstance().LoadErrors(file);
	}
	static void ThrowError(int index, string extraMessage = "")
	{
		getInstance().ThrowErrorInternal(index, extraMessage);
	}


private:
	bool loaded = false;
	static Debug& getInstance()
	{
		static Debug    instance; 
							  
		return instance;
	}

	class Error
	{
	public:
		int index;
		ErrorServerity Severity;
		string Message;
		string Caption;

		Error(int ind, int severity, string message, string caption);

		void ThrowError(bool debug, string extraMessage);
	};

	Debug() { loaded = false; }
	bool isDebug = true;
	void ThrowErrorInternal(int index, string extraMessage)
	{
		if (loaded)
		{
			//if error is not found, an unknown error has occured
			if (errors.count(index) == 0)
			{
				errors[ErrorCodes::UNKNOWN]->ThrowError(isDebug, "");
			}
			errors[index]->ThrowError(isDebug, extraMessage);
		}
	}
	map<int, Error*> errors;
	void LoadErrors(string errorFile);


	
};

	
