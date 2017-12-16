#pragma once

enum GameEvent
{
	NONE,
	EVENT_DEBUG,
	WINDOW_CLOSED,
	EVENT_CLICK_LEFT
};

struct EventMessage
{
	GameEvent EventType;
	void* EventData;
};
struct WindowEvent
{
	bool closeWindow;
};
struct LeftClickEvent
{
	int mouseX, mouseY;
};

struct KeyboardEvent
{
	char keyPressed;
	
};

enum CommandType
{
	Open,
	Close,
	Move_Unit,
	Cast
};
