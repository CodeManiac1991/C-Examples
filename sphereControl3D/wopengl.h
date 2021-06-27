#ifndef WOPENGL_H
#define WOPENGL_H

#include <QGLWidget>

class SceneGL : public QGLWidget
{
public:
    SceneGL();
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void rotate(float x = 1.0);
    void drawSphere();
    void drawTriangle();

    void setX(GLfloat x);
    void setY(GLfloat y);
    void setZ(GLfloat z);

    void rotateX(GLfloat x);
    void rotateY(GLfloat y);
    void rotateZ(GLfloat z);

    void moveFigure(GLfloat m_ix, GLfloat m_iy, GLfloat m_iz);
    void rotateFigure(GLfloat m_irotatex, GLfloat m_irotatey, GLfloat m_irotatez);

    int m_iRot;
    GLfloat m_ix, m_iy, m_iz;
    GLfloat m_irotatex, m_irotatey, m_irotatez;

};

#endif // WOPENGL_H
