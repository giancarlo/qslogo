/*
 *	Coaxial Software
 *	Copyright (c) 2007 - Giancarlo Bellido
 *
 *	actions_turtles.cpp
 *  
 */

#include "main.hpp"
#include "actions.hpp"

namespace logo
{
	namespace action
	{

		/// Square
		void sqr(IterT, IterT)
		{
			qreal n = stack.pop().toDouble();
			stack.push_back(n * n);
		}

		void sum(IterT, IterT)
		{
			stack.push(stack.pop().toDouble() + stack.pop().toDouble());
		}

		void dif(IterT, IterT)
		{
			stack.push(stack.pop().toDouble() - stack.pop().toDouble());
		}

		void product(IterT, IterT)
		{
			stack.push(stack.pop().toDouble() * stack.pop().toDouble());
		}

		void divide(IterT, IterT)
		{
			stack.push(stack.pop().toDouble() / stack.pop().toDouble());
		}

		void negate(IterT, IterT)
		{
			stack.push(- stack.pop().toDouble());
		}
	}
}

