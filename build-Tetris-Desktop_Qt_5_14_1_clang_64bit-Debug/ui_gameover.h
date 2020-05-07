/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GameOver
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *GameOver)
    {
        if (GameOver->objectName().isEmpty())
            GameOver->setObjectName(QString::fromUtf8("GameOver"));
        GameOver->resize(350, 400);
        GameOver->setMinimumSize(QSize(350, 400));
        GameOver->setMaximumSize(QSize(350, 400));
        GameOver->setStyleSheet(QString::fromUtf8("background-image: url(:/gameooover.png);"));
        pushButton = new QPushButton(GameOver);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 310, 150, 80));
        pushButton->setMinimumSize(QSize(150, 80));
        pushButton->setMaximumSize(QSize(130, 50));
        pushButton->setStyleSheet(QString::fromUtf8("border: none;\n"
"background: rgba(255,255,255,0);"));
        pushButton_2 = new QPushButton(GameOver);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 0, 130, 50));
        pushButton_2->setMinimumSize(QSize(130, 50));
        pushButton_2->setMaximumSize(QSize(130, 50));
        pushButton_2->setStyleSheet(QString::fromUtf8("border: none;\n"
"background: rgba(255,255,255,0);"));

        retranslateUi(GameOver);

        QMetaObject::connectSlotsByName(GameOver);
    } // setupUi

    void retranslateUi(QDialog *GameOver)
    {
        GameOver->setWindowTitle(QCoreApplication::translate("GameOver", "Dialog", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameOver: public Ui_GameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
