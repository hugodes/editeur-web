#ifndef AFFICHAGELIGNE_H
#define AFFICHAGELIGNE_H

#include <QPlainTextEdit>
#include <QObject>
#include <editeur.h>

class affichageLigne: public QPlainTextEdit
{
    Q_OBJECT
public:
    affichageLigne(QWidget *parent = 0);

public slots:
    void genererLigne(int nombreLigne);
};

#endif // AFFICHAGELIGNE_H
