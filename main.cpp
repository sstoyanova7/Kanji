#include <GL/glfw.h>
#include <cmath>
#include <iostream>
using namespace std;


const float originalBrush = 0.4,
            brush = originalBrush/2,
            depth = 5*originalBrush;


void drawHorizontal(float x, float y, float z, float length)
{
    length *= brush;
    //glColor3ub(0, 255, 0); //front
    glBegin(GL_POLYGON);
        glNormal3f(0.0, +1.0, 0.0);
        glVertex3f(x-length, y+depth, z+brush);
        glVertex3f(x+length, y+depth, z+brush);
        glVertex3f(x+length, y+depth, z-brush);
        glVertex3f(x-length, y+depth, z-brush);
    glEnd();

    //glColor3ub(0, 255, 0); //back
    glBegin(GL_POLYGON);
        glNormal3f(0.0, -1.0, 0.0);
        glVertex3f(x-length, y-depth, z+brush);
        glVertex3f(x+length, y-depth, z+brush);
        glVertex3f(x+length, y-depth, z-brush);
        glVertex3f(x-length, y-depth, z-brush);
    glEnd();

    //glColor3ub(0, 0, 255); //left
    glBegin(GL_POLYGON);
        glNormal3f(-1.0, 0.0, 0.0);
        glVertex3f(x-length, y+depth, z+brush);
        glVertex3f(x-length, y-depth, z+brush);
        glVertex3f(x-length, y-depth, z-brush);
        glVertex3f(x-length, y+depth, z-brush);
    glEnd();

    //glColor3ub(255, 255, 0); //right
    glBegin(GL_POLYGON);
        glNormal3f(+1.0, 0.0, 0.0);
        glVertex3f(x+length, y+depth, z+brush);
        glVertex3f(x+length, y-depth, z+brush);
        glVertex3f(x+length, y-depth, z-brush);
        glVertex3f(x+length, y+depth, z-brush);
    glEnd();

    //glColor3ub(255, 0, 255); //top
    glBegin(GL_POLYGON);
        glNormal3f(0.0, 0.0, +1.0);
        glVertex3f(x-length, y+depth, z+brush);
        glVertex3f(x+length, y+depth, z+brush);
        glVertex3f(x+length, y-depth, z+brush);
        glVertex3f(x-length, y-depth, z+brush);
    glEnd();

    //glColor3ub(0, 255, 255); //bottom
    glBegin(GL_POLYGON);
        glNormal3f(0.0, 0.0, -1.0);
        glVertex3f(x-length, y+depth, z-brush);
        glVertex3f(x+length, y+depth, z-brush);
        glVertex3f(x+length, y-depth, z-brush);
        glVertex3f(x-length, y-depth, z-brush);
    glEnd();
}

