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
			double y = stack.pop().toDouble();
			double x = stack.pop().toDouble();
			stack.push(x - y);
		}

		void product(IterT, IterT)
		{
			stack.push(stack.pop().toDouble() * stack.pop().toDouble());
		}

		void divide(IterT, IterT)
		{
			double y = stack.pop().toDouble();
			double x = stack.pop().toDouble();
			stack.push(x / y);
		}

		void negate(IterT, IterT)
		{
			stack.push(- stack.pop().toDouble());
		}

		void mod(IterT, IterT)
		{
			int y = stack.pop().toDouble();
			int x = stack.pop().toDouble();
			stack.push(x % y);
		}

		void gt(IterT, IterT)
		{
			stack.push(stack.pop().toDouble() < stack.pop().toDouble());
		}

		void lt(IterT, IterT)
		{
			stack.push(stack.pop().toDouble() > stack.pop().toDouble());
		}

		void gte(IterT, IterT)
		{
			stack.push(stack.pop().toDouble() <= stack.pop().toDouble());
		}

		void lte(IterT, IterT)
		{
			stack.push(stack.pop().toDouble() >= stack.pop().toDouble());
		}

		void eq(IterT, IterT)
		{
			stack.push(stack.pop().toDouble() == stack.pop().toDouble());
		}

	}
}

