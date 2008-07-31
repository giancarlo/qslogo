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

		void forward(IterT, IterT)
		{	
			if (!stack.isEmpty())
			{
				logo::win->turtle->translate(0, - stack.last());
				stack.pop_back();
			}
		}

		void back(IterT, IterT)
		{
			if (!stack.isEmpty())
			{
				logo::win->turtle->translate(0, stack.last());
				stack.pop_back();
			}
		}

		void right(IterT, IterT)
		{
			if (!stack.isEmpty())
			{
				// middle x and y to rotate around
				/*int mx = logo::win->turtle->width() / 2;
				int my = logo::win->turtle->height()/ 2;

			  logo::win->turtle->setTransform(QTransform()
					.translate(mx, my)
					.rotate(stack.last())
					.translate(-mx, -my)
				);*/
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
