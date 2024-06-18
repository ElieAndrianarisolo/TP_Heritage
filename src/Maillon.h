/*************************************************************************
Maillon -  description
-------------------
début                : 23/11
copyright            : Rémy Etienne, Elie Andrianarisolo
*************************************************************************/

//---------- Interface de la classe <Maillon> (fichier Maillon.h) ----------------
#if ! defined ( MAILLON_H )
#define MAILLON_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Maillon>
// Représenter un maillon de la liste chainée ListeTrajets
//------------------------------------------------------------------------

class Maillon
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  void Afficher() const;
  // Mode d'emploi :
  // Afficher le maillon 
  // Contrat :
  //

  Trajet * GetMaillon() const;
  // Mode d'emploi :
  // Renvoyer le maillon
  // Contrat :
  // 

  Maillon * GetNext() const;
  // Mode d'emploi :
  // Renvoyer le maillon suivant
  // Contrat :
  //

  void SetTrajet(Trajet * unTrajet);
  // Mode d'emploi :
  // Affecter un trajet au maillon
  // Contrat :
  // 

  void SetNext(Maillon * unNext);
  // Mode d'emploi :
  // Affecter un successeur au maillon
  // Contrat :
  // 

  void SetNextNull();
  // Mode d'emploi :
  // Affecter un successeur unNext au maillon, et un successeur null à unNext
  // Contrat :
  // 


  //------------------------------------------------- Surcharge d'opérateurs

  //-------------------------------------------- Constructeurs - destructeur

  Maillon(Trajet * unTrajet);
  // Mode d'emploi :
  // Construire un maillon à partir d'un trajet
  // Contrat :
  //

  ~Maillon ();
  // Mode d'emploi :
  // Destruction d'un maillon
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
  Trajet * value;
  Maillon * next;
};

//-------------------------------- Autres définitions dépendantes de <ListeTrajets>

#endif // MAILLON_H