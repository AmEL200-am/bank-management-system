
#include <stdio.h>
#include <string.h>

#include "../include/transaction.h"
#include "../include/account.h"


void viderBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Vider les caracteres restants
    }
}

Transaction transactions[1000];
int nombreTransactions = 0;

void effectuerDepot() {
    int numero;
    int indice = -1;
    double montant;

    if (nombreTransactions >= 1000) {
        printf("Erreur : historique des transactions plein.\n");
        return;
    }

    printf("\n===== EFFECTUER UN DEPOT =====\n");
    printf("Numero du compte : ");

    if (scanf("%d", &numero) != 1) {
        printf("Erreur : numero invalide.\n");
        return;
    }

    // Rechercher le compte
    for (int i = 0; i < nombreComptes; i++) {
        if (comptes[i].numero == numero) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Erreur : compte introuvable.\n");
        return;
    }

    printf("Montant du depot : ");

    if (scanf("%lf", &montant) != 1) {
        printf("Erreur : montant invalide.\n");
        viderBuffer();
        return;
    }

    if (montant <= 0) {
        printf("Erreur : le montant doit etre positif.\n");
        return;
    }

    // Mettre a jour le solde
    comptes[indice].solde += montant;

    // Enregistrer la transaction
    transactions[nombreTransactions].id = nombreTransactions + 1;
    transactions[nombreTransactions].compte_source = 0;
    transactions[nombreTransactions].compte_destination = numero;
    transactions[nombreTransactions].montant = montant;
    strcpy(transactions[nombreTransactions].type, "Depot");

    nombreTransactions++;

    printf("\nDepot effectue avec succes !\n");
    printf("Nouveau solde : %.2f DH\n",
           comptes[indice].solde);
    sauvegarderComptes();
}

void effectuerRetrait() {
    int numero;
    int indice = -1;
    double montant;

    if (nombreTransactions >= 1000) {
        printf("Erreur : historique des transactions plein.\n");
        return;
    }

    printf("\n===== EFFECTUER UN RETRAIT =====\n");
    printf("Numero du compte : ");

    if (scanf("%d", &numero) != 1) {
        printf("Erreur : numero invalide.\n");
        return;
    }

    // Rechercher le compte
    for (int i = 0; i < nombreComptes; i++) {
        if (comptes[i].numero == numero) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Erreur : compte introuvable.\n");
        return;
    }

    printf("Montant du retrait : ");

    if (scanf("%lf", &montant) != 1) {
        printf("Erreur : montant invalide.\n");
        viderBuffer();
        return;
    }

    if (montant <= 0) {
        printf("Erreur : le montant doit etre positif.\n");
        return;
    }

    if (montant > comptes[indice].solde) {
        printf("Erreur : solde insuffisant.\n");
        return;
    }

    // Mettre a jour le solde
    comptes[indice].solde -= montant;

    // Enregistrer la transaction
    transactions[nombreTransactions].id = nombreTransactions + 1;
    transactions[nombreTransactions].compte_source = numero;
    transactions[nombreTransactions].compte_destination = 0;
    transactions[nombreTransactions].montant = montant;
    strcpy(transactions[nombreTransactions].type, "Retrait");

    nombreTransactions++;

    printf("\nRetrait effectue avec succes !\n");
    printf("Nouveau solde : %.2f DH\n",
           comptes[indice].solde);
    sauvegarderComptes();
}

void effectuerVirement() {
    int numeroSource, numeroDestination;
    int indiceSource = -1, indiceDestination = -1;
    double montant;

    if (nombreTransactions >= 1000) {
        printf("Erreur : historique des transactions plein.\n");
        return;
    }

    printf("\n===== EFFECTUER UN VIREMENT =====\n");

    printf("Numero du compte source : ");
    if (scanf("%d", &numeroSource) != 1) {
        printf("Erreur : numero invalide.\n");
        return;
    }

    printf("Numero du compte destination : ");
    if (scanf("%d", &numeroDestination) != 1) {
        printf("Erreur : numero invalide.\n");
        return;
    }

    if (numeroSource == numeroDestination) {
        printf("Erreur : les deux comptes doivent etre differents.\n");
        return;
    }

    // Rechercher les deux comptes
    for (int i = 0; i < nombreComptes; i++) {
        if (comptes[i].numero == numeroSource)
            indiceSource = i;

        if (comptes[i].numero == numeroDestination)
            indiceDestination = i;
    }

    if (indiceSource == -1 || indiceDestination == -1) {
        printf("Erreur : compte source ou destination introuvable.\n");
        return;
    }

    printf("Montant du virement : ");
    if (scanf("%lf", &montant) != 1) {
        printf("Erreur : montant invalide.\n");
        viderBuffer();
        return;
    }

    if (montant <= 0) {
        printf("Erreur : le montant doit etre positif.\n");
        return;
    }

    if (montant > comptes[indiceSource].solde) {
        printf("Erreur : solde insuffisant.\n");
        return;
    }

    // Effectuer le transfert
    comptes[indiceSource].solde -= montant;
    comptes[indiceDestination].solde += montant;

    // Enregistrer la transaction
    transactions[nombreTransactions].id = nombreTransactions + 1;
    transactions[nombreTransactions].compte_source = numeroSource;
    transactions[nombreTransactions].compte_destination =
        numeroDestination;
    transactions[nombreTransactions].montant = montant;

    strcpy(transactions[nombreTransactions].type, "Virement");

    nombreTransactions++;

    printf("\nVirement effectue avec succes !\n");
    printf("Nouveau solde source : %.2f DH\n",
           comptes[indiceSource].solde);
    printf("Nouveau solde destination : %.2f DH\n",
           comptes[indiceDestination].solde);
    sauvegarderComptes();
}

void afficherHistorique() {
    if (nombreTransactions == 0) {
        printf("\nAucune transaction enregistree.\n");
        return;
    }

    printf("\n========== HISTORIQUE DES TRANSACTIONS ==========\n");

    for (int i = 0; i < nombreTransactions; i++) {
        printf("\nTransaction ID : %d\n", transactions[i].id);
        printf("Type           : %s\n", transactions[i].type);
        printf("Montant        : %.2f DH\n", transactions[i].montant);
        printf("Compte source  : %d\n", transactions[i].compte_source);
        printf("Compte destination : %d\n",
               transactions[i].compte_destination);
        printf("------------------------------------------\n");
    }
}
