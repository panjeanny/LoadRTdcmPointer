#include "window.h"


#include"dcmtk/config/osconfig.h"
#include"dcmtk/dcmdata/dctk.h"

#include"dcmtk/dcmrt/seq/drtcs.h"
#include "dcmtk/ofstd/ofstdinc.h"
#include "dcmtk/dcmrt/drtdose.h"


#include <QtWidgets>

using namespace std;

window::window(QWidget *parent)
{

    browseButton = createButton(tr("&Browse..."), SLOT(browse()));
    findButton = createButton(tr("&Find"), SLOT(find()));

    fileComboBox = createComboBox(tr("*"));
    textComboBox = createComboBox();
    directoryComboBox = createComboBox(QDir::currentPath());
    textBox =createComboBox();

    fileLabel = new QLabel(tr("Named:"));
    textLabel = new QLabel(tr("Containing text:"));
    directoryLabel = new QLabel(tr("In directory:"));
    filesFoundLabel = new QLabel;

    createFilesTable();

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(fileLabel, 0, 0);
    mainLayout->addWidget(fileComboBox, 0, 1, 1, 2);
    mainLayout->addWidget(textLabel, 1, 0);
    mainLayout->addWidget(textComboBox, 1, 1, 1, 2);
    mainLayout->addWidget(directoryLabel, 2, 0);
    mainLayout->addWidget(directoryComboBox, 2, 1);
    mainLayout->addWidget(browseButton, 2, 2);
    mainLayout->addWidget(filesTable, 3, 0, 1, 3);
    mainLayout->addWidget(filesFoundLabel, 4, 0, 1, 2);
    mainLayout->addWidget(findButton, 4, 2);
    mainLayout->addWidget(textBox,1,1,5,5);
    setLayout(mainLayout);

    setWindowTitle(tr("Find Files"));
    resize(700, 300);
}

void window::browse()
{
    QString directory = QFileDialog::getExistingDirectory(this,
                               tr("Find Files"), QDir::currentPath());

    if (!directory.isEmpty()) {
        if (directoryComboBox->findText(directory) == -1)
            directoryComboBox->addItem(directory);
        directoryComboBox->setCurrentIndex(directoryComboBox->findText(directory));
    }
}

static void updateComboBox(QComboBox *comboBox)
{
    if (comboBox->findText(comboBox->currentText()) == -1)
        comboBox->addItem(comboBox->currentText());
}


void window::find()
{
    filesTable->setRowCount(0);

    QString fileName = fileComboBox->currentText();
    QString text = textComboBox->currentText();
    QString path = directoryComboBox->currentText();

    updateComboBox(fileComboBox);
    updateComboBox(textComboBox);
    updateComboBox(directoryComboBox);

    currentDir = QDir(path);
    QStringList files;
    if (fileName.isEmpty())
        fileName = "*";
    files = currentDir.entryList(QStringList(fileName),
                                 QDir::Files | QDir::NoSymLinks);

    if (!text.isEmpty())
        files = findFiles(files, text);
    showFiles(files);
}

int window::DRTContourSeq()
{

    QString directory = QFileDialog::getExistingDirectory(this,
                               tr("Find Files"), QDir::currentPath());

    if (!directory.isEmpty()) {
        if (directoryComboBox->findText(directory) == -1)
            directoryComboBox->addItem(directory);
        directoryComboBox->setCurrentIndex(directoryComboBox->findText(directory));
    }
    QString path = directoryComboBox->currentText();


    DcmFileFormat fileformat;
    OFCondition status =fileformat.loadFile(path.toUtf8().data());



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


}





QStringList window::findFiles(const QStringList &files, const QString &text)
{
    QProgressDialog progressDialog(this);
    progressDialog.setCancelButtonText(tr("&Cancel"));
    progressDialog.setRange(0, files.size());
    progressDialog.setWindowTitle(tr("Find Files"));

    QStringList foundFiles;

    for (int i = 0; i < files.size(); ++i) {
        progressDialog.setValue(i);
        progressDialog.setLabelText(tr("Searching file number %1 of %2...")
                                    .arg(i).arg(files.size()));
        qApp->processEvents();

        if (progressDialog.wasCanceled())
            break;

        QFile file(currentDir.absoluteFilePath(files[i]));

        if (file.open(QIODevice::ReadOnly)) {
            QString line;
            QTextStream in(&file);
            while (!in.atEnd()) {
                if (progressDialog.wasCanceled())
                    break;
                line = in.readLine();
                if (line.contains(text)) {
                    foundFiles << files[i];
                    break;
                }
            }
        }
    }
    return foundFiles;
}

void window::showFiles(const QStringList &files)
{
    for (int i = 0; i < files.size(); ++i) {
        QFile file(currentDir.absoluteFilePath(files[i]));
        qint64 size = QFileInfo(file).size();

        QTableWidgetItem *fileNameItem = new QTableWidgetItem(files[i]);
        fileNameItem->setFlags(fileNameItem->flags() ^ Qt::ItemIsEditable);
        QTableWidgetItem *sizeItem = new QTableWidgetItem(tr("%1 KB")
                                             .arg(int((size + 1023) / 1024)));
        sizeItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        sizeItem->setFlags(sizeItem->flags() ^ Qt::ItemIsEditable);

        int row = filesTable->rowCount();
        filesTable->insertRow(row);
        filesTable->setItem(row, 0, fileNameItem);
        filesTable->setItem(row, 1, sizeItem);
    }
    filesFoundLabel->setText(tr("%1 file(s) found").arg(files.size()) +
                             (" (Double click on a file to open it)"));
    filesFoundLabel->setWordWrap(true);
}

QPushButton *window::createButton(const QString &text, const char *member)
{
    QPushButton *button = new QPushButton(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

QComboBox *window::createComboBox(const QString &text)
{
    QComboBox *comboBox = new QComboBox;
    comboBox->setEditable(true);
    comboBox->addItem(text);
    comboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    return comboBox;
}

void window::createFilesTable()
{
    filesTable = new QTableWidget(0, 2);
    filesTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    QStringList labels;
    labels << tr("Filename") << tr("Size");
    filesTable->setHorizontalHeaderLabels(labels);
    filesTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    filesTable->verticalHeader()->hide();
    filesTable->setShowGrid(false);

    connect(filesTable, SIGNAL(cellActivated(int,int)),
            this, SLOT(openFileOfItem(int,int)));
}


void window::openFileOfItem(int row, int /* column */)
{
    QTableWidgetItem *item = filesTable->item(row, 0);

    QDesktopServices::openUrl(QUrl::fromLocalFile(currentDir.absoluteFilePath(item->text())));
}
