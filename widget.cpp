#include <time.h>
#include <QMessageBox>
#include <QDebug>
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QRect>
#include <QLabel>
#include <QString>
#include <QPushButton>
#include <windows.h>
#include "widget.h"
#include "ui_widget.h"
#include "Point.h"
bool E = false;
bool B = false;
bool Begin = false;
//定义图案代码和边

Widget::Widget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton * btn_1 = new QPushButton();
    QPushButton * btn_2 = new QPushButton();
    QPushButton * btn_3 = new QPushButton();
    QPushButton * btn_4 = new QPushButton();
    btn_1->setFixedSize(150,50);
    btn_1->setText(tr("Start"));
    btn_1->move(600,800);
    btn_1->setParent(this);
    btn_2->setFixedSize(150,50);
    btn_2->setText(tr("Reset"));
    btn_2->move(750,800);
    btn_2->setParent(this);
    btn_3->setFixedSize(150,50);
    btn_3->setText(tr("Restart"));
    btn_3->move(900,800);
    btn_3->setParent(this);
    btn_4->setFixedSize(150,50);
    btn_4->setText(tr("Exit"));
    btn_4->move(1050,800);
    btn_4->setParent(this);
    connect(btn_1,&QPushButton::clicked,this,&Widget::keyPressEvent1);
    connect(btn_2,&QPushButton::clicked,this,&Widget::keyPressEvent2);
    connect(btn_3,&QPushButton::clicked,this,&Widget::keyPressEvent3);
    connect(btn_4,&QPushButton::clicked,this,&Widget::close);
    QString text = QString("Introduction:Use the left mouse button to draw an electric field or the right mouse button to draw a magnetic field to move the proton to its end.");
    QLabel * label_1 = new QLabel(this);
    label_1->setFixedSize(600,50);
    label_1->move(0,800);
    label_1->setText(text);
    label_1->setWordWrap(true);
}

