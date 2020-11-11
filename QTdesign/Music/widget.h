#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QTimer>
#include <QTime>
#include <QDir>
#include <QListWidgetItem>
#include <QMovie>
#include <QPixmap>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent);
    ~Widget();

private slots:
    //页面切换
    void on_my_music_clicked();
    void on_music_return_clicked();
    void on_my_bang_clicked();
    void on_bang_my_clicked();
    void on_my_return_clicked();
    void on_set_return_clicked();
    void on_bang_music_clicked();
    void on_set_music_clicked();
    void on_bengDi_my_clicked();
    void on_my_bengDi_clicked();
    void on_bengDi_music_clicked();
    void on_bengDi_bangDan_clicked();
    void on_music_list_clicked();

    //音乐播放
    void setVolumeValue(int val);  // 音量
    void setHSliderRange(qint64 dur); //设置播放进度条范围
    void setHSliderValue(qint64 pos); //音乐播放改变播放的进度
    void setPlayerPosSlot(int pos);  //改变播放的进度（快进)
    void on_playBtn_clicked();  //播放或者暂停
    void timeoutSlot(); //播放时间显示
    void bengDi_play(QListWidgetItem *item);  //双击播放
    void on_bengDi_addMusic_clicked();  //添加歌曲名字


private:
    Ui::Widget *ui;
    QMediaPlayer *player;
    QTimer *timer;
    QString filePath;  //文件路径
    QString str;
    int n ;  //用于歌曲名的动态显示
    QStringList list;  //歌曲地址列表
    int List_num;  //歌曲序号 等于列表中歌曲的存储顺序
    QMovie movie; //动图
    QPixmap pix; //静图


};

#endif // WIDGET_H
