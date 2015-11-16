#ifndef OPENDCM_H
#define OPENDCM_H

#include <QMainWindow>
#include<QObject>


namespace Ui {
class Opendcm;
}
class DcmFileFormat;

class Opendcm : public QMainWindow
{
    Q_OBJECT


public:
    explicit Opendcm(QWidget *parent = 0);
    ~Opendcm();
    int loadDcmFile();


private slots:
    void on_pushButton_clicked();

private:
    Ui::Opendcm *ui;
};

#endif // OPENDCM_H


