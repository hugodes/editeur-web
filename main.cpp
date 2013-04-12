#include "leedit.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LeEdit w;
    w.show();
    
    return a.exec();
}
