#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QStyle>   //标准的图形化显示播放按钮

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
        ui->setupUi(this);

        //设置窗口大小
        this->setMaximumSize(640, 480);
        this->setMinimumSize(640, 480);

        openBtn = new QPushButton(this);  //打开文件
        playBtn = new QPushButton(this);   //播放暂停
        hSlider = new QSlider(Qt::Horizontal, this);  //进度条
        videoWidget = new QVideoWidget(this);   //显示视频窗口

        hLayout = new QHBoxLayout;  //水平布局
        vLayout = new QVBoxLayout;

         player = new QMediaPlayer(this);
         //设置openBtn的值
         openBtn->setText("open");

         //添加到水平布局
         hLayout->addWidget(openBtn);
         hLayout->addWidget(playBtn);
         hLayout->addWidget(hSlider);

         //添加到垂直布局
         vLayout->addWidget(videoWidget);
         vLayout->addLayout(hLayout);

         //将垂直布局设置到界面上
         this->setLayout(vLayout);

         //设置将视频显示到videoWidget上
         player->setVideoOutput(videoWidget);

         //点击打开 按钮
          connect(openBtn,SIGNAL(clicked(bool)),this,SLOT(openSlot()));
          //暂停
          connect(playBtn,SIGNAL(clicked(bool)),this,SLOT(playSlot()));
}

Widget::~Widget()
{
    delete ui;
    //水平布局和垂直布局 父对象不是widget
    delete hLayout;
    delete vLayout;
}

//打开文件播放
void Widget::openSlot()
{
    filePath = QFileDialog::getOpenFileName(this,"open","./","mp4(*.mp4);;avi(*.avi);;rmvb(*.rmvb);;mkv(*.mkv)");
    //不存在
    if(filePath.isEmpty())
    {
        return;
    }
    player->setMedia(QUrl(filePath));
    //播放视频
    player->play();
    //播放按键该为 暂停
    playBtn->setIcon(QIcon(this->style()->standardIcon(QStyle::SP_MediaPause)));

}

void Widget::playSlot()
{
    //通过此时视频的播放状态进行判断
    if(QMediaPlayer::PlayingState == player->state())
    {
        player->pause();  //暂停
        playBtn->setIcon(QIcon(this->style()->standardIcon(QStyle::SP_MediaPlay)));
    }
    else
    {
        player->play();  //播放
        playBtn->setIcon(QIcon(this->style()->standardIcon(QStyle::SP_MediaPause)));
    }
}
