/*
 *	Coaxial Software
 *	Copyright (c) 2007 - Giancarlo Bellido
 *
 *	actions_io.cpp
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

		void string(IterT a, IterT b)
		{
			stack.push_back(QString::fromUtf8(a, b-a));
		}

		void number(float a)
		{
			stack.push_back(a);
		}

		void print(IterT, IterT)
		{
			// If there is an element in the number stack print that.
			// TODO Fix this
			/*if ( stack.isEmpty() )
			{
				// Print all the strings in strings stack. Make sure the turtle moves when printing.
				for (int i = 0; i < strings.size(); i++)
				{
					QGraphicsTextItem* text = logo::win->scene->addText( strings.last() );
					strings.pop_back();

					logo::win->turtle->moveBy(text->boundingRect().width(), text->boundingRect().height());
				}
			} else
			{*/
			QGraphicsTextItem* text = logo::win->scene->addText( stack.last().toString() );
			text->setPos(logo::win->turtle->pos());
			logo::win->turtle->moveBy(text->textWidth(), 0);
			
		}

		void clear_screen(IterT, IterT)
		{
			const QList<QGraphicsItem*> &list = logo::win->scene->items();
			
			for (QList<QGraphicsItem*>::const_iterator i = list.begin(); i != list.end(); i++) 
			{
				if (*i != static_cast<QGraphicsItem*>(logo::win->turtle->item()))
				{
					logo::win->scene->removeItem(*i);
					delete *i;
				}
			}

			logo::win->turtle->reset();
		}

		void exit(IterT, IterT)
		{
			qApp->quit();
		}
	}
}
