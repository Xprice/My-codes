/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TcpClient
{
public:
    QLabel *tcpClientStatusLabel;
    QProgressBar *progressBar;
    QPushButton *tcpClientCancleBtn;
    QPushButton *tcpClientCloseBtn;

    void setupUi(QDialog *TcpClient)
    {
        if (TcpClient->objectName().isEmpty())
            TcpClient->setObjectName(QString::fromUtf8("TcpClient"));
        TcpClient->resize(512, 185);
        tcpClientStatusLabel = new QLabel(TcpClient);
        tcpClientStatusLabel->setObjectName(QString::fromUtf8("tcpClientStatusLabel"));
        tcpClientStatusLabel->setGeometry(QRect(50, 20, 391, 71));
        QFont font;
        font.setPointSize(12);
        tcpClientStatusLabel->setFont(font);
        progressBar = new QProgressBar(TcpClient);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(50, 110, 441, 23));
        progressBar->setValue(0);
        tcpClientCancleBtn = new QPushButton(TcpClient);
        tcpClientCancleBtn->setObjectName(QString::fromUtf8("tcpClientCancleBtn"));
        tcpClientCancleBtn->setGeometry(QRect(80, 150, 121, 26));
        tcpClientCloseBtn = new QPushButton(TcpClient);
        tcpClientCloseBtn->setObjectName(QString::fromUtf8("tcpClientCloseBtn"));
        tcpClientCloseBtn->setGeometry(QRect(290, 150, 121, 26));

        retranslateUi(TcpClient);

        QMetaObject::connectSlotsByName(TcpClient);
    } // setupUi

    void retranslateUi(QDialog *TcpClient)
    {
        TcpClient->setWindowTitle(QApplication::translate("TcpClient", "\346\216\245\346\224\266\347\253\257", nullptr));
        tcpClientStatusLabel->setText(QApplication::translate("TcpClient", "      \347\255\211\345\276\205\346\216\245\345\217\227\346\226\207\344\273\266........", nullptr));
        tcpClientCancleBtn->setText(QApplication::translate("TcpClient", "\345\217\226\346\266\210", nullptr));
        tcpClientCloseBtn->setText(QApplication::translate("TcpClient", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpClient: public Ui_TcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
