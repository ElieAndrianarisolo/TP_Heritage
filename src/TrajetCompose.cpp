/*************************************************************************
TrajetCompose  -  description
-------------------
début                : 23/11
copyright            : Rémy Etienne, Elie Andrianarisolo
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cstring>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


void TrajetCompose::AjouterEtape(const char* villeDepart, const char* villeArrivee, const char* transportUtilise)
{
    TrajetSimple * nouvelleEtape = new TrajetSimple(villeDepart, villeArrivee, transportUtilise);
    etapes->AjouterEtapeTrajetCompose(nouvelleEtape);
} //----- Fin de AjouterEtape


void TrajetCompose::Afficher() const
{
    unsigned int nbTrajets = etapes->GetNombreTrajets();
    
    cout << "Trajet de " << depart << " à " << arrivee << " de " << nbTrajets << " étapes : " << endl;
    
    for(unsigned int i = 1; i <= nbTrajets ; i++)
    {
        cout << " - ";
        etapes->GetTrajet(i)->Afficher();
    }

} //----- Fin de Afficher

char* TrajetCompose::Decrire() const
{
    unsigned int nbTotal = 0;
    char* resultat;
    unsigned int nbTrajet = etapes->GetNombreTrajets();

    for (unsigned int i = 1 ; i <= nbTrajet ; i++)
    {
        resultat = etapes->GetTrajet(i)->Decrire();
        nbTotal += strlen(resultat);
        delete [] resultat;
    }

    char* description = new char [strlen(depart) + strlen(arrivee) + nbTotal+4];
    
    char separateur [2];
    separateur[0] = ':';
    separateur[1] = '\0';
    description[0] = '\0';

    strcpy(description,separateur);
    strcat(description,depart);

    strcat(description,separateur);
    strcat(description,arrivee);

    for( unsigned int i = 1 ; i <= nbTrajet ; i++)
    {
        resultat = etapes->GetTrajet(i)->Decrire();
        description = strcat(description , resultat);
        delete [] resultat;
    }
    
    
    return description;
} //----- Fin de Decrire

ListeTrajets * TrajetCompose::GetListeTrajet() const
{
    return etapes;
} //----- Fin de GetListeTrajet

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose(const char* villeDepart, const char* villeArrivee) : Trajet(villeDepart,villeArrivee)
{

    #ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
    #endif

    etapes = new ListeTrajets();

} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose()
{
  #ifdef MAP
  cout << "Appel au destructeur de <TrajetCompose>" << endl;
  #endif 

  delete etapes;

} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
