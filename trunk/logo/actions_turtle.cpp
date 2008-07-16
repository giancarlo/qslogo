/*
 *	Coaxial Software
 *	Copyright (c) 2007 - Giancarlo Bellido
 *
 *	actions_turtles.cpp
 *  
 */

#include "main.hpp"
#include "debug.hpp"
#include "actions.hpp"
#include "window.hpp"

namespace logo
{
	namespace action
	{
		
		void xcor(IterT, IterT)
		{
			stack.push_back(logo::win->turtle->x());
		}

		/*
		 *
		 */
		void ycor(IterT, IterT)
		{
			stack.push_back(logo::win->turtle->y());
		}

		/*
		 *	She is an angel for sure. She just cant stop telling lies.
		 */
		void forward(IterT, IterT)
		{	
			// If the stack is empty then there is the possibility that there is some fucked up error.
			if (!stack.isEmpty())
			{
				logo::win->turtle->moveBy(0, stack.last());
				stack.pop_back();
			}
		}

		void back(IterT, IterT)
		{
			if (!stack.isEmpty())
			{
				logo::win->turtle->moveBy(0, - stack.last());
				stack.pop_back();
			}
		}

		void right(IterT, IterT)
		{
			if (!stack.isEmpty())
			{
				logo::win->turtle->rotate(stack.last());
				stack.pop_back();
			}
		}

		void left(IterT, IterT)
		{
			if (!stack.isEmpty())
			{
				logo::win->turtle->rotate(- stack.last());
				stack.pop_back();
			}
		}
	}
}
