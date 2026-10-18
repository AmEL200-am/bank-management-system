#ifndef CLIENT_H
#define CLIENT_H

#include "models.h"
extern Client clients[100];
extern int nombreClients;

void ajouterClient();
void afficherClients();
void rechercherClient();
void modifierClient();
void supprimerClient();
void sauvegarderClients();
void chargerClients();
#endif