#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QDir>
#include <QTextBrowser>
#include <QTextEdit>
#include <QTreeView>
#include <QListView>

class QComboBox;
class QLabel;
class QPushButton;
class QTableWidget;
class QTableWidgetItem;

class window : public QWidget
{
    Q_OBJECT

public:
    window(QWidget *parent = 0);
    void DRTContourSeq();




private slots:
    void browse();
    void find();
    void contour();
    void openFileOfItem(int row, int column);







private:
    QStringList findFiles(const QStringList &files, const QString &text);
    void showFiles(const QStringList &files);
    QPushButton *createButton(const QString &text, const char *member);
    QComboBox *createComboBox(const QString &text = QString());
    void createFilesTable();

    QComboBox *fileComboBox;
    QComboBox *textComboBox;
    QComboBox *directoryComboBox;
    QLabel *fileLabel;
    QLabel *textLabel;
    QLabel *directoryLabel;
    QLabel *filesFoundLabel;
    QPushButton *contourButton;
    QPushButton *browseButton;
    QPushButton *findButton;
    QTableWidget *filesTable;
    QTextEdit *textBox;
    QComboBox *itemComboBox;

    QTreeView *getPatientsTreeView;
    QTreeView *getStudiesTreeView;
    QTreeView *getSeriesTreeView;







    QDir currentDir;

};

#endif // WINDOW_H
