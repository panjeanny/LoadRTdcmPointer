#include "dicom.h"
#include"dcmtk/config/osconfig.h"
#include"dcmtk/dcmdata/dctk.h"

#include"dcmtk/dcmrt/seq/drtcs.h"
#include "dcmtk/ofstd/ofstdinc.h"
#include"dcmtk/dcmrt/drtdose.h"



using namespace std;



Dicom::Dicom()
{


}


void Dicom::LoadFile()
{
    DcmFileFormat fileformat;
    fileformat.loadFile("/home/jeannypan/Documents/dcmtk_image/real_dicom.dcm");



}

int Dicom::DRTContourSeq()
{


            DcmFileFormat fileformat;
            OFCondition status= fileformat.loadFile("/home/jeannypan/Documents/dcmtk_image/RSRT.dcm");



              if (status.good())
                {
                    signed long i =0;
                    DcmItem *roiitem = NULL;
                    DcmItem * contouritem = NULL;
                      while(fileformat.getDataset()->findAndGetSequenceItem(DCM_ROIContourSequence,roiitem,i++).good())
                      {
                          signed long j=0;

                          while(roiitem->findAndGetSequenceItem(DCM_ContourSequence, contouritem, j++).good())
                          {
                              Float64 n =0.0;
                              unsigned long k=0;

                              while (contouritem->findAndGetFloat64(DCM_ContourData, n, k++).good())
                              {

                                     cout<<n<<","<<endl;
                              }

                              //else cerr << "Error:cannot access Contoritem"<<endl;

                          } //else cerr << "Error:cannot find Contoritem"<<endl;

                          /*roiitem now points to some item in the ContourSequence
                           * There are differtnt ways to access the conzour Data.
                           * The following approach is simple but not the most efficienrt one.*/


                      }
                }

                return 0;




}
//                  OFString patientName;
//                  status = rtdose.getPatientName(patientName);
//                  if (status.good())
//                  {
//                    cout << "Patient's Name: " << patientName << endl;
//                  } else
//                    cerr << "Error: cannot access Patient's Name (" << status.text() << ")" << endl;
//                } else
//                  cerr << "Error: cannot read RT Dose object (" << status.text() << ")" << endl;




//                status = rtContourSeq.read(*fileformat.getMetaInfo());
//                if(status.good())
//                {
//                     DRTContourSequence rtContourSeq;

//                     OFString CurrentSequence;
//                     status=rtContourSeq.read(fileformat.getMetaInfo());
//                     if(status.good())
//                     {
//                         cout << "Current Item in the Sequence"<<CurrentSequence<<endl;
//                     } else
//                         cerr << "Cannot access current Item"<< status.text()<<endl;



//                } else
//                    cerr << "Error: cannot read RT DICOM file"<<status.text()<<endl;
//             } else
//                cerr << "Error:cannot load DICOM file"<<status.text()<<endl;
//                cout << "hallo world"<<endl;
//            return 0;


//}






int Dicom::DRTInfo()
{


            DcmFileFormat fileformat;
            OFCondition status= fileformat.loadFile("/home/jeannypan/Documents/dcmtk_image/RSRT.dcm");
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


int Dicom::PatientsData()
{

        DcmFileFormat fileformat;
        OFCondition status= fileformat.loadFile("/home/jeannypan/Documents/dcmtk_image/real_dicom.dcm");
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

