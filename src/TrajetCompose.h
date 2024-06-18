/*************************************************************************
TrajetCompose  -  description
-------------------
début                : 23/11
copyright            : Rémy Etienne, Elie Andrianarisolo
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "ListeTrajets.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Représenter un trajet composé de plusieurs trajets simples entre deux villes avec un moyen de transport
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        void AjouterEtape(const char* villeDepart, const char* villeArrivee, const char* transportUtilise);
        // Mode d'emploi :
        // Rajouter un trajet intermiédiaire au trajet composé
        // Contrat :
        //
        
        void Afficher () const;
        // Mode d'emploi :
        // Afficher les caractéristiques du trajet composé
        // Contrat :
        //

        char* Decrire() const;
        // Mode d'emploi :
        // Renvoyer une chaine de caractères décrivant le trajet composé.
        // La mémoire associée à cette chaine doit être libérée
        // Contrat :
        // Le trajet est bien formé

        ListeTrajets * GetListeTrajet() const;
        // Mode d'emploi :
        // Renvoyer la liste des étapes du trajet composé
        // Contrat :
        // 



        //------------------------------------------------- Surcharge d'opérateurs


        //-------------------------------------------- Constructeurs - destructeur

        TrajetCompose (const char* villeDepart, const char*  villeArrivee);
        // Mode d'emploi :
        // Construire un trajet partant de villeDepart vers villeArrivee
        // Contrat :
        //

        ~TrajetCompose ();
        // Mode d'emploi :
        // Destruction d'un trajet composé
        // Contrat :
        //

    //------------------------------------------------------------------ PRIVE

    protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    ListeTrajets * etapes;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H

