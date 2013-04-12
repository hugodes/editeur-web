#ifndef LEEDIT_H
#define LEEDIT_H

#include <QMainWindow>
#include <QtWebKitWidgets\QWebView>

namespace Ui {
class LeEdit;
}

class LeEdit : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit LeEdit(QWidget *parent = 0);
    ~LeEdit();

public slots:
   void affichageDOM(bool visible);
   void affichageHIE(bool visible);
   void affichageAPE();
   void affichageWID(int i);

private:
    Ui::LeEdit *ui;
};

#endif // LEEDIT_H
