#include "opendcm.h"
#include "ui_opendcm.h"

#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmdata/dctk.h"
#include"dcmtk/ofstd/ofstring.h"

#include<QFile>
#include<QTextStream>
#include <QMessageBox>
#include<QtWebKitWidgets/QWebView>
#include<QUrl>
#include<QtCore>
#include<QtGui>
#include<QString>

#define _HAVE_STD_STRING

using namespace std;

Opendcm::Opendcm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Opendcm)
{
    ui->setupUi(this);
    loadDcmFile();
}

Opendcm::~Opendcm()
{
    delete ui;
}



int Opendcm::loadDcmFile()
{

        // OFCondition status;
        DcmFileFormat fileformat;
        fileformat.loadFile("/home/jeannypan/Documents/dcmtk_image/real_dicom.dcm");
        QString sopClass,;
        fileformat.getMetaInfo()->findAndGetString(DCM_MediaStorageSOPClassUID),sopClass





//        QString out;
//        string sopClass;
//        status= fileformat.loadFile("/home/jeannypan/Documents/dcmtk_image/real_dicom.dcm");
//        if (status.good())
//        {
//                OFString sopClassUID, xferUID;
//                //if(fileformat.getMetaInfo()->findAndGetString(DCM_MediaStorageSOPClassUID),sopClassUID).good())
//                if(fileformat.getMetaInfo()->findAndGetOFString(DCM_MediaStorageSOPClassUID,sopClassUID).good())

//                    //COUT << "SOP Class UID:" << sopClassUID << OFendl;
//                    sopClass =sopClassUID;
//                    sopClass = QString ::fromStdString(sopClass);
//                    //sopClass = QsopClassUID;
//                    //out="SOP Class UID:";
//                    //out += sopClass;

//                    ui->textEdit->setPlainText(sopClass);

//                //ui->textBrowser->out();

//                if(fileformat.getMetaInfo() ->findAndGetOFString(DCM_TransferSyntaxUID,xferUID).good())
//                    //COUT << "Transfer Syntax UID:" << xferUID << OFendl;
//                    out="SOP Class UID:";//+sopClassUID;
//                    ui->textEdit->setText(out);
//                //ui->textBrowser->out();
//                //fileformat.print(out);

//        } else
//        //cerr << "Error: cannot read DICOM file"<<status.text()<<endl;
//            out="Error: cannot read DICOM file";//+sopClassUID;
//            ui->textEdit->setPlainText(out);
//        //ui->textBrowser->out();


               return 0;

}






void Opendcm::on_pushButton_clicked()
{
//            DcmFileFormat fileformat;
//            Qstring location = ui->Qline_localPath->text();
//            QUrl localpath;
//            localpath.isLocalFile(location);



}


