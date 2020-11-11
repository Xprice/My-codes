#include "widget.h"
#include "ui_widget.h"

#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include <QFile>
#include <QPixmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //美化
    setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(backgroundRole(), QPixmap(":/photo/pic1/1.jpg"));
	setPalette(pal);

    //动图显示
    //添加动画
    movie.setFileName(":/photo/pic2/6.gif");
    ui->music_photo->setScaledContents(true); //让图片自己适应显示框大小
    ui->music_photo->setMovie(&movie);

    setWindowTitle(tr("音乐播放器"));  //设置窗口标题
    this->setWindowIcon(QIcon(":/photo/pic2/2.png"));  //窗口的图标

    //显示头像图标
    pix.load(":/photo/pic2/5.jpg");
    ui->my_name->setScaledContents(true); //让图片自己适应显示框大小
    ui->my_name->setPixmap(pix);

    //小图标 显示
    ui->my_like->setIcon(QIcon(":/photo/pic2/7.png"));
    ui->set_like->setIcon(QIcon(":/photo/pic2/7.png"));



    // 主界面 显示 我的音乐
    ui->stackedWidget->setCurrentWidget(ui->page_my);

    player = new QMediaPlayer(this);
     //设置垂直滑块(音量)的初始值
    ui->verticalSlider->setValue(player->volume());
    ui->verticalSlider_2->setValue(player->volume());

    //通过垂直滑块改变音量
    connect(ui->verticalSlider,SIGNAL(sliderMoved(int)),this,SLOT(setVolumeValue(int)));
    connect(ui->verticalSlider_2,SIGNAL(sliderMoved(int)),this,SLOT(setVolumeValue(int)));
    //设置播放进度条范围
    connect(player,SIGNAL(durationChanged(qint64)),this,SLOT(setHSliderRange(qint64)));
    //根据音乐播放 改变进度 水平滑块
    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(setHSliderValue(qint64)));

    //播放时间的显示
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeoutSlot()));

    //设置playBtn为不可点击(无音乐)
     ui->playBtn->setEnabled(false);

     n = 0;
     List_num = 0;

     //改变播放的进度（快进）
    connect(ui->horizontalSlider,SIGNAL(sliderMoved(int)),this,SLOT(setPlayerPosSlot(int)));

    //鼠标双击
    connect(ui->bengDi_list,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(bengDi_play(QListWidgetItem*)));
}

Widget::~Widget()
{
    delete ui;
    delete player;
}

//==============各页面关系=====================
//主页面 进入 music页面
void Widget::on_my_music_clicked()
{
       ui->stackedWidget->setCurrentWidget(ui->page_music);
}
//music 页面进入到 本地列表
void Widget::on_music_list_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_bengDiList);
}

//返回主
void Widget::on_music_return_clicked()
{
       ui->stackedWidget->setCurrentWidget(ui->page_my);
}

//主页面进入 排行榜
void Widget::on_my_bang_clicked()
{
       ui->stackedWidget->setCurrentWidget(ui->page_bang);
}
//榜 进入音乐播放
void Widget::on_bang_music_clicked()
{
      ui->stackedWidget->setCurrentWidget(ui->page_music);
}
//返回主
void Widget::on_bang_my_clicked()
{
       ui->stackedWidget->setCurrentWidget(ui->page_my);
}

//主进入 设置
void Widget::on_my_return_clicked()
{
       ui->stackedWidget->setCurrentWidget(ui->page_set);
}
//设置 进入音乐
void Widget::on_set_music_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->page_music);
}
//返回主
void Widget::on_set_return_clicked()
{
       ui->stackedWidget->setCurrentWidget(ui->page_my);
}

//进入本地音乐列表
void Widget::on_my_bengDi_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->page_bengDiList);
}
//从本地音乐到 音乐
void Widget::on_bengDi_music_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_music);
}
//本地音乐进入到 榜
void Widget::on_bengDi_bangDan_clicked()
{
      ui->stackedWidget->setCurrentWidget(ui->page_bang);
}
//本地音乐 到 主
void Widget::on_bengDi_my_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->page_my);
}

//=================音乐的播放===================

//改变播放的音量
void Widget::setVolumeValue(int val)
{
    player->setVolume(val);
}

//设置水平进度条范围
void Widget::setHSliderRange(qint64 dur)
{
    //设置水平滑块的范围
    ui->horizontalSlider->setRange(0, dur);
}

//改变播放的进度
void Widget::setHSliderValue(qint64 pos)
{
    ui->horizontalSlider->setValue(pos);
}

