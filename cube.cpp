#include "cube.h"

void cube::init()
{
    xrot = yrot = zrot = 45.0;
    xtrans = ytrans = 0.0;
    ztrans = - 3.0;
    ifcolor = 1;
    iftexture = 0;
    iflight = 0;
    m_dCoordinateChange = 1;
}

void cube::init_face()
{
    for (int i = 0; i<24 ; i++)
    {
        index[i] = i;
    }
}

void cube::init_vertex()
{
    GLfloat temp[] = {
        -0.5,0.5,0.5, -0.5,-0.5,0.5, 0.5,-0.5,0.5, 0.5,0.5,0.5,
        0.5,0.5,0.5, 0.5,-0.5,0.5, 0.5,-0.5,-0.5, 0.5,0.5,-0.5,
        0.5,0.5,-0.5, 0.5,-0.5,-0.5, -0.5,-0.5,-0.5, -0.5,0.5,-0.5,
        -0.5,0.5,-0.5, -0.5,-0.5,-0.5, -0.5,-0.5,0.5, -0.5,0.5,0.5,
        -0.5,0.5,-0.5, -0.5,0.5,0.5, 0.5,0.5,0.5, 0.5,0.5,-0.5,
        -0.5,-0.5,-0.5, 0.5,-0.5,-0.5, 0.5,-0.5,0.5, -0.5,-0.5,0.5
    };

    for (int i = 0; i<72 ; i++)
        vertex[i] = temp[i];

}

void cube::init_color()
{
/*    GLfloat temp[] = {
        -0.5,0.5,0.5, -0.5,0.5,0.5, -0.5,0.5,0.5, -0.5,0.5,0.5,
        0.5,0.5,0.5, 0.5,0.5,0.5, 0.5,0.5,0.5, 0.5,0.5,0.5,
        0.5,0.5,-0.5, 0.5,0.5,-0.5, 0.5,0.5,-0.5, 0.5,0.5,-0.5,
        1.0,0.0,0.0, 1.0,0.0,0.0, 1.0,0.0,0.0, 1.0,0.0,0.0,
        0.0,1.0,0.0, 0.0,1.0,0.0, 0.0,1.0,0.0, 0.0,1.0,0.0,
        0.0,0.0,1.0, 0.0,0.0,1.0, 0.0,0.0,1.0, 0.0,0.0,1.0,
    };

    for (int i = 0; i<72 ; i++)
        color[i] = temp[i];
*/
    for(int i = 0 ; i<72 ;i ++)
    {color[i] = 0.0;}
    for(int i  = 0; i< 72;i++)
    {
        color[i] = 1;
        i= i+2;
    }

}

void cube::init_texture()
{
    GLfloat temp[] = {
        1.0,0.0, 0.0,0.0, 0.0,1.0, 1.0,1.0,
        1.0,0.0, 0.0,0.0, 0.0,1.0, 1.0,1.0,
        1.0,0.0, 0.0,0.0, 0.0,1.0, 1.0,1.0,
        1.0,0.0, 0.0,0.0, 0.0,1.0, 1.0,1.0,
        1.0,0.0, 0.0,0.0, 0.0,1.0, 1.0,1.0,
        1.0,0.0, 0.0,0.0, 0.0,1.0, 1.0,1.0,
    };

    for (int i = 0; i<48 ; i++)
        texture[i] = temp[i];
}

void cube::init_normal()
{
    GLint temp[] = {
        0,0,1, 0,0,1, 0,0,1, 0,0,1,
        1,0,0, 1,0,0, 1,0,0, 1,0,0,
        0,0,-1, 0,0,-1, 0,0,-1, 0,0,-1,
        -1,0,0, -1,0,0, -1,0,0, -1,0,0,
        0,1,0, 0,1,0, 0,1,0, 0,1,0,
        0,-1,0, 0,-1,0, 0,-1,0, 0,-1,0,
    };

    for (int i = 0; i<72 ; i++)
        normal[i] = temp[i];
}

void cube::init_edge()
{

}

void cube::set_light()
{
    static const GLfloat light_position[] = {1.0f, 1.0f, 1.0f, 1.0f};
 //   static const GLfloat light_ambient[]  = {0.0f, 0.0f, 0.0f, 1.0f};
 //   static const GLfloat light_diffuse[]  = {1.0f, 1.0f, 1.0f, 1.0f};
//    static const GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   // glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
   // glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
   // glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

}

void cube::set_material()
{
 //   GLfloat mat_ambient[]={1.0f,1.0f,0.0f,1.0f};
 //   GLfloat mat_diffuse[]={0.5f,0.5f,0.0f,1.0f};
  //  GLfloat mat_specular[]={1.0f,1.0f,0.0f,1.0f};
    GLfloat mat_shininess=10.0;

   // glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
 //   glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
 //   glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialf (GL_FRONT, GL_SHININESS, mat_shininess);

}

