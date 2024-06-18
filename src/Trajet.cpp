/*************************************************************************
Trajet  -  description
-------------------
début                : 23/11
copyright            : Rémy Etienne, Elie Andrianarisolo
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Trajet::Afficher() const
{
    cout << "Trajet de " << depart << " à " << arrivee << endl;
} //----- Fin de Afficher

char * Trajet::GetDepart() const
{
    return depart;
} //----- Fin de GetDepart

char * Trajet::GetArrivee() const
{
    return arrivee;
} //----- Fin de GetArrivee

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


Trajet::Trajet(const char* villeDepart, const char* villeArrivee)
{
  #ifdef MAP
  cout << "Appel au constructeur de <Trajet>" << endl;
  #endif

  depart = new char[strlen(villeDepart) + 1];
  arrivee = new char[strlen(villeArrivee)+1];
  strcpy(depart, villeDepart);
  strcpy(arrivee, villeArrivee);
} //----- Fin de Trajet

Trajet::~Trajet()
{
  #ifdef MAP
  cout << "Appel au destructeur de <Trajet>" << endl;
  #endif
  
  delete [] depart;
  delete [] arrivee;

} //----- Fin de ~Trajet

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
