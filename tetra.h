#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H
#include <GL/glew.h>
#include <GL/GLU.h>
#include <QPoint>
#include <QGLWidget>
#include "operation.h"
#include <QTimer>

class tetra : public operation
{

private:
    GLfloat vertex[4][3];
    GLbyte surface[4][3];
    GLfloat color[12];
    GLfloat texture[8];
    GLuint textu;
    QPoint m_lastPos;
    GLfloat m_dCoordinateChange;

    GLfloat colora, colorb, colorc;


    float xrot, yrot, zrot;
    float xtrans, ytrans , ztrans;
    bool ifcolor, iftexture, iflight;


public:

    void init();
    void initializetetra();
    void init_face();
    void init_vertex();
    void init_normal();
    void init_color();
    void init_texture();
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
    void change_color(GLfloat *colornew);
    void change_type(int type);
    void change_light(int t);
    void change_place(float i, float j , float k);
};

#endif // TETRAHEDRON_H
