#include "ball.h"

void ball::init()
{
    xrot = yrot = zrot = 45.0;
    xtrans = ytrans = 0.0;
    ztrans = - 3.0;
    ifcolor = 1;
    iftexture = 0;
    iflight = 0;
    colora = 1.0;
    colorb = colorc = 0.0;
    m_dCoordinateChange = 1;
}


void ball::init_edge()
{

}

void ball::set_light()
{
    static const GLfloat light_position[] = {1.0f, 1.0f, 1.0f, 1.0f};
 //   static const GLfloat light_ambient[]  = {0.0f, 0.0f, 0.0f, 1.0f};
 //   static const GLfloat light_diffuse[]  = {1.0f, 1.0f, 1.0f, 1.0f};
  //  static const GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   // glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
   // glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
   // glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

}

void ball::set_material()
{
 //   GLfloat mat_ambient[]={1.0f,1.0f,0.0f,1.0f};
//    GLfloat mat_diffuse[]={0.5f,0.5f,0.0f,1.0f};
 //   GLfloat mat_specular[]={1.0f,1.0f,0.0f,1.0f};
    GLfloat mat_shininess=10.0;

   // glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
 //   glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
 //   glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialf (GL_FRONT, GL_SHININESS, mat_shininess);

}

void ball::initializeball()
{

    glClearColor(1.0,1.0,1.0,1.0);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

 //   glEnableClientState(GL_VERTEX_ARRAY);


}

/*
void ball::loadTexture()
{
     AUX_RGBImageRec *TextureImage[1];
     glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

     glGenTextures(1, &texName);
     glBindTexture(GL_TEXTURE_2D, texName);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
     memset(TextureImage, 0, sizeof(void *) * 1);
     if (TextureImage[0] = auxDIBImageLoadA("13.bmp"))
     {
      glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
     }
}
*/

void ball::paint()
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

    GLUquadricObj* qobj;
    qobj = gluNewQuadric();
    glPushMatrix();


    if(ifcolor){
        glDisable(GL_TEXTURE_2D);

        glColor3f(colora,colorb,colorc);

      //  glDeleteTextures(1,&textu);
    }
    if(iftexture){
        glEnable(GL_TEXTURE_2D);
   //     glBindTexture(GL_TEXTURE_2D, texName);
        gluQuadricTexture(qobj, GL_TRUE);

//        loadTexture();
    }

    gluSphere(qobj, 0.45, 60, 60);
 //   glPopMatrix();
 //   glutSwapBuffers();

    //paint lines


}

//SLOTS

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

void ball::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xrot) {
        xrot = angle;
  //      updateGL();
    }
}

void ball::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yrot) {
        yrot = angle;
 //       updateGL();
    }
}

void ball::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zrot) {
        zrot = angle;
//       updateGL();
    }
}

void ball::change_color(int c)
{
    if (c == 0){
        colorb = colorc = 0.0;
        colora = 1.0;
    }
    if (c == 1){
        colora = colorc = 0.0;
        colorb = 1.0;
    }
    if (c == 2){
        colora = colorb = 0.0;
        colorc = 1.0;
    }
}

void ball::change_vertex(GLfloat *vertexnew)
{

}

void ball::change_type(int type)
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

void ball::change_light(int t)
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

void ball::change_place(float i, float j , float k)
{
    xtrans += i;
    ytrans += j;
    ztrans += k;
}

//EVENTS

void ball::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->pos();
}

void ball::mouseMoveEvent(QMouseEvent *event)
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

void ball::keyPressEvent(QKeyEvent *event)
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

void ball::wheelEvent(QWheelEvent *event)
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
