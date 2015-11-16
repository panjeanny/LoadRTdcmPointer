#ifndef DICOM_OPEN_LOAD_H
#define DICOM_OPEN_LOAD_H

#include <QMainWindow>

namespace Ui {
class Dicom_open_load;
}

class Dicom_open_load : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dicom_open_load(QWidget *parent = 0);
    ~Dicom_open_load();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dicom_open_load *ui;
};

#endif // DICOM_OPEN_LOAD_H
