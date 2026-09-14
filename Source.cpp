/**
* Programme permettant d'exécuter tous les exercices se trouvant dans le TD1.
* \file   ExercicesTD1.cpp
* \author Achour Alicia et Baya Fortas
* \date   13 septembre 2026
* Créé le 3 septembre 2026
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// QUESTION 1.
static void calculerSommeReelle()
{
	int nombreEntier = 0;
	cout << "Entrez un nombre entier dont vous voulez calculer la somme reelle : ";
	cin >> nombreEntier;

	double somme = 0.0;

	for (int i = 1; i <= nombreEntier; i++)
	{
		somme += 1.0 / i;
	}
	int a = 0; // Plus petit entier superieur ou egal a la somme reelle.

	while (a < somme)
	{
		a++;
	}

	cout << "La somme reelle est : " << somme << endl;
	cout << "Le plus petit entier superieur ou egal a la somme reelle est : " << a << endl;
}

// QUESTION 2.
static void trouverLeDiviseur()
{
	int nombreEntier = 0;

	while (nombreEntier < 2)
	{
		cout << "Entrez un nombre entier superieur ou egal a 2 : ";
		cin >> nombreEntier;
	}

	bool estPremier = true;
	bool estPremierDiviseur = true; // Si c'est le premier diviseur trouve pour afficher le message.

	for (int i = 2; i < nombreEntier; i++)
	{
		if (nombreEntier % i == 0)
		{
			estPremier = false;

			if (estPremierDiviseur)
			{
				cout << "Le nombre " << nombreEntier << " n'est pas premier." << endl;
				cout << "Les diviseurs de " << nombreEntier << " sont : ";
				cout << i;
				estPremierDiviseur = false;
			}
			else
			{
				cout << "," << i;
			}
		}
	}

	if (estPremier)
	{
		cout << "Le nombre " << nombreEntier << " est premier.";
	}

	cout << endl;
}

// QUESTION 3.
string changerDirection(string chaine, size_t nRotations, bool versLaDroite) {

	string partieDebut = "";
	string partieFin = "";

	if (versLaDroite) {

		for (size_t i = 0; i < chaine.size() - nRotations; i++)
		{
			partieFin += chaine[i];
		}

		for (size_t i = chaine.size() - nRotations; i < chaine.size(); i++)
		{
			partieDebut += chaine[i];
		}

		return partieDebut + partieFin;

	}
	else {

		for (size_t i = 0; i < nRotations; i++)
		{
			partieDebut += chaine[i];
		}

		for (size_t i = nRotations; i < chaine.size(); i++)
		{
			partieFin += chaine[i];
		}

		return partieFin + partieDebut;

	}

}

void inverserChaine()
{
	string chaineCaractere = "";
	size_t nRotations = 0;
	bool estVersDroite = false;

	cout << "Entrez une chaine de caracteres : ";
	cin >> chaineCaractere;

	do
	{
		cout << "Entrez le nombre de rotations : ";
		cin >> nRotations;
	} while (nRotations == 0 || nRotations > chaineCaractere.size());

	cout << "Entrez 0 pour gauche ou 1 pour droite : ";
	cin >> estVersDroite;

	cout << changerDirection(chaineCaractere, nRotations, estVersDroite) << endl;
}

// QUESTION 4.
static void lancerJeuDevinette()
{
	int nombreADeviner = 0;
	cout << "Utilisateur 1, entrez un nombre de votre choix: ";
	cin >> nombreADeviner;
	int nombreDevine = 0;
	int nTentatives = 0;
	bool estDevine = false;

	while (!estDevine)
	{
		cout << "Utilisateur 2, entrez votre proposition: ";
		cin >> nombreDevine;
		nTentatives++;
		if (nombreDevine == nombreADeviner)
		{
			estDevine = true;
		}
		else if (nombreDevine < nombreADeviner)
		{
			cout << "Le nombre est plus grand que votre proposition. Essayez encore." << endl;
		}
		else
		{
			cout << "Le nombre est plus petit que votre proposition. Essayez encore." << endl;
		}
	}

	cout << "Felicitations! Utilisateur 2 a trouve le nombre apres " << nTentatives << " tentatives." << endl;
}

// QUESTION 5.
int retirerDoublons(int nombres[], int nElements)
{
	for (int i = 0; i < nElements; i++)
	{
		// On commence a comparer avec les valeurs qui suivent pour être plus efficace. 
		for (int j = i + 1; j < nElements; j++)
		{
			if (nombres[i] == nombres[j])
			{
				// On decal toutes les valeurs si on trouve un doublon.
				for (int k = j; k < nElements - 1; k++)
				{
					nombres[k] = nombres[k + 1];
				}
				nElements--;
				j--;
			}
		}
	}

	return nElements;
}

void filtrerTableau()
{
	const int tailleMaxListe = 100;
	int nombres[tailleMaxListe]; // Valeur par defaut.

	// On veut que la valeur ne soit pas valide ici, afin de rentrer au moins une fois dans la boucle.
	int nElements = tailleMaxListe + 1;

	while (nElements > tailleMaxListe)
	{
		cout << "SVP, entrez le nombre d'elements (maximum " << tailleMaxListe << ") ";
		cin >> nElements;
	}

	for (int i = 0; i < nElements; i++)
	{
		cout << "SVP entrez l'element " << i + 1 << " du tableau: ";
		cin >> nombres[i];
	}

	nElements = retirerDoublons(nombres, nElements); // Met a jour le nombre d'element apres filtration.

	cout << "La liste filtree contient " << nElements << " elements: ";

	for (int i = 0; i < nElements; i++)
	{
		cout << nombres[i] << " ";
	}

	cout << endl;
}

// QUESTION 6.
struct Etudiant
{
	int matricule;
	double noteIntra;
	double moyenneLabs;
	double noteFinale;
	double moyenneFinale;
};

void evaluerCours()
{
	const double ponderationIntra = 0.3;
	const double ponderationLabs = 0.3;
	const double ponderationFinal = 0.4;

	ifstream fichierDeNotes("notes.txt");

	if (!fichierDeNotes.is_open())
	{
		cout << "Erreur!! Impossible d'ouvrir le fichier." << endl;
		return;
	}

	Etudiant etudiant;
	Etudiant etudiantMeilleurMoyenneLab;
	Etudiant etudiantMeilleurMoyenneFinale;

	double sommeMoyennes = 0.0;
	int nEtudiants = 0;

	while (fichierDeNotes >> etudiant.matricule >> etudiant.noteIntra >> etudiant.moyenneLabs >> etudiant.noteFinale)
	{
		etudiant.moyenneFinale = (ponderationIntra * etudiant.noteIntra)
			+ (ponderationLabs * etudiant.moyenneLabs)
			+ (ponderationFinal * etudiant.noteFinale);
		sommeMoyennes += etudiant.moyenneFinale;
		nEtudiants++;

		if (nEtudiants == 1)
		{
			etudiantMeilleurMoyenneLab = etudiant;
			etudiantMeilleurMoyenneFinale = etudiant;
		}
		else
		{
			if (etudiant.moyenneLabs > etudiantMeilleurMoyenneLab.moyenneLabs)
			{
				etudiantMeilleurMoyenneLab = etudiant;
			}

			if (etudiant.moyenneFinale > etudiantMeilleurMoyenneFinale.moyenneFinale)
			{
				etudiantMeilleurMoyenneFinale = etudiant;
			}
		}
	}

	fichierDeNotes.close();

	// Eviter les erreurs de division par zero si le fichier est vide et les calculs inutiles.
	if (nEtudiants == 0)
	{
		cout << "Aucun etudiant trouvé dans le fichier." << endl;
		return;
	}

	double moyenneDeLaClasse = sommeMoyennes / nEtudiants;

	cout << "La moyenne de la classe est: " << moyenneDeLaClasse << endl;

	cout << "L'etudiant avec la meilleure moyenne de lab est : "
		<< etudiantMeilleurMoyenneLab.matricule << " avec une moyenne de "
		<< etudiantMeilleurMoyenneLab.moyenneLabs << endl;

	cout << "L'etudiant avec la meilleure moyenne finale est : "
		<< etudiantMeilleurMoyenneFinale.matricule << " avec une moyenne de "
		<< etudiantMeilleurMoyenneFinale.moyenneFinale << endl;

	ofstream fichierEvaluation("evaluation.txt");

	if (!fichierEvaluation.is_open())
	{
		cout << "Erreur. Impossible de creer le fichier evaluation.txt";
		return;
	}

	fichierEvaluation << "La moyenne de la classe est : " << moyenneDeLaClasse << endl;

	fichierEvaluation << "L'etudiant ayant le matricule " << etudiantMeilleurMoyenneLab.matricule
		<< " a la meilleure note " << etudiantMeilleurMoyenneLab.moyenneLabs << " dans les labs" << endl;

	fichierEvaluation << "L'etudiant ayant le matricule " << etudiantMeilleurMoyenneFinale.matricule
		<< " a la meilleure moyenne " << etudiantMeilleurMoyenneFinale.moyenneFinale << endl;

	fichierEvaluation.close();
}

int main()
{
	bool estMenuAffiche = true;

	while (estMenuAffiche)
	{
		int choix = 0;
		cout << endl << "Quel exercice voulez vous faire: 1, 2, 3, 4, 5 ou 6 ? (0 pour quitter): ";
		cin >> choix;

		switch (choix)
		{
		case 0:
			cout << "Vous quittez le menu" << endl;
			estMenuAffiche = false;
			break;
		case 1:
			calculerSommeReelle();
			break;
		case 2:
			trouverLeDiviseur();
			break;
		case 3:
			inverserChaine();
			break;
		case 4:
			lancerJeuDevinette();
			break;
		case 5:
			filtrerTableau();
			break;
		case 6:
			evaluerCours();
			break;
		default:
			cout << "Ceci n'est pas un choix valide." << endl;
			break;
		}
	}

	return 0;
}