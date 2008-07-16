/*
 *	Coaxial Software
 *	Copyright (c) 2007 - Giancarlo Bellido
 *
 *	Logo Interpreter.
 *  Just Because I am bored.
 */

//#include "interpreter.hpp"
#include <QtGui/QApplication>

#include "main.hpp"
#include "window.hpp"
#include "interpreter.hpp"

int main(int argc, char* args[] )
{
	QApplication application(argc, args);

	logo::window win;
	logo::win = &win;

	win.show();	
	
	return application.exec();
}