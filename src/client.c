#include <stdio.h>
#include "../include/client.h"

Client clients[100];
int nombreClients = 0;


void ajouterClient() {
    int id;
    int trouve = 0;

    printf("\n===== AJOUTER UN CLIENT =====\n");
    printf("Entrez l'ID du client : ");
    scanf("%d", &id);

    // Verifier si l'ID existe deja
    for (int i = 0; i < nombreClients; i++) {
        if (clients[i].id == id) {
            trouve = 1;
            break;
        }
    }

    if (trouve == 1) {
        printf("Erreur : cet ID existe deja !\n");
        return;
    }

    // Verifier la capacite du tableau
    if (nombreClients >= 100) {
        printf("Erreur : le nombre maximum de clients est atteint.\n");
        return;
    }

    clients[nombreClients].id = id;

    printf("Nom : ");
    scanf("%49s", clients[nombreClients].nom);

    printf("Prenom : ");
    scanf("%49s", clients[nombreClients].prenom);

    printf("Telephone : ");
    scanf("%19s", clients[nombreClients].telephone);

    printf("Adresse : ");
    scanf("%99s", clients[nombreClients].adresse);

    nombreClients++;

    printf("\nClient ajoute avec succes !\n");
    sauvegarderClients();
}

void afficherClients() {

    printf("\n===== LISTE DES CLIENTS =====\n");

    if (nombreClients == 0) {
        printf("Aucun client enregistre.\n");
        return;
    }

    for (int i = 0; i < nombreClients; i++) {

        printf("\n--- Client %d ---\n", i + 1);
        printf("ID : %d\n", clients[i].id);
        printf("Nom : %s\n", clients[i].nom);
        printf("Prenom : %s\n", clients[i].prenom);
        printf("Telephone : %s\n", clients[i].telephone);
        printf("Adresse : %s\n", clients[i].adresse);
    }
}

void rechercherClient() {
    int idRecherche;
    int trouve = 0;

    printf("\n===== RECHERCHER UN CLIENT =====\n");
    printf("Entrez l'ID du client : ");
    scanf("%d", &idRecherche);

    for (int i = 0; i < nombreClients; i++) {

        if (clients[i].id == idRecherche) {
            printf("\nClient trouve !\n");
            printf("ID : %d\n", clients[i].id);
            printf("Nom : %s\n", clients[i].nom);
            printf("Prenom : %s\n", clients[i].prenom);
            printf("Telephone : %s\n", clients[i].telephone);
            printf("Adresse : %s\n", clients[i].adresse);

            trouve = 1;
            break;
        }
    }

    if (trouve == 0) {
        printf("Aucun client avec cet ID.\n");
    }
}

void modifierClient() {
    int idRecherche;
    int trouve = 0;

    printf("\n===== MODIFIER UN CLIENT =====\n");
    printf("Entrez l'ID du client : ");
    scanf("%d", &idRecherche);

    for (int i = 0; i < nombreClients; i++) {

        if (clients[i].id == idRecherche) {

            printf("\nClient trouve : %s %s\n",
                   clients[i].prenom,
                   clients[i].nom);

            printf("Nouveau nom : ");
            scanf("%49s", clients[i].nom);

            printf("Nouveau prenom : ");
            scanf("%49s", clients[i].prenom);

            printf("Nouveau telephone : ");
            scanf("%19s", clients[i].telephone);

            printf("Nouvelle adresse : ");
            scanf("%99s", clients[i].adresse);

            trouve = 1;

            printf("\nClient modifie avec succes !\n");
            sauvegarderClients();
            break;
        }
    }

    if (trouve == 0) {
        printf("Aucun client avec cet ID.\n");
    }
}

void supprimerClient() {
    int idRecherche;
    int trouve = 0;

    printf("\n===== SUPPRIMER UN CLIENT =====\n");
    printf("Entrez l'ID du client : ");
    scanf("%d", &idRecherche);

    for (int i = 0; i < nombreClients; i++) {

        if (clients[i].id == idRecherche) {

            // Decaler les clients suivants vers la gauche
            for (int j = i; j < nombreClients - 1; j++) {
                clients[j] = clients[j + 1];
            }

            nombreClients--;
            trouve = 1;

            printf("\nClient supprime avec succes !\n");
            sauvegarderClients();
            break;
        }
    }

    if (trouve == 0) {
        printf("Aucun client avec cet ID.\n");
    }
}

void sauvegarderClients() {
    FILE *fichier = fopen("data/clients.txt", "w");

    if (fichier == NULL) {
        printf("Erreur : impossible de sauvegarder les clients.\n");
        return;
    }

    for (int i = 0; i < nombreClients; i++) {
        fprintf(fichier, "%d;%s;%s;%s;%s\n",
                clients[i].id,
                clients[i].nom,
                clients[i].prenom,
                clients[i].telephone,
                clients[i].adresse);
    }

    fclose(fichier);
    printf("Clients sauvegardes avec succes.\n");
}

void chargerClients() {
    FILE *fichier = fopen("data/clients.txt", "r");

    if (fichier == NULL) {
        return;
    }

    nombreClients = 0;

    while (nombreClients < 100 &&
           fscanf(fichier, "%d;%49[^;];%49[^;];%19[^;];%99[^\n]\n",
                  &clients[nombreClients].id,
                  clients[nombreClients].nom,
                  clients[nombreClients].prenom,
                  clients[nombreClients].telephone,
                  clients[nombreClients].adresse) == 5) {
        nombreClients++;
    }

    fclose(fichier);
}

