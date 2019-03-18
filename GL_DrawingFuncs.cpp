//
// Created by fernando9825 on 03-13-19.
//

#include "GL_DrawingFuncs.h"

//#include <iostream>
//#include <GL/gl.h>
//#include <GL/glut.h>
//#include <cmath>

#define ERROR_MESSAGE_POINTS  "The minimum amount of points is a positive integer value, aborting drawing a "
#define ERROR_MESSAGE_LENGTH "The minimum length is a positive floating point value, aborting drawing a "
#define CIRCLE2D "circle"

#define SQUARE2D "square"

double fixVerticalPosition(double posY) {
    /*
     * Assuming that orthogonal view is glOrtho(-30.0, 30.0, -16.00, 16.0, -30.0, 30.0);
     * 30.0 left and right, 16.0 top and bottom, 30 near and far, then
     * 16 / 30 = 0.5333333 approximately, so posY must be multiplied to fix coordinates
     */
    return posY * (16.0 / 30.0);
}

// colors
/*
GLfloat * RGB(byte red, byte green, byte blue) {
    GLfloat RGB[3];
    RGB[0] = (to_integer<int>(red) / (GLfloat) 255);
    RGB[1] = (to_integer<int>(green) / (GLfloat) 255);
    RGB[2] = (to_integer<int>(blue) / (GLfloat) 255);

    cout << "red " << RGB[0] <<" green " << RGB[1] << " blue " << RGB[2] << endl;
    return RGB;
}*/

/*double convertRadiansToDegrees(double radians) {
    return (180*radians)/M_PI;
}*/

void colorSet(GLfloat RGB[3]) {
    glColor3f(RGB[0], RGB[1], RGB[2]);
}

double convertDegreesToRadians(double degrees) {
    return (degrees * M_PI) / 180;
}

// FUNCTIONS TO DRAW A CIRCLE
void circle2d(double posX, double posY, double radius, double amountOfPoints, double degreesStart, double degreesEnd,
              GLfloat RGB[3]) {

    if (amountOfPoints <= 0) {
        cout << "The minimum amount of points is a positive integer value, aborting drawing a circle" << endl;
        return;
    }

    if (amountOfPoints > 500) {
        amountOfPoints = 500;
    }

    // fixing Y coordinate
    posY = fixVerticalPosition(posY);

    glPointSize(1.0f);
    colorSet(RGB);
    glBegin(GL_POINTS);

    double x = 0, y = 0, final = 0;

    final = degreesStart + degreesEnd;

    double increment = convertDegreesToRadians(degreesStart);
    //cout << "increment " << increment << endl;
    //cout << "final " << convertDegreesToRadians(final) << endl;
    while (increment < convertDegreesToRadians(final)) {
        x = posX + radius * cos(increment);
        y = posY + radius * sin(increment);
        glVertex2d(x, y);
        increment += M_PI / amountOfPoints;
    }

    glEnd();
}

void
solidCircle2d(double posX, double posY, double radius, double amountOfPoints, double degreesStart, double degreesEnd,
              GLfloat RGB[3]) {

    if (amountOfPoints <= 0) {
        cout << "The minimum amount of points is a positive integer value, aborting drawing a circle" << endl;
        return;
    }

    if (amountOfPoints > 500) {
        amountOfPoints = 500;
    }

    // fixing Y coordinate
    posY = fixVerticalPosition(posY);

    colorSet(RGB);
    glBegin(GL_POLYGON);

    double x = 0, y = 0, final = 0;

    final = degreesStart + degreesEnd;

    double increment = convertDegreesToRadians(degreesStart);
    //cout << "increment " << increment << endl;
    //cout << "final " << convertDegreesToRadians(final) << endl;
    while (increment < convertDegreesToRadians(final)) {
        x = posX + radius * cos(increment);
        y = posY + radius * sin(increment);
        glVertex2d(x, y);
        increment += M_PI / amountOfPoints;
    }

    glEnd();
}

void wiredCircle2d(double posX, double posY, double radius, int amountOfPoints, double degreesStart, double degreesEnd,
                   GLfloat RGB[3]) {
    if (amountOfPoints <= 0) {
        cout << ERROR_MESSAGE_POINTS << CIRCLE2D << endl;
        return;
    }

    if (amountOfPoints > 500) {
        amountOfPoints = 500;
    }

    // fixing Y coordinate
    posY = fixVerticalPosition(posY);

    colorSet(RGB);
    glBegin(GL_LINES);

    double x = 0, y = 0, final = 0;

    final = degreesStart + degreesEnd;

    double increment = convertDegreesToRadians(degreesStart);
    //cout << "increment " << increment << endl;
    //cout << "final " << convertDegreesToRadians(final) << endl;
    while (increment < convertDegreesToRadians(final)) {
        x = posX + radius * cos(increment);
        y = posY + radius * sin(increment);
        glVertex2d(posX, posY);
        glVertex2d(x, y);
        increment += M_PI / amountOfPoints;
    }

    glEnd();
}

// FUNCTIONS TO DRAW A SQUARE

void square2d(double posX, double posY, double length) {
    //order is top-left -> top-right; top-right -> bottom-right; bottom-right -> bottom-left; bottom-left -> top-left

    if (length <= 0) {
        cout << ERROR_MESSAGE_LENGTH << SQUARE2D << endl;
    }

    // Y values must be fixed
    glBegin(GL_QUADS);

    /*
    glVertex2d(-0.5, 0.5); // top-left
    glVertex2d(0.5 , 0.5); // top-right

    glVertex2d(0.5, -0.5); // bottom-right
    glVertex2d(-0.5, -0.5); // bottom-left
    */

    glVertex2d(posX, posY); // top-left
    glVertex2d(posX + length , posY); // top-right

    glVertex2d(posX + length, posY - length); // bottom-right
    glVertex2d(posX, posY - length); // bottom-left


    /*glVertex2d(-posX, -fixVerticalPosition(length)); // bottom-left
    glVertex2d(posX, fixVerticalPosition(posY)); // top-left*/

    glEnd();

}
