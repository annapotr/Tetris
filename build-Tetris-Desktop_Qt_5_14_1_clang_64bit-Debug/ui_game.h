/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QPushButton *Close_game;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_score;
    QSpacerItem *verticalSpacer;
    QLabel *label_high_score;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton;

    void setupUi(QDialog *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName(QString::fromUtf8("game"));
        game->resize(503, 574);
        game->setMinimumSize(QSize(503, 574));
        game->setMaximumSize(QSize(503, 574));
        game->setStyleSheet(QString::fromUtf8("background-image: url(:/background1.png);"));
        layoutWidget = new QWidget(game);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 20, 413, 527));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(layoutWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setBaseSize(QSize(265, 525));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/background.png);"));

        horizontalLayout->addWidget(graphicsView);

        verticalLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        verticalLayout->setSpacing(-1);
#endif
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(40, -1, -1, -1);
        Close_game = new QPushButton(layoutWidget);
        Close_game->setObjectName(QString::fromUtf8("Close_game"));
        Close_game->setStyleSheet(QString::fromUtf8("background-image: url(:/close.png);\n"
""));

        verticalLayout->addWidget(Close_game);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_score = new QLabel(layoutWidget);
        label_score->setObjectName(QString::fromUtf8("label_score"));
        label_score->setMaximumSize(QSize(150, 200));
        label_score->setStyleSheet(QString::fromUtf8("color:rgb(255, 69, 241);\n"
"font: 36pt \".SF NS Text\";"));
        label_score->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_score);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_high_score = new QLabel(layoutWidget);
        label_high_score->setObjectName(QString::fromUtf8("label_high_score"));
        label_high_score->setStyleSheet(QString::fromUtf8("background-image: url(:/high_score.png);\n"
"font: 36pt \".SF NS Text\";"));
        label_high_score->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_high_score);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("color:rgb(255, 95, 250);\n"
"font: 48pt \".SF NS Text\";"));

        verticalLayout->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(game);
        QObject::connect(Close_game, SIGNAL(clicked()), game, SLOT(close()));

        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QDialog *game)
    {
        game->setWindowTitle(QCoreApplication::translate("game", "Dialog", nullptr));
        Close_game->setText(QString());
        label_score->setText(QCoreApplication::translate("game", "Score", nullptr));
        label_high_score->setText(QString());
        pushButton->setText(QCoreApplication::translate("game", "||", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
