/*
 *	
 *	Copyright (c) 2008 - Giancarlo Bellido
 *
 *	This file is part of qsLogo.
 *
 *  Foobar is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Foobar is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *  
 */

//#include <boost/spirit/core.hpp>
//#include <string>

#include <QResource>

#include "debug.hpp"
#include "interpreter.hpp"
#include "window.hpp"
#include "turtle.hpp"

namespace logo {

	const logo::window* win;

}

/*
 *	Here we just humbly parse the command line and wait. Then we check for errors which we hope
 *	are returned to us by an exception. Now, after this we should log somehow the command and 
 *	probably also clear the text box.
 */
void logo::window::onReturnPressed() {
	
	log->addItem(command->text());
	QString cmds = editor->toPlainText();
	cmds += "\n";
	cmds += command->text();

	this->interpreter->parse(cmds.constBegin(), cmds.constEnd());
	
	command->clear();
}

/*
 *	The Famous constructor will create the window and GUI. We are using pointers to create the 
 *	objects at runtime. I hope this works well. The objects are guaranteed to be destructed.
 */
logo::window::window(QWidget *parent) : QMainWindow(parent)
{
	// Set Instance
	logo::win = this;

	QResource::registerResource("resources.rcc");

	setWindowTitle("qsLogo 1.0");

	// Set Our Interpreter!
	interpreter = new logo::interpreter;

	// set tabs
	tabs = new QTabWidget(this);
	setCentralWidget(tabs);

	// set statusbars
	
	// Set Scene
	scene = new QGraphicsScene(this);

	// Set View	
	view = new QGraphicsView(scene);
	view->setRenderHint(QPainter::Antialiasing);
	tabs->addTab(view, "Screen");

	// Set Editor
	editor = new QTextEdit();
	editor->setCurrentFont(QFont("Courier New", 12));
	tabs->addTab(editor, "Editor");

	// Set Log
	log = new QListWidget();
	tabs->addTab(log, "Log");

#ifdef LOGO_DEBUG_ENABLE
	// Set Debug
	debug = new QListWidget();
	tabs->addTab(debug, "Debug");
#endif
	
	// Set the Dock Widgets
	dockCommand = new QDockWidget("Command", this);
	dockCommand->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

	command = new QLineEdit(dockCommand);
	dockCommand->setWidget(command);
	addDockWidget(Qt::BottomDockWidgetArea, dockCommand);

	// Set the main widget (focus it)
	command->setFocus();

	// Create Turtle!!
	//turtle = scene->addPixmap(QPixmap(":/resources/turtle.png"));

	//turtles = new logo::turtle(scene)[logo::MAX_TURTLES];
	//turtle  = turtles[0];
	turtle = new logo::turtle(scene);

	this->setWindowIcon(QIcon(":/resources/turtle.png"));
	this->resize(640, 480);

	statusBar()->showMessage("Ready.");

	resizeEvent(0);
	
	connect(command, SIGNAL(returnPressed()), this, SLOT(onReturnPressed()));

	LOGO_DEBUG("Window Initialized.");
}

/*
 * TODO delete all turtles not only 1
 */
logo::window::~window()
{
	delete turtle;
	delete interpreter;
}

/**
 *	Change the Graphics View Viewpoint
 */
void logo::window::resizeEvent(QResizeEvent * /*event*/)
{
	qreal w = scene->width();
	qreal h = scene->height();

	scene->setSceneRect(-w/2, -h/2, w, h);
}
