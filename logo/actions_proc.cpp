/*
 *	
 *	Copyright (c) 2008 - Giancarlo Bellido
 *
 *	This file is part of qsLogo.
 *
 *  qsLogo is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  qsLogo is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with qsLogo.  If not, see <http://www.gnu.org/licenses/>.
 *  
 */

#include "main.hpp"
#include "actions.hpp"
#include "window.hpp"

namespace logo {

	namespace action {

		void to(IterT, IterT)
		{
			

		}

		void repeat(IterT, IterT)
		{

		}

		void call(IterT first, IterT last)
		{
			QString x = QString::fromAscii(first, last-first);
			x.prepend("I don't know how to ");

			win->statusBar()->showMessage(x);
		}

	}
}

