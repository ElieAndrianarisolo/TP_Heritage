/*************************************************************************
Affichage  -  description
                             -------------------
début                : 23/11
copyright            : Rémy Etienne, Elie Andrianarisolo
*************************************************************************/

//---------- Interface de la classe <Affichage> (fichier Affichage.h) ----------------
#if ! defined (AFFICHAGE_H)
#define AFFICHAGE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

enum choixMenu { AJOUT_SIMPLE, AJOUT_COMPOSE, AFFICHAGE, RECHERCHE_SIMPLE, RECHERCHE_COMPOSE, QUITTER };

//------------------------------------------------------------------------
// Rôle de la classe <Affichage> :
// Gérer les interactions du catalogue avec l'utilisateur
//------------------------------------------------------------------------

class Affichage
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    static choixMenu Menu();
    // Mode d'emploi :
    // Renvoyer l'action souhaitée par l'utilisateur
    // Contrat :
    //

    static char* DemanderDepart();
    // Mode d'emploi :
    // Renvoyer la ville de départ souhaitée par l'utilisateur
    // Contrat :
    //
    static char* DemanderArrivee();
    // Mode d'emploi :
    // Renvoyer la ville d'arrivée souhaitée par l'utilisateur
    // Contrat :
    //
    static char* DemanderTransport();
    // Mode d'emploi :
    // Renvoyer le moyen de transport souhaité par l'utilisateur
    // Contrat :
    //
    static char* DemanderEtape(const char* villeDepart);
    // Mode d'emploi :
    // Renvoyer la ville étape souhaitée par l'utilisateur dans le cas d'un trajet composé.
    // Informer l'utilisateur que sa ville de depart est villeDepart
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    
//----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Affichage>

#endif // AFFICHAGE_H