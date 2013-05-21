#ifndef EDITEUR_H
#define EDITEUR_H

#include <QPlainTextEdit>
#include <QObject>
#include <QTextBlock>

class editeur : public QPlainTextEdit
{
       Q_OBJECT
public:
    editeur(QWidget *parent = 0);
    int miseAJourLignes();

public slots:
    void highlightCurLine();

};

#endif // EDITEUR_H
