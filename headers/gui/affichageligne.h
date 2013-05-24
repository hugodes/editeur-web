#ifndef AFFICHAGELIGNE_H
#define AFFICHAGELIGNE_H

/*!
 * \file affichageligne.h
 * \brief Fichier d'entête de l'affichage du nombre de ligne
 * \author Bryan Libourel & Nicolas Emeri
 */


#include <QPlainTextEdit>
#include <QObject>
#include <headers/gui/editeur.h>
/**
 * \class affichageLigne
 * \brief Classe de gestion de l'affichage du nombre de ligne
 */
class affichageLigne: public QPlainTextEdit
{
    Q_OBJECT
public:
    /*!
     * @brief affichageLigne Constructeur de l'affichage d'un QPlainTextEdit qui gère l'affichage du nombre de ligne
     * @param parent pointeur sur lewidget qui apelle cet objet
     */
    affichageLigne(QWidget *parent = 0);

public slots:
    /*!
     * @brief genererLigne Fonction de génération de l'affichage des lignes et de mise à jour
     * @param nombreLigne Nombre de ligne que l'on souhaite afficher
     */
    void genererLigne(int nombreLigne);
};

#endif // AFFICHAGELIGNE_H
