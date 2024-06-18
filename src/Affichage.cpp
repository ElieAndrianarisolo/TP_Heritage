/*************************************************************************
Affichage  -  description
                             -------------------
début                : 23/11
copyright            : Rémy Etienne, Elie Andrianarisolo
*************************************************************************/

//---------- Réalisation de la classe <Affichage> (fichier Affichage.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Affichage.h"

//------------------------------------------------------------- Constantes
static const unsigned int TAILLE_MAX = 164; // 164 a été choisi car il s'agit de la taille+1 du nom de lieu le plus long du monde
static const unsigned int TAILLE_INPUT = 2147483647; // Pour avoir une input à tout épreuve
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

choixMenu Affichage::Menu()
{
    char * choix = new char [TAILLE_MAX];
    cout << endl << "--------------------------------------------------" << endl;
    cout << "Que souhaiteriez-vous faire ?" << endl << endl;
    cout << "1-  Ajouter un trajet simple" << endl;
    cout << "2 - Ajouter un trajet composé" << endl;
    cout << "3 - Afficher le catalogue actuel" << endl;
    cout << "4 - Effectuer une recherche simple" << endl;
    cout << "5 - Effectuer une recherche complexe" << endl;
    cout << "6 - Quitter" << endl;
    cout << "--------------------------------------------------" << endl;
    cin.getline(choix, TAILLE_MAX);

    while(choix[0] < '1' || choix[0] > '6')
    {
        cout << "Votre choix est invalide. Veuillez réessayer" << endl;
        cin >> choix;
        cin.get();
    }

    int choixFinal = (int)(choix [0]) - (int)('0') ;
    delete [] choix;

    return choixMenu (choixFinal-1);

} //----- Fin de Menu

char * Affichage::DemanderDepart()
{
    char* buffer = new char [TAILLE_MAX];
    cout << "Entrez une ville de départ :" << endl;
    cin.getline(buffer,TAILLE_MAX);
    cout<<endl;

    return buffer;
} //----- Fin de DemanderDepart

char* Affichage::DemanderArrivee()
{
    char* buffer = new char [TAILLE_MAX] ;
    cout << "Entrez une ville d'arrivée :" << endl;
    cin.getline (buffer,TAILLE_MAX);
    cout<<endl;
    
    return buffer;
} //----- Fin de DemanderArrivee

char* Affichage::DemanderTransport()
{
    char* buffer = new char [TAILLE_MAX];
    cout << "Entrez un moyen de transport :" << endl;
    cin.getline(buffer, TAILLE_MAX);
    
    return buffer;
} //----- Fin de DemanderTransport

char* Affichage::DemanderEtape(const char* villeDepart)
{
    char* buffer = new char [TAILLE_MAX] ;
    cout << "Etape, vous partez de " << villeDepart << "," << endl;
    cout << "Entrez une ville d'arrivée :" << endl;
    cin.getline(buffer, TAILLE_MAX);
    cout<<endl;
    
    return buffer;
} //----- Fin de DemanderEtape

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
