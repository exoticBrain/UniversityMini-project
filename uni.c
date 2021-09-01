// lES BEBLIOTHEQUE NECESSAIRE
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


// Les structures necessaire
typedef char CH[30];
typedef struct {
    int a,m,j;
}Date;

typedef struct {
    char nom[15];
    Date DD;
    int nbE,nbL;
    CH tab[3];
}Universite;


// MENU PRINCIPALE
void   menu() {
    system("cls");
    printf("-------------------- MENU --------------------\n\n");
    printf("1-Remplir le tableau d'Universite\n2-Afficher les Universites disponibles\n3-Modifier une Universite\n4-Supprimer une Universite\n5-Ajouter Fin\n6-Rechercher une Universite par son nom\n7-Quitter\n\nVotre choix --> ");
}

//  Remplir un tableau d'universite
int    remplir(Universite t[100],int n) {
    int nb;
    printf("Veuillez donner le nombres des universites : ");
    scanf("%d",&nb);
    if (n == 100) {
        printf("Tableau plein!\n");
        printf("\n\nPress any key to go back!!\n");
        getch();
    }
    else {

        // La saisie des donnes
        printf("-------------- Veuillez saisir les donnes suivantes --------------\n\n");
        for (int i=n;i<nb+n;i++) {

            printf("\nUniversite --> %d\n\n",i+1);
            printf("Veuillez donner un nom d'uni                        : ");
            scanf("%s",t[i].nom);
            printf("Veuillez donner un nombre d'etudiants               : ");
            scanf("%d",&t[i].nbE);
            printf("Veuillez donner un nombre de licences               : ");
            scanf("%d",&t[i].nbL);

            if (t[i].nbL != 0) {

                printf("\n-------- Donner les licences existants --------\n");
                for (int j=0;j<t[i].nbL;j++) {
                    printf("Veuillez saisir Licences %d                          : ",j+1);
                    scanf("%s",t[i].tab[j]);
                }
                    
            } else {
                printf("\nAucune licence disponible !\n");
            }

            // La saisie d'une DATE
            printf("\n-------- Donner une date --------\n");
            printf("Veuillez saisir un jour                             : ");
            scanf("%d",&t[i].DD.j);
            printf("Veuillez saisir un mois                             : ");
            scanf("%d",&t[i].DD.m);
            printf("Veuillez saisir une annee                           : ");
            scanf("%d",&t[i].DD.a);
        }
        printf("\n\nPress any key to go back!!\n");
        getch();
    }
    n = nb+n;
    return n;
}

// Afficher
void    afficher(Universite t[100], int n) {
    if (n<=0) {
        printf("-------------- Aucune information est disponibles --------------\n\n\nNO DATA !");
        printf("\n\n\n\n\nPress any key to go back!!\n");
        getch();
    } else if (n>=100) {

        printf("\nTableau plein!\n");
        printf("\n\n\n\n\nPress any key to go back!!\n");
        getch();
    } else {

        printf("-------------- Voici les universites disponibles --------------\n\n");

        for (int i=0;i<n;i++) {
            printf("\nUniversite --> %d\n\n",i+1);
            printf("Nom d'universite                                :   %s\n",t[i].nom);
            printf("Le nombre d'etudiants dans l'uni                :   %d\n",t[i].nbE);
            if (t[i].nbL != 0) {

                printf("\n-------- Les licences existants --------\n");
                for (int j=0;j<t[i].nbL;j++) {
                    printf("Licences %d                                      :   %s\n",j+1,t[i].tab[j]);
                }  
            } else {
                printf("\nAucune licence disponible !\n\n");
            }

            // L'affichage d'une DATE
            printf("-------------- %d-%d-%d --------------\n",t[i].DD.j,t[i].DD.m,t[i].DD.a);
        }
    }
}



// Rechercher  Uni
int rechercher(Universite t[100], char val[10], int n) {

    for(int i=0;i<n;i++) {
        if (strcmp(t[i].nom,val)==0)
            return i;
    }
    return -1;
}



// Modifier
void modUni(Universite t[100],char val[10], int n) {

    int pos = rechercher(t,val,n);
    if (pos == -1) {

        printf("\nNom introuvable!\n");
        printf("\n\nPress any key to go back!!\n");
        getch();
    }
    else {

        printf("Veuillez donner un nombre d'etudiants               : ");
        scanf("%d",&t[pos].nbE);
        printf("Veuillez donner un nombre de licences               : ");
        scanf("%d",&t[pos].nbL);
        if (t[pos].nbL != 0) {

            printf("\n-------- Donner les licences existants --------\n");
            for (int j=0;j<t[pos].nbL;j++) {
                printf("Veuillez saisir Licences %d                          : ",j+1);
                scanf("%s",t[pos].tab[j]);
            }                    
        } else {
            printf("\nAucune licence disponible !\n");
        }
        
        // La Modification d'une DATE
        printf("\n-------- Donner une date --------\n");
        printf("Veuillez saisir un jour                             : ");
        scanf("%d",&t[pos].DD.j);
        printf("Veuillez saisir un mois                             : ");
        scanf("%d",&t[pos].DD.m);
        printf("Veuillez saisir une annee                           : ");
        scanf("%d",&t[pos].DD.a);
    }
    printf("\n\nPress any key to go back!!\n");
    getch();
}




