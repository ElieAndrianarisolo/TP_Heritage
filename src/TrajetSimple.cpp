/*************************************************************************
TrajetSimple  -  description
-------------------
début                : 23/11
copyright            : Rémy Etienne, Elie Andrianarisolo
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetSimple::Afficher() const
{
    cout << "Trajet de " << depart << " à " << arrivee << " en " << transport << endl;
} //----- Fin de Afficher

char * TrajetSimple::Decrire() const
{
    char* description = new char [strlen(depart) + strlen(arrivee) + strlen(transport)+ 4];
    
    char separateur [2];
    separateur[0] = ':';
    separateur[1] = '\0';
    description[0] = '\0';

    strcpy(description,separateur);
    strcat(description,depart);

    strcat(description,separateur);
    strcat(description,arrivee);

    strcat(description,separateur);
    strcat(description,transport);

    return description;
} //----- Fin de Decrire

char* TrajetSimple::GetTransport() const
{
    return transport;
} //----- Fin de GetTransport



//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple (const char* villeDepart, const char* villeArrivee, const char* transportUtilise) : Trajet(villeDepart,villeArrivee)
{
    #ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif

    transport = new char[strlen(transportUtilise) + 1 ];
    strcpy(transport, transportUtilise);
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple()
{
    #ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
    #endif
    
    delete [] transport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

