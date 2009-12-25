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
		logo::win->turtle->home();
	}

	void circle(IterT, IterT)
	{
		logo::win->turtle->circle(stack.pop().toDouble());	
	}

	void arc(IterT, IterT)
	{
		double dg = stack.pop().toDouble();
		double r = stack.pop().toDouble();
		logo::win->turtle->arc(dg, r);
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

	void setxy(IterT, IterT)
	{
		logo::win->turtle->home();
		double y = stack.pop().toDouble();
		logo::win->turtle->moveBy(stack.pop().toDouble(), y);
	}

	void penwidth(IterT, IterT)
	{
		logo::win->turtle->Pen().setWidth(stack.pop().toInt());
	}

	void setcolor(IterT, IterT)
	{
		int b = stack.pop().toInt();
		int g = stack.pop().toInt();
		int r = stack.pop().toInt();

		logo::win->turtle->Pen().setColor(QColor(
			r > 255 ? 255 : r, g > 255 ? 255 : g, b > 255 ? 255 : b
		));
	}

} } // end logo::action
