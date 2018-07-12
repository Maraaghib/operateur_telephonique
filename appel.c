#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Operateur {
    char nom_op[50];
    char* capital_op;
    int nombre_index;
    int liste_index[10]; // Les index doivent être tous différents
    // Les index des opérateurs aussi doivent différents (L'INDEX "9" EST DEJA PRIS PAR UN AUTRE OPERATEUR !!! ENTRER L'INDICE :)
    int prix_abonnement; // Le prix de l'abonnement min est 500 FCFA
    int credit_initial;
    int cout_appel_op;
    int cout_appel_autre_op;
    int cout_appel_inter;
    int cout_sms_op;
    int cout_sms_autre_op;
    int cout_sms_inter;
} Operateur;

Operateur operateur[1000];

int nb_op = 0;

void nouvel_operateur(int *nb_operateurs) {
    int op = 0;
    char ajout_autre_op;

    while(ajout_autre_op == 'O' || ajout_autre_op != 'N') {
        printf("NOM DE L'OPERATEUR :\n");
        scanf("%s", &operateur[op].nom_op);

        operateur[op].capital_op = "1.000.000";
        printf("CAPITAL DE L'OPERATEUR :\n%s\n", operateur[op].capital_op);

        do {
            printf("NOMBRE D'INDEX [MIN : 1]\n");
            scanf("%d", &operateur[op].nombre_index);
        } while (operateur[op].nombre_index < 1);
        for (int i = 0; i < operateur[op].nombre_index; i++) {
            bool doublon;
            do {
                doublon = false;
                printf("ENTRER L'INDICE N %d\n", i+1);
                scanf("%d", &operateur[op].liste_index[i]);
                // Tester si on a donné un index existant
                for (int j = 0; j < op; j++) {
                    for (int k = 0; k < i; k++) {
                        if (operateur[op].liste_index[i] == operateur[j].liste_index[k]) {
                            doublon = true;
                            // todo: Un message pour dire que un autre opérateur détient déjà cet index
                            // L'INDEX "11" EST DEJA PRIS PAR UN AUTRE OPERATEUR !!! ENTRER L'INDICE N 2 :
                        }
                    }
                }
            } while (doublon == true);
        }

        printf("PRIX DE L'ABONNEMENT :\n");
        scanf("%d", &operateur[op].prix_abonnement);
        while (operateur[op].prix_abonnement < 500 ) {
            printf("LE PRIX DE L'ABONNEMENT MIN EST 500 FCFA :\n");
            scanf("%d", &operateur[op].prix_abonnement);
        }

        printf("CREDIT INITIAL : \n");
        scanf("%d", &operateur[op].credit_initial);
        printf("COUT APPEL VERS %s [la seconde] :\n", operateur[op].nom_op);
        scanf("%d", &operateur[op].cout_appel_op);
        printf("COUT APPEL VERS AUTRE OPERATEUR [la seconde] :\n", operateur[op].nom_op);
        scanf("%d", &operateur[op].cout_appel_autre_op);
        printf("COUT APPEL VERS INTERNATIONAL [la seconde] :\n", operateur[op].nom_op);
        scanf("%d", &operateur[op].cout_appel_inter);
        printf("COUT SMS VERS %s [la seconde] :\n", operateur[op].nom_op);
        scanf("%d", &operateur[op].cout_sms_op);
        printf("COUT SMS VERS AUTRE OPERATEUR [la seconde] :\n", operateur[op].nom_op);
        scanf("%d", &operateur[op].cout_sms_autre_op);
        printf("COUT SMS VERS INTERNATIONAL [la seconde] :\n", operateur[op].nom_op);
        scanf("%d", &operateur[op].cout_sms_inter);
        printf("-------\n");

        printf("Voulez-vous ajouter un autre operateur[op] ? [O/N]\n");
        scanf(" %c", &ajout_autre_op);

        while (ajout_autre_op != 'O' && ajout_autre_op != 'N') {
            printf("Repondre par O ou N\n");
            scanf(" %c", &ajout_autre_op);
        }
        op++;
        // if (ajout_autre_op == 'N') {
        //     // break;
        // }
    }

    *nb_operateurs = op; // retourner le nombre total d'operateurs
}

/* Cette fonction rencoie un nombre aleatoire de 7 chiffres pour les numéros de téléphone */
int random_num_tel() {
    int num_tel = 0;
    num_tel +=  ((rand() % 9)+1) * 10000000;
    num_tel +=  ((rand() % 9)+1) * 1000000;
    num_tel +=  ((rand() % 9)+1) * 100000;
    num_tel +=  ((rand() % 9)+1) * 10000;
    num_tel +=  ((rand() % 9)+1) * 1000;
    num_tel +=  ((rand() % 9)+1) * 100;
    num_tel +=  ((rand() % 9)+1) * 10;
    num_tel +=  ((rand() % 9)+1) ;

    return num_tel;
}

