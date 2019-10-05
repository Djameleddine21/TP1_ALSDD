#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <ctype.h>
#include "TP.h"
#define NB_FONCTIONALITES 16

int main()
{
    annuaire *p=NULL ;
    char nom[26],ville[26],nom_h[26];
    int sauv=1,stop=0,i;
    system("mode con LINES=40 COLS=110");
    system("color F0");
    esi(35,5,8,0,10);
    chargement();
    color(15,0);
    afficher(sauv);
    while(stop==0)
    {
        char c;
        c=getch();
        if (c =='1')
         sauv=afficher(1);
        else if (c=='2')
         sauv=afficher(2);
        else if (c=='3')
         sauv=afficher(3);
         else if (c=='4')
         sauv=afficher(4);
         else if (c=='5')
         sauv=afficher(5);
         else if (c=='6')
         sauv=afficher(6);
         else if (c=='7')
         sauv=afficher(7);
         else if (c=='8')
         sauv=afficher(8);
         else if (c=='9')
         sauv=afficher(9);
         else if (c=='10')
         sauv=afficher(10);
         else if (c=='11')
         sauv=afficher(11);
         else if (c=='12')
         sauv=afficher(12);
         else if (c=='13')
         sauv=afficher(13);
         else if (c=='14')
         sauv=afficher(14);
         else if (c=='15')
         sauv=afficher(15);
         else if (c=='16')
         sauv=afficher(16);
        else if (c==72)
            {if ((sauv-1)>=1) sauv=afficher(sauv-1);else sauv=afficher(NB_FONCTIONALITES);}
        else if (c==80)
            {if ((sauv+1)<=NB_FONCTIONALITES) sauv=afficher(sauv+1);else sauv=afficher(1);}
        else if (c==13)

        switch(sauv)
        {
            case 1 :
                    p=ajouter_hotels_depuis_un_fichier(p);
                    printf("click Enter ...");
                    getchar();
                    sauv=afficher(1);
                    break;
            case 2 :
                    if (p!=NULL)
                    {
                        sauvgarde_structhotel(p);
                    }
                    else
                    {
                        color(15,12);
                        printf("La liste des hotels est vide !");
                        color(15,0);
                        printf("\n");
                    }
                    printf("click Enter ...");
                    getchar();
                    sauv=afficher(2);
                    break;
            case 3 :
                    p=charger_reservation_depuis_un_fichier(p);
                    printf("click Enter ...");
                    getchar();
                    sauv=afficher(3);
                    break;
            case 4 :
                    if (p!=NULL)
                    {
                        sauvgarder_reservation_dans_un_fichier(p);
                    }
                    else
                    {
                        color(15,12);
                        printf("La liste des hotels est vide !");
                        color(15,0);
                        printf("\n");
                    }
                    printf("click Enter ...");
                    getchar();
                    sauv=afficher(4);
                    break;
            case 5 :
                    if (p!=NULL)
                    {
                        system("cls");
                        printf("\t\t");
                        color(15,1);
                        printf("-----------------------------------------------------------------------\n");
                        color(0,0);
                        printf("\t\t");
                        color(15,1);
                        printf("|                  TP1_ALGO ....... Realise par : SEBBAGH & FODIL     |\n");
                        color(0,0);
                        printf("\t\t");
                        color(15,1);
                        printf("-----------------------------------------------------------------------\n\n\n");
                        color(15,0);
                        affichage_status_de_reservation(p);
                    }
                    else
                    {
                        color(15,12);
                        printf("La liste des hotels est vide !");
                        color(15,0);
                        printf("\n");
                    }
                    printf("click Enter ...");
                    getchar();
                    sauv=afficher(5);
                    break;
            case 6 :
                    if (p!=NULL)
                    {
                        system("cls");
                        printf("\t\t");
                        color(15,1);
                        printf("-----------------------------------------------------------------------\n");
                        color(0,0);
                        printf("\t\t");
                        color(15,1);
                        printf("|                  TP1_ALGO ....... Realise par : SEBBAGH & FODIL     |\n");
                        color(0,0);
                        printf("\t\t");
                        color(15,1);
                        printf("-----------------------------------------------------------------------\n\n\n");
                        color(15,0);
                        afficher_tout_les_hotels(p);
                        printf("Introduire votre nom : \n");
                        scanf("%s",nom);
                        fflush(stdin);
                        for (i=0;i<26;i++)
                        {
                            nom[i]=tolower(nom[i]);
                        }
                        reservation(nom,p);
                    }
                    else
                    {
                        color(15,12);
                        printf("La liste des hotels est vide !");
                        color(15,0);
                        printf("\n");
                    }
                    printf("click Enter ...");
                    getchar();
                    sauv=afficher(6);
                    break;
            case 7 :
                    if (p!=NULL)
                    {
                        system("cls");
                        printf("\t\t");
                        color(15,1);
                        printf("-----------------------------------------------------------------------\n");
                        color(0,0);
                        printf("\t\t");
                        color(15,1);
                        printf("|                  TP1_ALGO ....... Realise par : SEBBAGH & FODIL     |\n");
                        color(0,0);
                        printf("\t\t");
                        color(15,1);
                        printf("-----------------------------------------------------------------------\n\n\n");
                        color(15,0);
                        printf("Introduire votre nom : \n");
                        scanf("%s",nom);
                        fflush(stdin);
                        for (i=0;i<26;i++)
                        {
                            nom[i]=tolower(nom[i]);
                        }
                        printf("Introduire le nom de l'hotel : \n");
                        scanf("%s",nom_h);
                        fflush(stdin);
                        for (i=0;i<26;i++)
                        {
                            nom_h[i]=tolower(nom_h[i]);
                        }
                        printf("Introduire la ville de votre hotel : \n");
                        scanf("%s",ville);
                        fflush(stdin);
                        for (i=0;i<26;i++)
                        {
                            ville[i]=tolower(ville[i]);
                        }
                        modifier_reservation(p,nom_h,ville,nom);
                    }
                    else
                    {
                        color(15,12);
                        printf("La liste des hotels est vide !");
                        color(15,0);
                        printf("\n");
                    }
                    printf("click Enter ...");
                    getchar();
                    sauv=afficher(7);
                    break;
            case 8 :
                    if (p!=NULL)
                    {
                        system("cls");
                        printf("\t\t");
                        color(15,1);
                        printf("-----------------------------------------------------------------------\n");
                        color(0,0);
                        printf("\t\t");
                        color(15,1);
                        printf("|                  TP1_ALGO ....... Realise par : SEBBAGH & FODIL     |\n");
                        color(0,0);
                        printf("\t\t");
                        color(15,1);
                        printf("-----------------------------------------------------------------------\n\n\n");
                        color(15,0);
                        printf("Introduire votre nom : \n");
                        scanf("%s",nom);
                        fflush(stdin);
                        for (i=0;i<26;i++)
                        {
                            nom[i]=tolower(nom[i]);
                        }
                        printf("Introduire le nom de l'hotel : \n");
                        scanf("%s",nom_h);
                        fflush(stdin);
                        for (i=0;i<26;i++)
                        {
                            nom_h[i]=tolower(nom_h[i]);
                        }
                        printf("Introduire la ville de votre hotel : \n");
                        scanf("%s",ville);
                        fflush(stdin);
                        for (i=0;i<26;i++)
                        {
                            ville[i]=tolower(ville[i]);
                        }
                        supprimer_reservation(p,nom_h,ville,nom);
                    }
                    else
                    {
                        color(15,12);
                        printf("La liste des hotels est vide !");
                        color(15,0);
                        printf("\n");
                    }
                    printf("click Enter ...");
                    getchar();
                    sauv=afficher(8);
                    break;
            case 9 :
                    if (p!=NULL)
                    {
                        system("cls");
                        printf("\t\t");
                        color(15,1);
                        printf("-----------------------------------------------------------------------\n");
                        color(0,0);
                        printf("\t\t");
                        color(15,1);
                        printf("|                  TP1_ALGO ....... Realise par : SEBBAGH & FODIL     |\n");
                        color(0,0);
                        printf("\t\t");
                        color(15,1);
                        printf("-----------------------------------------------------------------------\n\n\n");
                        color(15,0);
                        recherche_chambre(p);
                    }
                    else
                    {
                        color(15,12);
                        printf("La liste des hotels est vide !");
                        color(15,0);
                        printf("\n");
                    }
                    printf("click Enter ...");
                    getchar();
                    sauv=afficher(9);
                    break;
            case 10 :
                    if (p!=NULL)
                    {
                        system("cls");
                        printf("\t\t");
                        color(15,1);
                        printf("-----------------------------------------------------------------------\n");
                        color(0,0);
                        printf("\t\t");
                        color(15,1);
                        printf("|                  TP1_ALGO ....... Realise par : SEBBAGH & FODIL     |\n");
                        color(0,0);
                        printf("\t\t");
                        color(15,1);
                        printf("-----------------------------------------------------------------------\n\n\n");
                        color(15,0);
                        printf("Introduire votre nom : \n");
                        scanf("%s",nom);
                        fflush(stdin);
                        for (i=0;i<26;i++)
                        {
                            nom[i]=tolower(nom[i]);
                        }
                        rechercher_reservation_effectuer_par_une_personne(p,nom);
                    }
                    else
                    {
                        color(15,12);
                        printf("La liste des hotels est vide !");
                        color(15,0);
                        printf("\n");
                    }
                    printf("click Enter ...");
                    getchar();
                    sauv=afficher(10);
                    break ;
            case 11 :
                    system("cls");
                    printf("\t\t");
                    color(15,1);
                    printf("-----------------------------------------------------------------------\n");
                    color(0,0);
                    printf("\t\t");
                    color(15,1);
                    printf("|                  TP1_ALGO ....... Realise par : SEBBAGH & FODIL     |\n");
                    color(0,0);
                    printf("\t\t");
                    color(15,1);
                    printf("-----------------------------------------------------------------------\n\n\n");
                    color(15,0);
                    printf("Introduire le nom de l'hotel : \n");
                    scanf("%s",nom_h);
                    fflush(stdin);
                    for (i=0;i<26;i++)
                    {
                        nom_h[i]=tolower(nom_h[i]);
                    }
                    p=rajouter_hotel(p,nom_h);
                    printf("click Enter ...");
                    getchar();
                    sauv=afficher(11);
                    break ;
            case 12 :
                    if (p!=NULL)
                    {
                        system("cls");
                        printf("\t\t");
                        color(15,1);
                        printf("-----------------------------------------------------------------------\n");
                        color(0,0);
                        printf("\t\t");
                        color(15,1);
                        printf("|                  TP1_ALGO ....... Realise par : SEBBAGH & FODIL     |\n");
                        color(0,0);
                        printf("\t\t");
                        color(15,1);
                        printf("-----------------------------------------------------------------------\n\n\n");
                        color(15,0);
                        printf("Introduire le nom de l'hotel : \n");
                        scanf("%s",nom_h);
                        fflush(stdin);
                        for (i=0;i<26;i++)
                        {
                            nom_h[i]=tolower(nom_h[i]);
                        }
                        printf("Introduire la ville de votre hotel : \n");
                        scanf("%s",ville);
                        fflush(stdin);
                        for (i=0;i<26;i++)
                        {
                            ville[i]=tolower(ville[i]);
                        }
                        p=suppression_hotel(nom_h,ville,p);
                    }
                    else
                    {
                        color(15,12);
                        printf("La liste des hotels est vide !");
                        color(15,0);
                        printf("\n");
                    }
                    printf("click Enter ...");
                    getchar();
                    sauv=afficher(12);
                    break ;
            case 13 :
                    if (p!=NULL)
                    {
                        liberer_chambre_ayant_une_date_fin(p);
                    }
                    else
                    {
                        color(15,12);
                        printf("La liste des hotels est vide !");
                        color(15,0);
                        printf("\n");
                    }
                    printf("click Enter ...");
                    getchar();
                    sauv=afficher(13);
                    break;
            case 14 :
                    if (p!=NULL)
                    {
                        p=trier_annuaire(p);
                    }
                    else
                    {
                        color(15,12);
                        printf("La liste des hotels est vide !");
                        color(15,0);
                        printf("\n");
                    }
                    printf("click Enter ...");
                    getchar();
                    sauv=afficher(14);
                    break;
            case 15 :
                system("cls");
                printf("\t\t");
                color(15,1);
                printf("-----------------------------------------------------------------------\n");
                color(0,0);
                printf("\t\t");
                color(15,1);
                printf("|                  TP1_ALGO ....... Realise par : SEBBAGH & FODIL     |\n");
                color(0,0);
                printf("\t\t");
                color(15,1);
                printf("-----------------------------------------------------------------------\n\n\n");
                color(15,0);
                afficher_tout_les_hotels(p);
                printf("click Enter ...");
                getchar();
                sauv=afficher(15);
                break;
            case 16:
                if (p!=NULL)
                {
                    sauvgarde_structhotel(p);
                    sauvgarder_reservation_dans_un_fichier(p);
                }
                default :exit(1);
        }
    }
    return 0;
}