void drawVertical(float x, float y, float z, float length)
{
    length *= brush;

    //glColor3ub(255, 0, 0); //front
    glBegin(GL_POLYGON);
        glNormal3f(0.0, +1.0, 0.0);
        glVertex3f(x-brush, y+depth, z+length);
        glVertex3f(x+brush, y+depth, z+length);
        glVertex3f(x+brush, y+depth, z-length);
        glVertex3f(x-brush, y+depth, z-length);
    glEnd();

    //glColor3ub(0, 255, 0); //back
    glBegin(GL_POLYGON);
        glNormal3f(0.0, -1.0, 0.0);
        glVertex3f(x-brush, y-depth, z+length);
        glVertex3f(x+brush, y-depth, z+length);
        glVertex3f(x+brush, y-depth, z-length);
        glVertex3f(x-brush, y-depth, z-length);
    glEnd();

    //glColor3ub(0, 0, 255); //left
    glBegin(GL_POLYGON);
        glNormal3f(-1.0, 0.0, 0.0);
        glVertex3f(x-brush, y+depth, z+length);
        glVertex3f(x-brush, y-depth, z+length);
        glVertex3f(x-brush, y-depth, z-length);
        glVertex3f(x-brush, y+depth, z-length);
    glEnd();

    //glColor3ub(255, 255, 0); //right
    glBegin(GL_POLYGON);
        glNormal3f(+1.0, 0.0, 0.0);
        glVertex3f(x+brush, y+depth, z+length);
        glVertex3f(x+brush, y-depth, z+length);
        glVertex3f(x+brush, y-depth, z-length);
        glVertex3f(x+brush, y+depth, z-length);
    glEnd();

    //glColor3ub(255, 0, 255); //top
    glBegin(GL_POLYGON);
        glNormal3f(0.0, 0.0, +1.0);
        glVertex3f(x-brush, y+depth, z+length);
        glVertex3f(x+brush, y+depth, z+length);
        glVertex3f(x+brush, y-depth, z+length);
        glVertex3f(x-brush, y-depth, z+length);
    glEnd();

    //glColor3ub(0, 255, 255); //bottom
    glBegin(GL_POLYGON);
        glNormal3f(0.0, 0.0, -1.0);
        glVertex3f(x-brush, y+depth, z-length);
        glVertex3f(x+brush, y+depth, z-length);
        glVertex3f(x+brush, y-depth, z-length);
        glVertex3f(x-brush, y-depth, z-length);
    glEnd();
}

void drawRingPart(float x, float y, float z, float Rx, float Ry, float Rz, float angle, float R)
{
    float startAngle = acos((z - Rz)/R);
    float width = M_PI/180;
    startAngle = 0;
    angle+=startAngle;

    glBegin(GL_POLYGON);
        glNormal3f(sin(angle), 0.0, cos(angle));
        glVertex3f(x+(R-brush)*cos(startAngle), y+depth, z-(R-brush)*sin(startAngle));
        glVertex3f(x+(R+brush)*cos(startAngle), y+depth, z-(R+brush)*sin(startAngle));
        glVertex3f(x+(R+brush)*cos(startAngle), y-depth, z-(R+brush)*sin(startAngle));
        glVertex3f(x+(R-brush)*cos(startAngle), y-depth, z-(R-brush)*sin(startAngle));
    glEnd();

    for (float i = startAngle; fabs(i) < fabs(angle); i += width)
    {
        glBegin(GL_POLYGON); //front
            glNormal3f(0.0, +1.0, 0.0);
            glVertex3f(x+(R-brush)*cos(i-width), y+depth, z-(R-brush)*sin(i-width));
            glVertex3f(x+(R+brush)*cos(i-width), y+depth, z-(R+brush)*sin(i-width));
            glVertex3f(x+(R+brush)*cos(i+width), y+depth, z-(R+brush)*sin(i+width));
            glVertex3f(x+(R-brush)*cos(i+width), y+depth, z-(R-brush)*sin(i+width));
        glEnd();

        glBegin(GL_POLYGON); // back
            glNormal3f(0.0, -1.0, 0.0);
            glVertex3f(x+(R-brush)*cos(i-width), y-depth, z-(R-brush)*sin(i-width));
            glVertex3f(x+(R+brush)*cos(i-width), y-depth, z-(R+brush)*sin(i-width));
            glVertex3f(x+(R+brush)*cos(i+width), y-depth, z-(R+brush)*sin(i+width));
            glVertex3f(x+(R-brush)*cos(i+width), y-depth, z-(R-brush)*sin(i+width));
        glEnd();

        glBegin(GL_POLYGON); // inside
            glNormal3f(-cos(i+width), 0.0, +sin(i+width));
            glVertex3f(x+(R-brush)*cos(i-width), y+depth, z-(R-brush)*sin(i-width));
            glVertex3f(x+(R-brush)*cos(i+width), y+depth, z-(R-brush)*sin(i+width));
            glVertex3f(x+(R-brush)*cos(i+width), y-depth, z-(R-brush)*sin(i+width));
            glVertex3f(x+(R-brush)*cos(i-width), y-depth, z-(R-brush)*sin(i-width));
        glEnd();

        glBegin(GL_POLYGON); // outside
            glNormal3f(+cos(i+width), 0.0, -sin(i+width));
            glVertex3f(x+(R+brush)*cos(i-width), y+depth, z-(R+brush)*sin(i-width));
            glVertex3f(x+(R+brush)*cos(i+width), y+depth, z-(R+brush)*sin(i+width));
            glVertex3f(x+(R+brush)*cos(i+width), y-depth, z-(R+brush)*sin(i+width));
            glVertex3f(x+(R+brush)*cos(i-width), y-depth, z-(R+brush)*sin(i-width));
        glEnd();
    }

    glBegin(GL_POLYGON);
        glNormal3f(-1.0, 0.0, 0.0);
        glVertex3f(x+(R-brush)*cos(angle), y + depth, z+(R-brush)*sin(angle));
        glVertex3f(x+(R+brush)*cos(angle), y + depth, z+(R+brush)*sin(angle));
        glVertex3f(x+(R+brush)*cos(angle), y - depth, z+(R+brush)*sin(angle));
        glVertex3f(x+(R-brush)*cos(angle), y - depth, z+(R-brush)*sin(angle));
    glEnd();

}

