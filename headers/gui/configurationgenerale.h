#ifndef CONFIGURATIONGENERALE_H
#define CONFIGURATIONGENERALE_H

/*!
 * \file configurationGenerale.h
 * \brief Fichier d'entête de l'affichage graphique de la partie configuration générale
 * \author Bryan Libourel & Nicolas Emeri
 */

#include <QDialog>
#include "string.h"

using namespace std;

/*! \namespace Ui
 *  espace de nommage regroupant les outils composants de l'interface graphique
 */
namespace Ui {
class configurationGenerale;
}
/*!
 * \class configurationGenerale
 * \brief Classe gérant la configuration des options générales
 */
class configurationGenerale : public QDialog
{
    Q_OBJECT
    
public:
    /*!
     * \brief configurationGenerale Constructeur de l'objet
     * \param parent Widget parent
     */
    explicit configurationGenerale(QWidget *parent = 0);
    ~configurationGenerale();

public slots:
    /*!
     * \brief modifierHie Modifie le paramètre "hiérarchie"
     * \param val Valeur coché par l'utilisateur
     */
    void modifierHie(bool val);
    /*!
     * \brief modifierDom Modifie le paramètre "Dom"
     * \param val Valeur coché par l'utilisateur
     */
    void modifierDom(bool val);
    /*!
     * \brief modifierEcran Modifie le paramètre "Ecran"
     * \param val Valeur coché par l'utilisateur
     */
    void modifierEcran(bool val);
    /*!
     * \brief modifierIndent Modifie le paramètre "Indentation"
     * \param val Valeur coché par l'utilisateur
     */
    void modifierIndent(bool val);
    /*!
     * \brief modifierVal Modifie le paramètre "Valeur"
     * \param option nom de la valeur a modifier
     * \param val Valeur coché par l'utilisateur en fonction de option
     */
    void modifierVal(string option, bool val);
    /*!
     * \brief getOption Récupère les options du fichier de configuration
     */
    void getOption();
    /*!
     * \brief getIndent Obtenir la valeur du paramètre indentation
     * \return retourne true ou false en fonction du paramètre
     */
    bool getIndent();
    /*!
     * \brief getDom Obtenir la valeur du paramètre DOM
     * \return retourne true ou false en fonction du paramètre
     */
    bool getDom();
    /*!
     * \brief getHie Obtenir la valeur du paramètre hiérarchie
     * \return retourne true ou false en fonction du paramètre
     */
    bool getHie();
    /*!
     * \brief getEcran Obtenir la valeur du paramètre écran
     * \return retourne true ou false en fonction du paramètre
     */
    bool getEcran();
private:
    /*!
     * \brief ui Interface graphique QT
     */
    Ui::configurationGenerale *ui;
    /*!
     * \brief ecran Booléen de l'option écran
     */
    bool ecran;
    /*!
     * \brief hie Booléen de l'option hiérarchie
     */
    bool hie;
    /*!
     * \brief dom Booléen de l'option dom
     */
    bool dom;
    /*!
     * \brief indent Booléen de l'option identation
     */
    bool indent;
};

#endif // CONFIGURATIONGENERALE_H
