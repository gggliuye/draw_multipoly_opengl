#include <draw.h>

draw_poly::draw_poly(QWidget *parent)
   : QGLWidget(parent)
{
   drawcube.init();
   drawball.init();
   drawtetra.init();
   type = 0;
   setwidget();
   QTimer *timer = new QTimer(this);
   QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
   timer->start(10);
}

draw_poly::~draw_poly()
{

}

void draw_poly::setwidget()
{

}



void draw_poly::mousePressEvent(QMouseEvent *event)
{
    drawcube.mousePressEvent(event);
    drawball.mousePressEvent(event);
    drawtetra.mousePressEvent(event);
}

void draw_poly::mouseMoveEvent(QMouseEvent *event)
{
    drawcube.mouseMoveEvent(event);
    drawball.mouseMoveEvent(event);
    drawtetra.mouseMoveEvent(event);
}

void draw_poly::keyPressEvent(QKeyEvent *event)
{
    drawcube.keyPressEvent(event);
    drawball.keyPressEvent(event);
    drawtetra.keyPressEvent(event);
}

void draw_poly::wheelEvent(QWheelEvent *event)
{
    drawcube.wheelEvent(event);
    drawball.wheelEvent(event);
    drawtetra.wheelEvent(event);
}

void draw_poly::set_color(int colort)
{
    GLfloat *color = new GLfloat[72];
  //  QMessageBox::information(this, tr("Info"),"yes");
    if (colort == 0)
    {
        for(int i = 0 ; i<72 ;i ++)
        {color[i] = 0.0;}
        for(int i  = 0; i< 72;i++)
        {
            color[i] = 1;
            i= i+2;
        }
        drawcube.change_color(color);
        drawtetra.change_color(color);
        drawball.change_color(colort);

    };
    if (colort == 1)
    {
        for(int i = 0 ; i<72 ;i ++)
        {color[i] = 0.0;}
        for(int i  = 0; i< 72;i++)
        {
            i= i+1;
            color[i] = 1;
            i = i+1;
        }
        drawcube.change_color(color);
        drawtetra.change_color(color);
        drawball.change_color(colort);
    };
    if (colort == 2)
    {
        for(int i = 0 ; i<72 ;i ++)
        {color[i] = 0.0;}
        for(int i  = 0; i< 72;i++)
        {
            i= i+2;
            color[i] = 1;
        }
        drawcube.change_color(color);
        drawtetra.change_color(color);
        drawball.change_color(colort);
    };
    delete color;
}

void draw_poly::set_type(int type)
{
    drawcube.change_type(type);
    drawtetra.change_type(type);
}

void draw_poly::set_polytype(int t)
{
    type = t;
}

void draw_poly::set_light(int t)
{
    drawcube.change_light(t);
    drawball.change_light(t);
    drawtetra.change_light(t);
}

void draw_poly::change_placeout()
{
    drawcube.change_place(0,0,0.1);
    drawball.change_place(0,0,0.1);
    drawtetra.change_place(0,0,0.1);
}
void draw_poly::change_placein()
{
    drawcube.change_place(0,0,-0.1);
    drawball.change_place(0,0,-0.1);
    drawtetra.change_place(0,0,-0.1);
}

void draw_poly::change_placeleft()
{
    drawcube.change_place(-0.1,0,0);
    drawball.change_place(-0.1,0,0);
    drawtetra.change_place(-0.1,0,0);
}

void draw_poly::change_placeright()
{
    drawcube.change_place(0.1,0,0);
    drawball.change_place(0.1,0,0);
    drawtetra.change_place(0.1,0,0);
}

void draw_poly::change_placeup()
{
    drawcube.change_place(0,0.1,0);
    drawball.change_place(0,0.1,0);
    drawtetra.change_place(0,0.1,0);
}

void draw_poly::change_placedown()
{
    drawcube.change_place(0,-0.1,0);
    drawball.change_place(0,-0.1,0);
    drawtetra.change_place(0,-0.1,0);
}

void draw_poly::initializeGL()
{
    drawcube.initializecube();
    drawball.initializeball();
    drawtetra.initializetetra();
}

void draw_poly::resizeGL(int w, int h )
{
    glViewport(0,0,(GLint)w,(GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(GLfloat)w/(GLfloat)h,0.1,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void draw_poly::paintGL()
{
    if (type == 0){
        drawcube.paint();
    }
    if (type == 1){
        drawball.paint();
    }
    if (type == 2){
        drawtetra.paint();
    }
}
