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
#include "turtle.hpp"

namespace logo
{
	namespace action
	{
		
		void xcor(IterT, IterT)
		{
			stack.push(logo::win->turtle->x());
		}

		/*
		 *
		 */
		void ycor(IterT, IterT)
		{
			stack.push(logo::win->turtle->y());
		}

		void forward(IterT, IterT)
		{	
			if (!stack.isEmpty())
			{
				logo::win->turtle->forward(stack.pop());
			}
		}

		void back(IterT, IterT)
		{
			if (!stack.isEmpty())
			{
				logo::win->turtle->backward(stack.pop());
			}
		}

		void right(IterT, IterT)
		{
			if (!stack.isEmpty())
			{
				logo::win->turtle->rotate(stack.pop());
			}
		}

		void left(IterT, IterT)
		{
			if (!stack.isEmpty())
			{
				logo::win->turtle->rotate(- stack.pop());
			}
		}
	}
}
