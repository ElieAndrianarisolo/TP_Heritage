/*************************************************************************
Main  -  description
-------------------
début                : 23/11
copyright            : Rémy Etienne, Elie Andrianarisolo
*************************************************************************/

//---------- Réalisation du module <Main> (fichier Main.cpp) ---------------

//-------------------------------------------------------- Include système
#include <cstring>
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Affichage.h"
#include "Catalogue.h"
#include "TrajetCompose.h"
//---------------------------------------------------- Fonctions publiques
int main()
{
    Catalogue * unCatalogue = new Catalogue();
    choixMenu choixActuel;
    char * villeDepart;
    char * villeArrivee;
    char * transport;
    char * villeEtape;

    cout<<"--------------------------------------------------"<<endl;
    cout<<"Bienvenu dans le fabuleux éditeur de catalogue de trajet !"<<endl;
    cout<<"Nota Bene : toutes les entrées sont sensibles à la casse.\nDe plus, dans la navigation du menu, seul le premier caractère est pris en compte."<<endl;
    cout<<"--------------------------------------------------"<<endl;
    
    while((choixActuel = Affichage::Menu()) != QUITTER)
    {
        switch(choixActuel)
        {

            case AJOUT_SIMPLE:
            {
                cout<<endl;
                villeDepart = Affichage::DemanderDepart();
                villeArrivee = Affichage::DemanderArrivee();
                transport = Affichage::DemanderTransport();
                unCatalogue->AjouterTrajetSimple(villeDepart,villeArrivee,transport);

                
                delete [] villeDepart;
                delete [] villeArrivee;
                delete [] transport;
                break;
            }

            case AJOUT_COMPOSE:
            {
                cout<<endl;
                cout<<"Commencez par saisir le départ et l'arrivée de votre trajet COMPLET"<<endl;
                villeDepart = Affichage::DemanderDepart();
                villeArrivee = Affichage::DemanderArrivee();
                TrajetCompose * nouveauTrajet = new TrajetCompose(villeDepart,villeArrivee);
                
                while(strcmp(villeEtape = Affichage::DemanderEtape(villeDepart),villeArrivee)!=0)
                {
                    transport = Affichage::DemanderTransport();
                    nouveauTrajet->AjouterEtape(villeDepart,villeEtape,transport);
                    delete [] villeDepart;
                    villeDepart = villeEtape;
                    delete [] transport;
                }

                transport = Affichage::DemanderTransport();
                nouveauTrajet->AjouterEtape(villeDepart,villeEtape,transport);
                
                if(unCatalogue->DetecterDoublon(nouveauTrajet))
                {
                    delete [] villeEtape;
                    delete [] transport;
                    delete [] villeDepart;
                    delete [] villeArrivee;
                    break;
                }
                else
                {
                    unCatalogue->GetListeTrajets()->AjouterTrajet(nouveauTrajet);
                }

                delete [] villeEtape;
                delete [] transport;
                delete [] villeDepart;
                delete [] villeArrivee;
                
                break;
            }

            case AFFICHAGE:
            {
                cout<<endl;
                if(unCatalogue->GetNombreTrajets() == 0)
                {
                    cout << "Le catalogue est vide. Veuillez d'abord initialiser votre catalogue en bonne et due forme." << endl;
                    break;
                }
                unCatalogue->Afficher();
                break;
            }

            case RECHERCHE_SIMPLE:
            {
                cout<<endl;
                if(unCatalogue->GetNombreTrajets() == 0)
                {
                    cout << "Le catalogue est vide. Veuillez d'abord initialiser votre catalogue en bonne et due forme." << endl;
                    break;
                }
                villeDepart = Affichage::DemanderDepart();
                villeArrivee = Affichage::DemanderArrivee();
                unCatalogue->RechercheSimple(villeDepart,villeArrivee);

                delete [] villeDepart;
                delete [] villeArrivee;

                break;
            }

            case RECHERCHE_COMPOSE:
            {
                cout<<endl;
                if(unCatalogue->GetNombreTrajets() == 0)
                {
                    cout << "Le catalogue est vide. Veuillez d'abord initialiser votre catalogue en bonne et due forme." << endl;
                    break;
                }
                villeDepart = Affichage::DemanderDepart();
                villeArrivee = Affichage::DemanderArrivee();
                unCatalogue->RechercheCompose(villeDepart,villeArrivee);
                
                delete [] villeDepart;
                delete [] villeArrivee;

                break;
            }

            case QUITTER:
            {
                break;
            }
            
        }

    }
    
    delete unCatalogue;
    return 0;
    
} //----- Fin de main


    

