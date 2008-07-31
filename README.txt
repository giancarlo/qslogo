#
# qsLogo (Qt Spirit Logo Programming Environment)
#


I. TO BUILD

I.1 Modify logo.pro

Before running qmake you need to set the BOOST variable with the location of your BOOST include files.

I.2 Run Qmake

qmake BOOST=/location/of/boost/dir

I.3 Run make or nmake or other

make

I.4 Enjoy

II. Installation

You will need qtcore4.dll and qtgui4.dll in the bin/(target) folder.


II Documentation

II.1 Supported Commands

sqr number	# Square Root
forward/fd step
back/bk step
right/rt degree
left/lt degree
xcor	# returns x coordinate
ycor	# returns y coordinate
get turtle x
get turtle y
cs	# clear screen
print <string | number>
exit

	
