/*
 *	Coaxial Software
 *	Copyright (c) 2007 - Giancarlo Bellido
 *
 */

//#include <boost/spirit/core.hpp>
//#include <string>

#include <QTCore/QResource>

#include "debug.hpp"
#include "window.hpp"
#include "interpreter.hpp"

namespace logo {

	const logo::window* win;

}

/*
 *	Here we just humbly parse the command line and wait. Then we check for errors which we hope
 *	are returned to us by an exception. Now, after this we should log somehow the command and 
 *	probably also clear the text box.
 */
void logo::window::onReturnPressed() {
	
	logo::interpreter g;

	QByteArray cmd = command->text().toAscii();
	
	g.parse(cmd.data(), cmd.data() + cmd.length());

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

	//resize(640, 480);
	setWindowTitle("Coaxial Logo 1.0");
	//setWindowIcon(QIcon(":/resources/turtle.png"));

	// set tabs
	tabs = new QTabWidget(this);
	setCentralWidget(tabs);

	// set statusbars
	
	// Set Scene
	scene = new QGraphicsScene(this);
	//scene->setSceneRect(-320, -240, 640, 480);

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
	
	// Set the Dock Widgets
	dockCommand = new QDockWidget("Command", this);
	dockCommand->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

	command = new QLineEdit(dockCommand);
	dockCommand->setWidget(command);
	addDockWidget(Qt::BottomDockWidgetArea, dockCommand);

	// Set the main widget (focus it)
	command->setFocus();

	// Create Turtle!!
	turtle = scene->addPixmap(QPixmap(":/resources/turtle.png"));

	statusBar()->showMessage("Ready.");

	resizeEvent(0);
	
	connect(command, SIGNAL(returnPressed()), this, SLOT(onReturnPressed()));

}

/**
 *	Change the Graphics View Viewpoint
 */
void logo::window::resizeEvent(QResizeEvent *event)
{
	qreal w = width() - 4;
	qreal h = height() - 4;

	scene->setSceneRect(-w/2, -h/2, w, h);
}