#ifndef TEXTFINDER_H
#define TEXTFINDER_H

#include <QMainWindow>
#include"download.h"
#include<QObject>
#include<QUrl>


namespace Ui {
class TextFinder;
}

class TextFinder : public QMainWindow
{
    Q_OBJECT

public:
    explicit TextFinder(QWidget *parent = 0);
    ~TextFinder();
    void loadTextFile();


private slots:
    void on_SearchButton_clicked();

    void on_ClearButton_clicked();

    void on_AddButton_clicked();

private:
    Ui::TextFinder *ui;


};


#endif // TEXTFINDER_H
