#ifndef DICOM_H
#define DICOM_H

#include <QObject>

class Dicom
{
public:
    Dicom();
    int PatientsData();
    void LoadFile();
    int DRTInfo();
    int DRTContourSeq();
};

#endif // DICOM_H
