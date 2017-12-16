#pragma once
#include <vector>
#include "Debug.h"
using namespace std;
//Works similarly to a linked list and a stack.
//Can always perform stack functions
//Can also iterate through nodes below the top of the stack like a linked list, but cannot pop them.
template <class T>
class TraversableStack
{
	template <class T>
	class Node
	{
	public:
		Node(const T &v) :Value(v) {}
		
		T Value;
	};

public:

	//stack functions
	void Push(const T& value)
	{
		ResetPosition();
		Node<T> * node = new Node<T>(value);
		

		stack.push_back(node);
		ResetPosition();
	}	//Adds a node containing T to the top of the stack
	void Pop()
	{
		if (!Empty())
		{
			stack.erase(stack.end() - 1);
		}
	}			//Removes the top node
	const T& Top()
	{
		if (!Empty())
		{
			return stack[stack.size() - 1]->Value;
			
		}
	}			//returns the T inside the node at the top of the stack
	bool Empty()
	{
		return (stack.size() == 0);
	}		//checks if the size of the stack is 0
	void Clear()
	{
		stack.clear();
	}	//Empty the stack
	
	void Force(const T& value)
	{
		Clear();
		Push(value);
	}	//clear the stack and add the new value

	//Traversable Functions

	//Sets the position counter to the top node
	void ResetPosition()
	{
		if (!Empty())
		{
			position = stack.size() - 1;
		}
	}
	//Sets the position counter to the bottom node
	void SetToBottom()
	{

		if (!Empty())
		{
			position = 0;
		}
	}
	//Decrements the counter
	void Descend()
	{
		try
		{
			if (position > 0)
			{
				position--;
			}
			else
			{
				throw;
			}
		}
		catch (exception e)
		{
			Debug::ThrowError(ErrorCodes::ARRAY_OUT_OF_BOUNDS, "Position: " + position);
		}
	}			
	//Increases the position
	void Ascend()
	{
		try
		{
			if (position < this->stack.size()-1)
			{
				position++;
			}
			else
			{
				throw;
			}
		}
		catch (exception e)
		{
			Debug::ThrowError(ErrorCodes::ARRAY_OUT_OF_BOUNDS, "Position: " + position);
		}
	}
	const T& GetCurrent()
	{
		if (stack.size() > position)
		{
			return stack[position]->Value;
		}
	}

	//determines if it is possible to Descend
	bool isAtBottom()
	{
		return(position == 0);
	}
	bool isAtTop()
	{
		return(position == stack.size()-1);
	}

	//other
	
	
private:

	vector<Node<T>*> stack;
	//When not looking at the 
	int position;
};

