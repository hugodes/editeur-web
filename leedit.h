#ifndef LEEDIT_H
#define LEEDIT_H

#include <QMainWindow>

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

private:
    Ui::LeEdit *ui;
};

#endif // LEEDIT_H
