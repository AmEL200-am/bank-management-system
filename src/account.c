#include <stdio.h>
#include "../include/account.h"
#include "../include/client.h"
#include <string.h>

Compte comptes[100];
int nombreComptes = 0;


void ajouterCompte() {
    int idClient;
    int numero;
    int clientExiste = 0;

    if (nombreComptes >= 100) {
        printf("Erreur : nombre maximum de comptes atteint.\n");
        return;
    }

    printf("\n===== AJOUTER UN COMPTE =====\n");

    // 1. Saisir et verifier le client
    printf("ID du client : ");
    if (scanf("%d", &idClient) != 1) {
        printf("Erreur : ID invalide.\n");
        return;
    }

    for (int i = 0; i < nombreClients; i++) {
        if (clients[i].id == idClient) {
            clientExiste = 1;
            break;
        }
    }

    if (!clientExiste) {
        printf("Erreur : ce client n'existe pas.\n");
        return;
    }

    // 2. Saisir et verifier le numero du compte
    printf("Numero du compte : ");
    if (scanf("%d", &numero) != 1) {
        printf("Erreur : numero invalide.\n");
        return;
    }

    for (int i = 0; i < nombreComptes; i++) {
        if (comptes[i].numero == numero) {
            printf("Erreur : ce numero de compte existe deja.\n");
            return;
        }
    }

    // 3. Saisir et verifier le solde
    printf("Solde initial : ");
    if (scanf("%lf", &comptes[nombreComptes].solde) != 1) {
        printf("Erreur : solde invalide.\n");
        return;
    }

    if (comptes[nombreComptes].solde < 0) {
        printf("Erreur : le solde initial ne peut pas etre negatif.\n");
        return;
    }

    // 4. Saisir le type du compte
    printf("Type (Courant ou Epargne) : ");
    scanf("%19s", comptes[nombreComptes].type);

    // 5. Enregistrer les informations
    comptes[nombreComptes].numero = numero;
    comptes[nombreComptes].client_id = idClient;

    nombreComptes++;

    printf("\nCompte ajoute avec succes !\n");
    sauvegarderComptes();
}


void afficherComptes() {
    if (nombreComptes == 0) {
        printf("Aucun compte enregistre.\n");
        return;
    }

    printf("\n===== LISTE DES COMPTES =====\n");

    for (int i = 0; i < nombreComptes; i++) {
        printf("\nNumero : %d\n", comptes[i].numero);
        printf("ID du client : %d\n", comptes[i].client_id);
        printf("Solde : %.2f DH\n", comptes[i].solde);
        printf("Type : %s\n", comptes[i].type);
    }
}

void rechercherCompte() {
    int numeroRecherche;
    int trouve = 0;

    printf("\n===== RECHERCHER UN COMPTE =====\n");
    printf("Numero du compte : ");

    if (scanf("%d", &numeroRecherche) != 1) {
        printf("Erreur : numero invalide.\n");
        return;
    }

    for (int i = 0; i < nombreComptes; i++) {
        if (comptes[i].numero == numeroRecherche) {
            printf("\nCompte trouve !\n");
            printf("Numero : %d\n", comptes[i].numero);
            printf("ID du client : %d\n", comptes[i].client_id);
            printf("Solde : %.2f DH\n", comptes[i].solde);
            printf("Type : %s\n", comptes[i].type);

            trouve = 1;
            break;
        }
    }

    if (trouve == 0) {
        printf("Aucun compte avec ce numero.\n");
    }
}

void modifierCompte() {

    int numeroRecherche;
    int trouve = 0;
    char nouveauType[20];

    printf("\n===== MODIFIER UN COMPTE =====\n");
    printf("Numero du compte : ");

    if (scanf("%d", &numeroRecherche) != 1) {
        printf("Erreur : numero invalide.\n");
        return;
    }

    for (int i = 0; i < nombreComptes; i++) {
        if (comptes[i].numero == numeroRecherche) {
            trouve = 1;

            printf("\nCompte trouve !\n");
            printf("Type actuel : %s\n", comptes[i].type);
            printf("Nouveau type (Courant ou Epargne) : ");

            if (scanf("%19s", nouveauType) != 1) {
                printf("Erreur de saisie.\n");
                return;
            }

            if (strcmp(nouveauType, "Courant") != 0 &&
                strcmp(nouveauType, "Epargne") != 0) {
                printf("Erreur : type invalide.\n");
                return;
            }

            strcpy(comptes[i].type, nouveauType);

            printf("Type du compte modifie avec succes !\n");
            sauvegarderComptes();
            break;
        }
    }

    if (trouve == 0) {
        printf("Aucun compte avec ce numero.\n");
    }
}

void supprimerCompte() {
    int numeroRecherche;
    int trouve = 0;

    printf("\n===== SUPPRIMER UN COMPTE =====\n");
    printf("Numero du compte : ");

    if (scanf("%d", &numeroRecherche) != 1) {
        printf("Erreur : numero invalide.\n");
        return;
    }

    for (int i = 0; i < nombreComptes; i++) {
        if (comptes[i].numero == numeroRecherche) {

            // Decaler les comptes suivants vers la gauche
            for (int j = i; j < nombreComptes - 1; j++) {
                comptes[j] = comptes[j + 1];
            }

            nombreComptes--;
            trouve = 1;

            printf("Compte supprime avec succes !\n");
            sauvegarderComptes();
            break;
        }
    }

    if (trouve == 0) {
        printf("Aucun compte avec ce numero.\n");
    }
}

void sauvegarderComptes() {
    FILE *fichier = fopen("data/comptes.txt", "w");

    if (fichier == NULL) {
        printf("Erreur : impossible de sauvegarder les comptes.\n");
        return;
    }

    for (int i = 0; i < nombreComptes; i++) {
        fprintf(fichier, "%d;%d;%.2f;%s\n",
                comptes[i].numero,
                comptes[i].client_id,
                comptes[i].solde,
                comptes[i].type);
    }

    fclose(fichier);
    printf("Comptes sauvegardes avec succes.\n");
}

void chargerComptes() {
    FILE *fichier = fopen("data/comptes.txt", "r");

    if (fichier == NULL) {
        return;
    }

    nombreComptes = 0;

    while (nombreComptes < 100 &&
           fscanf(fichier, "%d;%d;%lf;%19[^\n]\n",
                  &comptes[nombreComptes].numero,
                  &comptes[nombreComptes].client_id,
                  &comptes[nombreComptes].solde,
                  comptes[nombreComptes].type) == 4) {
        nombreComptes++;
    }

    fclose(fichier);
}

void afficherStatistiques() {
    double totalSoldes = 0.0;
    double soldeMoyen = 0.0;

    for (int i = 0; i < nombreComptes; i++) {
        totalSoldes += comptes[i].solde;
    }

    if (nombreComptes > 0) {
        soldeMoyen = totalSoldes / nombreComptes;
    }

    printf("\n===== STATISTIQUES BANCAIRES =====\n");
    printf("Nombre total de clients : %d\n", nombreClients);
    printf("Nombre total de comptes : %d\n", nombreComptes);
    printf("Total des soldes : %.2f DH\n", totalSoldes);
    printf("Solde moyen par compte : %.2f DH\n", soldeMoyen);
}



