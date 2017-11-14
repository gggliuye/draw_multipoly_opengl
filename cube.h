#ifndef CUBE_H
#define CUBE_H

#include <GL/glew.h>
#include <GL/GLU.h>
#include <QPoint>
#include <QGLWidget>
#include "operation.h"
#include <QTimer>

class cube : public operation
{

private:
    GLfloat vertex[72];
    GLfloat color[72];
    GLfloat texture[48];
    GLint normal[72];
    GLuint textu;
    QPoint m_lastPos;
    GLfloat m_dCoordinateChange;

    GLubyte index[24];

    float xrot, yrot, zrot;
    float xtrans, ytrans , ztrans;
    bool ifcolor, iftexture, iflight;

public:
    void init();
    void initializecube();
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
    void change_vertex(GLfloat *vertexnew);
    void change_type(int type);
    void change_light(int t);
    void change_place(float i, float j , float k);
};


#endif // CUBE_H
