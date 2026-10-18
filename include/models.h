#ifndef MODELS_H
#define MODELS_H

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    char telephone[20];
    char adresse[100];
} Client;


typedef struct {
    int numero;
    int client_id; //un lien vers le client
    double solde;
    char type[20];
} Compte;


typedef struct {
    int id;
    int compte_source;
    int compte_destination;
    double montant;
    char type[20];
} Transaction;

#endif