void cube::initializecube()
{
    init_face();
    init_vertex();
    init_normal();
    init_color();
    init_texture();
    glClearColor(1.0,1.0,1.0,1.0);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glEnableClientState(GL_VERTEX_ARRAY);


}

void cube::loadTexture()
{
    QImage tex;
    QImage buf;
    if(!buf.load("E:/qt_projet/drawwwww/texture/NeHe.bmp"))
    {
        qWarning("Cannot open the image!");
        QImage dummy(128,128,QImage::Format_RGB32);
        dummy.fill(Qt::green);
        buf = dummy;
    }
    //tex = convertToGLFormat(buf);
    tex = buf;
    glGenTextures(1,&textu);
    glTexImage2D(GL_TEXTURE_2D,0,3,tex.width(),tex.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,tex.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

void cube::paint()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(xtrans, ytrans, ztrans);
    glRotatef(xrot,1.0,0.0,0.0);
    glRotatef(yrot,0.0,1.0,0.0);
    glRotatef(zrot,0.0,0.0,1.0);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glShadeModel(GL_SMOOTH);

    glColorMaterial(GL_FRONT,GL_AMBIENT);
    glEnable(GL_COLOR_MATERIAL);
    set_light();
    set_material();
    if(!iflight){
        glDisable(GL_LIGHTING);
    }
    glScalef(m_dCoordinateChange,m_dCoordinateChange,m_dCoordinateChange);


    if(ifcolor){
        glDisable(GL_TEXTURE_2D);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(3,GL_FLOAT,0,&color);
        glDeleteTextures(1,&textu);
    }
    if(iftexture){
        glEnable(GL_TEXTURE_2D);
        glDisableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        loadTexture();
        glTexCoordPointer(2,GL_FLOAT,0,&texture);
    }
    glNormalPointer(GL_FLOAT,0,normal);
    glVertexPointer(3,GL_FLOAT,0,vertex);


    glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,index);


        //paint lines
  //  GLfloat colorline[72] = {0.0};
  //  glColorPointer(3,GL_FLOAT,0,colorline);

 //   glDrawElements(GL_LINE_LOOP,24,GL_UNSIGNED_BYTE,index);



}
//SLOTS

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

void cube::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xrot) {
        xrot = angle;
  //      updateGL();
    }
}

void cube::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yrot) {
        yrot = angle;
 //       updateGL();
    }
}

void cube::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zrot) {
        zrot = angle;
//       updateGL();
    }
}

void cube::change_color(GLfloat *colornew)
{
    for(int i = 0 ;i < 72 ; i++)
    {
        color[i] = colornew[i];
    }
}

void cube::change_vertex(GLfloat *vertexnew)
{
    for (int i = 0; i<72 ; i++)
        vertex[i] = vertexnew[i];
}

void cube::change_type(int type)
{
    if(type == 0)
    {
        ifcolor = 1;
        iftexture = 0;
    }
    if(type == 1)
    {
        ifcolor = 0;
        iftexture = 1;
    }
}

void cube::change_light(int t)
{
    if (t == 0)
    {
        iflight = 0;
    }
    else
    {
        iflight = 1;
    }
}

void cube::change_place(float i, float j , float k)
{
    xtrans += i;
    ytrans += j;
    ztrans += k;
}

//EVENTS

void cube::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->pos();
}

void cube::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - m_lastPos.x();
    int dy = event->y() - m_lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xrot + 4 * dy);
        setYRotation(yrot + 4 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xrot + 4 * dy);
        setZRotation(zrot + 4 * dx);
    }
    m_lastPos = event->pos();
}

void cube::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Up:
        ytrans += 0.1;
        break;
    case Qt::Key_Left:
        xtrans -= 0.1;
        break;
    case Qt::Key_Right:
        xtrans += 0.1;
        break;
    case Qt::Key_Down:
        ytrans -= 0.1;
        break;
    case Qt::Key_Plus:
        ztrans += 0.1;
        break;
    case Qt::Key_Minus:
        ztrans -= 0.1;
        break;
    }
//    updateGL();

}

void cube::wheelEvent(QWheelEvent *event)
{
    int numDegress = event->delta()/8;  //滚动的角度
    int numSteps = numDegress / 15;     //滚动的步数,正值表示滚轮向前旋转原理用户

    if(numSteps > 0)
    {
        m_dCoordinateChange += 0.1;

        if(m_dCoordinateChange > 2)
        {
            m_dCoordinateChange = 2;
        }
    }
    else
    {
        m_dCoordinateChange -= 0.1;
        if(m_dCoordinateChange < 0.1)
        {
            m_dCoordinateChange = 0.1;
        }
    }
     //updateGL();
    event->accept();
}
