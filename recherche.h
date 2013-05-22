#ifndef RECHERCHE_H
#define RECHERCHE_H

#include <QDialog>

class LeEdit ;
#include <leedit.h>

namespace Ui {
class recherche;
}

class recherche : public QDialog
{
    Q_OBJECT

public:
    explicit recherche(LeEdit *parent = 0);
    ~recherche();

public slots:

   void rechercher();

   void remplacer();

private:
    Ui::recherche *ui;
    LeEdit *parent;
};

#endif // RECHERCHE_H
