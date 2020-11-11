#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QVideoWidget> //视频播放
#include <QHBoxLayout>  //水平布局类
#include <QVBoxLayout>  //垂直布局类
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void openSlot();  //添加文件播放
    void playSlot();   //播放暂停

private:
    Ui::Widget *ui;
    QPushButton *openBtn;
    QPushButton *playBtn;
    QSlider *hSlider;
    QVideoWidget *videoWidget;

    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;

    QString filePath;
    QMediaPlayer *player;
};
#endif // WIDGET_H
