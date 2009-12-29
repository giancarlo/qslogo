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

#ifndef LOGO_WINDOW_HPP
#define LOGO_WINDOW_HPP

#include <QtGui/QApplication>
#include <QtGui/QMainWindow>
#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsView>
#include <QtGui/QDockWidget>
#include <QtGui/QLineEdit>
#include <QtGui/QTextEdit>
#include <QtGui/QListWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QGraphicsPixmapItem>
#include <QSyntaxHighlighter>

#include "interpreter.hpp"

namespace logo
{

	static const int MAX_TURTLES = 4;

	class turtle;

	class window : public QMainWindow
	{
		Q_OBJECT

	protected:

		void resizeEvent ( QResizeEvent * event );
		void onLogDoubleClick(const QModelIndex& index);

	public slots:
		void onReturnPressed();

	public:
		/**
		 * Constructor
		 */
		window(QWidget *parent=0);
		~window();

		/*
		 *	Objects
		 */
		QTabWidget		*tabs;
		QTextEdit		*editor;
		QListWidget		*log;
		QSyntaxHighlighter      *syntax;

#ifdef LOGO_DEBUG_ENABLE
		QListWidget		*debug;
#endif
		/*
		 *	Graphic Objects
		 */
		QGraphicsScene	*scene;
		QGraphicsView	*view;

		/*
		 *	Command DockWidget
		 */
		QDockWidget		*dockCommand;
		QLineEdit		*command;

		/*
		 * Turtles!
		 */
		logo::turtle* turtles;
		logo::turtle* turtle;
		//QGraphicsPixmapItem*	turtle;

		/*
		 * Interpreter
		 */
		logo::interpreter* interpreter;

};

	// win defined in window.cpp
	extern logo::window* win;
};


#endif