// Supprimer 
int supp(Universite t[100],char val[10], int n) {

    int pos;
    // pos= rechercher(t);
    if (pos == -1) {
        printf("\nNom introuvable!\n");
        printf("\n\nPress any key to go back!!\n");
        getch();
    } else {
        int i;
        for(i=pos;i < n;i++) {
            t[i] = t[i+1];
        }
        printf("\nMerci !\n");
        printf("\n\nPress any key to go back!!\n");
        getch();
        n--;
    }
    return n;
}

// Ajouter Fin
int ajouterF(Universite t[], int n) {
    if (n==100) {
        printf("\nTableau plein!\n");
        printf("\n\n\n\n\nPress any key to go back!!\n");
        getch();
        
    } else {
        printf("Veuillez donner un nom d'uni                        : ");
        scanf("%s",t[n].nom);
        printf("Veuillez donner un nombre d'etudiants               : ");
        scanf("%d",&t[n].nbE);
        printf("Veuillez donner un nombre de licences               : ");
        scanf("%d",&t[n].nbL);
        if (t[n].nbL != 0) {
            printf("\n-------- Donner les licences existants --------\n");
            for (int j=0;j<t[n].nbL;j++) {
                printf("Veuillez saisir Licences %d                          : ",j+1);
                scanf("%s",t[n].tab[j]);
            }                    
        } else {
            printf("\nAucune licence disponible !\n");
        }

        // La saisie d'une DATE
        printf("\n-------- Donner une date --------\n");
        printf("Veuillez saisir un jour                             : ");
        scanf("%d",&t[n].DD.j);
        printf("Veuillez saisir un mois                             : ");
        scanf("%d",&t[n].DD.m);
        printf("Veuillez saisir une annee                           : ");
        scanf("%d",&t[n].DD.a);
        n++;
    }
    printf("\n\nPress any key to go back!!\n");
    getch();
    return n;
}


// Ajouter Debut
// int ajouterD(Universite t[], int n) {
//     if (n==100) {
//         printf("\nTableau plein!\n");
//         printf("\n\n\n\n\nPress any key to go back!!\n");
//         getch();
        
//     } else {
//         int i;
//         for (i=n;i>0;i--) {
//             t[i] = t[i-1];
//         }
//         printf("Veuillez donner un nom d'uni                        : ");
//         scanf("%s",t[0].nom);
//         printf("Veuillez donner un nombre d'etudiants               : ");
//         scanf("%d",&t[0].nbE);
//         printf("Veuillez donner un nombre de licences               : ");
//         scanf("%d",&t[0].nbL);
//         if (t[n].nbL != 0) {
//             printf("\n-------- Donner les licences existants --------\n");
//             for (int j=0;j<t[0].nbL;j++) {
//                 printf("Veuillez saisir Licences %d                          : ",j+1);
//                 scanf("%s",t[0].tab[j]);
//             }                    
//         } else {
//             printf("\nAucune licence disponible !\n");
//         }

//         // La saisie d'une DATE
//         printf("\n-------- Donner une date --------\n");
//         printf("Veuillez saisir un jour                             : ");
//         scanf("%d",&t[0].DD.j);
//         printf("Veuillez saisir un mois                             : ");
//         scanf("%d",&t[0].DD.m);
//         printf("Veuillez saisir une annee                           : ");
//         scanf("%d",&t[0].DD.a);
//         n++;
//     }
//     printf("\n\nPress any key to go back!!\n");
//     getch();
//     return n;
// }

// Rechercher et afficher
void    rechercherAff(Universite t[100], char val[10], int n) {
    int pos = -1;
    for(int i=0;i<n;i++) {
        if (strcmp(t[i].nom,val)==0)
            pos = i;
    }
    if (pos != -1) {
        printf("\nUniversite --> %d\n\n",pos+1);
        printf("Nom d'universite                                :   %s\n",t[pos].nom);
        printf("Le nombre d'etudiants dans l'uni                :   %d\n",t[pos].nbL);
        if (t[pos].nbL != 0) {

            printf("\n-------- Les licences existants --------\n");
            for (int j=1;j<=t[pos].nbL;j++) {
                printf("Licences %d                                      :   %s\n",j,t[pos].tab[j]);
            }  
        } else {
            printf("\nAucune licence disponible !\n\n");
        }

        // L'affichage d'une DATE
        printf("-------------- %d-%d-%d --------------\n",t[pos].DD.j,t[pos].DD.m,t[pos].DD.a);
        printf("\n\n\nPress any key to go back!!\n");
        getch();
    } else {
        printf("\n\nNom introuvable !\n");
        printf("\n\nPress any key to go back!!\n");
        getch();
    }
}



// Program principale
int     main() {
    
    // Declaration des variables
    int n=0,choix;
    Universite tab[n];
    char test[10];

    // MENU PRINCIPALE
    do {

        menu();
        scanf("%d",&choix);
        system("cls");

        switch (choix) {
            case 1: {
                n=remplir(tab,n);
                break;
            }
            case 2: {
                afficher(tab,n);
                getch();
                break;
            }
            case 3: {
                printf("Veuillez donner un nom d'universite : ");
                scanf("%s", test);
                modUni(tab,test,n);
                break;
            }
            case 4: {
                printf("Veuillez donner un nom d'universite : ");
                scanf("%s", test);
                n=supp(tab,test,n);
                break;
            }
            case 5: {
                n=ajouterF(tab,n);
                break;
            }
            case 6: {
                printf("Veuillez donner un nom d'universite : ");
                scanf("%s", test);
                rechercherAff(tab, test,n);
                break;
            }
            default:
                break;
        }
    }while(choix != 7);
    
    return 0;
}
