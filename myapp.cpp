#include <myapp.h>

poly_widget::poly_widget(QWidget *parent)
    : QWidget( parent )
{


    draw_poly *mypoly = new draw_poly;
// choose type
    QComboBox *ctype = new QComboBox(parent);
    ctype->addItem(QWidget::tr("cube"));
    ctype->addItem(QWidget::tr("ball"));
    ctype->addItem(QWidget::tr("tetrahedron"));
    QObject::connect(ctype,SIGNAL(currentIndexChanged(int)),mypoly,SLOT(set_polytype(int)));



// change color combobox
    QComboBox *comboc = new QComboBox(parent);
    comboc->addItem(QWidget::tr("red"));
    comboc->addItem(QWidget::tr("green"));
    comboc->addItem(QWidget::tr("blue"));
    QObject::connect(comboc,SIGNAL(currentIndexChanged(int)),mypoly,SLOT(set_color(int)));

// color or texture combobox
    QComboBox *colortexture = new QComboBox(parent);
    colortexture->addItem(QWidget::tr("use color"));
    colortexture->addItem(QWidget::tr("use texture"));
    QObject::connect(colortexture,SIGNAL(currentIndexChanged(int)),mypoly,SLOT(set_type(int)));

// set texture

// light on or off
    QComboBox *ilight = new QComboBox(parent);
    ilight->addItem(QWidget::tr("light off"));
    ilight->addItem(QWidget::tr("light on"));
    QObject::connect(ilight,SIGNAL(currentIndexChanged(int)),mypoly,SLOT(set_light(int)));

// change position
    QPushButton *up = new QPushButton(parent);
    up->setText("up");
    QObject::connect(up,SIGNAL(clicked()),mypoly,SLOT(change_placeup()));

    QPushButton *down = new QPushButton(parent);
    down->setText("down");
    QObject::connect(down,SIGNAL(clicked()),mypoly,SLOT(change_placedown()));

    QPushButton *left = new QPushButton(parent);
    left->setText("left");
    QObject::connect(left,SIGNAL(clicked()),mypoly,SLOT(change_placeleft()));

    QPushButton *right = new QPushButton(parent);
    right->setText("right");
    QObject::connect(right,SIGNAL(clicked()),mypoly,SLOT(change_placeright()));

    QPushButton *in = new QPushButton(parent);
    in->setText("in");
    QObject::connect(in,SIGNAL(clicked()),mypoly,SLOT(change_placein()));

    QPushButton *out = new QPushButton(parent);
    out->setText("out");
    QObject::connect(out,SIGNAL(clicked()),mypoly,SLOT(change_placeout()));



// layout
    QGridLayout *box = new QGridLayout;
    box->addWidget(mypoly,0,0,8,6);
    box->addWidget(ctype,0,0,1,1);
    box->addWidget(colortexture,0,1,1,1);
    box->addWidget(comboc,0,2,1,1);
    box->addWidget(ilight,0,3,1,1);
    box->addWidget(up,6,4);
    box->addWidget(down,7,4);
    box->addWidget(left,7,3);
    box->addWidget(right,7,5);
    box->addWidget(in,6,0);
    box->addWidget(out,7,0);



    this->setLayout(box);
    this->setFixedSize(1200,800);
}


poly_widget::~poly_widget()
{

}
