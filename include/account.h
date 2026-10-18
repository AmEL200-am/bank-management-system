
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "models.h"
extern Compte comptes[100];
extern int nombreComptes;
void ajouterCompte();
void afficherComptes();
void rechercherCompte();
void modifierCompte();
void supprimerCompte();
void sauvegarderComptes();
void chargerComptes();
void afficherStatistiques();
#endif
