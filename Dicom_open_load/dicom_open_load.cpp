#include "dicom_open_load.h"
#include "ui_dicom_open_load.h"
#include"dicom.h"
#include<QString>

Dicom_open_load::Dicom_open_load(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dicom_open_load)
{
    ui->setupUi(this);
}

Dicom_open_load::~Dicom_open_load()
{
    delete ui;
}

void Dicom_open_load::on_pushButton_clicked()
{

    Dicom d;
    d.PatientsData();
    //QString s;

    //QString Data=QString::number(d.PatientsData());



}