void liste_operateurs(int op) {
    printf("OPERATEUR : ................................... %s\n", operateur[op].nom_op);
    printf("CAPITAL : ..................................... %s FCFA\n", operateur[op].capital_op);
    printf("NOMBRE DE VENTES : ............................ 0 FCFA\n");
    printf("ABONNEMENT : .................................. %d FCFA\n", operateur[op].prix_abonnement);
    printf("CREDIT LORS DE L'ABONNEMENT : ................. %d FCFA\n", operateur[op].credit_initial);
    printf("INDEX : ....................................... ");
    for (int i = 0; i < operateur[op].nombre_index; i++) {
        printf("%d ", operateur[op].liste_index[i]);
    }
    printf("\n");
    printf("COUT DES APPELS / SECONDE:\n\n");
    printf("\t\tVERS MEME OPERATEUR: %d FCFA\n", operateur[op].cout_appel_op);
    printf("\t\tVERS AUTRE OPERATEUR: %d FCFA\n", operateur[op].cout_appel_autre_op);
    printf("\t\tVERS INTERNATIONAL: %d FCFA\n", operateur[op].cout_appel_inter);
    printf("LISTE DES NUMEROS :\n\n\n");
    printf("____________________________________________________________________________________________________\n");
    printf("\tINDICE\tNUMERO TEL\tINDICE\tNUMERO TEL\tINDICE\tNUMERO TEL\tINDICE\tNUMERO TEL\n\n");
    printf("____________________________________________________________________________________________________\n");

    int indice = 1;
    for (int i = 1; i <= 25; i++) {
        for (int j = 1; j <= 4; j++) {
            int num_tel = random_num_tel();
            printf("\t%d\t%d", indice, num_tel);
            indice++;
        }
        printf("\n");
        for (int j = 0; j < 4; j++) {
            printf("_________________________");
        }
        printf("\n");
        for (int j = 0; j < 4; j++) {
            printf("_________________________");
        }
        printf("\n");
    }
    printf("\n");
}

void infos_operateur(int nb_operateurs) {
    char nom_cherche[50];
    printf("------------INFO OPERATEUR------------\n\n\n");
    printf("NOM OPERATEUR RECHERCHE : ");
    scanf("%s", &nom_cherche);

    int op = 0;
    while ( op < nb_operateurs && strcmp(operateur[op].nom_op, nom_cherche) != 0) {
        op++;
    }
    if (strcmp(operateur[op].nom_op, nom_cherche) != 0) {
        printf("\n\nAUCUN OPERATEUR TROUVE AVEC LE NOM \"%s\"\n\n", nom_cherche);
    }
    else {
        liste_operateurs(op);
    }
}

void editer_operateur(int nb_operateurs) {
    char nom_cherche[50];
    printf("------------EDITER UN OPERATEUR------------\n\n\n");
    printf("NOM OPERATEUR A  EDITER : ");
    scanf("%s", &nom_cherche);

    int op = 0;
    while ( op < nb_operateurs && strcmp(operateur[op].nom_op, nom_cherche) != 0) {
        op++;
    }
    if (strcmp(operateur[op].nom_op, nom_cherche) != 0) {
        printf("\n\nAUCUN OPERATEUR TROUVE AVEC LE NOM \"%s\"\n\n", nom_cherche);
    }
    else {
        printf("ANCIEN NOM : %s\n", operateur[op].nom_op);
        printf("NOUVEAU NOM [tapez 0 pour ne pas modifier] : ");
        char nom_op[50];
        scanf("%s", &nom_op);
        if (strcmp(nom_op, "0") != 0) { // Si l'utilisateur a saisi autre chose que 0
            strcpy(operateur[op].nom_op, nom_op); // Modifier
        }
        printf("ANCIEN PRIX ABONNEMENT : %d\n", operateur[op].prix_abonnement);
        printf("NOUVEAU PRIX ABONNEMENT [tapez -1 pour ne pas modifier] : ");
        int prix_abonnement;
        scanf("%d", &prix_abonnement);
        if (prix_abonnement != -1) { // Si l'utilisateur a saisi autre chose que -1
            operateur[op].prix_abonnement = prix_abonnement; // Modifier
        }
        printf("ANCIEN MONTANT CREDIT ABONNEMENT : %d\n", operateur[op].credit_initial);
        printf("NOUVEAU MONTANT CREDIT ABONNEMENT [tapez -1 pour ne pas modifier] : ");
        int credit_initial;
        scanf("%d", &credit_initial);
        if (credit_initial != -1) { // Si l'utilisateur a saisi autre chose que -1
            operateur[op].credit_initial = credit_initial; // Modifier
        }
        printf("ANCIEN COUT APPEL MEME OPERATEUR : %d\n", operateur[op].cout_appel_op);
        printf("NOUVEAU COUT APPEL MEME OPERATEUR [tapez -1 pour ne pas modifier] : ");
        int cout_appel_op;
        scanf("%d", &cout_appel_op);
        if (cout_appel_op != -1) { // Si l'utilisateur a saisi autre chose que -1
            operateur[op].cout_appel_op = cout_appel_op; // Modifier
        }
        printf("ANCIEN COUT APPEL AUTRE OPERATEUR : %d\n", operateur[op].cout_appel_autre_op);
        printf("NOUVEAU COUT APPEL AUTRE OPERATEUR [tapez -1 pour ne pas modifier] : ");
        int cout_appel_autre_op;
        scanf("%d", &cout_appel_autre_op);
        if (cout_appel_autre_op != -1) { // Si l'utilisateur a saisi autre chose que -1
            operateur[op].cout_appel_autre_op = cout_appel_autre_op; // Modifier
        }
        printf("ANCIEN COUT APPEL INTERNATIONAL : %d\n", operateur[op].cout_appel_inter);
        printf("NOUVEAU COUT APPEL INTERNATIONAL [tapez -1 pour ne pas modifier] : ");
        int cout_appel_inter;
        scanf("%d", &cout_appel_inter);
        if (cout_appel_inter != -1) { // Si l'utilisateur a saisi autre chose que -1
            operateur[op].cout_appel_inter = cout_appel_inter; // Modifier
        }
        printf("ANCIEN COUT SMS MEME OPERATEUR : %d\n", operateur[op].cout_sms_op);
        printf("NOUVEAU COUT SMS MEME OPERATEUR [tapez -1 pour ne pas modifier] : ");
        int cout_sms_op;
        scanf("%d", &cout_sms_op);
        if (cout_sms_op != -1) { // Si l'utilisateur a saisi autre chose que -1
            operateur[op].cout_sms_op = cout_sms_op; // Modifier
        }
        printf("ANCIEN COUT SMS AUTRE OPERATEUR : %d\n", operateur[op].cout_sms_autre_op);
        printf("NOUVEAU COUT SMS AUTRE OPERATEUR [tapez -1 pour ne pas modifier] : ");
        int cout_sms_autre_op;
        scanf("%d", &cout_sms_autre_op);
        if (cout_sms_autre_op != -1) { // Si l'utilisateur a saisi autre chose que -1
            operateur[op].cout_sms_autre_op = cout_sms_autre_op; // Modifier
        }
        printf("ANCIEN COUT SMS INTERNATIONAL : %d\n", operateur[op].cout_sms_inter);
        printf("NOUVEAU COUT SMS INTERNATIONAL [tapez -1 pour ne pas modifier] : ");
        int cout_sms_inter;
        scanf("%d", &cout_sms_inter);
        if (cout_sms_inter != -1) { // Si l'utilisateur a saisi autre chose que -1
            operateur[op].cout_sms_inter = cout_appel_inter; // Modifier
        }
    }
}

