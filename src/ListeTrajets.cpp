/*************************************************************************
ListeTrajets -  description
-------------------
début                : 23/11
copyright            : Rémy Etienne, Elie Andrianarisolo
*************************************************************************/

//---------- Réalisation de la classe <ListeTrajets> (fichier ListeTrajets.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cstring>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ListeTrajets.h"

//------------------------------------------------------------- Constantes

void ListeTrajets::AjouterTrajet(Trajet * unTrajet)
{
	Maillon * newMaillon = new Maillon(unTrajet);
	Maillon * parcour = liste;

	if(parcour == NULL && nbElements == 0 )
	{
		liste = newMaillon;
		nbElements++;
		return;
	}

	char * descriptionCible = unTrajet->Decrire();
	char * descriptionCourant = parcour->GetMaillon()->Decrire();

	if(strcmp( descriptionCible, descriptionCourant) <= 0)
	{
		newMaillon->SetNext(liste);
		liste = newMaillon;
		nbElements++;
		delete [] descriptionCible;
		delete [] descriptionCourant;
		return;
	}

	unsigned int put = 0;
	char * descriptionCourantNext = descriptionCourant;

	while(parcour->GetNext() != NULL)
	{
		descriptionCourantNext = parcour->GetNext()->GetMaillon()->Decrire();
		if(strcmp( descriptionCible, descriptionCourant) >= 0 && strcmp( descriptionCible, descriptionCourantNext) <= 0 )
		{	
			newMaillon->SetNext(parcour->GetNext());
			parcour->SetNext(newMaillon);
			delete [] descriptionCible;
			delete [] descriptionCourant;
			delete [] descriptionCourantNext;
			put = 1;
			nbElements++;
			return;
		}
		else
		{
			delete [] descriptionCourant;
			delete [] descriptionCourantNext;
			descriptionCourant = parcour->GetMaillon()->Decrire();
			parcour = parcour->GetNext();
		}
	}

	
	if(!put)
	{
		delete [] descriptionCourant;
		delete [] descriptionCible;
		parcour->SetNextNull();
		parcour->SetNext(newMaillon);
	}

	nbElements++;

} //----- Fin de AjouterTrajet

void ListeTrajets::AjouterEtapeTrajetCompose(Trajet * unTrajet)
{
	Maillon * newMaillon = new Maillon(unTrajet);

	if(liste == NULL && nbElements == 0)
	{
		liste = newMaillon;
		nbElements++;
		return;
	}

	Maillon * parcour = liste;
	while(parcour->GetNext() != NULL)
	{
		parcour = parcour->GetNext();
	}
	parcour->SetNext(newMaillon);

	nbElements++;
} //----- Fin de AjouterEtapeTrajetCompose

bool ListeTrajets::RetirerTrajet(const unsigned int position)
{
	if( position < 1 || position > nbElements || liste == NULL )
	{
		return false;
	}
	
	unsigned int indice = 1;
	Maillon * nextMaillon;
	

	if(position == 1)
	{
		nextMaillon = liste->GetNext();
		liste = nextMaillon;
		nbElements--;
		return true;
	}
	
	if(position == nbElements)
	{	
		Maillon * parcour = liste;
		
		while(parcour->GetNext()->GetNext() != NULL)
		{
			parcour = parcour->GetNext();
		}
		
		parcour->SetNextNull();
		
		nbElements--;
		return true;
	}


	Maillon * parcour = liste;
	Maillon * nextNextMaillon;

	while(parcour != NULL && parcour->GetNext() != NULL)
	{
		nextMaillon = parcour->GetNext();
		nextNextMaillon = nextMaillon->GetNext();
		if(indice+1 == position)
		{
			parcour->SetNext(nextNextMaillon);
			nextMaillon = parcour->GetNext();
			indice++;
			break;
		}
		else
		{
			parcour = nextMaillon;
			nextMaillon = nextNextMaillon;
			indice++;
		}
			
	}

	nbElements--;
	return true;

} //----- Fin de RetirerTrajet

void ListeTrajets::Afficher() const
{

	#ifdef MAP
		cout << "Taille actuelle" << nbElements << endl;
	#endif

	Maillon * parcour = liste;

	while(parcour!= NULL)
	{
		parcour->Afficher();
		cout << endl;
		parcour = parcour->GetNext();
	}

} //----- Fin de Afficher

unsigned int ListeTrajets::GetNombreTrajets() const
{
	return nbElements;
} //----- Fin de GetNombreTrajets

Trajet* ListeTrajets::GetTrajet(const unsigned int position) const
{

	unsigned int indice = 1;
	Maillon * parcour = liste;
	Trajet * trajetVoulu;

	while(parcour != NULL)
	{
		if(indice == position)
		{
			trajetVoulu = parcour->GetMaillon();
		}
		parcour = parcour->GetNext();
		indice++;	
	}

	return trajetVoulu;
} //----- Fin de GetTrajet

Maillon * ListeTrajets::GetListe(const unsigned int position) const
{

	unsigned int indice = 1;
	Maillon * parcour = liste;


	while(parcour != NULL)
	{
		if(indice == position)
		{
			break;
		}
		parcour = parcour->GetNext();
		indice++;	
	}

	return parcour;
} //----- Fin de GetListe



//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

ListeTrajets::ListeTrajets()
{

	#ifdef MAP
	cout << "Appel au constructeur de <ListeTrajets>" << endl;
	#endif

	liste = NULL;
	nbElements = 0;
	
} //----- Fin de ListeTrajets

ListeTrajets::~ListeTrajets()
{
	#ifdef MAP
	cout << "Appel au destructeur de <ListeTrajets>" << endl;
	#endif

	delete liste;
} //----- Fin de ~ListeTrajets



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
