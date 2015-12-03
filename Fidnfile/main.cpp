#include <QApplication>
#include "window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    window wind;
    wind.show();

    return app.exec();
}

