#include <stdio.h>
#include "../include/models.h"//.. pour remonter un dosier en arriere 
#include "../include/client.h"
#include "../include/account.h"
#include "../include/transaction.h"

int main() {

    chargerClients();
    chargerComptes();
    int choix;
    do {
        printf("\n===== BANK MANAGEMENT SYSTEM =====\n");
        printf("1. Gestion des clients\n");
        printf("2. Gestion des comptes\n");
        printf("3. Transactions\n");
        printf("4. Recherche\n");
        printf("5. Statistiques\n");
        printf("0. Quitter\n");

        printf("\nVotre choix : ");
        scanf("%d", &choix);

        switch (choix) {

            case 1: {
                int choixClient;

                do {
                    printf("\n===== GESTION DES CLIENTS =====\n");
                    printf("1. Ajouter un client\n");
                    printf("2. Afficher les clients\n");
                    printf("3. Rechercher un client\n");
                    printf("4. Modifier un client\n");
                    printf("5. Supprimer un client\n");
                    printf("0. Retour au menu principal\n");

                    printf("\nVotre choix : ");
                    scanf("%d", &choixClient);

                 switch (choixClient) {

                    case 1:
                    ajouterClient();
                    break;

                    case 2:
                    afficherClients();
                    break;

                    case 3:
                    rechercherClient();
                    break;

                    case 4:
                    modifierClient();
                    break;

                    case 5:
                    supprimerClient();
                    break;

                    case 0:
                    printf("Retour au menu principal...\n");
                    break;

                    default:
                    printf("Choix invalide.\n");
                   }

                } while (choixClient != 0);

            break;
            }

            case 2: {
                int choixCompte;

                do {
                    printf("\n===== GESTION DES COMPTES =====\n");
                    printf("1. Ajouter un compte\n");
                    printf("2. Afficher les comptes\n");
                    printf("3. Rechercher un compte\n");
                    printf("4. Modifier un compte\n");
                    printf("5. Supprimer un compte\n");
                    printf("0. Retour au menu principal\n");
                    printf("Votre choix : ");
                    scanf("%d", &choixCompte);

                    switch (choixCompte) {
                        case 1:
                        ajouterCompte();
                        break;

                        case 2:
                        afficherComptes();
                        break;

                        case 3:
                        rechercherCompte();
                        break;

                        case 4:
                        modifierCompte();
                        break;
                        case 5:
                        supprimerCompte();
                        break;

                        case 0:
                        break;
                        default:
                        printf("Choix invalide.\n");
                    }
                } while (choixCompte != 0);

            break;
           } 
            

           
            case 3: {
                int choixTransaction;

                    do {
                    printf("\n===== GESTION DES TRANSACTIONS =====\n");
                    printf("1. Effectuer un depot\n");
                    printf("2. Effectuer un retrait\n");
                    printf("3. Effectuer un virement\n");
                    printf("4. Afficher l'historique\n");
                    printf("0. Retour au menu principal\n");
                    printf("Votre choix : ");

                    if (scanf("%d", &choixTransaction) != 1) {
                        printf("Erreur : veuillez entrer un nombre.\n");
                        viderBuffer();
                        choixTransaction = -1;
                        continue;
                        }
                    switch (choixTransaction) {
                    case 1:
                        effectuerDepot();
                        break;
                    case 2:
                        effectuerRetrait();
                        break;
                    case 3:
                        effectuerVirement();
                        break;
                    case 4:
                        afficherHistorique();
                        break;
                    case 0:
                        printf("Retour au menu principal...\n");
                        break;

                    default:
                        printf("Choix invalide.\n");
                    }

                    } while (choixTransaction != 0);

            break;
            }

               
            case 4: {
                int choixRecherche;

                    do {
                    printf("\n===== MENU RECHERCHE =====\n");
                    printf("1. Rechercher un client\n");
                    printf("2. Rechercher un compte\n");
                    printf("0. Retour au menu principal\n");
                    printf("Votre choix : ");

                    scanf("%d", &choixRecherche);

                    switch (choixRecherche) {
                    case 1:
                    rechercherClient();
                    break;

                    case 2:
                    rechercherCompte();
                    break;

                    case 0:
                    printf("Retour au menu principal...\n");
                    break;

                    default:
                    printf("Choix invalide.\n");
                    }

                    } while (choixRecherche != 0);

            break;
            }
            case 5:
                afficherStatistiques();
                break;

            case 0:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide.\n");
        }

    } while (choix != 0);

    return 0;
}