void drawPolygon (float x, float y, float z, float angle, float R)
{
    glBegin(GL_POLYGON); //front
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(x+(R-brush)*cos(angle), y-depth,   z+(R-brush)*sin(angle));
    glVertex3f(x+(R+brush)*cos(angle), y - depth, z+(R+brush)*sin(angle));
    glVertex3f(x-1.6*originalBrush,    y-depth,   z+(R+brush)*sin(angle));
    glVertex3f(x-2*originalBrush,      y-depth,   z-0.55*originalBrush);
    glEnd();

    glBegin(GL_POLYGON);  //back
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(x+(R-brush)*cos(angle), y+depth, z+(R-brush)*sin(angle));
    glVertex3f(x+(R+brush)*cos(angle), y+depth, z+(R+brush)*sin(angle));
    glVertex3f(x-1.6*originalBrush,    y+depth, z+(R+brush)*sin(angle));
    glVertex3f(x-2*originalBrush,      y+depth, z-0.55*originalBrush);
    glEnd();

    glBegin(GL_POLYGON); //left
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(x-2*originalBrush,      y-depth, z-0.55*originalBrush);
    glVertex3f(x-1.6*originalBrush,    y-depth, z+(R+brush)*sin(angle));
    glVertex3f(x-1.6*originalBrush,    y+depth, z+(R+brush)*sin(angle));
    glVertex3f(x-2*originalBrush,      y+depth, z-0.55*originalBrush);
    glEnd();

    glBegin(GL_POLYGON); //right
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(x+(R-brush)*cos(angle), y+depth, z+(R-brush)*sin(angle));
    glVertex3f(x+(R+brush)*cos(angle), y+depth, z+(R+brush)*sin(angle));
    glVertex3f(x+(R+brush)*cos(angle), y-depth, z+(R+brush)*sin(angle));
    glVertex3f(x+(R-brush)*cos(angle), y+depth, z+(R-brush)*sin(angle));
    glEnd();

    glBegin(GL_POLYGON); //top
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(x+(R-brush)*cos(angle), y-depth, z+(R-brush)*sin(angle));
    glVertex3f(x-2*originalBrush,      y-depth, z-0.55*originalBrush);
    glVertex3f(x-2*originalBrush,      y+depth, z-0.55*originalBrush);
    glVertex3f(x+(R-brush)*cos(angle), y+depth, z+(R-brush)*sin(angle));
    glEnd();

    glBegin(GL_POLYGON); //bottom
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(x+(R+brush)*cos(angle), y-depth, z+(R+brush)*sin(angle));
    glVertex3f(x-1.6*originalBrush,    y-depth, z+(R+brush)*sin(angle));
    glVertex3f(x-1.6*originalBrush,    y+depth, z+(R+brush)*sin(angle));
    glVertex3f(x+(R+brush)*cos(angle), y+depth, z+(R+brush)*sin(angle));
    glEnd();
}

