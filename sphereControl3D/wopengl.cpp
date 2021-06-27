#include "wopengl.h"
#include <QtOpenGL>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QColor>

SceneGL::SceneGL()
{
    m_iRot = 0;
    m_ix=0.0f;
    m_iy=0.0f;
    m_iz=0.0f;
    m_irotatex=0.0f;
    m_irotatey=0.0f;
    m_irotatez=0.0f;
    resize(300,300);
}

void SceneGL::initializeGL()
{
    qglClearColor(Qt::white); // заполняем экран белым цветом
    glEnable(GL_DEPTH_TEST); // задаем глубину проверки пикселей
    glShadeModel(GL_FLAT); // убираем режим сглаживания цветов
    glEnable(GL_CULL_FACE); // говорим, что будем строить только внешние поверхности
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); // фигуры будут закрашены с обеих сторон
}

void SceneGL::resizeGL(int nWidth, int nHeight)
{
    Q_UNUSED(nWidth);
    glViewport(0, 0, nWidth, nHeight); // установка точки обзора
    glMatrixMode(GL_PROJECTION); // установка режима матрицы
    glLoadIdentity(); // загрузка матрицы
}

void SceneGL::paintGL()
{
    glMatrixMode(GL_MODELVIEW); // задаем модельно-видовую матрицу
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //drawTriangle();
    drawSphere();
}

void SceneGL::rotate(float x)
{
    m_iRot=x;
}

void SceneGL::drawSphere()
{
        GLUquadricObj* m_qObj = gluNewQuadric();
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        rotateFigure(m_irotatex, m_irotatey, m_irotatez);
        qglColor(Qt::blue);
        moveFigure(m_ix, m_iy, m_iz);
        gluSphere(m_qObj, 0.25f, 25, 25);
}

void SceneGL::drawTriangle()
{
    qglColor(Qt::green); // задаем цвет
    glRotatef(m_iRot, 1.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex3f(0.0, 0.9, 0.0); //Координаты 1 ТРЕУГОЛЬНИКА
        glVertex3f(0.0, 0.3, 0.0);
        glVertex3f(0.3, 0.9, 0.0);
    glEnd();
}

void SceneGL::setX(GLfloat x)
{
    m_ix+=x;
    moveFigure(m_ix, m_iy, m_iz);
}

void SceneGL::setY(GLfloat y)
{
    m_iy+=y;
    moveFigure(m_ix, m_iy, m_iz);
}

void SceneGL::setZ(GLfloat z)
{
    m_iz+=z;
    moveFigure(m_ix, m_iy, m_iz);
}

void SceneGL::rotateX(GLfloat x)
{
    m_irotatex+=x;
    rotateFigure(m_irotatex, m_irotatey, m_irotatez);
}

void SceneGL::rotateY(GLfloat y)
{
    m_irotatey+=y;
    rotateFigure(m_irotatex, m_irotatey, m_irotatez);
}

void SceneGL::rotateZ(GLfloat z)
{
    m_irotatez+=z;
    rotateFigure(m_irotatex, m_irotatey, m_irotatez);
}

void SceneGL::moveFigure(GLfloat m_ix, GLfloat m_iy, GLfloat m_iz)
{
   glTranslatef(m_ix, m_iy, m_iz);
}

void SceneGL::rotateFigure(GLfloat m_irotatex, GLfloat m_irotatey, GLfloat m_irotatez)
{
   glRotatef(m_iRot, m_irotatex, m_irotatey, m_irotatez);
}