void Point2QPoint(QPoint &A,Point &B){
    A.setX(B.X());
    A.setY(B.Y());
    return;
}
void Widget::InitializeProton(){
    ProtonList[0].changeP(50,50);
    ProtonList[0].clearSpeed();
};
void Widget::Initialize(){
    ElectricFieldList.clear();
    MagneticFieldList.clear();
    ProtonList[0].InitializeProton();
    numberOfElectricField = 0;
    numberOfMagneticField = 0;
};
Widget::~Widget()
{
    delete ui;
}
void Widget::mousePressEvent(QMouseEvent *event) // 鼠标按下事件
{
if(!Begin){
if(event->button() == Qt::LeftButton){       // 如果是鼠标左键按下
    if(!E){
    theFirstPointForE.changeP(event->pos().x(),event->pos().y());
    //theFirstPointForE.getPoint();
    //qDebug()<<"1";
    E = true;
    //Paint();
    //update();
    return;
    }
}
if(event->button() == Qt::RightButton){       // 如果是鼠标右键按下
    if(!B){
    theFirstPointForB.changeP(event->pos().x(),event->pos().y());
    //theFirstPointForB.getPoint();
    //qDebug()<<"1";
    B = true;
    //Paint();
    //update();
    return;
    }
}
}
}
void Widget::mouseMoveEvent(QMouseEvent *event) // 鼠标移动事件
{
    if(event->buttons() == Qt::LeftButton){
        if(E){
        theSecondPointForE.changeP(event->pos().x(),event->pos().y());
        //theSecondPointForE.getPoint();
        //qDebug()<<pos();
        update();
        //paintEvent();
        }
    }
    if(event->buttons() == Qt::RightButton){
        if(B){
        theSecondPointForB.changeP(event->pos().x(),event->pos().y());
        //theSecondPointForB.getPoint();
        //qDebug()<<pos();
        update();
        //paintEvent();
        }
    }
}
void Widget::mouseReleaseEvent(QMouseEvent *event) // 鼠标释放事件
{
    update();
if(event->button() == Qt::LeftButton){
    if(E){
    theSecondPointForE.changeP(event->pos().x(),event->pos().y());
    //theSecondPointForE.getPoint();
    //qDebug()<<"2";
    ElectricField* p = new ElectricField(theFirstPointForE,theSecondPointForE);
    QPoint A,B;
    Point2QPoint(A,theFirstPointForE);
    Point2QPoint(B,theSecondPointForE);
    QRect rect;
    rect.setTopLeft(A);
    rect.setBottomRight(B);
    ElectricFieldPic pp = {*p,rect};
    ElectricFieldList << pp;
    numberOfElectricField ++ ;
    E = false;
    //update();
    return;
    }
}
if(event->button() == Qt::RightButton){
    if(B){
    theSecondPointForB.changeP(event->pos().x(),event->pos().y());
    //theSecondPointForB.getPoint();
    //qDebug()<<"2";
    double R = theSecondPointForB - theFirstPointForB;
    MagneticField* p = new MagneticField(theFirstPointForB,R);
    MagneticFieldPic pp = {*p,theFirstPointForB.X(),theFirstPointForB.Y(),R};
    MagneticFieldList << pp;
    numberOfMagneticField ++ ;
    B = false;
    //update();
    return;
    }
}
}
void Widget::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    QImage Elect(":/back/Electric.png");
    QImage Magne(":/back/Magnetic.png");
    qDebug()<<Magne;
    //painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(Qt::red);
    painter.drawEllipse(ProtonList[0].X()-3,ProtonList[0].Y()-3,6,6);
    painter.setBrush(QColor(1,1,1,255));
    for(int i=0;i<numberOfBarrier;i++){
        painter.drawRect(BarrierList[i].rect);
    }
    painter.setBrush(QColor(255,255,0,255));
    for(int i=0;i<numberOfFinish;i++){
        painter.drawRect(FinishList[i].rect);
    }
    painter.setBrush(QColor(0,238,238,30));
    for(int i=0;i<numberOfElectricField;i++){
        painter.drawRect(ElectricFieldList[i].rect);
        //qDebug()<<Elect;
        int x,y,sx,sy;
        QRect Draw;
        Draw = ElectricFieldList[i].rect;
        x = Draw.topLeft().x();
        y = Draw.topLeft().y();
        sx = Elect.width() - Draw.width();
        sy = Elect.height() - Draw.height();
        painter.drawPixmap(x,y,QPixmap(QPixmap::fromImage(Elect)),sx,sy,Draw.width(),Draw.height());
    }
    painter.setBrush(QColor(152,251,152,50));
    QBrush Magnetic;
    Magnetic.setTextureImage(Magne);
    painter.setBrush(Magnetic);
    //painter.setBrush(Qt::TexturePattern);
    for(int i=0;i<numberOfMagneticField;i++){
        int theX = MagneticFieldList[i].x;
        int theY = MagneticFieldList[i].y;
        int theR = MagneticFieldList[i].R;
        painter.drawEllipse(theX-theR,theY-theR,theR*2,theR*2);
    }
    if(E)
    {
        QPoint startpoint;
        //qDebug()<<theFirstPointForE.X()<<"，"<<theFirstPointForE.Y();
        startpoint.setX(theFirstPointForE.X());
        startpoint.setY(theFirstPointForE.Y());
        QPoint endpoint;
        endpoint.setX(theSecondPointForE.X());
        endpoint.setY(theSecondPointForE.Y());
        QRect rect(startpoint, endpoint);
        QPainter painter(this);
        painter.setBrush(QColor(0,238,238,30));
        painter.drawRect(rect);
        //qDebug()<<rect;
        this->show();
    }
    if(B)
    {
        double R = theSecondPointForB - theFirstPointForB;
        QPainter painter(this);
        painter.setBrush(QColor(152,251,152,30));
        painter.drawEllipse(theFirstPointForB.X()-R,theFirstPointForB.Y()-R,2*R,2*R);
        this->show();
    }
    if(Begin){
    painter.setBrush(QColor(1,1,1,255));
    painter.drawEllipse(ProtonList[0].X()-3,ProtonList[0].Y()-3,6,6);
    this->show();
    //qDebug()<<"drawing";
    }
    return;
}


void Widget::keyPressEvent1()
{
    // 是否按下B键
        work(this);
        update();
        Begin = true;

}
void Widget::keyPressEvent2()
{
     // 是否按下E键
        update();
        Begin = false;
        ProtonList[0].InitializeProton();

}
void Widget::keyPressEvent3()
{
    // 是否按下R键

        update();
        Begin = false;
        Initialize();

}

void Widget::keyPressEvent(QKeyEvent *event)       // 键盘按下事件
{
    if(event->key() == Qt::Key_B){ // 是否按下B键
        work(this);
        update();
        Begin = true;
    }
    if(event->key() == Qt::Key_E){ // 是否按下E键
        update();
        Begin = false;
        Initialize();
    }
    if(event->key() == Qt::Key_R){ // 是否按下R键
        update();
        Begin = false;
        ProtonList[0].InitializeProton();
    }
}

void Widget::work(Widget* w){
    for(int i=0;i<w->numberOfElectricField;i++){
        ElectricFieldList[i].field.addSpeed(ProtonList[0]);
    }
    for(int i=0;i<w->numberOfMagneticField;i++){
        MagneticFieldList[i].field.addSpeed(ProtonList[0]);
    }
    for(int i=0;i<w->numberOfBarrier;i++){
        BarrierList[i].field.hitted(ProtonList[0]);
    }
    for(int i=0;i<w->numberOfFinish;i++){
        FinishList[i].field.hitted(ProtonList[0]);
    }
    ProtonList[0].move();
    //ProtonList[0].getPoint();
}