void drawLeftPart(float x, float y, float z)
{
    drawVertical(  x - 2.3*originalBrush + brush, y, z,                             7.2);
    drawHorizontal(x,                             y, z + 3.6*originalBrush - brush, 2.6);
    drawVertical(  x + 2.3*originalBrush - brush, y, z+0.6*originalBrush,           6.0);
    drawHorizontal(x,                             y, z + 1.2*originalBrush - brush, 2.6);
    drawHorizontal(x,                             y, z - 2.4*originalBrush + brush, 2.6);
}

void drawRightPart(float x, float y, float z)
{
    drawVertical(  x - 2.85*originalBrush + brush, y, z + 0.35*originalBrush,         5.6);
    drawRingPart(  x - 6.25*originalBrush + brush, y, z - 1.45*originalBrush,         x - 5*originalBrush, y,
                   z - 3.5*originalBrush,   -M_PI/2.75,                         3.5*originalBrush);
    drawHorizontal(x,                              y, z + 3.15*originalBrush - brush, 3.7);
    drawVertical(  x + 2.85*originalBrush - brush, y, z,                              6.3);
    drawRingPart(  x + 1.15*originalBrush,         y, z-3*originalBrush,              0,                   0,
                   0,                       -M_PI/2,                            1.2*originalBrush);
    drawPolygon (  x + 1.15*originalBrush,         y, z-3*originalBrush,              -M_PI/2,             1.2*originalBrush);
    drawHorizontal(x,                              y, z + 0.85*originalBrush - brush, 3.7);
    drawHorizontal(x,                              y, z - 2.45*originalBrush + brush, 3.7);
}

void drawBottomPart(float x, float y, float z)
{
    drawVertical(  x - 4*originalBrush - brush,    y, z,                              2);
    drawHorizontal(x,                              y, z + 1*originalBrush + brush,    10);
    drawVertical(  x + 4*originalBrush + brush,    y, z,                              2);
    drawVertical(  x - 1*originalBrush - brush,    y, z,                              2);
    drawVertical(  x + 1*originalBrush + brush,    y, z,                              2);
    drawHorizontal(x,                              y, z - 1*originalBrush - brush,    13);
}


void init()
{
    int width, height;

    glfwInit();
    if( !glfwOpenWindow( 640, 480, 0, 0, 0, 0, 8, 0, GLFW_WINDOW ) ) return;

    glfwGetWindowSize( &width, &height );
    height = height > 0 ? height : 1;

    glViewport( 0, 0, width, height );
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 65.0f, (GLfloat)width/(GLfloat)height, 1.0f, 100.0f );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(0.0f, -10.0f, 0.0f,
            0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f );

    glfwSetWindowTitle("Kanji");

    glEnable( GL_DEPTH_TEST );
    glEnable( GL_LIGHTING );
    glEnable( GL_COLOR_MATERIAL );
    glEnable( GL_LIGHT0 );
}

int main()
{
    bool running = 1;

    init();


    while(running)
    {
        glClear(GL_COLOR_BUFFER_BIT + GL_DEPTH_BUFFER_BIT);

        glRotatef( 0.005, 0.4, -0.2, 0.7);
        glRotatef( 0.04, 0.6, -0.2, 0.7);

        glColor3ub(128, 128, 64);
        drawLeftPart(  -3.4*originalBrush, 0,  1.5*originalBrush);
        drawRightPart( 3.5*originalBrush,  0,  2.5*originalBrush);
        drawBottomPart(0,                  0,  -5*originalBrush);

        glfwSwapBuffers();
        running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
    }

    glfwTerminate();

    return 0;
}
