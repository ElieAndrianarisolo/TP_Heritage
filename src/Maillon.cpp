/*************************************************************************
Maillon -  description
-------------------
début                : 23/11
copyright            : Rémy Etienne, Elie Andrianarisolo
*************************************************************************/

//---------- Réalisation de la classe <Maillon> (fichier Maillon.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cstring>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Maillon.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


void Maillon::Afficher() const
{
    value->Afficher();
} //----- Fin de Afficher

Trajet * Maillon::GetMaillon() const
{
    return value;
} //----- Fin de GetMaillon

Maillon* Maillon::GetNext() const
{
    return next;
} //----- Fin de GetNext

void Maillon::SetTrajet(Trajet * unTrajet)
{
    value = unTrajet;
} //----- Fin de SetTrajet

void Maillon::SetNext(Maillon * unNext)
{
    this->next = unNext;
    this->next->next = unNext->next;
} //----- Fin de SetNext

void Maillon::SetNextNull()
{
    next = NULL;
} //----- Fin de SetNextNull


//------------------------------------------------- Surcharge d'opérateurs

// 

//-------------------------------------------- Constructeurs - destructeur

Maillon::Maillon(Trajet * unTrajet)
{
    #ifdef MAP
    cout << "Appel au constructeur de <Maillon>" << endl;
    #endif
    
    value = unTrajet;
    next = NULL;

} //----- Fin de Maillon

Maillon::~Maillon()
{
    #ifdef MAP
    cout << "Appel au destructeur de <Maillon>" << endl;
    #endif

    delete value;
    delete next;
} //----- Fin de ~Maillon

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées