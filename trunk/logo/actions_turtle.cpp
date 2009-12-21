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

namespace logo { namespace action {
		
	void xcor(IterT, IterT) { stack.push(logo::win->turtle->x()); }

	void ycor(IterT, IterT)
	{
		stack.push(logo::win->turtle->y());
	}

	void forward(IterT, IterT)
	{	
		if (!stack.isEmpty())
		{
			logo::win->turtle->forward(stack.pop().toDouble() );
		}
	}

	void back(IterT, IterT)
	{
		if (!stack.isEmpty())
		{
			logo::win->turtle->backward(stack.pop().toDouble() );
		}
	}

	void right(IterT, IterT)
	{
		if (!stack.isEmpty())
		{
			logo::win->turtle->rotate(stack.pop().toDouble() );
		}
	}

	void left(IterT, IterT)
	{
		if (!stack.isEmpty())
		{
			logo::win->turtle->rotate(- stack.pop().toDouble());
		}
	}

	void penup(IterT, IterT)
	{
		logo::win->turtle->setpen(logo::up);		
	}

	void pendown(IterT, IterT)
	{
		logo::win->turtle->setpen(logo::down);
	}

	void home(IterT, IterT)
	{
		logo::win->turtle->reset();
	}

	void circle(IterT, IterT)
	{
		logo::win->turtle->circle(stack.pop().toDouble());	
	}

	void setx(IterT, IterT)
	{
		logo::win->turtle->reset();
		logo::win->turtle->moveBy(stack.pop().toDouble(), 0);
	}

	void sety(IterT, IterT)
	{
		logo::win->turtle->reset();
		logo::win->turtle->moveBy(0, stack.pop().toDouble());
	}


} } // end logo::action
