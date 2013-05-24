#include "headers/gui/leedit.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(true);
    LeEdit w;
    w.show();
    
    exit(a.exec());
}
