/*************************************************************************
Catalogue  -  description
                             -------------------
début                : 23/11
copyright            : Rémy Etienne, Elie Andrianarisolo
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cstring>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetCompose.h"
#include "Trajet.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

 void Catalogue::AjouterTrajetSimple(const char* villeDepart, const char* villeArrivee, const char* transportUtilise)
 {
   TrajetSimple * nouveauTrajet = new TrajetSimple(villeDepart, villeArrivee, transportUtilise);

   if(DetecterDoublon(nouveauTrajet))
   {
        return;
   }
   else
   {
        trajets->AjouterTrajet(nouveauTrajet);
   }
   
 } //----- Fin de AjouterTrajetSimple

 void Catalogue::Afficher() const
 {

   cout << "--------------------------------------------------" << endl << endl;
   cout << "Liste des trajets :\n " << endl;

   trajets->Afficher();

   cout << "--------------------------------------------------" << endl;
 } //----- Fin de Afficher

void Catalogue::RechercheSimple(const char* villeDepart, const char* villeArrivee) const
 {
    
    unsigned int nbTrajets = trajets->GetNombreTrajets();
    unsigned int taille = 0;
    unsigned int i;

    cout << "-----------------------------------" << endl << endl;

	for (i = 1; i <= nbTrajets; i++)
    {
		Trajet* t = trajets->GetTrajet(i);
		if  (strcmp(t->GetDepart(), villeDepart) == 0 &&  strcmp(t->GetArrivee(), villeArrivee) == 0)
		{
            cout << "* ";
            t->Afficher();
            cout <<endl;
            taille++;
		}
	}


    if(taille == 0 || taille == 1)
    {
        cout << taille << " résultat trouvé." << endl;
    }
    else
    {
        cout << taille << " résultats trouvés." << endl;
    }
	
 } //----- Fin de RechercheSimple


void Catalogue::RechercheCompose(const char* villeDepart, const char* villeArrivee) const
{
    cout<<endl;
    ListeTrajets * utilise = new ListeTrajets();
	unsigned int nbPossible = etapeRecherche(villeDepart,villeArrivee,utilise);
    
    if(nbPossible == 0 || nbPossible == 1)
    {
        cout << "Trajet totale : "<< nbPossible << " choix différent." << endl;
    }
    else
    {
        cout << "Trajets totales : "<< nbPossible << " choix différents." << endl;
    }

    delete utilise;

} //----- Fin de RechercheCompose


unsigned int Catalogue::etapeRecherche(const char* villeDepart, const char* villeArrivee, ListeTrajets * utilise) const
//Algorithme
// Parcours en profondeur du graphe où les trajets sont les arrêtes, et les villes les noeuds
// Conditions d'arrêt :
// - Si, au noeud courant, la destination est atteinte => afficher la composition de trajet
// - Il n'y a plus de trajets partant du noeud courant
// - Tous les trajets partant du noeud courant se terminent dans une ville déjà visitée
{
	unsigned int nbPossible = 0;
	if (strcmp(villeDepart, villeArrivee) == 0) // Si la destination est atteinte
	{
		cout << "-----------------------------------" << endl << endl;
		utilise->Afficher(); //Afficher la composition de trajets utilisée
        return 1;
	}

    unsigned int nbTrajets = trajets->GetNombreTrajets();
	for (unsigned int i = 1; i <= nbTrajets ; i++)
	{
		Trajet* t = trajets->GetTrajet(i);

		//Si le trajet t part de l'arrivée du précédent, on poursuit le parcours
		if (strcmp(t->GetDepart(), villeDepart) == 0) //même départ
		{
			unsigned int valide = 1;
            unsigned int utiliseNbTrajets = utilise->GetNombreTrajets();

            // Sa villeArrivee n'est pas le départ de tout autre trajet déjà utilisé (détection de cycles)
			for(unsigned int j = 1; j <= utiliseNbTrajets; j++)
			{
				Trajet* tutilise = utilise->GetTrajet(j);
				if (strcmp(t->GetArrivee(), tutilise->GetDepart()) == 0)
				{
					valide = 0;//Cas d'arrêt du cycle
				}

			}

			if (valide)
			{
            // Parcourir l'arbre depuis le trajet t récursivement
				utilise->AjouterTrajet(t);
				nbPossible += etapeRecherche (t->GetArrivee(), villeArrivee, utilise);
                Maillon * mTrash = utilise->GetListe(utilise->GetNombreTrajets());
                mTrash->SetTrajet(NULL);
				utilise->RetirerTrajet(utilise->GetNombreTrajets());
                delete mTrash;
			}
		}
	}
   
	return nbPossible;
} //----- Fin de etapeRecherche

bool Catalogue::DetecterDoublon(Trajet * unTrajet)
{
    char * descriptionDernier;
    descriptionDernier = unTrajet->Decrire();

    unsigned int nbTrajets = trajets->GetNombreTrajets();
    for(unsigned int i = 1 ; i <= nbTrajets; i++)
    {
        char * descriptionCourant = trajets->GetTrajet(i)->Decrire() ;
        if(strcmp(descriptionDernier, descriptionCourant) == 0)
        {
            cout << endl << "Ce trajet existe deja dans le catalogue. Votre ajout est donc annulé.\n"<< endl;
            delete unTrajet;
            delete [] descriptionCourant;
            delete [] descriptionDernier;
            return true;
        }
        delete [] descriptionCourant;
    }

    delete [] descriptionDernier;
    cout << endl << "Votre trajet simple a été ajouté au catalogue.\n"<<endl;
    return false;
} //----- Fin de DetecterDoublon

ListeTrajets * Catalogue::GetListeTrajets() const
{
    return trajets;
} //----- Fin de GetListeTrajets

unsigned int Catalogue::GetNombreTrajets() const
{
    return trajets->GetNombreTrajets();
} //----- Fin de GetNombreTrajets

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue()
{
    #ifdef MAP
        cout << "Appel au constructeur de <Catalogue>" << endl;
    #endif

    trajets = new ListeTrajets();
} //----- Fin de Catalogue


Catalogue::~Catalogue()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Catalogue>" << endl;
    #endif
    
    delete trajets;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
