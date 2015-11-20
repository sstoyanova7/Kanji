#include <GL/glfw.h>

#include <iostream>
using namespace std;


const float originalBrush = 0.4,
      brush = originalBrush/2,
      depth = 5*originalBrush;


void drawHorizontal(float x, float y, float z, float length)
{
    length *= brush;
    //glColor3ub(0, 255, 0); //top
    glBegin(GL_POLYGON);
        glNormal3f(0.0, +1.0, 0.0);
        glVertex3f(x-length, y+depth, z+brush);
        glVertex3f(x+length, y+depth, z+brush);
        glVertex3f(x+length, y+depth, z-brush);
        glVertex3f(x-length, y+depth, z-brush);
    glEnd();

    //glColor3ub(0, 255, 0); //bottom
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

    //glColor3ub(255, 0, 255); //front
    glBegin(GL_POLYGON);
        glNormal3f(0.0, 0.0, +1.0);
        glVertex3f(x-length, y+depth, z+brush);
        glVertex3f(x+length, y+depth, z+brush);
        glVertex3f(x+length, y-depth, z+brush);
        glVertex3f(x-length, y-depth, z+brush);
    glEnd();

    //glColor3ub(0, 255, 255); //back
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

    //glColor3ub(255, 0, 0); //top
    glBegin(GL_POLYGON);
        glNormal3f(0.0, +1.0, 0.0);
        glVertex3f(x-brush, y+depth, z+length);
        glVertex3f(x+brush, y+depth, z+length);
        glVertex3f(x+brush, y+depth, z-length);
        glVertex3f(x-brush, y+depth, z-length);
    glEnd();

    //glColor3ub(0, 255, 0); //bottom
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

    //glColor3ub(255, 0, 255); //front
    glBegin(GL_POLYGON);
        glNormal3f(0.0, 0.0, +1.0);
        glVertex3f(x-brush, y+depth, z+length);
        glVertex3f(x+brush, y+depth, z+length);
        glVertex3f(x+brush, y-depth, z+length);
        glVertex3f(x-brush, y-depth, z+length);
    glEnd();

    //glColor3ub(0, 255, 255); //back
    glBegin(GL_POLYGON);
        glNormal3f(0.0, 0.0, -1.0);
        glVertex3f(x-brush, y+depth, z-length);
        glVertex3f(x+brush, y+depth, z-length);
        glVertex3f(x+brush, y-depth, z-length);
        glVertex3f(x-brush, y-depth, z-length);
    glEnd();
}

void drawLeftPart(float x, float y, float z)
{
    drawVertical(  x - 2.3*originalBrush + brush, y,                             z, 7.2);
    drawHorizontal(x,                             y, z + 3.6*originalBrush - brush, 2.6);
    drawVertical(  x + 2.3*originalBrush - brush, y, z+0.6*originalBrush,           6.0);
    drawHorizontal(x,                             y, z + 1.2*originalBrush - brush, 2.6);
    drawHorizontal(x,                             y, z - 2.4*originalBrush + brush, 2.6);
}

void drawRightPart(float x, float y, float z)
{
    drawVertical(  x - 2.85*originalBrush + brush, y, z + 0.35*originalBrush,         5.6);
    drawHorizontal(x,                              y, z + 3.15*originalBrush - brush, 3.7);
    drawVertical(  x + 2.85*originalBrush - brush, y, z,                              6.3);
    drawHorizontal(x,                              y, z + 0.85*originalBrush - brush, 3.7);
    drawHorizontal(x,                              y, z - 2.45*originalBrush + brush, 3.7);
}

void drawBottomPart(float x, float y, float z)
{
    drawVertical(  x - 4*originalBrush - brush, y, z,                           2);
    drawHorizontal(x,                           y, z + 1*originalBrush + brush, 10);
    drawVertical(  x + 4*originalBrush + brush, y, z,                           2);
    drawVertical(  x - 1*originalBrush - brush, y, z,                           2);
    drawVertical(  x + 1*originalBrush + brush, y, z,                           2);
    drawHorizontal(x,                           y, z - 1*originalBrush - brush, 13);
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
}

int main()
{
    bool running = 1;

 /*   glfwInit();

    if(!glfwOpenWindow(512, 512, 0, 0, 0, 0, 8, 0, GLFW_WINDOW))
    {
        glfwTerminate();
        return 0;
    }
*/
    init();
    glfwSetWindowTitle("Kanji");

    glEnable( GL_DEPTH_TEST );
    glEnable( GL_LIGHTING );
    glEnable( GL_COLOR_MATERIAL );
    glEnable( GL_LIGHT0 );

    while(running)
    {
        glClear(GL_COLOR_BUFFER_BIT + GL_DEPTH_BUFFER_BIT);
        glRotatef( 0.005, 0.4, -0.2, 0.7);
        glRotatef( 0.04, 0.6, -0.2, 0.7);

        drawLeftPart(-3.4*originalBrush, 0 , 1.5*originalBrush);
        drawRightPart(3.5*originalBrush,0,2.5*originalBrush);
        drawBottomPart(0,0,-5*originalBrush);
                glfwSwapBuffers();
        running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
    }
    glfwTerminate();
    return 0;
}
