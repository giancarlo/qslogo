/*
 *	Coaxial Software
 *	Copyright (c) 2007 - Giancarlo Bellido
 *
 *	actions_turtles.cpp
 *	TODO This file should be called actions_math.cpp
 *  
 */

#include "main.hpp"
#include "actions.hpp"
#include <cmath>

#define PI 3.14159265

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

		void sqrt(IterT, IterT)
		{
			stack.push(::sqrt(stack.pop().toDouble()));
		}

		void cos(IterT, IterT)
		{
			stack.push(::cos(stack.pop().toDouble() * PI / 180.0));			
		}

		void sin(IterT, IterT)
		{
			stack.push(::sin(stack.pop().toDouble() * PI / 180.0));
		}

		void mod(IterT, IterT)
		{
			int y = stack.pop().toDouble();
			int x = stack.pop().toDouble();
			stack.push(x % y);
		}

		void random(IterT, IterT)
		{
			stack.push(rand() % stack.pop().toInt());
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

