/*************************************************************************
Trajet  -  description
-------------------
début                : 23/11
copyright            : Rémy Etienne, Elie Andrianarisolo
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet> :
// Représenter un trajet
//------------------------------------------------------------------------

class Trajet
{
    //----------------------------------------------------------------- PUBLIC

  public:
    //----------------------------------------------------- Méthodes publiques

    virtual void Afficher() const;
    // Mode d'emploi :
    // Afficher les caractéristiques du trajet
    // Contrat :
    //

    virtual char* Decrire() const = 0;
    // Mode d'emploi :
    // Renvoyer une chaine de caractères décrivant le trajet.
    // La mémoire associée à cette chaine doit être libérée
    // Contrat :
    // Le trajet est bien formé

    char* GetDepart() const;
    // Mode d'emploi :
    // Renvoyer le départ du trajet
    // Contrat :
    //

    char* GetArrivee() const;
    // Mode d'emploi :
    // Renvoyer l'arrivée du trajet
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur


    Trajet (const char* villeDepart, const char* villeArrivee);
    // Mode d'emploi :
    // Construire un trajet allant de villeDepart vers villeArrivee
    // Contrat :
    //

    virtual ~Trajet();
    // Mode d'emploi :
    // Destruction d'un trajet
    // Contrat :
    //

    
    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Méthodes protégées
    

    //----------------------------------------------------- Attributs protégés
    char *depart;
    char *arrivee;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
