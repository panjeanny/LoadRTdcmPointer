#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmdata/dctk.h"
#include"dcmtk/dcmimage/diregist.h"

int main()
{

    DicomImage *image = new DicomImage("IM-0001-0001.dcm");
    if (image != NULL)
    {
      if (image->getStatus() == EIS_Normal)
      {
        Uint8 *pixelData = (Uint8 *)(image->getOutputData(8 /* bits per sample */));
        if (pixelData != NULL)
        {
          /* do something useful with the pixel data */
        }
      } else
        cerr << "Error: cannot load DICOM image (" << DicomImage::getString(image->getStatus()) << ")" << endl;
    }
    delete image;

}
