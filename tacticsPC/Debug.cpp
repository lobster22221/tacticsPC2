#include "Debug.h";


Debug::Error::Error(int ind, int severity, string message, string caption) :index(ind), Message(message), Caption(caption)
{
	Severity = (ErrorServerity)severity;
}

void Debug::Error::Error::ThrowError(bool debug, string extraMessage)
{
	switch (Severity)
	{
	case message:
		if (debug)
		{
			Log(Caption + ": " + Message);
			if (extraMessage != "")
			{
				Log("Information:" + extraMessage);
			}
		}
		break;
	case warning:
		if (extraMessage != "")
		{
			Log(Caption + " " + Message);
		}
		Log("Error Details:" + extraMessage);
		break;
	case severe:
		if (extraMessage != "")
		{
			Message += "\nDetails: \n" + extraMessage;
		}

		MessageBoxA(NULL, Message.c_str(), Caption.c_str(), MB_ICONEXCLAMATION);
		Log("Error Details:" + extraMessage);
		break;
	case  fatal:
		if (extraMessage != "")
		{
			Message += "\nDetails: \n" + extraMessage;
		}
		MessageBoxA(NULL, Message.c_str(), Caption.c_str(), MB_ICONEXCLAMATION);
		Log("Error Details:" + extraMessage);
		exit(index);
		break;
	default:
		break;
	}

}


void  Debug::LoadErrors(string errorFile)
{
	//load default error
	Error * defaultError = new Error(0, fatal, "An undefined error has occured and the program will shutdown", "Unknown Error");
	errors[0] = defaultError;
	std::ifstream fileStream;
	fileStream.open(errorFile);
	string delimiter = "|";
	if (fileStream.is_open())
	{
		string line;
		while (getline(fileStream, line))
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
				//error parameters
				//Formatting:
				//index | caption | Message | 0 = warning 1 = error

				string caption;
				string message;
				int severity;

				//Get first token, the error index
				string str_index = line.substr(0, line.find(delimiter));
				//remove it from the line
				line = line.substr(str_index.length() + delimiter.length());
				//assign it
				int errorIndex = std::stoi(str_index);

				//assign caption
				caption = line.substr(0, line.find(delimiter));
				//remove it from the line
				line = line.substr(caption.length() + delimiter.length());

				//assign message
				message = line.substr(0, line.find(delimiter));
				//remove it from the line
				line = line.substr(message.length() + delimiter.length());

				//Get last token, the severity level
				string str_severity = line.substr(0, line.find(delimiter));
				//remove it from the line

				//assign it
				severity = std::stoi(str_severity);

				Error * newError = new Error(errorIndex, severity, message, caption);

				errors[errorIndex] = newError;
				loaded = true;
			}
		}
	}
	else
	{
		Log("Unable to load errors, ironic, right?");
	}
}


