/*************************************************************************
ListeTrajets -  description
-------------------
début                : 23/11
copyright            : Rémy Etienne, Elie Andrianarisolo
*************************************************************************/

//---------- Interface de la classe <ListeTrajets> (fichier ListeTrajets.h) ----------------
#if ! defined ( LISTE_TRAJETS_H )
#define LISTE_TRAJETS_H

//--------------------------------------------------- Interfaces utilisées
#include "Maillon.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeTrajets>
// Représenter une liste chainée de trajets simples ou composés
//------------------------------------------------------------------------

class ListeTrajets
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  void AjouterTrajet(Trajet * unTrajet);
  // Mode d'emploi :
  // Ajouter un trajet à la liste, ordonnée dans l'ordre lexicographique
  // Contrat :
  //

  void AjouterEtapeTrajetCompose(Trajet * unTrajet);
  // Mode d'emploi :
  // Ajouter un trajet à la liste dans l'ordre d'arrivée
  // Contrat :
  //

  bool RetirerTrajet (const unsigned int position);
  // Mode d'emploi :
  // Retirer un trajet de la liste situé à position
  // Renvoie true si l'opération a marché, false sinon
  // Contrat :
  // 

  void Afficher () const;
  // Mode d'emploi :
  // Afficher les trajets de la liste, ligne à ligne
  // Contrat :
  //

  unsigned int GetNombreTrajets() const;
  // Mode d'emploi :
  // Renvoyer le nombre de trajets de la liste
  // Contrat :
  //

  Trajet* GetTrajet( const unsigned int position) const;
  // Mode d'emploi :
  // Renvoyer un pointeur vers le trajet à l'indice position
  // Contrat :
  // position correspond à un trajet existant dans la liste

  Maillon * GetListe(const unsigned int position) const;
  // Mode d'emploi :
  // Renvoyer le maillon liste
  // Contrat :
  // 

  //------------------------------------------------- Surcharge d'opérateurs

  //-------------------------------------------- Constructeurs - destructeur

  ListeTrajets();
  // Mode d'emploi :
  // Construire une liste de trajet vide
  // Contrat :
  //

  ~ListeTrajets ();
  // Mode d'emploi :
  // Destruction d'une liste de trajets
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
  unsigned int nbElements;
  Maillon * liste;

};

//-------------------------------- Autres définitions dépendantes de <ListeTrajets>

#endif // LISTE_TRAJETS_H
