#include "opendcm.h"
#include <QApplication>
#include"dcmtk/dcmdata/dcfilefo.h"
#include"dcmtk/ofstd/ofcond.h"
#include"dcmtk/dcmdata/dcfilefo.h"
#include "dcmtk/config/osconfig.h"

#include "dcmtk/dcmdata/dctk.h"

#include "dcmtk/dcmdata/dcistrmf.h"
#include "dcmtk/ofstd/ofcond.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Opendcm d;
    d.show();


    return a.exec();

//        OFCondition status;
//        DcmFileFormat fileformat;
//        status=fileformat.loadFile("LungCT.dcm",EXS_Unknown,EGL_noChange,DCM_MaxReadLength,ERM_autoDetect);
//        if (status.good())
//        {
//                OFString sopClassUID, xferUID;
//                if(fileformat.getMetaInfo()->findAndGetOFString(DCM_MediaStorageSOPClassUID,sopClassUID).good())
//                    COUT << "SOP Class UID:" << sopClassUID << OFendl;
//                if(fileformat.getMetaInfo() ->findAndGetOFString(DCM_TransferSyntaxUID,xferUID).good())
//                    COUT << "Transfer Syntax UID:" << xferUID << OFendl;
//                fileformat.print(COUT);

//        }
//               return 0;

}
