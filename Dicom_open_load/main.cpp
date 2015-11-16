#include "dicom_open_load.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dicom_open_load w;
    w.show();

    return a.exec();
}
