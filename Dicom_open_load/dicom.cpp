#include "dicom.h"
#include"dcmtk/config/osconfig.h"
#include"dcmtk/dcmdata/dctk.h"

#include "dcmtk/ofstd/ofstdinc.h"



using namespace std;

DcmFileFormat fileformat;
OFCondition status= fileformat.loadFile("/home/jeannypan/Documents/dcmtk_image/real_dicom.dcm");

Dicom::Dicom()
{


}

void Dicom::LoadFile()
{
    DcmFileFormat fileformat;
    fileformat.loadFile("/home/jeannypan/Documents/dcmtk_image/real_dicom.dcm");



}

int Dicom::MetaInfo()
{
    if(status.good())
    {

    }

    return 0;

}


int Dicom::PatientsData(status)
{
        //Dicom::LoadFile();
         //DcmFileFormat fileformat;
        //OFCondition status= fileformat;
        if(status.good())
        {
            OFString patientsName,patientsID,patientsSex,patientsBirthdate;
            if(fileformat.getDataset()->findAndGetOFString(DCM_PatientName,patientsName).good())
            {
                cout << "Patients Name：" << patientsName << endl;

            } else
                cerr << "Error:cannot access Patient Name"<<endl;

            if(fileformat.getDataset()->findAndGetOFString(DCM_PatientBirthDate,patientsBirthdate).good())
            {
                cout << "Patient Birth Date：" << patientsName << endl;

            } else
                cerr << "Error:cannot access Patient Birth Date"<<endl;

            if(fileformat.getDataset()->findAndGetOFString(DCM_PatientID,patientsID).good())
            {
                cout << "Patients ID：" << patientsID << endl;

            } else
                cerr << "Error:cannot access Patients Sex"<<endl;

            if(fileformat.getDataset()->findAndGetOFString(DCM_PatientSex,patientsSex).good())
            {
                cout << "Patients Sex：" << patientsSex << endl;

            } else
                cerr << "Error:cannot access Patient Sex"<<endl;

        } else
            cerr << "Error: cannot read DICOM file"<<status.text()<<endl;



        cout << "hallo world"<<endl;
        return 0;
}

//OFCondition status;
//DcmFileFormat fileformat;
// //            Qstring location = ui->Qline_localPath->text();
// //            QUrl localpath;
// //            localpath.isLocalFile(location);
// //QString localpath =CRL.readLine();
//char temp;
//cin >> temp;


// //Class Objet (tmp.c_str());

//status=fileformat.loadFile(temp,EXS_Unknown,EGL_noChange,DCM_MaxReadLength,ERM_autoDetect);
//if (status.good())
//{
//        OFString sopClassUID, xferUID;
//        if(fileformat.getMetaInfo()->findAndGetOFString(DCM_MediaStorageSOPClassUID,sopClassUID).good())

//             cout<< "SOP Class UID:" << sopClassUID << OFendl;
//        if(fileformat.getMetaInfo() ->findAndGetOFString(DCM_TransferSyntaxUID,xferUID).good())
//            cout << "Transfer Syntax UID:" << xferUID << OFendl;
//        fileformat.print(cout);

//}
//       return 0;




//const int paramCount = cmd.getParamCount();
// /* iterate over all input filenames */
//for (int i = 1; i <= paramCount; i++)
//{
//  cmd.getParam(i, paramValue);
//  /* search directory recursively (if required) */
//  if (OFStandard::dirExists(paramValue))
//  {
//    if (scanDir)
//      OFStandard::searchDirectoryRecursively(paramValue, inputFiles, scanPattern, "" /*dirPrefix*/, recurse);
//    else
//      OFLOG_WARN(dcmdumpLogger, "ignoring directory because option --scan-directories is not set: " << paramValue);
//  } else
//    inputFiles.push_back(paramValue);
//}
// /* check whether there are any input files at all */
//if (inputFiles.empty())
//{
//  OFLOG_FATAL(dcmdumpLogger, "no input files to be dumped");
//  return 1;
//}

