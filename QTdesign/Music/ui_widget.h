/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_my;
    QLabel *my_label_3;
    QPushButton *my_my;
    QPushButton *my_shouCang;
    QPushButton *my_video;
    QLabel *my_label_1;
    QPushButton *my_bang;
    QLabel *my_label_2;
    QPushButton *my_music;
    QPushButton *my_like;
    QPushButton *my_jingXuan;
    QLabel *my_label_4;
    QPushButton *my_bengDi;
    QPushButton *my_zuiJing;
    QPushButton *my_return;
    QPushButton *my_download;
    QLabel *my_name;
    QPushButton *my_shouSuo;
    QWidget *page_bengDiList;
    QListWidget *bengDi_list;
    QLabel *bengDi_label;
    QPushButton *bengDi_addMusic;
    QPushButton *bengDi_my;
    QPushButton *bengDi_jingXue;
    QPushButton *bengDi_music;
    QPushButton *bengDi_bangDan;
    QPushButton *bengDi_shiPing;
    QWidget *page_music;
    QPushButton *music_return;
    QSlider *horizontalSlider;
    QPushButton *playBtn;
    QTextBrowser *music_name;
    QSlider *verticalSlider;
    QLabel *timeLabel;
    QSlider *verticalSlider_2;
    QComboBox *comboBox;
    QPushButton *music_up;
    QPushButton *music_down;
    QPushButton *music_list;
    QLabel *music_text;
    QLabel *music_photo;
    QWidget *page_bang;
    QPushButton *bang_my;
    QPushButton *pushButton_40;
    QPushButton *bang_music;
    QPushButton *bang_bang;
    QPushButton *bang_video;
    QLabel *bang_label_1;
    QWidget *page_set;
    QStackedWidget *stackedWidget_2;
    QWidget *page_set_2;
    QLabel *set_label_3;
    QPushButton *set_shouSuo;
    QPushButton *set_my;
    QPushButton *set_shouCang;
    QPushButton *set_video;
    QLabel *set_label_1;
    QPushButton *set_bang;
    QLabel *set_label_4;
    QPushButton *set_music;
    QPushButton *set_like;
    QPushButton *set_jingXuan;
    QLabel *set_label_2;
    QPushButton *set_bengDi;
    QPushButton *set_zuiJin;
    QPushButton *set_return_1;
    QPushButton *set_download;
    QTextBrowser *textBrowser_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *set_return;
    QPushButton *set_qianDao;
    QPushButton *set_sleep;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(480, 640);
        Widget->setMinimumSize(QSize(480, 640));
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 480, 640));
        stackedWidget->setMinimumSize(QSize(480, 640));
        page_my = new QWidget();
        page_my->setObjectName(QString::fromUtf8("page_my"));
        page_my->setMinimumSize(QSize(480, 640));
        my_label_3 = new QLabel(page_my);
        my_label_3->setObjectName(QString::fromUtf8("my_label_3"));
        my_label_3->setGeometry(QRect(20, 350, 441, 20));
        my_my = new QPushButton(page_my);
        my_my->setObjectName(QString::fromUtf8("my_my"));
        my_my->setGeometry(QRect(30, 590, 75, 31));
        my_shouCang = new QPushButton(page_my);
        my_shouCang->setObjectName(QString::fromUtf8("my_shouCang"));
        my_shouCang->setGeometry(QRect(80, 250, 311, 31));
        my_video = new QPushButton(page_my);
        my_video->setObjectName(QString::fromUtf8("my_video"));
        my_video->setGeometry(QRect(380, 590, 75, 31));
        my_label_1 = new QLabel(page_my);
        my_label_1->setObjectName(QString::fromUtf8("my_label_1"));
        my_label_1->setGeometry(QRect(190, 20, 101, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        my_label_1->setFont(font);
        my_bang = new QPushButton(page_my);
        my_bang->setObjectName(QString::fromUtf8("my_bang"));
        my_bang->setGeometry(QRect(290, 590, 75, 31));
        my_label_2 = new QLabel(page_my);
        my_label_2->setObjectName(QString::fromUtf8("my_label_2"));
        my_label_2->setGeometry(QRect(20, 370, 141, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        my_label_2->setFont(font1);
        my_music = new QPushButton(page_my);
        my_music->setObjectName(QString::fromUtf8("my_music"));
        my_music->setGeometry(QRect(210, 580, 61, 41));
        my_like = new QPushButton(page_my);
        my_like->setObjectName(QString::fromUtf8("my_like"));
        my_like->setGeometry(QRect(80, 410, 311, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        my_like->setFont(font2);
        my_like->setAutoRepeatDelay(299);
        my_jingXuan = new QPushButton(page_my);
        my_jingXuan->setObjectName(QString::fromUtf8("my_jingXuan"));
        my_jingXuan->setGeometry(QRect(120, 590, 75, 31));
        my_label_4 = new QLabel(page_my);
        my_label_4->setObjectName(QString::fromUtf8("my_label_4"));
        my_label_4->setGeometry(QRect(160, 60, 41, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(11);
        font3.setUnderline(false);
        my_label_4->setFont(font3);
        my_bengDi = new QPushButton(page_my);
        my_bengDi->setObjectName(QString::fromUtf8("my_bengDi"));
        my_bengDi->setGeometry(QRect(80, 150, 311, 31));
        my_zuiJing = new QPushButton(page_my);
        my_zuiJing->setObjectName(QString::fromUtf8("my_zuiJing"));
        my_zuiJing->setGeometry(QRect(80, 200, 311, 31));
        my_return = new QPushButton(page_my);
        my_return->setObjectName(QString::fromUtf8("my_return"));
        my_return->setGeometry(QRect(20, 20, 41, 23));
        my_download = new QPushButton(page_my);
        my_download->setObjectName(QString::fromUtf8("my_download"));
        my_download->setGeometry(QRect(80, 300, 311, 31));
        my_name = new QLabel(page_my);
        my_name->setObjectName(QString::fromUtf8("my_name"));
        my_name->setGeometry(QRect(80, 60, 71, 61));
        my_shouSuo = new QPushButton(page_my);
        my_shouSuo->setObjectName(QString::fromUtf8("my_shouSuo"));
        my_shouSuo->setGeometry(QRect(410, 22, 41, 21));
        stackedWidget->addWidget(page_my);
        page_bengDiList = new QWidget();
        page_bengDiList->setObjectName(QString::fromUtf8("page_bengDiList"));
        bengDi_list = new QListWidget(page_bengDiList);
        bengDi_list->setObjectName(QString::fromUtf8("bengDi_list"));
        bengDi_list->setGeometry(QRect(70, 90, 331, 451));
        bengDi_label = new QLabel(page_bengDiList);
        bengDi_label->setObjectName(QString::fromUtf8("bengDi_label"));
        bengDi_label->setGeometry(QRect(180, 20, 141, 21));
        bengDi_label->setFont(font);
        bengDi_addMusic = new QPushButton(page_bengDiList);
        bengDi_addMusic->setObjectName(QString::fromUtf8("bengDi_addMusic"));
        bengDi_addMusic->setGeometry(QRect(370, 30, 75, 23));
        bengDi_my = new QPushButton(page_bengDiList);
        bengDi_my->setObjectName(QString::fromUtf8("bengDi_my"));
        bengDi_my->setGeometry(QRect(30, 590, 75, 31));
        bengDi_jingXue = new QPushButton(page_bengDiList);
        bengDi_jingXue->setObjectName(QString::fromUtf8("bengDi_jingXue"));
        bengDi_jingXue->setGeometry(QRect(120, 590, 75, 31));
        bengDi_music = new QPushButton(page_bengDiList);
        bengDi_music->setObjectName(QString::fromUtf8("bengDi_music"));
        bengDi_music->setGeometry(QRect(210, 580, 61, 41));
        bengDi_bangDan = new QPushButton(page_bengDiList);
        bengDi_bangDan->setObjectName(QString::fromUtf8("bengDi_bangDan"));
        bengDi_bangDan->setGeometry(QRect(290, 590, 75, 31));
        bengDi_shiPing = new QPushButton(page_bengDiList);
        bengDi_shiPing->setObjectName(QString::fromUtf8("bengDi_shiPing"));
        bengDi_shiPing->setGeometry(QRect(380, 590, 75, 31));
        stackedWidget->addWidget(page_bengDiList);
        page_music = new QWidget();
        page_music->setObjectName(QString::fromUtf8("page_music"));
        page_music->setMinimumSize(QSize(480, 640));
        music_return = new QPushButton(page_music);
        music_return->setObjectName(QString::fromUtf8("music_return"));
        music_return->setGeometry(QRect(420, 10, 51, 23));
        music_return->setStyleSheet(QString::fromUtf8(""));
        horizontalSlider = new QSlider(page_music);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(40, 500, 321, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        playBtn = new QPushButton(page_music);
        playBtn->setObjectName(QString::fromUtf8("playBtn"));
        playBtn->setGeometry(QRect(200, 550, 75, 61));
        music_name = new QTextBrowser(page_music);
        music_name->setObjectName(QString::fromUtf8("music_name"));
        music_name->setGeometry(QRect(60, 20, 341, 31));
        verticalSlider = new QSlider(page_music);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(420, 170, 21, 171));
        verticalSlider->setOrientation(Qt::Vertical);
        timeLabel = new QLabel(page_music);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(370, 500, 71, 21));
        timeLabel->setFrameShape(QFrame::Box);
        verticalSlider_2 = new QSlider(page_music);
        verticalSlider_2->setObjectName(QString::fromUtf8("verticalSlider_2"));
        verticalSlider_2->setGeometry(QRect(20, 170, 21, 171));
        verticalSlider_2->setOrientation(Qt::Vertical);
        comboBox = new QComboBox(page_music);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(40, 570, 71, 22));
        music_up = new QPushButton(page_music);
        music_up->setObjectName(QString::fromUtf8("music_up"));
        music_up->setGeometry(QRect(120, 562, 51, 41));
        music_down = new QPushButton(page_music);
        music_down->setObjectName(QString::fromUtf8("music_down"));
        music_down->setGeometry(QRect(300, 562, 51, 41));
        music_list = new QPushButton(page_music);
        music_list->setObjectName(QString::fromUtf8("music_list"));
        music_list->setGeometry(QRect(360, 570, 81, 23));
        music_text = new QLabel(page_music);
        music_text->setObjectName(QString::fromUtf8("music_text"));
        music_text->setGeometry(QRect(60, 240, 341, 231));
        music_text->setFrameShape(QFrame::Box);
        music_photo = new QLabel(page_music);
        music_photo->setObjectName(QString::fromUtf8("music_photo"));
        music_photo->setGeometry(QRect(60, 60, 341, 171));
        music_photo->setFrameShape(QFrame::Box);
        stackedWidget->addWidget(page_music);
        page_bang = new QWidget();
        page_bang->setObjectName(QString::fromUtf8("page_bang"));
        bang_my = new QPushButton(page_bang);
        bang_my->setObjectName(QString::fromUtf8("bang_my"));
        bang_my->setGeometry(QRect(30, 590, 75, 31));
        pushButton_40 = new QPushButton(page_bang);
        pushButton_40->setObjectName(QString::fromUtf8("pushButton_40"));
        pushButton_40->setGeometry(QRect(120, 590, 75, 31));
        bang_music = new QPushButton(page_bang);
        bang_music->setObjectName(QString::fromUtf8("bang_music"));
        bang_music->setGeometry(QRect(210, 580, 61, 41));
        bang_bang = new QPushButton(page_bang);
        bang_bang->setObjectName(QString::fromUtf8("bang_bang"));
        bang_bang->setGeometry(QRect(290, 590, 75, 31));
        bang_video = new QPushButton(page_bang);
        bang_video->setObjectName(QString::fromUtf8("bang_video"));
        bang_video->setGeometry(QRect(380, 590, 75, 31));
        bang_label_1 = new QLabel(page_bang);
        bang_label_1->setObjectName(QString::fromUtf8("bang_label_1"));
        bang_label_1->setGeometry(QRect(210, 10, 71, 41));
        bang_label_1->setFont(font);
        stackedWidget->addWidget(page_bang);
        page_set = new QWidget();
        page_set->setObjectName(QString::fromUtf8("page_set"));
        page_set->setMinimumSize(QSize(480, 640));
        stackedWidget_2 = new QStackedWidget(page_set);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(0, 0, 480, 640));
        stackedWidget_2->setMinimumSize(QSize(480, 640));
        page_set_2 = new QWidget();
        page_set_2->setObjectName(QString::fromUtf8("page_set_2"));
        page_set_2->setMinimumSize(QSize(480, 640));
        set_label_3 = new QLabel(page_set_2);
        set_label_3->setObjectName(QString::fromUtf8("set_label_3"));
        set_label_3->setGeometry(QRect(20, 350, 441, 20));
        set_shouSuo = new QPushButton(page_set_2);
        set_shouSuo->setObjectName(QString::fromUtf8("set_shouSuo"));
        set_shouSuo->setGeometry(QRect(410, 22, 41, 21));
        set_my = new QPushButton(page_set_2);
        set_my->setObjectName(QString::fromUtf8("set_my"));
        set_my->setGeometry(QRect(30, 590, 75, 31));
        set_shouCang = new QPushButton(page_set_2);
        set_shouCang->setObjectName(QString::fromUtf8("set_shouCang"));
        set_shouCang->setGeometry(QRect(80, 250, 311, 31));
        set_video = new QPushButton(page_set_2);
        set_video->setObjectName(QString::fromUtf8("set_video"));
        set_video->setGeometry(QRect(380, 590, 75, 31));
        set_label_1 = new QLabel(page_set_2);
        set_label_1->setObjectName(QString::fromUtf8("set_label_1"));
        set_label_1->setGeometry(QRect(190, 20, 101, 21));
        set_label_1->setFont(font);
        set_bang = new QPushButton(page_set_2);
        set_bang->setObjectName(QString::fromUtf8("set_bang"));
        set_bang->setGeometry(QRect(290, 590, 75, 31));
        set_label_4 = new QLabel(page_set_2);
        set_label_4->setObjectName(QString::fromUtf8("set_label_4"));
        set_label_4->setGeometry(QRect(20, 370, 141, 21));
        set_label_4->setFont(font1);
        set_music = new QPushButton(page_set_2);
        set_music->setObjectName(QString::fromUtf8("set_music"));
        set_music->setGeometry(QRect(210, 580, 61, 41));
        set_like = new QPushButton(page_set_2);
        set_like->setObjectName(QString::fromUtf8("set_like"));
        set_like->setGeometry(QRect(80, 410, 311, 31));
        set_like->setFont(font2);
        set_like->setText(QString::fromUtf8("   \346\234\200\345\226\234\346\254\242\347\232\204\351\237\263\344\271\220"));
        set_jingXuan = new QPushButton(page_set_2);
        set_jingXuan->setObjectName(QString::fromUtf8("set_jingXuan"));
        set_jingXuan->setGeometry(QRect(120, 590, 75, 31));
        set_label_2 = new QLabel(page_set_2);
        set_label_2->setObjectName(QString::fromUtf8("set_label_2"));
        set_label_2->setGeometry(QRect(160, 60, 41, 21));
        set_label_2->setFont(font3);
        set_bengDi = new QPushButton(page_set_2);
        set_bengDi->setObjectName(QString::fromUtf8("set_bengDi"));
        set_bengDi->setGeometry(QRect(80, 150, 311, 31));
        set_zuiJin = new QPushButton(page_set_2);
        set_zuiJin->setObjectName(QString::fromUtf8("set_zuiJin"));
        set_zuiJin->setGeometry(QRect(80, 200, 311, 31));
        set_return_1 = new QPushButton(page_set_2);
        set_return_1->setObjectName(QString::fromUtf8("set_return_1"));
        set_return_1->setGeometry(QRect(20, 20, 41, 23));
        set_download = new QPushButton(page_set_2);
        set_download->setObjectName(QString::fromUtf8("set_download"));
        set_download->setGeometry(QRect(80, 300, 311, 31));
        textBrowser_4 = new QTextBrowser(page_set_2);
        textBrowser_4->setObjectName(QString::fromUtf8("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(80, 60, 61, 51));
        scrollArea = new QScrollArea(page_set_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 20, 181, 561));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 179, 559));
        set_return = new QPushButton(scrollAreaWidgetContents);
        set_return->setObjectName(QString::fromUtf8("set_return"));
        set_return->setGeometry(QRect(120, 10, 51, 23));
        set_qianDao = new QPushButton(scrollAreaWidgetContents);
        set_qianDao->setObjectName(QString::fromUtf8("set_qianDao"));
        set_qianDao->setGeometry(QRect(30, 60, 101, 21));
        set_sleep = new QPushButton(scrollAreaWidgetContents);
        set_sleep->setObjectName(QString::fromUtf8("set_sleep"));
        set_sleep->setGeometry(QRect(30, 100, 101, 21));
        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget_2->addWidget(page_set_2);
        set_music->raise();
        set_label_3->raise();
        set_shouSuo->raise();
        set_my->raise();
        set_shouCang->raise();
        set_video->raise();
        set_label_1->raise();
        set_bang->raise();
        set_label_4->raise();
        set_like->raise();
        set_jingXuan->raise();
        set_label_2->raise();
        set_bengDi->raise();
        set_zuiJin->raise();
        set_return_1->raise();
        set_download->raise();
        textBrowser_4->raise();
        scrollArea->raise();
        stackedWidget->addWidget(page_set);

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(4);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        my_label_3->setText(QCoreApplication::translate("Widget", "--------------------------------------------------------------------------", nullptr));
        my_my->setText(QCoreApplication::translate("Widget", "\346\210\221\347\232\204", nullptr));
        my_shouCang->setText(QCoreApplication::translate("Widget", "\346\224\266\350\227\217\345\244\271", nullptr));
        my_video->setText(QCoreApplication::translate("Widget", "\350\247\206\351\242\221", nullptr));
        my_label_1->setText(QCoreApplication::translate("Widget", "\346\210\221\347\232\204\351\237\263\344\271\220", nullptr));
        my_bang->setText(QCoreApplication::translate("Widget", "\346\246\234\345\215\225", nullptr));
        my_label_2->setText(QCoreApplication::translate("Widget", "\346\210\221\345\210\233\345\273\272\347\232\204\346\255\214\345\215\225", nullptr));
        my_music->setText(QCoreApplication::translate("Widget", "\351\237\263\344\271\220", nullptr));
        my_like->setText(QCoreApplication::translate("Widget", "   \346\234\200\345\226\234\346\254\242\347\232\204\351\237\263\344\271\220", nullptr));
        my_jingXuan->setText(QCoreApplication::translate("Widget", "\347\262\276\351\200\211", nullptr));
        my_label_4->setText(QCoreApplication::translate("Widget", "\347\224\250\346\210\267\357\274\232", nullptr));
        my_bengDi->setText(QCoreApplication::translate("Widget", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        my_zuiJing->setText(QCoreApplication::translate("Widget", "\346\234\200\350\277\221\346\222\255\346\224\276", nullptr));
        my_return->setText(QCoreApplication::translate("Widget", "-", nullptr));
        my_download->setText(QCoreApplication::translate("Widget", "\344\270\213\350\275\275\347\256\241\347\220\206", nullptr));
        my_name->setText(QString());
        my_shouSuo->setText(QCoreApplication::translate("Widget", "\346\220\234\347\264\242", nullptr));
        bengDi_label->setText(QCoreApplication::translate("Widget", "\346\234\254\345\234\260\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
        bengDi_addMusic->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240\351\237\263\344\271\220", nullptr));
        bengDi_my->setText(QCoreApplication::translate("Widget", "\346\210\221\347\232\204", nullptr));
        bengDi_jingXue->setText(QCoreApplication::translate("Widget", "\347\262\276\351\200\211", nullptr));
        bengDi_music->setText(QCoreApplication::translate("Widget", "\351\237\263\344\271\220", nullptr));
        bengDi_bangDan->setText(QCoreApplication::translate("Widget", "\346\246\234\345\215\225", nullptr));
        bengDi_shiPing->setText(QCoreApplication::translate("Widget", "\350\247\206\351\242\221", nullptr));
        music_return->setText(QCoreApplication::translate("Widget", "\350\277\224\345\233\236", nullptr));
        playBtn->setText(QCoreApplication::translate("Widget", "\346\222\255\346\224\276", nullptr));
        timeLabel->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("Widget", "\345\215\225\346\233\262\345\276\252\347\216\257", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Widget", "\351\232\217\346\234\272\346\222\255\346\224\276", nullptr));
        comboBox->setItemText(2, QString());

        music_up->setText(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\346\233\262", nullptr));
        music_down->setText(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\346\233\262", nullptr));
        music_list->setText(QCoreApplication::translate("Widget", "\345\210\227\350\241\250", nullptr));
        music_text->setText(QString());
        music_photo->setText(QString());
        bang_my->setText(QCoreApplication::translate("Widget", "\346\210\221\347\232\204", nullptr));
        pushButton_40->setText(QCoreApplication::translate("Widget", "\347\262\276\351\200\211", nullptr));
        bang_music->setText(QCoreApplication::translate("Widget", "\351\237\263\344\271\220", nullptr));
        bang_bang->setText(QCoreApplication::translate("Widget", "\346\246\234\345\215\225", nullptr));
        bang_video->setText(QCoreApplication::translate("Widget", "\350\247\206\351\242\221", nullptr));
        bang_label_1->setText(QCoreApplication::translate("Widget", "\346\216\222\350\241\214\346\246\234", nullptr));
        set_label_3->setText(QCoreApplication::translate("Widget", "--------------------------------------------------------------------------", nullptr));
        set_shouSuo->setText(QCoreApplication::translate("Widget", "\346\220\234\347\264\242", nullptr));
        set_my->setText(QCoreApplication::translate("Widget", "\346\210\221\347\232\204", nullptr));
        set_shouCang->setText(QCoreApplication::translate("Widget", "\346\224\266\350\227\217\345\244\271", nullptr));
        set_video->setText(QCoreApplication::translate("Widget", "\350\247\206\351\242\221", nullptr));
        set_label_1->setText(QCoreApplication::translate("Widget", "\346\210\221\347\232\204\351\237\263\344\271\220", nullptr));
        set_bang->setText(QCoreApplication::translate("Widget", "\346\246\234\345\215\225", nullptr));
        set_label_4->setText(QCoreApplication::translate("Widget", "\346\210\221\345\210\233\345\273\272\347\232\204\346\255\214\345\215\225", nullptr));
        set_music->setText(QCoreApplication::translate("Widget", "\351\237\263\344\271\220", nullptr));
        set_jingXuan->setText(QCoreApplication::translate("Widget", "\347\262\276\351\200\211", nullptr));
        set_label_2->setText(QCoreApplication::translate("Widget", "\347\224\250\346\210\267\357\274\232", nullptr));
        set_bengDi->setText(QCoreApplication::translate("Widget", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        set_zuiJin->setText(QCoreApplication::translate("Widget", "\346\234\200\350\277\221\346\222\255\346\224\276", nullptr));
        set_return_1->setText(QCoreApplication::translate("Widget", "\342\200\224\342\200\224", nullptr));
        set_download->setText(QCoreApplication::translate("Widget", "\344\270\213\350\275\275\347\256\241\347\220\206", nullptr));
        set_return->setText(QCoreApplication::translate("Widget", "\350\277\224\345\233\236", nullptr));
        set_qianDao->setText(QCoreApplication::translate("Widget", "\346\257\217\346\227\245\347\255\276\345\210\260", nullptr));
        set_sleep->setText(QCoreApplication::translate("Widget", "\347\235\241\347\234\240\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
