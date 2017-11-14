#ifndef DRAW_H
#define DRAW_H

#include <cube.h>
#include <ball.h>
#include <tetra.h>

class draw_poly:  public QGLWidget
{
      Q_OBJECT

private:
    cube drawcube;
    ball drawball;
    tetra drawtetra;
    int type;
    GLuint texName;


public:
     draw_poly(QWidget *parent = 0);
    ~draw_poly();

     void setwidget();

     void initializeGL();
     void resizeGL(int w, int h);
     void paintGL();

     void mousePressEvent(QMouseEvent *event) ;
     void mouseMoveEvent(QMouseEvent *event) ;
     void keyPressEvent(QKeyEvent *event) ;
     void wheelEvent(QWheelEvent *event) ;

public slots:

     void set_color(int colort);
     void set_type(int type);
     void set_polytype(int type);
     void set_light(int t);
     void change_placeup();
     void change_placedown();
     void change_placeleft();
     void change_placeright();
     void change_placein();
     void change_placeout();
};


#endif // DRAW_H
