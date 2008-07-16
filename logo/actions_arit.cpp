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
			qreal n = stack.last();
			stack.pop_back();
			stack.push_back(n * n);
		}
	}
}

