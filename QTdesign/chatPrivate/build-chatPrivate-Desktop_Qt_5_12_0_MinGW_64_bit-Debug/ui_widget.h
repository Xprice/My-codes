/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextBrowser *messageBrower;
    QFontComboBox *fontComBox;
    QComboBox *sizeComboBox;
    QToolButton *boldToolBtn;
    QToolButton *italicToolBtn;
    QToolButton *underlineToolBtn;
    QToolButton *colorToolBtn;
    QToolButton *sendToolBtn;
    QToolButton *saveToolBtn;
    QToolButton *clearToolBtn;
    QTextEdit *messageTextEdit;
    QTableWidget *userTableWidget;
    QPushButton *sendPushButton;
    QPushButton *exitPushButton;
    QLabel *userNumLabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(867, 434);
        messageBrower = new QTextBrowser(Widget);
        messageBrower->setObjectName(QString::fromUtf8("messageBrower"));
        messageBrower->setGeometry(QRect(10, 10, 451, 211));
        fontComBox = new QFontComboBox(Widget);
        fontComBox->setObjectName(QString::fromUtf8("fontComBox"));
        fontComBox->setGeometry(QRect(10, 230, 151, 30));
        sizeComboBox = new QComboBox(Widget);
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->setObjectName(QString::fromUtf8("sizeComboBox"));
        sizeComboBox->setGeometry(QRect(170, 230, 72, 30));
        boldToolBtn = new QToolButton(Widget);
        boldToolBtn->setObjectName(QString::fromUtf8("boldToolBtn"));
        boldToolBtn->setGeometry(QRect(250, 230, 30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        boldToolBtn->setIcon(icon);
        boldToolBtn->setIconSize(QSize(20, 20));
        boldToolBtn->setCheckable(true);
        boldToolBtn->setAutoRaise(true);
        italicToolBtn = new QToolButton(Widget);
        italicToolBtn->setObjectName(QString::fromUtf8("italicToolBtn"));
        italicToolBtn->setGeometry(QRect(280, 230, 30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        italicToolBtn->setIcon(icon1);
        italicToolBtn->setIconSize(QSize(20, 20));
        italicToolBtn->setCheckable(true);
        italicToolBtn->setAutoRaise(true);
        underlineToolBtn = new QToolButton(Widget);
        underlineToolBtn->setObjectName(QString::fromUtf8("underlineToolBtn"));
        underlineToolBtn->setGeometry(QRect(310, 230, 30, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/under.png"), QSize(), QIcon::Normal, QIcon::Off);
        underlineToolBtn->setIcon(icon2);
        underlineToolBtn->setIconSize(QSize(20, 20));
        underlineToolBtn->setCheckable(true);
        underlineToolBtn->setAutoRaise(true);
        colorToolBtn = new QToolButton(Widget);
        colorToolBtn->setObjectName(QString::fromUtf8("colorToolBtn"));
        colorToolBtn->setGeometry(QRect(340, 230, 30, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorToolBtn->setIcon(icon3);
        colorToolBtn->setIconSize(QSize(20, 20));
        colorToolBtn->setAutoRaise(true);
        sendToolBtn = new QToolButton(Widget);
        sendToolBtn->setObjectName(QString::fromUtf8("sendToolBtn"));
        sendToolBtn->setGeometry(QRect(370, 230, 30, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendToolBtn->setIcon(icon4);
        sendToolBtn->setIconSize(QSize(20, 20));
        sendToolBtn->setAutoRaise(true);
        saveToolBtn = new QToolButton(Widget);
        saveToolBtn->setObjectName(QString::fromUtf8("saveToolBtn"));
        saveToolBtn->setGeometry(QRect(400, 230, 30, 30));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveToolBtn->setIcon(icon5);
        saveToolBtn->setIconSize(QSize(20, 20));
        saveToolBtn->setAutoRaise(true);
        clearToolBtn = new QToolButton(Widget);
        clearToolBtn->setObjectName(QString::fromUtf8("clearToolBtn"));
        clearToolBtn->setGeometry(QRect(430, 230, 30, 30));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearToolBtn->setIcon(icon6);
        clearToolBtn->setIconSize(QSize(20, 20));
        clearToolBtn->setAutoRaise(true);
        messageTextEdit = new QTextEdit(Widget);
        messageTextEdit->setObjectName(QString::fromUtf8("messageTextEdit"));
        messageTextEdit->setGeometry(QRect(10, 270, 451, 101));
        userTableWidget = new QTableWidget(Widget);
        if (userTableWidget->columnCount() < 3)
            userTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        userTableWidget->setObjectName(QString::fromUtf8("userTableWidget"));
        userTableWidget->setGeometry(QRect(470, 10, 381, 361));
        userTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        userTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        userTableWidget->setShowGrid(false);
        sendPushButton = new QPushButton(Widget);
        sendPushButton->setObjectName(QString::fromUtf8("sendPushButton"));
        sendPushButton->setGeometry(QRect(100, 390, 80, 26));
        exitPushButton = new QPushButton(Widget);
        exitPushButton->setObjectName(QString::fromUtf8("exitPushButton"));
        exitPushButton->setGeometry(QRect(500, 390, 80, 26));
        userNumLabel = new QLabel(Widget);
        userNumLabel->setObjectName(QString::fromUtf8("userNumLabel"));
        userNumLabel->setGeometry(QRect(290, 390, 101, 26));

        retranslateUi(Widget);

        sizeComboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        fontComBox->setCurrentText(QApplication::translate("Widget", "\345\256\213\344\275\223", nullptr));
        sizeComboBox->setItemText(0, QApplication::translate("Widget", "9", nullptr));
        sizeComboBox->setItemText(1, QApplication::translate("Widget", "10", nullptr));
        sizeComboBox->setItemText(2, QApplication::translate("Widget", "11", nullptr));
        sizeComboBox->setItemText(3, QApplication::translate("Widget", "12", nullptr));
        sizeComboBox->setItemText(4, QApplication::translate("Widget", "13", nullptr));
        sizeComboBox->setItemText(5, QApplication::translate("Widget", "14", nullptr));
        sizeComboBox->setItemText(6, QApplication::translate("Widget", "15", nullptr));
        sizeComboBox->setItemText(7, QApplication::translate("Widget", "16", nullptr));
        sizeComboBox->setItemText(8, QApplication::translate("Widget", "17", nullptr));

#ifndef QT_NO_TOOLTIP
        boldToolBtn->setToolTip(QApplication::translate("Widget", "\345\212\240\347\262\227", nullptr));
#endif // QT_NO_TOOLTIP
        boldToolBtn->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        italicToolBtn->setToolTip(QApplication::translate("Widget", "\345\200\276\346\226\234", nullptr));
#endif // QT_NO_TOOLTIP
        italicToolBtn->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        underlineToolBtn->setToolTip(QApplication::translate("Widget", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_NO_TOOLTIP
        underlineToolBtn->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        colorToolBtn->setToolTip(QApplication::translate("Widget", "\346\233\264\346\224\271\351\242\234\350\211\262\345\255\227\344\275\223", nullptr));
#endif // QT_NO_TOOLTIP
        colorToolBtn->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        sendToolBtn->setToolTip(QApplication::translate("Widget", "\344\274\240\350\276\223\346\226\207\344\273\266", nullptr));
#endif // QT_NO_TOOLTIP
        sendToolBtn->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        saveToolBtn->setToolTip(QApplication::translate("Widget", "\344\277\235\345\255\230\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
#endif // QT_NO_TOOLTIP
        saveToolBtn->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        clearToolBtn->setToolTip(QApplication::translate("Widget", "\346\270\205\347\251\272\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
#endif // QT_NO_TOOLTIP
        clearToolBtn->setText(QApplication::translate("Widget", "...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = userTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = userTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget", "\344\270\273\346\234\272\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = userTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget", "IP\345\234\260\345\235\200", nullptr));
        sendPushButton->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        exitPushButton->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
        userNumLabel->setText(QApplication::translate("Widget", "\345\234\250\347\272\277\347\224\250\346\210\267:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
