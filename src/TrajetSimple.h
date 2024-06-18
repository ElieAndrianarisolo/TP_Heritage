/*************************************************************************
TrajetSimple  -  description
-------------------
début                : 23/11
copyright            : Rémy Etienne, Elie Andrianarisolo
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Représenter un trajet à partir d'un départ, d'une arrivée et d'un moyen de transport
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
  //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques

        void Afficher() const;
        // Mode d'emploi :
        // Afficher les caractéristiques du trajet simple
        // Contrat :
        //

        char* Decrire() const;
        // Mode d'emploi :
        // Renvoyer une chaine de caractères décrivant le trajet simple.
        // La mémoire associée à cette chaine doit être libérée
        // Contrat :
        // Le trajet est bien formé

        char* GetTransport() const;
        // Mode d'emploi :
        // Renvoyer le nom du moyen de transport
        // Contrat :
        //

        //------------------------------------------------- Surcharge d'opérateurs


        //-------------------------------------------- Constructeurs - destructeur


        TrajetSimple (const char* villeDepart, const char* villeArrivee, const char* inputTransport);
        // Mode d'emploi :
        // Construire un trajet allant de villeDepart vers villeArrivee par le biais de transport
        // Contrat :
        //

        ~TrajetSimple();
        // Mode d'emploi :
        // Destruction d'un trajet simple
        // Contrat :
        //

    //------------------------------------------------------------------ PRIVE

    protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
      char *transport;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H

