#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
#include <MagneticField.h>
#include <ElectricField.h>
#include <Barrier.h>
#include <Proton.h>
#include <Finish.h>

struct ElectricFieldPic{
    ElectricField field;
    QRect rect;
};
struct MagneticFieldPic{
    MagneticField field;
    int x;
    int y;
    double R;
};
struct BarrierPic{
    Barrier field;
    QRect rect;
};
struct FinishPic{
    Finish field;
    QRect rect;
};
namespace Ui {

class Widget;
}

class Widget : public QWidget
{
public:
    void RestartGame();
    void Initialize();
    void InitializeProton();
public:
    int numberOfElectricField = 0;
    int numberOfMagneticField = 0;
    int numberOfBarrier = 0;
    int numberOfFinish = 0;
    Point theFirstPointForE;
    Point theSecondPointForE;
    Point theFirstPointForB;
    Point theSecondPointForB;
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent* event);
    void work(Widget* w);
    virtual void keyPressEvent(QKeyEvent *event);
    //virtual void paintEvent(QPaintEvent *event); //场景刷新
    //virtual void timerEvent(QTimerEvent *event); //定时器事件
    //virtual void keyPressEvent(QKeyEvent *event); //键盘响应

private:
    Ui::Widget *ui;

public:
    QList<ElectricFieldPic> ElectricFieldList;
    QList<MagneticFieldPic> MagneticFieldList;
    QList<BarrierPic> BarrierList;
    QList<FinishPic> FinishList;
    QList<Proton> ProtonList;
public slots:
    void closegame();
    void keyPressEvent1();
    void keyPressEvent2();
    void keyPressEvent3();
};

#endif // WIDGET_H
