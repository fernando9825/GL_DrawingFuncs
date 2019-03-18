#ifndef GL_DRAWINGFUNCS_LIBRARY_H
#define GL_DRAWINGFUNCS_LIBRARY_H

#include <iostream>
#include <GL/gl.h>
#include <cmath>
#include <cstddef>
#include <array>

using namespace std;

//double convertRadiansToDegrees(double radians);
double convertDegreesToRadians(double degrees);

// colors
//GLfloat[] RGB(byte red, byte green, byte blue);

// FUNCTIONS TO DRAW A CIRCLE
void circle2d(double posX, double posY, double radius, double amountOfPoints, double degreesStart, double degreesEnd,
              GLfloat RGB[3]);
void solidCircle2d(double posX, double posY, double radius, double amountOfPoints, double degreesStart, double degreesEnd,
                   GLfloat RGB[3]);
void wiredCircle2d(double posX, double posY, double radius, int amountOfPoints, double degreesStart, double degreesEnd,
                   GLfloat  RGB[3]);

// FUNCTIONS TO DRAW A SQUARE
void square2d(double posX, double posY, double length);

#endif