void menu_principal() {
    int choix;

    system("cls");

    while(choix < 1 || choix > 11) {
        printf("-------------MENU PRINCIPAL------------\n");
        printf("1......................NOUVEL OPERATEUR\n");
        printf("2..................LISTE DES OPERATEURS\n");
        printf("3........................INFO OPERATEUR\n");
        printf("4...................EDITER UN OPERATEUR\n");
        printf("5.....................AJOUTER DES INDEX\n");
        printf("---------------------------------------\n");
        printf("6.....................NOUVEL ABONNEMENT\n");
        printf("7................ABONNES D'UN OPERATEUR\n");
        printf("8..........................INFOS ABONNE\n");
        printf("---------------------------------------\n");
        printf("9.......................ACHAT DE CREDIT\n");
        printf("---------------------------------------\n");
        printf("10.....................UTILISER MON SIM\n");
        printf("11..............................QUITTER\n");
        printf("FAITES VOTRE CHOIX................... ");
        scanf("%d", &choix);
        if (choix < 1 || choix > 11) {
            printf("CHOIX INDISPONIBLE !!!\n");
            system("pause");
            printf("Appuyer sur une touche pour continuer ... ");
            system("cls");
        }
    }

    switch (choix) {
        case 1:
            system("cls");
            // todo: Amenr la boucle while N || O  de nouvel_operateur ici ?
            nouvel_operateur(&nb_op);
            menu_principal();

            // printf("Le nombre d'operateurs est %d \n", nb_op);
        break;

        case 2:
            system("cls");
            printf("Le nombre d'opérateurs est: %d\n", nb_op);
            for (int op = 0; op < nb_op; op++) {
                liste_operateurs(op);
            }
            system("pause");
            printf("Appuyer sur une touche pour continuer ... ");
            system("cls");
            menu_principal();
        break;

        case 3:
            system("cls");
            infos_operateur(nb_op);
            system("pause");
            printf("Appuyer sur une touche pour continuer ... ");
            system("cls");
            menu_principal();
        break;

        case 4:
            system("cls");
            editer_operateur(nb_op);
            system("pause");
            printf("Appuyer sur une touche pour continuer ... ");
            system("cls");
            menu_principal();
        break;

        case 5:
            system("cls");
            printf("Menu 5\n");
        break;

        case 6:
            system("cls");
            printf("Menu 6\n");
        break;

        case 7:
            system("cls");
            printf("Menu 7\n");
        break;

        case 8:
            system("cls");
            printf("Menu 8\n");
        break;

        case 9:
            system("cls");
            printf("Menu 9\n");
        break;

        case 10:
            system("cls");
            printf("Menu 10\n");
        break;

        case 11:
            exit(EXIT_SUCCESS);
        break;

        default:
        break;
    }
}

int main(int argc, char const *argv[]) {

    menu_principal();

    return 0;
}