//快进播放
void Widget::setPlayerPosSlot(int  pos)
{
    player->setPosition(pos);
}

//播放时间的显示
void Widget::timeoutSlot()
{
    //获得总时长
    qint64 dur = player->duration() / 1000;  //秒
    //获得当前播放的时间
    qint64 pos = player->position() / 1000;

    //显示时间
    ui->timeLabel->setText(QTime(0,0,0).addSecs(pos).toString("mm:ss") + "/" +
                           QTime(0,0,0).addSecs(dur).toString("mm:ss"));

    //歌曲名字动态显示
    n ++;
    ui->music_name->setText(str.mid(n));
    if(n >= str.length())
    {
        n = 0;
    }

    //播放结束
    if(player->position() == player->duration())
    {
        //判断是否是单曲循环
        if("单曲循环" == ui->comboBox->currentText())
        {
            player->stop();
            player->play();
            return;
        }
        player->stop();
        timer->stop();
        ui->timeLabel->clear();
        ui->music_name->clear();
        ui->playBtn->setText("播放");
        ui->horizontalSlider->setValue(0);  //播放进度条设置为0
        ui->music_text->clear(); //清理歌词
    }
}

//点击 播放 或暂停音乐
void Widget::on_playBtn_clicked()
{
    if("播放" == ui->playBtn->text())
       {
           player->play();
           ui->playBtn->setText("暂停");
       }
       else
       {
           player->pause();
           ui->playBtn->setText("播放");
       }
}


//==============播放列表================

//添加音乐到播放列表
void Widget::on_bengDi_addMusic_clicked()
{
    list = QFileDialog::getOpenFileNames(this,"添加歌曲","./","mp3(*.mp3)");
    qDebug()<<list.size();

    QString fileName;
    int i ;
    //判断是否重复
    for(i = 0; i < list.size(); i++)
    {
       //获得文件名字
        QListWidgetItem *item = new QListWidgetItem(ui->bengDi_list);
        QFileInfo info(list.at(i));
        fileName = info.fileName();

//        for(j = 0; j <= ui->bengDi_list->count(); j++)
//        {
//               QString showName = ui->bengDi_list->item(j)->text();
//               QString  a = showName.mid(6);  //从第六个字符开始分割
//               qDebug()<<a;
//               if( fileName == a)
//               {
//                    //有相等的
//                     tmp = 1;
//                }
//        }

        // 歌曲列表添加序号
         List_num++;
         char buf[4] = {0};
         sprintf(buf,"%d",List_num);
         QString showName =QString(buf) +" .   " +fileName ;
         //显示
         item->setText(showName);


    }
}


//双击播放音乐
void Widget::bengDi_play(QListWidgetItem *item)
{
     // 如果有歌曲正在播放
    if("暂停" == ui->playBtn->text())
    {
        player->stop();
        timer->stop();
        ui->timeLabel->clear();
        ui->music_name->clear();
        ui->music_text->clear();
        ui->horizontalSlider->setValue(0);
    }

    QString fileName;
    fileName = item->text(); //所点击的格式
    QString get_musicName = fileName.mid(6); //所点击的歌曲全名

    if(true == get_musicName.isEmpty())
     {
           return;
     }

    //获取所点击文件名 对应的路径
   QString List_musicName;
    int i = 0;
    for (i = 0; i < list.size(); i++ )
    {
           //获得文件名
            QFileInfo info(list.at(i));
            List_musicName = info.fileName();

            if ( get_musicName == List_musicName  )
            {
                //显示歌名
                str = "                         " +get_musicName;
                ui->music_name->setText(str);
                //跳转到音乐播放
                ui->stackedWidget->setCurrentWidget(ui->page_music);
                filePath = list.at(i);

                //播放歌曲
                player->setMedia(QUrl(filePath));
                player->play();
                ui->playBtn->setText("暂停");


                //显示歌词
                //获取歌词绝对路径
                QString musicText_path= info.absolutePath();
                //分离歌曲名和后缀
                QString arr_name = get_musicName;
                QStringList nameList = arr_name.split(".");
                //a 为分离后的歌曲名
                QString a = nameList[0];
                //拼接歌词的路径
                musicText_path = musicText_path +"/" + a +".lrc";

                //打开歌曲读取内容
                QFile file(musicText_path);
                bool ok = file.open(QIODevice::ReadOnly);
                //歌词的拆分


                if( true == ok )
                {
                         QByteArray arr = file.readAll();
                         ui->music_text->setText(QString(arr));


                          file.close();
                }

                //动图播放
                movie.start();

                timer->start(1000);
                ui->playBtn->setEnabled(true);
           }

        }
}




