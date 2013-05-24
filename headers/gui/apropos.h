#ifndef APROPOS_H
#define APROPOS_H

/*!
 * \file apropos.h
 * \brief Fichier d'entête de l'affichage graphique de la partie à propos
 * \author Bryan Libourel & Nicolas Emeri
 */

#include <QDialog>

/*! \namespace Ui
*  espace de nommage regroupant les outils composants de l'interface graphique
*/
namespace Ui {

class aPropos;
}
/*!
 * @brief aPropos
 * Classe gérant l'affichage de la partie à propos
 */
class aPropos : public QDialog
{
    Q_OBJECT
    
public:
    /*!
     * @brief aPropos Constructeur de la classe
     * @param parent Pointeur sur l'objet parent
     */
    explicit aPropos(QWidget *parent = 0);
    ~aPropos();
    
private:
    /*!
     * @brief ui Interface graphique QT
     */
    Ui::aPropos *ui;
};

#endif // APROPOS_H
