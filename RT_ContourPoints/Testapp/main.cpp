#include <QCoreApplication>

#include"dicom.h"



using namespace std;


int main()
{
    // QApplication a(argc, argv);
    Dicom d;
    //d.LoadFile();
    //d.PatientsData();
    d.DRTInfo();
    d.DRTContourSeq();

    return 0;

    // return a.exec();
}

