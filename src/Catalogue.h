/*************************************************************************
Catalogue  -  description
-------------------
début                : 23/11
copyright            : Rémy Etienne, Elie Andrianarisolo
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H
//--------------------------------------------------- Interfaces utilisées
#include "ListeTrajets.h"
#include "TrajetCompose.h"
#include "Affichage.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Permettre de stocker des trajets, d'en ajouter, de les afficher ou d'effectuer une recherche
//------------------------------------------------------------------------

class Catalogue
{
  //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques

        void AjouterTrajetSimple( const char* villeDepart, const char* villeArrivee, const char* transportUtilise);
        // Mode d'emploi :
        // Ajouter un trajet simple au catalogue
        // Contrat :
        //

        void Afficher () const;
        // Mode d'emploi :
        // Afficher les trajets du catalogue
        // Contrat :
        //

        void RechercheSimple(const char* villeDepart, const char* villeArrivee) const;
        // Mode d'emploi :
        // Afficher les trajets du catalogue dont les caractéristiques ui partent de villeDepart et
        // arrivent à villeArrivee
        // Contrat :
        //

        void RechercheCompose(const char* villeDepart, const char* villeArrivee) const;
        // Mode d'empoi :
        // Afficher les trajets ou compositions de trajets qui partent de villeDepart et
        // arrivent à villeArrivee
        // Contrat :
        //

        bool DetecterDoublon(Trajet * unTrajet);
        // Mode d'emploi :
        // Verifier si le dernier trajet du catalogue est un doublon, le retirer si c'est le cas
        // par rapport au reste du catalogue
        // Contrat :
        // A appeler après l'ajout d'un nouveau trajet

        ListeTrajets * GetListeTrajets() const;
        // Mode d'emploi :
        // Renvoyer les trajets du catalogue
        // Contrat :
        //

        unsigned int GetNombreTrajets() const;
        // Mode d'emploi :
        // Renvoyer le nombre de trajets du catalogue
        // Contrat :
        //


  //------------------------------------------------- Surcharge d'opérateurs



  //-------------------------------------------- Constructeurs - destructeur

    Catalogue();
    // Mode d'emploi :
    // Construire un catalogue de trajets vide
    // Contrat :
    //

    ~Catalogue();
    // Mode d'emploi :
    // Destruction d'un catalogue
    // Contrat :
    //

  //------------------------------------------------------------------ PRIVE

    protected:
    //----------------------------------------------------- Méthodes protégées
        unsigned int etapeRecherche (const char* villeDepart, const char* villeArrivee, ListeTrajets * utilise) const;   
    //----------------------------------------------------- Attributs protégés
        ListeTrajets * trajets;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H