#ifndef BALL_H
#define BALL_H

#include <GL/glew.h>
#include <GL/GLU.h>
#include <QPoint>
#include <QGLWidget>
#include "operation.h"
#include <QTimer>

class ball : public operation
{

private:
    GLdouble radius;
    GLint slices;
    GLint stacks;

    GLuint textu;
    QPoint m_lastPos;
    GLfloat m_dCoordinateChange;

    GLfloat colora, colorb, colorc;

    GLubyte index[24];

    float xrot, yrot, zrot;
    float xtrans, ytrans , ztrans;
    bool ifcolor, iftexture, iflight;


public:
    void init();
    void initializeball();
    void init_edge();

    void set_light();
    void set_material();
    void loadTexture();
    void paint();

    void mousePressEvent(QMouseEvent *event) ;
    void mouseMoveEvent(QMouseEvent *event) ;
    void keyPressEvent(QKeyEvent *event) ;
    void wheelEvent(QWheelEvent *event) ;

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void change_color(int c);
    void change_vertex(GLfloat *vertexnew);
    void change_type(int type);
    void change_light(int t);
    void change_place(float i, float j , float k);
};

#endif // BALL_H
