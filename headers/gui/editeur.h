#ifndef EDITEUR_H
#define EDITEUR_H

/*!
 * \file editeur.h
 * \brief Fichier d'entête de la classe editeur gérant l'affichage de la zone d'édition
 * \author Bryan Libourel & Nicolas Emeri
 */


#include <QPlainTextEdit>
#include <QObject>
#include <QTextBlock>
/*!
 * \class Editeur
 * \brief Classe d'affichage de la zone d'édition
 */
class editeur : public QPlainTextEdit
{
       Q_OBJECT
public:
    /*!
     * \brief editeur Constructeur de la classe éditeur
     * \param parent Widget parent
     */
    editeur(QWidget *parent = 0);
    /*!
     * \brief miseAJourLignes Retourne le nombre de ligne de l'éditeur
     * \return Renvoi un entier comptant le nombre de lignes actuel
     */
    int miseAJourLignes();

public slots:
    /*!
     * \brief highlightCurLine Fonction de surlignage de la ligne courante
     */
    void highlightCurLine();

};

#endif // EDITEUR_H
