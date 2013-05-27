/**
 * @file test.cc
 * @author Hugo des Longchamps
 */

using namespace std;

#include "../headers/core/buffer.h"
#include "../headers/core/facteur.h"

int main(){
   
    //*****************
    //Tests sur Facteur
    //*****************
  //cout << "test" << endl;
    //Creation d'une chaine C
  string str("<head>");  
  char* cstr = new char[str.length()+1];
  strcpy(cstr, str.c_str());
  // cout << cstr << endl;
   
    //Construction paramétrée de Facteur
    int jeton = 320;
    Facteur f1(cstr, jeton);
    delete cstr;
    //cout << f1 << endl;
    //Construction par copie
    Facteur f11(f1);
    //cout << "f11 : " << f11 << endl; 
    //Changer le texte du Facteur
     str = ("UnMot");
    char *cstr1 = new char[str.length()+1];
    strcpy(cstr1, str.c_str());
    f11.setTexte(cstr1);
    delete cstr1;
    //cout << " f11 : " << f11 << endl;

    //Recuperer le texte du Facteur
    /*  cout<<"Affichage de facteur"<<endl<<"----------------------------------"<<endl;
    cout << "Le texte du facteur est: " << endl;
    cout << f11.getTexte() << endl ;
    */
    //Changer la couleur du Facteur
     str = ("#FFF000");
    char *cstr2 = new char[str.length()+1];
    strcpy(cstr2, str.c_str());
    f11.setCouleur(cstr2);
    delete cstr2;
    // cout << "f11 : " << f11 << endl;
    
    //Recuperer le texte formate du facteur
    /*cout << "Le texte formate du facteur est: " << endl;
    cout << f11.getTexteFormate() << endl;
    */
    //Affichage de Facteur
    /* cout<<"Affichage du facteur f1:"<<endl;
    cout<<f1<<endl;
   
    //Affichage de Facteur
    cout<<"Affichage d'un facteur f11:"<<endl;
    cout<<f11<<endl<<endl<<endl;
    */
    //******************
    //Tests sur Ligne
    //******************

    //Creation d'une deuxième chaîne C
    /*    str="\t";
    cstr = new char[str.length()+1];
    strcpy(cstr, str.c_str());
    */	
    //Construction d'un deuxième facteur
    /* Facteur f2(cstr);
    delete cstr;
    */
    //Creation d'une troisieme chaîne 
    /* str="DeuMot";
    cstr= new char[str.length()+1];
    strcpy(cstr, str.c_str());
    */
    //Construction d'un troisième facteur
    /* Facteur f3(cstr);
    delete cstr;
    str=" ";	
    cstr= new char[str.length()+1];
    strcpy(cstr, str.c_str());
    
    Facteur f4(cstr);
    delete cstr;
    */
    //Creation d'un vecteur de facteurs
    /*  vector<Facteur> v1;
    v1.push_back(f2);   //tabulation
    v1.push_back(f2);	//tabulation
    v1.push_back(f3);  
    v1.push_back(f4);   //espace
    v1.push_back(f1);
    */
    //Construction d'une ligne
    // Ligne l1(v1);

    //Affichage d'une ligne avec la méthode affiche 
    /* cout<<"Tests sur Ligne"<<endl<<"------------------------------"<<endl;
    cout<<"Affichage de Ligne en utilisant la surcharge de l'operateur << "<<endl;
    cout<<"la ligne ainsi l'indentation(s) :\n";
    cout<<l1<<endl<<endl;
    */
   //Affichage d'une ligne en utilisant la méthode toString
   /* cout<<"Affichage de Ligne en utilisant la méthode toString qui nous renvoie une chaine de caractère"<<endl;
    string ma_ligne;
    ma_ligne=l1.toString();
    cout<<"la ligne est : "<<endl<<ma_ligne<<endl<<endl;
   */
   //Affichage d'une ligne en utilisant la méthode toCString
    /*  char* l;
    l=l1.toCString();
    cout<<"Affichage de Ligne en utilisant la méthode toCString qui nous renvoie un pointeur vers un caractère"<<endl;
    cout<<"la ligne est : "<<endl<<l<<endl<<endl<<endl;
    */




     cout<<endl<<endl<<endl;
     /*********************/
    /*  Test sur Noeud   */
   /*********************/
     cout<<endl<<endl<<endl;

    /* Création de facteurs */
    cout<<"Affichage de Noeud et DOM"<<endl<<"------------------------------"<<endl;

    /* Mise en commentaire car les tests ne marchent pas*/
    string s = "hello";  
    char* hello = new char[s.length()+1];
    strcpy(hello, s.c_str());
    s = "world";  
    char* world = new char[s.length()+1];
    strcpy(world, s.c_str());
    s = "<html>";  
    char* html = new char[s.length()+1];
    strcpy(html, s.c_str());
    s = "<body>";  
    char* body = new char[s.length()+1];
    strcpy(body, s.c_str());
    s = "Ceci";  
    char* ceci = new char[s.length()+1];
    strcpy(ceci, s.c_str());
    s = "est";  
    char* est = new char[s.length()+1];
    strcpy(est, s.c_str());
    s = "mon";  
    char* mon = new char[s.length()+1];
    strcpy(mon, s.c_str());
    s = "trop";  
    char* trop = new char[s.length()+1];
    strcpy(trop, s.c_str());
    s = "site";  
    char* site = new char[s.length()+1];
    strcpy(site, s.c_str());
    s = "genial";  
    char* genial = new char[s.length()+1];
    strcpy(genial, s.c_str());
    s = "/body";  
    char* b = new char[s.length()+1];
    strcpy(b, s.c_str());
    s = "/html";  
    char* hf = new char[s.length()+1];
    strcpy(hf, s.c_str());
    s = "<head>";  
    char* head = new char[s.length()+1];
    strcpy(head, s.c_str());
    s = "<p>";  
    char* par = new char[s.length()+1];
    strcpy(par, s.c_str());
    s = "</head>";  
    char* headf = new char[s.length()+1];
    strcpy(headf, s.c_str());
    s = "</p>";  
    char* pf = new char[s.length()+1];
    strcpy(pf, s.c_str());
    s = "<p>";  
    char* p = new char[s.length()+1];
    strcpy(p, s.c_str());
    s = "</p>";  
    char* parf = new char[s.length()+1];
    strcpy(parf, s.c_str());
    s = "Boujour";  
    char* boujour = new char[s.length()+1];
    strcpy(boujour, s.c_str());

    int Jt = 333;
    int Jb = 320;
    int Jbf = 325;
    
    Facteur F0(hello, Jt);
    Facteur F1(world, Jt);
    Facteur F2(html, Jb);
    Facteur F3(body, Jb);
    Facteur F4(ceci, Jt);
    Facteur F5(est, Jt);
    Facteur F6(mon, Jt);
    Facteur F7(site, Jt);
    Facteur F8(trop, Jt);
    Facteur F9(genial, Jt);
    Facteur F10(b, Jbf);
    Facteur F11(boujour, Jt);
    Facteur F12(head, Jb);
    Facteur F13(headf, Jbf);
    Facteur F14(p, Jb);
    Facteur F15(par, Jb);
    Facteur F16(pf, Jbf);
    Facteur F17(parf, Jbf);
    Facteur F18(hf, Jbf);

    // cout << F3.getJeton() << endl;
    /*   fin du commentaire temporaire*/

    /* Vecteur de facteur */

    /* Mise en commentaire car les tests ne marchent pas*:*/
    vector<Facteur*>V0;
    vector<Facteur*>V1;
    vector<Facteur*>V2;
    vector<Facteur*>V3;
    vector<Facteur*>V4;
    vector<Facteur*>V5;
    vector<Facteur*>V6;
    vector<Facteur*>V7;
    vector<Facteur*>V8;
    vector<Facteur*>V9;
    vector<Facteur*>V10;
    vector<Facteur*>V11;
    vector<Facteur*>V12;
    vector<Facteur*>V13;
    
    /* fin du commentaire temporaire*/

    /* Initialisation des vecteurs de facteurs */

    /* Mise en commentaire car les tests ne marchent pas*/
    V0.push_back(&F0);
    V0.push_back(&F1);
    V1.push_back(&F2);
    V2.push_back(&F3);
    V3.push_back(&F4);
    V3.push_back(&F5);
    V4.push_back(&F6);
    V4.push_back(&F7);
    V4.push_back(&F8);
    V4.push_back(&F9);
    V5.push_back(&F10);
    V6.push_back(&F11);
    V7.push_back(&F12);
    V11.push_back(&F13);
    V8.push_back(&F14);
    V10.push_back(&F16);
    V9.push_back(&F15);
    V12.push_back(&F17);
    V13.push_back(&F18);

 
    /* Création de lignes */ 
    
    /* Mise en commentaire car les tests ne marchent pas
    Ligne L0(V1);
    Ligne L1(V2);
    Ligne L2(V0);
    Ligne L3(V3);
    Ligne L4(V4);
    fin du commentaire temporaire*/

    /* Création de Noeud */

    /* Mise en commentaire car les tests ne marchent pas*/
    Noeud *N1 = new Noeud();
    string p1 = "<p1>";
    string p2 = "<p2>";
    string h = "html";
    Noeud N2(p1, 3, *N1, F0, F1);
    Noeud N3(p2, 3, *N1, F4, F9);
    Noeud N4(h, 0, N4, F2, F2);
    Noeud N5();
    /*    fin du commentaire temporaire*/
    
    //  cout << "premier N1 : " << N1 << endl;

    /* Initialisation de N1 */

    /* Mise en commentaire car les tests ne marchent pas*/
    (*N1).setNom("<body>");
    (*N1).setIndent(1);
    (*N1).setPere(&N4);
    (*N1).setFacteurDeb(F3);
    (*N1).setFacteurFin(F3);
    /*    fin du commentaire temporaire*/

    /* Affichage des noeuds */
    /*
    cout << "N1: " << N1 << endl;
    cout << "N2: " << N2 << endl;
    cout << "N3: " << N3 << endl;
    cout << "N4: " << N4 << endl;
    cout << "N5: " << N5 << endl;
    */
    /* Création d'un DOM */

    list<vector< Facteur*> > ligne;
    
    ligne.push_back(V1);
    ligne.push_back(V7);
    ligne.push_back(V8);
    ligne.push_back(V0);
    ligne.push_back(V10);
    ligne.push_back(V11);
    ligne.push_back(V2);
    ligne.push_back(V9);
    ligne.push_back(V3);
    ligne.push_back(V4);
    ligne.push_back(V12);
    ligne.push_back(V5);
    ligne.push_back(V13);


    
    /*
    cout << "ligne :" << endl;
    for (list< vector<Facteur*> >::const_iterator it = ligne.begin() ; it != ligne.end(); ++it){
      for (vector<Facteur*>::const_iterator it1 = (*it).begin() ; it1 != (*it).end(); ++it1){
	cout << (**it1) << endl;
      }
      }*/
    /* Mise en commentaire car les tests ne marchent pas*/
     Dom D(ligne);

     cout << "nb fils de la racine de D = " << D.getRacine().retournerNodesFils().size() << endl;

     /*   for (list<Noeud>::const_iterator it = D.getRacine().retournerNodesFils().begin() ; it != D.getRacine().retournerNodesFils().end(); ++it){
       cout << (*it).getNom() << endl;
       }*/

     /*for (list<Noeud>::const_iterator it = N4.retournerNodesFils().begin() ; it != N4.retournerNodesFils().end(); ++it){
       cout << (*it) << endl;
       }
     */
     cout << D << endl;
    /*    fin du commentaire temporaire*/

    /* Modification du DOM */

    /* Mise en commentaire car les tests ne marchent pas*/
    /* D.ajoutNoeud(N2, N5);

       cout << D << endl;*/
    /*    fin du commentaire temporaire*/
    
    /* Calcul sur Noeud */
    
    /* Mise en commentaire car les tests ne marchent pas
    cout << "Le noeud N1 a " << N1.nbFils() << " fils," << endl;
    cout << " et est indenté de " << N1.indent() << endl;
    fin du commentaire temporaire*/


     cout<<endl<<endl<<endl;
    //*****************
    //Tests sur Buffer
    //*****************
     cout<<endl<<endl<<endl;

    //Constructeur par défaut
    Buffer b1;
    //Affichage
    cout<<"Affichage de Buffer"<<endl<<"------------------------------"<<endl;
    cout<<"Affichage du premier buffer:"<<endl;
    cout<<b1<<endl;
    
    //Constructeur paramétré avec le chemin vers un fichier
    string str3("tests/testinput.txt");
    char *cstr3 = new char[str3.length()+1];
    strcpy(cstr3, str3.c_str());
    Buffer b2(cstr3);
    cout<<"Affichage du deuxième buffer:"<<endl;
    //cout<<b2<<endl;
    cout<<b2.toStringFormate()<<endl;


    //getDom
    //b1.getDom();

    //setDom
    /*Ne marche pas pour l'instant
    b1.setDom(D);
    */

    //getLigne
//    b1.getLignes();

    //setLignes


    return 0;
}
