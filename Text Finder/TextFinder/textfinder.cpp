#include "textfinder.h"
#include "ui_textfinder.h"
#include<QFile>
#include<QTextStream>
#include <QMessageBox>
#include<QtWebKitWidgets/QWebView>
#include<QUrl>




TextFinder::TextFinder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TextFinder)
{
    ui->setupUi(this);
    loadTextFile();

}


TextFinder::~TextFinder()
{
    delete ui;
}

void TextFinder::on_SearchButton_clicked()
{

    QString searchString= ui->Keyword->text();
    ui->SearchText->find(searchString,QTextDocument::FindWholeWords );
    ui->webView->findText(searchString,QWebPage::HighlightAllOccurrences);


}


void TextFinder::loadTextFile()
{
    QFile inputFile(":/input.txt");
    inputFile.open(QIODevice::ReadOnly);

    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();

    ui->SearchText->setPlainText(line);
    QTextCursor cursor=ui->SearchText->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}





void TextFinder::on_ClearButton_clicked()
{
    //QString clear= ui->Keyword->text();
    QString clear="";
    ui->Keyword->clear();
    ui->SearchText->clear();


    //t= new TextFinder(this);

}


void TextFinder::on_AddButton_clicked()
{
    QString website=ui->URLEdit->text();
    QUrl web="http://"+ website;
    ui->webView->load(QUrl(web));


}
