/********************************************************************************
** Form generated from reading UI file 'textfinder.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTFINDER_H
#define UI_TEXTFINDER_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextFinder
{
public:
    QWidget *centralWidget;
    QTextEdit *SearchText;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *Keyword;
    QPushButton *SearchButton;
    QPushButton *ClearButton;
    QWebView *webView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *URLEdit;
    QPushButton *AddButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *TextFinder)
    {
        if (TextFinder->objectName().isEmpty())
            TextFinder->setObjectName(QStringLiteral("TextFinder"));
        TextFinder->resize(1133, 680);
        centralWidget = new QWidget(TextFinder);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SearchText = new QTextEdit(centralWidget);
        SearchText->setObjectName(QStringLiteral("SearchText"));
        SearchText->setGeometry(QRect(20, 150, 1081, 151));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 0, 1081, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        Keyword = new QLineEdit(layoutWidget);
        Keyword->setObjectName(QStringLiteral("Keyword"));
        Keyword->setEnabled(true);

        horizontalLayout->addWidget(Keyword);

        SearchButton = new QPushButton(layoutWidget);
        SearchButton->setObjectName(QStringLiteral("SearchButton"));

        horizontalLayout->addWidget(SearchButton);

        ClearButton = new QPushButton(centralWidget);
        ClearButton->setObjectName(QStringLiteral("ClearButton"));
        ClearButton->setGeometry(QRect(1010, 310, 99, 27));
        webView = new QWebView(centralWidget);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setGeometry(QRect(20, 350, 1091, 231));
        webView->setUrl(QUrl(QStringLiteral("about:blank")));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 80, 1081, 61));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        URLEdit = new QLineEdit(widget);
        URLEdit->setObjectName(QStringLiteral("URLEdit"));

        horizontalLayout_2->addWidget(URLEdit);

        AddButton = new QPushButton(widget);
        AddButton->setObjectName(QStringLiteral("AddButton"));

        horizontalLayout_2->addWidget(AddButton);

        TextFinder->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TextFinder);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1133, 25));
        TextFinder->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TextFinder);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TextFinder->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(TextFinder);

        QMetaObject::connectSlotsByName(TextFinder);
    } // setupUi

    void retranslateUi(QMainWindow *TextFinder)
    {
        TextFinder->setWindowTitle(QApplication::translate("TextFinder", "TextFinder", 0));
        label->setText(QApplication::translate("TextFinder", "Keyword: ", 0));
        SearchButton->setText(QApplication::translate("TextFinder", "Search", 0));
        ClearButton->setText(QApplication::translate("TextFinder", "Clear", 0));
        label_2->setText(QApplication::translate("TextFinder", "URL:", 0));
        AddButton->setText(QApplication::translate("TextFinder", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class TextFinder: public Ui_TextFinder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTFINDER_H
