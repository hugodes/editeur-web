#ifndef RECHERCHE_H
#define RECHERCHE_H

/*!
 * \file recherche.h
 * \brief Fichier gérant la recherche et le remplacement
 * \author Bryan Libourel & Nicolas Emeri
 */

#include <QDialog>

class LeEdit ;
#include <headers/gui/leedit.h>

/*! \namespace Ui
 *
 *  espace de nommage regroupant les outils composants de l'interface graphique
 */
namespace Ui {
class recherche;
}
/*!
 * \class Recherche
 * \brief La classe de gestion de la recherche
 */
class recherche : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief recherche Constructeur de l'affichage de la fenêtre
     * \param parent Widget parent
     */
    explicit recherche(LeEdit *parent = 0);
    ~recherche();

public slots:
    /*!
    * \brief rechercher Recherche d'un mot
    */
   void rechercher();
   /*!
    * \brief remplacer Recherche et remplacement d'un mot
    */
   void remplacer();

private:
   /*!
     * \brief ui Interface graphique QT
     */
    Ui::recherche *ui;
    /*!
     * \brief parent Widget parent
     */
    LeEdit *parent;
};

#endif // RECHERCHE_H
