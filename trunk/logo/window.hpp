/*
 * Coaxial Software
 * Copyright (c) 2007 - Giancarlo Bellido
 *
 */

#ifndef LOGO_WINDOW_HPP
#define LOGO_WINDOW_HPP

#include <QtGui/QApplication>
#include <QtGui/QMainWindow>

/*
 *	OK. Lets create the QGraphicScene to Show the movement of the turtle.
 */
#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsView>
#include <QtGui/QDockWidget>
#include <QtGui/QLineEdit>
#include <QtGui/QTextEdit>
#include <QtGui/QListWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QGraphicsPixmapItem>

namespace logo
{

	class window : public QMainWindow
	{
		Q_OBJECT

	protected:

		void resizeEvent ( QResizeEvent * event );

	public slots:
		void onReturnPressed();

	public:
		/**
		 * Constructor
		 */
		window(QWidget *parent=0);

		/*
		 *	Objects
		 */
		QTabWidget		*tabs;
		QTextEdit		*editor;
		QListWidget		*log;
		
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

		QGraphicsPixmapItem*	turtle;



	};

	// win defined in window.cpp
	extern const logo::window* win;
};


#endif