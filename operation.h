#ifndef OPERATION_H
#define OPERATION_H

#include <QtOpenGL>
#include <glut.h>
#include <QtOpenGL>
#include <QGLWidget>
#include <QKeyEvent>


class operation
{
    //Q_OBJECT

protected:


private:


public:
    virtual void set_pic();
    virtual void init_vertex();

    virtual void init_edgetype();
    virtual void init_color();
    virtual void init_texture();
    virtual void init_surface_texture();

    virtual void init_light();
    virtual void init_transparency();
    virtual void init_view();
    virtual void init_fog();

    virtual void init_translate();
    virtual void init_rotate();
    virtual void init_zoom();

    virtual void paint();

public slots:

    virtual void change_vertex();
    virtual void change_edgetype();
    virtual void change_color();
    virtual void change_texture();
    virtual void change_surface_texture();

    virtual void change_light();
    virtual void change_transparency();
    virtual void change_view();
    virtual void change_fog();


    virtual void change_translate();
    virtual void change_rotate();
    virtual void change_zoom();


signals:



};






#endif // OPERATION_H
