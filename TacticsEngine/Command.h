#pragma once

enum GameEvent
{
	NONE,
	EVENT_DEBUG,
	WINDOW_CLOSED,
	EVENT_CLICK_LEFT,
	EVENT_LOAD_STATE
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

struct LoadStateEvent
{
	int state;

};

enum CommandType
{
	Open,
	Close,
	Move_Unit,
	Cast
};
