#ifndef CONFIGURATIONGENERALE_H
#define CONFIGURATIONGENERALE_H

#include <QDialog>
#include "string.h"

using namespace std;

namespace Ui {
class configurationGenerale;
}

class configurationGenerale : public QDialog
{
    Q_OBJECT
    
public:
    explicit configurationGenerale(QWidget *parent = 0);
    ~configurationGenerale();
public slots:
    void modifierHie(bool val);
    void modifierDom(bool val);
    void modifierEcran(bool val);
    void modifierIndent(bool val);
    void modifierVal(string option, bool val);
    void getOption();
    bool getIndent();
    bool getDom();
    bool getHie();
    bool getEcran();
private:
    Ui::configurationGenerale *ui;
    bool ecran;
    bool hie;
    bool dom;
    bool indent;
};

#endif // CONFIGURATIONGENERALE_H
