#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "TP.h"
#define NB_FONCTIONALITES 16
/////////////////////////////////// *** LES MODULES POUR AFFICHE LE MENU *** //////////////////////////////////////////////////////
//define les tableaux 1 lignage
#define _1 192
#define _2 193
#define _3 217
#define _4 195
#define _5 197
#define _6 180
#define _7 218
#define _8 194
#define _9 191
#define _0 179
#define _ 196
//define un etablea 2 soulignage
#define __1 200
#define __2 202
#define __3 188
#define __4 204
#define __5 206
#define __6 185
#define __7 201
#define __8 203
#define __9 187
#define __0 186
#define __ 205
//////////////////////////////////////// *** MODULE POUR  GO TO UNE PLACE SPECIFIE *** //////////////////////////////////////////
void gotoxy(int xpos, int ypos)
{
        COORD scrn;
        HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

        scrn.X = xpos-1;
        scrn.Y = ypos;
        SetConsoleCursorPosition(hOuput, scrn);
}
///////////////////////////////// **** MODULE DES COULEURS *** /////////////////////////////////////////////////////////
void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}
//////////////////////////////// *** MODULE POUR STOPER LE SYSTEME *** /////////////////////////////////////////////////
int delay(int x) // faire un puase au system pendant c millierseconds
{
	clock_t t1,t2;
	float tmp;
	int ii;
	t1=clock();
	do
	{
		t2=clock();
		tmp=(float)(t2-t1)*1000/CLOCKS_PER_SEC ;

	} while (tmp < x);
	return 0;

}
//////////////////////////// *** MODULE POUR EFFACER L'ECRAN *** ///////////////////////////////////////////////////////////////
void clr_pro(int t,int lig )
{
	int i,j ;
	for (i=110;i>=0;i--)
	{
		if (i == 54) break;
		for (j=lig;j<40;j++)
		{
			gotoxy(i,j);

			color(0,0);
			printf(" ");
			gotoxy(109-i,38-j);
			printf(" ");
		}
		delay(t);
	}
	gotoxy(109,39);

	return ;
}
///////////////////////////////////////// *** MODULE POUR AFFICHE LE CHARGEMENT *** /////////////////////////////////////////////
void chargement()
{
	int h ;
	color(0,15);
	gotoxy(45,20);
	printf("Chargement en cours");
	for (h=0;h<100;h++)
	{
		gotoxy(6+h,22);
		color(9,9);
		printf("  ");
		color(0,15);
		gotoxy(53,21);
		printf("%d%c",h+1,37);
		gotoxy(130,39);
		color(15,15);
		printf(" ");
		if ((h >60) && (h <80)) delay(90);
		else delay(20);
	}
	gotoxy(38,30);
	color(15,0);
	printf("press any key to continue ...");
	getch();
	clr_pro(0,0);
	return ;
}
/////////////////////////////////////////// *** MODULE POUR L'ECRIRE *** ////////////////////////////////////////////////////
int ecrire(char ss[],int tm) // ecrier une chaine de caractaire avec un delay entre les caracteres
{
	int uu ;
	for (uu=0;uu<strlen(ss);uu++)
	{
		delay(tm);
		printf("%c",ss[uu]);

	}
}
/////////////////////////////////////////// *** MODULE POUR ECRIRE ESI *** ///////////////////////////////////////////////////
void esi (int x, int y,int fond,int couleur,int t)
{
	color(couleur,couleur);
	// E
	gotoxy(x,y);
	printf("*******");
	delay(t);
	gotoxy(x,y+1);
	printf("*******");
	delay(t);
	gotoxy(x,y+2);
	printf("**");
	delay(t);
	gotoxy(x,y+3);
	printf("*****");
	delay(t);
	gotoxy(x,y+4);
	printf("*****");
	delay(t);
	gotoxy(x,y+5);
	printf("**");
	delay(t);
	gotoxy(x,y+6);
	printf("*******");
	delay(t);
	gotoxy(x,y+7);
	printf("*******");
	delay(t);
	// S
	gotoxy(x+8,y+7);
	printf("*******");
	delay(t);
	gotoxy(x+8,y+6);
	printf("*******");
	delay(t);
	gotoxy(x+8+5,y+5);
	printf("**");
	delay(t);
	gotoxy(x+8,y+4);
	printf("*******");
	delay(t);
	gotoxy(x+8,y+3);
	printf("*******");
	delay(t);
	gotoxy(x+8,y+2);
	printf("**");
	delay(t);
	gotoxy(x+8,y+1);
	printf("*******");
	delay(t);
	gotoxy(x+8,y);
	printf("*******");
	delay(t);
	// I
	int ii=0,jj=0;
	for (jj=0;jj<6;jj++)
	{
        for (ii = 0;ii<3;ii++)
        {
            gotoxy(x+16+ii,y+7-jj);
            printf("*");
            delay(t);
        }
	}
	// tete
	for (ii=0;ii<3;ii++)
	{
	switch (ii)
	{
	case 0 : color(4,7);
			break;
	case 1 : color(10,7);
			break;
	case 2 : color(9,7);
			break ;
	}
	gotoxy(x+16,y+1);
	printf("%c",_1);
	delay(t);
	gotoxy(x+17,y+1);
	printf("%c",_);
	delay(t);
	gotoxy(x+18,y+1);
	printf("%c",_3);
	delay(t);
	gotoxy(x+16,y);
	printf("%c",_7);
	delay(t);
	gotoxy(x+17,y);
	printf("%c",_);
	delay(t);
	gotoxy(x+18,y);
	printf("%c",_9);
	delay(t);
	}
	color(9,7);
    gotoxy(x+21,y+1);
    ecrire("Ecole nationale\n",20);
    gotoxy(x+21,y+3);
    ecrire("Superieure\n",20);
    gotoxy(x+21,y+5);
    ecrire("d'Informatique",20);
	gotoxy(110,39);
	printf("\n\n\n");
	return;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void textbackground(int bcolor)
{
     WORD wColor;
     //We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        //make a color form the current backgound and our forground color
          wColor = (csbi.wAttributes & 0xF) | ((bcolor  << 4 ) & 0xF0);
          SetConsoleTextAttribute(hStdOut, wColor);

     }
}
int wherey()
{
        CONSOLE_SCREEN_BUFFER_INFO coninfo;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
        return coninfo.dwCursorPosition.Y;
}

int afficher(int i) //concerne affichage de menu
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
    char * tab[]={"1-> Charger les hotels depuis un fichier\n","2-> Sauvgareder les hotels dans un fichier\n","3-> Charger les reservations depuis un fichier Texte\n","4-> Sauvegarder les reservations dans un fichier texte\n","5-> Affichage du statut des Reservations\n","6-> Inserer une nouvelle Reservation\n","7-> Modifier une Reservation\n","8-> Supprimer une reservation\n","9-> Rechercher une chambre libre selon son type (individuelle ou a deux)\n","10-> Rechercher la Reservation effectuee par une personne \n","11-> Rajouter un hotel\n","12-> Supprimer un hotel\n","13-> Liberer toutes les chambres occupees ayant une date de fin egale a la date du jour\n","14-> Trier les listes des hotels par ordre alphabetique\n","15-> Affiche tous les hotels\n","16-> Quitter\n\n"};
    int j=0;
    while (j<16)
    {
        if (j+1 == i)  textbackground(12);
        else textbackground(0);
        {
            gotoxy(10,wherey());
            printf("%s\n",tab[j]);
        }
        j++;
    }
        textbackground(0);
   int choix=i;
   return choix;
}
///////////////////////////////// *** LA MACHINE ABSTRAITE *** /////////////////////////////////////////////////////////////////
annuaire * allouer_annuaire(annuaire *p)
{
    p=malloc(sizeof(annuaire));
    p->tete_h=malloc(sizeof(hotel));
    p->tete_h->tete_ch=malloc(sizeof(chambres)) ;
    return p ;
}
hotel * allouer_hotel(hotel *h)
{
    h=malloc(sizeof(hotel));
    h->tete_ch=malloc(sizeof(chambres)) ;
    return h ;
}
chambres * allouer_chambre(chambres *c)
{
    c=malloc(sizeof(chambres)) ;
    return c ;
}
void aff_adr_annuaire(annuaire **p,annuaire **q)
{
        (*p)->suiv=(*q) ;
}
void aff_adr_hotel(hotel **h,hotel **l)
{
    (*h)->suiv=(*l) ;
}
void aff_adr_chambre(chambres **c,chambres **ca)
{
    (*c)->suiv=(*ca) ;
}
void liberer_annuaire(annuaire *p)
{
    hotel *h,*ha ;
    chambres *c,*ca;
    c=p->tete_h->tete_ch ;
    h=p->tete_h ;
    while (h!=NULL)
    {
        while (c!=NULL)
        {
            ca=c->suiv ;
            free(c);
            c=ca;
        }
        ha=h->suiv ;
        free(h);
        h=ha ;
    }
    free(p);
}
void liberer_hotel(hotel *h)
{
    chambres *c,*ca ;
    c=h->tete_ch ;
    while (c!=NULL)
    {
        ca=c->suiv ;
        free(c);
        c=ca;
    }
    free(h);
}
void liberer_chambre(hotel *c)
{
    free(c) ;
}
int prix_hotel (hotel *h)
{
    return h->tete_ch->prix ;
}
int capacite_hotel(hotel *h)
{
    return h->capacite ;
}
char nom_hotel(hotel *h)
{
    return h->nom ;
}
char ville_hotel(hotel *h)
{
    return h->ville ;
}
int nb_chambre_occ(hotel *h)
{
    return h->nb_occ ;
}
int nb_chambre_lib(hotel *h)
{
    return h->nb_lib ;
}
int nb_chambre_ind(hotel *h)
{
    return h->ch_individuel ;
}
int nb_chambre_deux(hotel *h)
{
    return h->ch_deux ;
}
annuaire * suiv_annuaire(annuaire *p)
{
    return p->suiv ;
}
hotel * suiv_hotel(hotel *h)
{
    return h->suiv ;
}
chambres * suiv_chambre(chambres *c)
{
    return c->suiv ;
}
int num_chambre (chambres *c)
{
    return c->nemuro ;
}
char valeur_annuaire (annuaire *p)
{
    return p->alpha ;
}
hotel * tete_hotel (annuaire *p)
{
    return p->tete_h ;
}
chambres * tete_chambre (hotel *h)
{
   return h->tete_ch ;
}
chambres * occ_chambre (hotel *h)
{
    return h->occ_ch ;
}
chambres * lib_chambre(hotel *h)
{
    return h->lib_ch ;
}
void aff_prix(chambres **c,int prix )
{
    (*c)->prix=prix ;
}
void aff_numero(chambres **c ,int n)
{
    (*c)->nemuro=n ;
}
int statut_ch (chambres *c)
{
    return c->statut ;
}
int type_ch(chambres *c)
{
    return c->type ;
}
/////////////////////////////////  *** LES MODULES PRINCIPALE *** //////////////////////////////////////////////////////////////
annuaire * suppression_hotel(char nom_hotel[26] ,char ville_hotel[26],annuaire *tete)
{
    char ch;
    boolean trouv1=faux, trouv2=faux;
    annuaire *p,*q=NULL;
    hotel *h,*ha=NULL;
    ch=nom_hotel[0];
    p=tete;
    while ((p != NULL)&&(trouv1==faux))  //parcours de la liste annuaire pour trouver la lettre dont il commence l'hotel
    {
        if (p->alpha==nom_hotel[0])
        {
            trouv1=vrai ;
            h=p->tete_h ;
            while ((h!=NULL)&&(trouv2==faux))
            {
                if ((strcmp(nom_hotel,h->nom)==0)&&(strcmp(ville_hotel,h->ville)==0))
                {
                    trouv2=vrai ;
                    liberer_toute_les_chambres(h->tete_ch);
                    if (ha==NULL)  // i.e: h est le premier hotel
                    {
                        if (h->suiv==NULL) // h est le seul hotel ou bien le dernier
                        {
                            if (q==NULL)    // le premier hotel dans la liste des hotels et annuaire
                            {
                                if ( p->suiv==NULL)
                                {
                                    free(h);
                                    free(p);
                                    tete=NULL;
                                }
                                else
                                {
                                    tete=p->suiv ;
                                    free(h) ;
                                    free(p);
                                }
                            }
                            else   // q!=NULL
                            {
                                if (p->suiv==NULL)
                                {
                                    q->suiv=NULL ;
                                    free(h);
                                    free(p);
                                }
                                else
                                {
                                    q->suiv=p->suiv ;
                                    free(h);
                                    free(p);
                                }
                            }
                        }
                        else  // suivant(h)!=NULL
                        {
                            if (q==NULL)
                            {
                                p->tete_h=h->suiv ;
                                free(h);
                            }
                            else
                            {
                                p->tete_h=h->suiv;
                                free(h);
                            }
                        }
                    }
                    else   // ha!=NULL  i.e : h n'est pas la tete de laa liste des hotels
                    {
                        if (h->suiv==NULL)
                        {
                            ha->suiv=NULL ;
                            free(h);
                        }
                        else
                        {
                            ha->suiv=h->suiv ;
                            free(h);
                        }
                    }
                }
                else
                {
                    ha=h ;
                    h=h->suiv ;
                }
            }
        }
        else
        {
            q=p;
            p=p->suiv ;
        }
    }
    if ((trouv2==faux)||(trouv1==faux))
    {
        color(15,12);
        printf("le nom de l'hotel n'existe pas !");
        color(15,0);
        printf("\n");
    }
    return tete;
}
///////////////////////////////////////////////////////////////////////////////
chambres *  liberer_toute_les_chambres(chambres *tete)
{
    chambres *a ;
    while (tete != NULL)
    {
        a=tete;
        tete=tete->suiv;
        free(a);
    }
  return(NULL);
}
///////////////////////////////////////////////////////////////////////////////
void reservation(char nom_reservateur[26],annuaire * tete)
{
    boolean trouv1=faux,trouv2=faux,trouv3=faux;
    char nom_hotel[26],nom_ville[26],ch;
    int number,i;
    if (tete!=NULL)
    {
        color(15,0);
        printf("Introduire le nom de l'hotel que vous voulez : \n");
        scanf("%s",nom_hotel);
        fflush(stdin);
        for (i=0;i<26;i++)
        {
            nom_hotel[i]=tolower(nom_hotel[i]);
        }
        printf("Introduire la ville de votre hotel : \n");
        scanf("%s",nom_ville);
        fflush(stdin);
        for (i=0;i<26;i++)
        {
            nom_ville[i]=tolower(nom_ville[i]);
        }
        ch=nom_hotel[0];
        annuaire * p =tete;
        chambres * c,*m=NULL,*ca,*l;
        int jj=0,mm=0,aaaa=0,jour=0,mois=0,annee=0;
        while ((p!=NULL)&&(trouv1==faux))
        {
            if((p->alpha)== ch)
            {
                trouv1=vrai;
            }
            else
            {
                p=p->suiv;
            }
        }
            if (trouv1 == vrai)
            {
                hotel * q = p->tete_h;
                while ((q!=NULL)&&(trouv2==faux))
                {
                    if ((strcmp(q->nom,nom_hotel)== 0)&&(strcmp(q->ville,nom_ville)== 0))
                    {
                        printf("Quel est le type de chambre que vous voulez prendre individuel ou a deux :\n");
                        printf("    -> Entrez '0' pour individuel \n");
                        printf("    -> Entrez '1' pour a deux \n");
                        scanf("%d",&number);
                        fflush(stdin);
                        c =q->tete_ch;
                        while ((c!=NULL)&&(trouv3==faux))
                        {
                            if ((c->statut == 0 )&&(c->type == number))
                            {
                                strcpy(c->nom,nom_reservateur);
                                printf("Veulliez precisez la date :\n");
                                printf("    le jour est : ");
                                scanf("%d",&jj);
                                fflush(stdin);
                                printf("    le mois est : ");
                                scanf("%d",&mm);
                                fflush(stdin);
                                printf("    l'annee est : ");
                                scanf("%d",&aaaa);
                                fflush(stdin);
                                c->date_debut.jour=jj;
                                c->date_debut.mois=mm;
                                c->date_debut.annee=aaaa;
                                printf("Veulliez precisez la date du fin de votre sejour :  \n");
                                printf("    le jour est : ");
                                scanf("%d",&jour);
                                fflush(stdin);
                                printf("    le mois est : ");
                                scanf("%d",&mois);
                                fflush(stdin);
                                printf("    l'annee est : ");
                                scanf("%d",&annee);
                                fflush(stdin);
                                printf("le numero de votre chambre est : ");
                                color(15,4);
                                printf("  %d  ",c->nemuro);
                                color(15,0);
                                printf("\n");
                                printf("    Vous allez recuperer cette chambre a la date suivante : ");
                                color(15,4);
                                printf("  %d-%d-%d  ",jj,mm,aaaa);
                                color(15,0);
                                printf("\n");
                                printf("    Votre sejour se termine a la date suivante : ");
                                color(15,4);
                                printf(" %d-%d-%d  ",jour,mois,annee);
                                color(15,0);
                                printf("\n");
                                c->date_fin.jour=jour;
                                c->date_fin.mois=mois;
                                c->date_fin.annee=annee;
                                c->statut=occupe ;
                                q->nb_occ=q->nb_occ+1 ;
                                q->nb_lib=q->nb_lib-1 ;
                                if (c == q->tete_ch)
                                {
                                    q->occ_ch=q->tete_ch;
                                    q->lib_ch=q->tete_ch->suiv;
                                }
                                else
                                {
                                    m->suiv=c->suiv;
                                    c->suiv=q->tete_ch ;
                                    q->tete_ch=c;
                                    q->occ_ch=q->tete_ch;
                                    q->lib_ch=q->tete_ch->suiv;
                                    while (c!=NULL)
                                    {
                                        if(c->statut==libre)
                                        {
                                            q->lib_ch=c ;
                                            break ;
                                        }
                                        else
                                        {
                                            c=c->suiv ;
                                        }
                                    }
                                }
                                trouv3=vrai;
                                trouv2=vrai;
                            }
                            else
                            {
                                m=c;
                                c=c->suiv;
                            }
                        }
                        if (trouv3==faux)
                        {
                            color(15,12);
                            printf("Desole l'hotel que vous avez choisis est saturee !");
                            color(15,0);
                            printf("\n");
                        }
                    }
                    else
                    {
                        q=q->suiv;
                    }
                }
                if (trouv2==faux)
                {
                    color(15,12);
                    printf("le nom que vous avez introduire n'existe pas dans la liste des hotels !");
                    color(15,0);
                    printf("\n");
                }
            }
            else
            {
                color(15,12);
                printf("L'hotel que vous avez introduire n'existe pas !");
                color(15,0);
                printf("\n");
            }
    }
    else
    {
        color(15,12);
        printf("La liste des hotels est vide !");
        color(15,0);
        printf("\n");
    }
    sauvgarder_reservation_dans_un_fichier(tete);
    sauvgarde_structhotel(tete);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void afficher_tout_les_hotels(annuaire * tete)
{
    annuaire * p = tete;
    if (tete!=NULL)
    {
        while (p!=NULL)
        {
            hotel * q=(p->tete_h);
            while (q!=NULL)
            {
                color(15,6);
                printf("Le nom de l'hotel : %s",q->nom);
                color(15,0);
                printf("\n");
                printf("    La ville de l'hotel est : %s \n",q->ville);
                printf("    Le prix est : %d DA \n",q->tete_ch->prix);
                printf("\n");
                q=q->suiv;
            }
            p=p->suiv;
        }
    }
    else
    {
        color(15,12);
        printf("la liste des hotels est vide !");
        color(15,0);
        printf("\n");
    }
}
/////////////////////////////////////////////// *** CREAT ANNUAIRE *** /////////////////////////////////////////////////////////
void creat_annuaire(annuaire *q,char nom[26],char ville[26])
{
    annuaire *p;
    hotel *h ;
    int v,m=0,n=0,a ;
    p=malloc(sizeof(annuaire));
    h=malloc(sizeof(hotel));
    h->occ_ch=NULL;
    p->tete_h=h ;
    p->alpha=nom[0];
    strcpy(p->tete_h->nom,nom);
    strcpy(p->tete_h->ville,ville) ;
    color(15,0);
    printf("Introduire la capacite de votre hotel : \n");
    scanf("%d",&v);
    fflush(stdin);
    p->tete_h->capacite=v ;
    p->tete_h->nb_lib=v;
    while (n+m!=v)
    {
        color(15,0);
        printf("Introduire le nombre des chambres a deux : \n");
        scanf("%d",&m);
        fflush(stdin);
        printf("Introduire le nombre des chambres individuelle : \n");
        scanf("%d",&n);
        fflush(stdin);
        if (n+m!=v)
        {
            color(15,12);
            printf("OOOPS il faut que la somme des deux type de chambre = %d ... \n",v);
        }
    }
    p->tete_h->ch_deux=m;
    p->tete_h->ch_individuel=n;
    color(15,0);
    printf("Introduire le prix : \n");
    scanf("%d",&a);
    p->tete_h->tete_ch=remplir_chambres(m,n,a);
    p->tete_h->lib_ch=p->tete_h->tete_ch;
    q->suiv=p ;
    p->tete_h->suiv=NULL;
    p->suiv=NULL ;
}
////////////////////////////////////////////////// *** INSERER HOTEL *** ////////////////////////////////////////////////////////
void inserer_hotel(hotel *ha,char nom[26],char ville[26])
{
   hotel *h ;
   int v,n=0,m=0,a;
    h=malloc(sizeof(hotel));
    strcpy(h->nom,nom);
    strcpy(h->ville,ville);
    h->occ_ch=NULL;
    color(15,0);
    printf("Introduire la capacite de votre hotel : \n");
    scanf("%d",&v);
    fflush(stdin);
    h->capacite=v ;
    h->nb_lib=v;
    h->nb_occ=0;
    while (n+m!=v)
    {
        color(15,0);
        printf("Introduire le nombre des chambres a deux : \n");
        scanf("%d",&m);
        fflush(stdin);
        printf("Introduire le nombre des chambres individuelle : \n");
        scanf("%d",&n);
        fflush(stdin);
        if (n+m!=v)
        {
            color(15,12);
            printf("OOOPS il faut que la somme des deux type de chambre = %d ...",v);
        }
    }
    h->ch_deux=m;
    h->ch_individuel=n;
    color(15,0);
    printf("\n");
    printf("Introduire le prix : \n");
    scanf("%d",&a);
    if (ha!=NULL)
    {
        ha->suiv=h ;
        h->suiv=NULL ;
        h->tete_ch=remplir_chambres(m,n,a);
        h->lib_ch=h->tete_ch;
    }
    else
    {
        h->suiv=NULL ;
        ha=h ;
        ha->tete_ch=remplir_chambres(m,n,a);
        ha->lib_ch=h->lib_ch;
    }
}
/////////////////////////////////////////////// *** REMPLIR LISTE DES CHAMBRES *** /////////////////////////////////////////////
chambres * remplir_chambres(int m,int n,int a)
{
    chambres *c,*ca,*tete_ch;
    int i ;
    c=malloc((sizeof(chambres)));
    c->nemuro=1 ;
    c->prix=a ;
    c->statut=libre ;
    c->type=deux ;
    tete_ch=c ;
    for (i=1;i<=n+m;i++)
    {
        if (i<m)
        {
            ca=malloc(sizeof(chambres));
            ca->nemuro=i+1 ;
            ca->prix=a ;
            ca->statut=libre ;
            ca->type=deux ;
            c->suiv=ca ;
            c=ca ;
        }
        else
        {
            ca=malloc(sizeof(chambres));
            ca->nemuro=i+1 ;
            ca->prix=a ;
            ca->statut=libre ;
            ca->type=individuel ;
            c->suiv=ca;
            c=ca ;
        }
    }
    c->suiv=NULL ;
    return tete_ch ;
}
////////////////////////////////////////////////// ***  RAJOUTER HOTEL  *** /////////////////////////////////////////////////////
annuaire * rajouter_hotel(annuaire *tete,char nom[26])
{
    annuaire *p,*q ;
    hotel *h,*ha ;
    chambres *c ;
    char ville[26],ligne[256];
    booleen b=faux ,t=faux;
    int v,n=0,m=0,a,i ;
    FILE *fic=fopen("structhotel.txt","r");
    if (fgets(ligne,256,fic)!=NULL)
    {
        tete=ajouter_hotels_depuis_un_fichier(tete);
    }
    if (tete==NULL)
    {
        tete=malloc(sizeof(annuaire));
        h=malloc(sizeof(hotel));
        c=malloc(sizeof(chambres));
        tete->tete_h=h ;
        tete->tete_h->tete_ch=c ;
        for (i=0;i<26;i++)
        {
            nom[i]=tolower(nom[i]);
        }
        tete->alpha=nom[0];
        strcpy(tete->tete_h->nom,nom) ;
        color(15,0);
        printf("Introduire la ville de votre hotel : \n");
        scanf("%s",ville);
        fflush(stdin);
        for (i=0;i<26;i++)
        {
            ville[i]=tolower(ville[i]);
        }
        strcpy(tete->tete_h->ville,ville);
        printf("Introduire la capacite de votre hotel : \n");
        scanf("%d",&v);
        tete->tete_h->capacite=v;
        tete->tete_h->nb_lib=v;
        tete->tete_h->nb_occ=0;
        while (n+m!=v)
        {
            color(15,0);
            printf("Introduire le nombre des chambres a deux : \n");
            scanf("%d",&m);
            fflush(stdin);
            printf("Introduire le nombre des chambres individuelle : \n");
            scanf("%d",&n);
            fflush(stdin);
            if (n+m!=v)
            {
                color(15,12);
                printf("OOOPS il faut que la somme des deux type de chambre = %d ... ",v);
                color(15,0);
                printf("\n");
            }
        }
        tete->tete_h->ch_deux=m;
        tete->tete_h->ch_individuel=n;
        color(15,0);
        printf("Introduire le prix : \n");
        scanf("%d",&a);
        tete->tete_h->tete_ch=remplir_chambres(m,n,a);
        tete->tete_h->occ_ch=NULL ;
        tete->tete_h->lib_ch=tete->tete_h->tete_ch;
        tete->suiv=NULL ;
        tete->tete_h->suiv=NULL;
    }
            //////////**************** TETE != NULL *********************/////////////
    else
    {
        printf("Introduire la ville de votre hotel : \n");
        scanf("%s",ville);
        fflush(stdin);
        for (i=0;i<26;i++)
        {
            ville[i]=tolower(ville[i]);
        }
        p=tete ;
        while ((p!=NULL)&&(b==faux))
        {
            if (p->alpha==nom[0])
            {
                h=p->tete_h ;
                while ((h!=NULL)&&(t==faux))
                {
                    if ((strcmp(nom,h->nom)==0)&&(strcmp(ville,h->ville)==0))
                    {
                        color(15,12);
                        printf("L'hotel que vous avez introduire deja exister !");
                        b=vrai ;
                        t=vrai ;
                        color(15,0);
                        printf("\n");
                    }
                    else
                    {
                        ha=h ;
                        h=h->suiv ;
                    }
                }
                if (t==faux)
                {
                    inserer_hotel(ha,nom,ville);
                    b=vrai ;
                }
            }
            else
            {
                q=p ;
                p=p->suiv ;
            }
        }
        if (b==faux)
        {
            creat_annuaire(q,nom,ville);
        }
    }
    tete=trier_annuaire(tete);
    sauvgarde_structhotel(tete);
    return tete ;
}
///////////////////////////////////implementation des fichier //////////////////////////////////////////////////
void sauvgarde_structhotel (annuaire * tete)
{
    FILE * fic=fopen("structhotel.txt","w");
    hotel * h=tete->tete_h;
        while (tete != NULL)
        {
            h=tete->tete_h;
            while ( h!=NULL )
            {
                fprintf(fic,"%s # %s # %d # %d # %d # %d # %d # %d #\n",h->nom,h->ville,h->capacite,h->ch_deux,h->ch_individuel,h->tete_ch->prix,h->nb_occ,h->nb_lib);
                h=h->suiv;
            }
            tete=tete->suiv;
        }
    fclose(fic);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
annuaire * ajouter_hotels_automatiquement(annuaire *tete,char nom[26], char ville[26],int prix ,int v,int nb_individuel,int nb_deux,int nb_occ,int nb_lib )
{
    annuaire *p,*q ;
    hotel *h,*ha ;
    chambres *c ;
    booleen b=faux ,t=faux;
    if (tete==NULL)
    {
        tete=malloc(sizeof(annuaire));
        h=malloc(sizeof(hotel));
        c=malloc(sizeof(chambres));
        tete->tete_h=h ;
        tete->tete_h->tete_ch=c ;
        tete->alpha=nom[0];
        strcpy(tete->tete_h->nom,nom) ;
        strcpy(tete->tete_h->ville,ville);
        tete->tete_h->capacite=v;
        tete->tete_h->nb_lib=nb_lib;
        tete->tete_h->nb_occ=nb_occ;
        tete->tete_h->ch_deux=nb_deux;
        tete->tete_h->ch_individuel=nb_individuel;
        tete->tete_h->tete_ch=remplir_chambres(nb_deux,nb_individuel,prix);
        tete->tete_h->occ_ch=NULL ;
        tete->tete_h->lib_ch=tete->tete_h->tete_ch;
        tete->suiv=NULL ;
        tete->tete_h->suiv=NULL;

    }
            //////////**************** TETE != NULL *********************/////////////
    else
    {
        p=tete ;
        while ((p!=NULL)&&(b==faux))
        {
            if (p->alpha==nom[0])
            {
                h=p->tete_h ;
                while ((h!=NULL)&&(t==faux))
                {
                    if ((strcmp(nom,h->nom)==0)&&(strcmp(ville,h->ville)==0))
                    {
                        b=vrai ;
                        t=vrai ;
                    }
                    else
                    {
                        ha=h ;
                        h=h->suiv ;
                    }
                }
                if (t==faux)
                {
                    inserer_hotel_autaumatique(ha,nom,ville,v,nb_deux,nb_individuel,prix,nb_occ,nb_lib);
                    b=vrai ;
                }
            }
            else
            {
                q=p ;
                p=p->suiv ;
            }
        }
        if (b==faux)
        {
            creat_annuaire_automatique(q,nom,ville,v,nb_deux,nb_individuel,prix,nb_occ,nb_lib);
        }

    }
    return tete;
}

/////////////////////////////////////////////// *** CREAT ANNUAIRE AUTAUMATIQUE *** /////////////////////////////////////////////////////////
void creat_annuaire_automatique(annuaire *q,char nom[26],char ville[26],int v,int m,int n,int a,int nb_occ,int nb_lib)
{                      //v:la capacite // m:nombres des chambres a deux //n:nombres des chambres individuel //a:le prix
    annuaire *p;
    hotel *h ;
    p=malloc(sizeof(annuaire));
    h=malloc(sizeof(hotel));
    h->occ_ch=NULL;
    p->tete_h=h ;
    p->alpha=nom[0];
    strcpy(p->tete_h->nom,nom);
    strcpy(p->tete_h->ville,ville) ;
    p->tete_h->capacite=v ;
    p->tete_h->nb_lib=nb_lib;
    p->tete_h->nb_occ=nb_occ ;
    p->tete_h->ch_deux=m;
    p->tete_h->ch_individuel=n;
    p->tete_h->tete_ch=remplir_chambres(m,n,a);
    p->tete_h->lib_ch=p->tete_h->tete_ch;
    q->suiv=p ;
    p->tete_h->suiv=NULL;
    p->suiv=NULL ;
}
////////////////////////////////////////////////// *** INSERER HOTEL AUTAUMATIQUE *** ////////////////////////////////////////////
void inserer_hotel_autaumatique(hotel *ha,char nom[26],char ville[26],int v,int m,int n,int a,int nb_occ,int nb_lib)
{
   hotel *h ;
    h=malloc(sizeof(hotel));
    strcpy(h->nom,nom);
    strcpy(h->ville,ville);
    h->occ_ch=NULL;
    h->capacite=v ;
    h->nb_lib=nb_lib;
    h->nb_occ=nb_occ;
    h->ch_deux=m;
    h->ch_individuel=n;
    if (ha!=NULL)
    {
        ha->suiv=h ;
        h->suiv=NULL ;
        h->tete_ch=remplir_chambres(m,n,a);
        h->lib_ch=h->tete_ch;
    }
    else
    {
        h->suiv=NULL ;
        ha=h ;
        ha->tete_ch=remplir_chambres(m,n,a);
        ha->lib_ch=h->lib_ch;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
annuaire * ajouter_hotels_depuis_un_fichier(annuaire *tete)
{
    char nom[26],ville[26];
    char ligne[256];
    int i,v,n,m,a,nb_lib,nb_occ;
    FILE *fic=fopen("structhotel.txt","r");
    if (fgets(ligne,256,fic)==NULL)
    {
        color(15,12);
        printf("le fichier de chargement est vide");
        color(15,0);
        printf("\n");
        tete=NULL ;
       return tete;
    }
        while (!feof(fic))
        {
            fgets(ligne,256,fic);
            sscanf(ligne,"%s # %s # %d # %d # %d # %d # %d # %d #",nom,ville,&v,&m,&n,&a,&nb_occ,&nb_lib);
            for (i=0;i<26;i++)
            {
                nom[i]=tolower(nom[i]);
                ville[i]=tolower(ville[i]);
            }
            tete=ajouter_hotels_automatiquement(tete,nom,ville,a,v,n,m,nb_occ,nb_lib);
        }
    fclose(fic);
    return tete ;
}
///////////////////////////////////// *** TRIER LISTE ANNUAIRE *** ///////////////////////////////////////////////////////////
annuaire * trier_annuaire(annuaire *tete)
{
    annuaire *p,*q,*l ;
    if (tete!=NULL)
    {
        p=tete ;
        q=tete->suiv ;
        l=NULL ;
        while(q!=NULL)
        {
            if((p->alpha)>(q->alpha))
            {
                if (l==NULL)
                {
                    p->suiv=q->suiv ;
                    q->suiv=p ;
                    tete=q ;
                }
                else
                {
                    l->suiv=q ;
                    p->suiv=q->suiv ;
                    q->suiv=p ;
                }
                p=tete ;
                q=tete->suiv ;
                l=NULL ;
            }
            else
            {
                l=p ;
                p=q ;
                q=q->suiv ;
            }
        }
        p=tete ;
        while(p!=NULL)
        {
            p->tete_h=trier_hotel(p->tete_h);
            p=p->suiv ;
        }
    }
    return tete ;
}
///////////////////////////////////// *** TRIER LISTE HOTEL *** ////////////////////////////////////////////////////////////////
hotel * trier_hotel(hotel *tete_h)
{
    hotel *h,*ha,*l ;
    h=tete_h;
    ha=tete_h->suiv ;
    l=NULL ;
    while (ha!=NULL)
    {
        if (strcmp(h->nom,ha->nom)==1)
        {
            if(l==NULL)
            {
                h->suiv=ha->suiv ;
                ha->suiv=h ;
                tete_h=ha ;
            }
            else
            {
                l->suiv=ha ;
                h->suiv=ha->suiv ;
                ha->suiv=h ;
            }
            h=tete_h ;
            ha=tete_h->suiv ;
            l=NULL ;
        }
        else
        {
            l=h ;
            h=ha ;
            ha=ha->suiv ;
        }
    }
    return tete_h ;
}
///////////////////////////////////////// *** MODIFIER RESEVATION *** //////////////////////////////////////////////////////////
void modifier_reservation(annuaire *tete,char nom_hotel[26],char nom_ville[26],char nom[26])
{
    annuaire *p;
    hotel *h ;
    chambres *c ;
    char name[26];
    int chois,j,m,a,jj,mm,aaaa,i ;
    booleen b=faux,bo=faux,trouv=faux ;
    color(15,0);
    p=tete;
    while ((p!=NULL)&&(bo==faux))
    {
        if (p->alpha==nom_hotel[0])
        {
            bo=vrai ;
            h=p->tete_h ;
            while ((h!=NULL)&&(trouv==faux))
            {
                if((strcmp(nom_hotel,h->nom)==0)&&(strcmp(nom_ville,h->ville)==0))
                {
                    trouv=vrai ;
                    c=h->tete_ch ;
                    while ((c!=NULL)&&(b==faux))
                    {
                        if (strcmp(c->nom,nom)==0)  // changer la date
                        {
                            b=vrai ;
                            printf("Vous voulez : \n");
                            printf("       1->Modifier la date de reservation \n");
                            printf("       2->Changer le nom de reservateur \n");
                            scanf("%d",&chois);
                            if (chois ==1)
                            {
                                printf("Introduire la debut du nouvelle journee : \n");
                                scanf("%d",&j);
                                fflush(stdin);
                                printf("Introduire la debut du mois : \n");
                                scanf("%d",&m);
                                fflush(stdin);
                                printf("Introduire la debut des annees : \n");
                                scanf("%d",&a);
                                fflush(stdin);
                                printf("Introduire la date du fin pour les jours : \n" );
                                scanf("%d",&jj);
                                fflush(stdin);
                                printf("Introduire la date du fin pour les mois : \n");
                                scanf("%d",&mm);
                                fflush(stdin);
                                printf("Introduire la du fin pour les annees : \n");
                                scanf("%d",&aaaa);
                                fflush(stdin);
                                c->date_debut.jour=j ;
                                c->date_debut.mois=m ;
                                c->date_debut.annee=a ;
                                c->date_fin.jour=jj ;
                                c->date_fin.mois=mm ;
                                c->date_fin.annee=aaaa ;
                            }
                            else  // changer le nom
                            {
                                printf("Introduire le nom : \n");
                                scanf("%s",name);
                                fflush(stdin);
                                for (i=0;i<26;i++)
                                {
                                    name[i]=tolower(name[i]);
                                }
                                strcpy(c->nom,name);
                            }
                        }
                        else
                        {
                            c=c->suiv ;
                        }
                    }
                }
                else
                {
                    h=h->suiv ;
                }
            }
            if (trouv==faux)
            {
                color(15,12);
                printf("Le nom de l'hotel n'existe pas !");
                color(15,0);
                printf("\n");
            }
            else
            {
                if (b==faux)
                {
                    color(15,12);
                    printf("Le nom n'existe pas dans la liste des reservations !");
                    color(15,0);
                    printf("\n");
                }
            }
        }
        else
        {
            p=p->suiv ;
        }
    }
    if (bo==faux)
    {
        color(15,12);
        printf("Le nom de l'hotel n'existe pas !");
        color(15,0);
        printf("\n");
    }
}
//////////////////////////////////// *** SUPPRIMER RESERVATION *** //////////////////////////////////////////////////////////
void supprimer_reservation(annuaire *tete,char nom_h[26],char ville[26],char nom[26])
{
    annuaire *p ;
    hotel *h ;
    chambres *c,*q,*l,*ca;
    booleen b1=faux,b2=faux,b3=faux,b4=faux ;
    p=tete ;
    while ((p!=NULL)&&(b1==faux))
    {

        if (p->alpha == nom_h[0])
        {
            b1=vrai ;
            h=p->tete_h ;
            while ((h!=NULL)&&(b2==faux))
            {
                if ((strcmp(h->nom,nom_h)== 0)&&(strcmp(h->ville,ville)==0))
                {
                    b2=vrai ;
                    c=h->tete_ch ;
                    while ((c!=NULL)&&(b3==faux))
                    {
                        if (strcmp(c->nom,nom)==0)
                        {
                            b3=vrai ;
                            strcpy(c->nom,"vide\0");
                            c->date_debut.annee=0 ;
                            c->date_debut.mois=0 ;
                            c->date_debut.jour=0 ;
                            c->date_fin.annee=0 ;
                            c->date_fin.mois=0 ;
                            c->date_fin.jour=0 ;
                            c->statut=libre ;
                            h->nb_lib=h->nb_lib+1 ;
                            h->nb_occ=h->nb_occ-1 ;
                            if ((c==h->tete_ch)&&(c->suiv==h->lib_ch))
                            {
                                h->lib_ch=h->tete_ch ;
                                h->occ_ch=NULL ;
                            }
                            else
                            {
                                if (c==h->tete_ch)
                                {
                                    l=h->tete_ch ;
                                    while ((l!=NULL)&&(b4==faux))
                                    {
                                        if (l==h->lib_ch)
                                        {
                                            b4=vrai ;
                                        }
                                        else
                                        {
                                            q=l ;
                                            l=l->suiv ;
                                        }
                                    }
                                    h->tete_ch=h->tete_ch->suiv ;
                                    h->occ_ch=h->tete_ch ;
                                    q->suiv=c ;
                                    c->suiv=h->lib_ch ;
                                    h->lib_ch=c ;
                                }
                                else
                                {
                                    if (c->suiv==h->lib_ch)
                                    {
                                        h->lib_ch=c ;
                                    }
                                    else
                                    {
                                        l=h->tete_ch ;
                                        while ((l!=NULL)&&(b4==faux))
                                        {
                                            if (l==h->lib_ch)
                                            {
                                                b4=vrai ;
                                            }
                                            else
                                            {
                                                q=l ;
                                                l=l->suiv ;
                                            }
                                        }
                                        ca->suiv=c->suiv ;
                                        q->suiv=c ;
                                        c->suiv=h->lib_ch ;
                                        h->lib_ch=c ;
                                    }
                                }
                            }
                        }
                        else
                        {
                            ca=c ;
                            c=c->suiv ;
                        }
                    }
                }
                else
                {
                    h=h->suiv ;
                }
            }
        }
        else
        {
            p=p->suiv ;
        }
    }
    if (b2==faux)
    {
        color(15,12);
        printf("L'hotel que vous avez introduire n'existe pas !");
        color(15,0);
        printf("\n");
    }
    else
    {
        if (b3==faux)
        {
            color(15,12);
            printf("Le nom que vous avez introduire n'existe pas dans la liste des reservations !");
            color(15,0);
            printf("\n");
        }
    }
    sauvgarde_structhotel(tete);
    sauvgarder_reservation_dans_un_fichier(tete);
}
////////////////////////////// *** RECHERCHER UNE CHAMBRE *** ///////////////////////////////////////////////////////////////////
void recherche_chambre(annuaire *tete)
{
    annuaire *p ;
    hotel *h,*ha,*l ;
    chambres *c,*ca ;
    int choix,n,i ;
    char ville[26],nom[26];
    booleen b=faux,b1=faux,b2=faux ;
    if (tete!=NULL)
    {
        color(15,0);
        printf("Vous voulez chercher une chambres selon : \n");
        printf("     1-> Une ville donnee \n");
        printf("     2-> Dans un hotel donne \n");
        printf("     3-> le plus petit prix dans toutes les hotels \n");
        scanf("%d",&choix);
        fflush(stdin);
        if (choix ==1)
        {
            printf("Introduire la ville de votre hotel : \n");
            scanf("%s",ville);
            fflush(stdin);
            for(i=0;i<26;i++)
            {
                ville[i]=tolower(ville[i]);
            }
            p=tete ;
            while (p!=NULL)
            {
                h=p->tete_h ;
                while ((h!=NULL)&&(b==faux))
                {
                    if (strcmp(h->ville,ville)==0)
                    {
                        b=vrai ;
                        printf("Le nom de l'hotel est : %s        Le prix est : %d \n",h->nom,h->tete_ch->prix) ;
                    }
                    h=h->suiv ;
                }
                p=p->suiv ;
            }
            if (b==faux)
            {
                color(15,12);
                printf("Desole n'existe pas des hotel dans cette ville !");
                color(15,0);
                printf("\n");
            }
            else
            {
                printf("Introduire le nom de votre hotel : \n");
                scanf("%s",nom) ;
                fflush(stdin);
                for (i=0;i<26;i++)
                {
                    nom[i]=tolower(nom[i]);
                }
                p=tete ;
                b=faux ;
                while((p!=NULL)&&(b==faux))
                {
                    if (p->alpha==nom[0])
                    {
                        h=p->tete_h ;
                        while ((h!=NULL)&&(b1==faux))
                        {
                            if ((strcmp(nom,h->nom)==0)&&(strcmp(ville,h->ville)==0))
                            {
                                printf("Introduire le type du chambre :\n");
                                printf("    -> introduire '0' pour une chambre individuelle \n");
                                printf("    -> introduire '1' puor une chambre a deux \n");
                                scanf("%d",&n);
                                fflush(stdin);
                                c=h->lib_ch ;
                                while ((c!=NULL)&&(b2==faux))
                                {
                                    if (c->type==n)
                                    {
                                        if (h->nb_occ==h->capacite)
                                        {
                                            color(15,12);
                                            printf("Desole tout les chambres sont occupees !");
                                            color(15,0);
                                            printf("\n");
                                        }
                                        else
                                        {
                                            h->tete_ch=reserve_chambres(h,c) ;
                                            h->nb_lib=h->nb_lib - 1 ;
                                            h->nb_occ=h->nb_occ + 1 ;
                                        }
                                        b2=vrai ;
                                        b1=vrai ;
                                        b=vrai ;
                                    }
                                    else
                                    {
                                        c=c->suiv ;
                                    }
                                }
                            }
                            else
                            {
                                h=h->suiv ;
                            }
                        }
                    }
                    else
                    {
                        p=p->suiv ;
                    }
                }
                if (b1==faux)
                {
                    color(15,12);
                    printf("Desole n'existe pas cet hotel !");
                    color(15,0);
                    printf("\n");
                }
            }
        }
        else  // choix = 2 ou 3
        {
            if (choix==2)
            {
                printf("Introduire le nom de votre hotel : \n") ;
                scanf("%s",nom);
                fflush(stdin);
                for (i=0;i<26;i++)
                {
                    nom[i]=tolower(nom[i]);
                }
                p=tete ;
                while (p!=NULL)
                {
                    if (p->alpha==nom[0])
                    {
                        h=p->tete_h ;
                        while (h!=NULL)
                        {
                            if (strcmp(h->nom,nom)==0)
                            {
                                printf("      La ville de votre hotel est : %s \n",h->ville);//pour eviter le cas lorsque deux hotels
                                b=vrai ;                                                // a le meme nom dans deux villes deffirent
                            }
                            h=h->suiv ;
                        }
                        break ;
                    }
                    else
                    {
                        p=p->suiv ;
                    }
                }
                if (b==vrai)
                {
                    printf("Introduire la ville de votre hotel : \n");
                    scanf("%s",ville);
                    fflush(stdin);
                    for (i=0;i<26;i++)
                    {
                        ville[i]=tolower(ville[i]);
                    }
                    printf("Introduire le type du chambre :\n");
                    printf("    -> introduire '0' pour une chambre individuelle \n");
                    printf("    -> introduire '1' puor une chambre a deux \n");
                    scanf("%d",&n);
                    fflush(stdin);
                    h=p->tete_h ;
                    while ((h!=NULL)&&(b1==faux))
                    {
                        if ((strcmp(h->nom,nom)==0)&&(strcmp(h->ville,ville)==0))
                        {
                            c=h->lib_ch ;
                            while ((c!=NULL)&&(b2==faux))
                            {
                                if (c->type==n)
                                {
                                    if (h->nb_occ==h->capacite)
                                    {
                                        color(15,12);
                                        printf("Desole tout les chambres sont occupees !");
                                        color(15,0);
                                        printf("\n");
                                    }
                                    else
                                    {
                                        h->tete_ch=reserve_chambres(h,c) ;
                                        h->nb_lib=h->nb_lib - 1 ;
                                        h->nb_occ=h->nb_occ + 1 ;
                                    }
                                    b1=vrai ;
                                    b2=vrai ;
                                }
                                else
                                {
                                    c=c->suiv ;
                                }
                            }
                        }
                        else
                        {
                            h=h->suiv ;
                        }
                    }
                }
                else
                {
                    color(15,12);
                    printf("Votre hotel n'existe pas !");
                    color(15,0);
                    printf("\n");
                }
            }
            else  // choix ==3
            {
                if (choix==3)
                {
                    ha=NULL ;
                    p=tete ;
                    while (p!=NULL)
                    {
                        h=p->tete_h ;
                        while (h!=NULL)
                        {
                            if (ha==NULL)
                            {
                                ha=h ;
                                l=h ;
                            }
                            else
                            {
                                if (h->tete_ch->prix < ha->tete_ch->prix)
                                {
                                    if (l->tete_ch->prix > h->tete_ch->prix)
                                    {
                                        l=h ;
                                    }
                                }
                                else
                                {
                                    if (l->tete_ch->prix > ha->tete_ch->prix)
                                    {
                                        l=ha ;
                                    }
                                }
                            }
                            h=h->suiv ;
                        }
                        p=p->suiv ;
                    }
                    color(15,6);
                    printf("Le nom de l'hotel est : %s ",l->nom);
                    color(15,0);
                    printf("\n");
                    printf("      La ville de l'hotel est : %s \n",l->ville);
                    printf("      Le prix est : %d \n \n",l->tete_ch->prix);
                    printf("      Vous voulez reserve une chambre dans cet hotel ?! \n");
                    printf("  Si Oui introduire la valeur '1',Sinon la valeur '0' \n");
                    scanf("%d",&choix);
                    fflush(stdin);
                    if (choix==1)
                    {
                        if (l->nb_occ==l->capacite)
                        {
                            color(15,12);
                            printf("Desole tout les chambres sont occupees !");
                            color(15,0);
                        }
                        else
                        {
                            printf("Introduire le type du chambre :\n");
                            printf("    -> introduire '0' pour une chambre individuelle \n");
                            printf("    -> introduire '1' puor une chambre a deux \n");
                            scanf("%d",&n);
                            c=l->lib_ch ;
                            while(c!=NULL)
                            {
                                if (c->type==n)
                                {
                                    l->tete_ch=reserve_chambres(l,c);
                                    l->nb_lib=l->nb_lib - 1 ;
                                    l->nb_occ=l->nb_occ + 1 ;
                                    break ;
                                }
                                else
                                {
                                    c=c->suiv ;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        color(15,12);
        printf("Toutes les listes sont vides ... il faut de charger les donnees a partir des fivhiers !");
        color(15,0);
        printf("\n");
    }
    sauvgarder_reservation_dans_un_fichier(tete);
    sauvgarde_structhotel(tete);
}
/////////////////////////////////////////// *** RESERVER CHAMBRE *** ////////////////////////////////////////////////////////////
chambres * reserve_chambres(hotel *h,chambres *c)
{
    chambres *ca,*l ;
    int j,m,a,jj,mm,aa,i ;
    char nom[26];
    color(15,0);
    printf("Introduire votre nom : \n");
    scanf("%s",nom);
    fflush(stdin);
    for (i=0;i<26;i++)
    {
        nom[i]=tolower(nom[i]);
    }
    strcpy(c->nom,nom);
    printf("Introduire la date du debut de votre sejour : \n");
    printf("le jour : ");
    scanf("%d",&j);
    fflush(stdin);
    printf("le mois : ");
    scanf("%d",&m);
    fflush(stdin);
    printf("l'annee : ");
    scanf("%d",&a) ;
    fflush(stdin) ;
    c->date_debut.annee=a ;
    c->date_debut.jour=j ;
    c->date_debut.mois=m ;
    printf("Introduire la date du fin de votre sejour : \n");
    printf("le jour : ");
    scanf("%d",&jj);
    fflush(stdin);
    printf("le mois : ");
    scanf("%d",&mm);
    fflush(stdin);
    printf("l'annee : ");
    scanf("%d",&aa) ;
    fflush(stdin) ;
    c->date_fin.annee=aa ;
    c->date_fin.jour=jj ;
    c->date_fin.mois=mm ;
    c->statut=occupe ;
    printf("Le numero de votre chambre est : ");
    color(15,4);
    printf("  %d  ",c->nemuro);
    color(15,0);
    printf("\n");
    if (h->tete_ch==c)
    {
        h->occ_ch=h->tete_ch ;
        h->lib_ch=h->tete_ch->suiv ;
    }
    else
    {
        l=h->lib_ch ;
        while (l!=NULL)
        {
            if (l==c)
            {
                ca->suiv=c->suiv ;
                c->suiv=h->occ_ch ;
                h->occ_ch=c ;
                h->tete_ch=c ;
                break ;
            }
            else
            {
                ca=l ;
                l=l->suiv ;
            }
        }
    }
    return h->tete_ch ;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
annuaire * charger_reservation_depuis_un_fichier(annuaire *tete)
{

    char nom_reservateur[26],nom_hotel[26],ville[26],ligne[256];
    int type,jd,md,ad,jf,mf,af;
    FILE *fic = fopen("chargement.txt","r");
    if (fgets(ligne,256,fic)==NULL)
    {

        color(15,12);
        printf("le fichier de chargement est vide");
        color(15,0);
        printf("\n");
       return tete;
    }
    while (!feof(fic))
    {
        fgets(ligne,256,fic);
        sscanf(ligne," %s # %s # %s # %d # %d # %d # %d # %d # %d # %d #",nom_hotel,ville,nom_reservateur,&type,&jd,&md,&ad,&jf,&mf,&af);
        tete= reservation_auto(tete ,nom_reservateur,nom_hotel,ville,type,jd,md,ad,jf,mf,af);
    }

    fclose(fic);

    return tete;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
annuaire * reservation_auto(annuaire * tete,char nom_reservateur[26],char nom_hotel[26], char nom_ville[26],int number,int jj,int mm,int aaaa,int jour,int mois,int annee)
{
    boolean trouv1=faux,trouv2=faux,trouv3=faux;
    annuaire * p =tete;
    chambres * c,*m=NULL;
    color(15,0);
    while ((p!=NULL)&&(trouv1==faux))
    {

        if((p->alpha) == nom_hotel[0])
        {

            trouv1=vrai;
        }
        else
        {
            p=p->suiv;
        }
    }
        if (trouv1 == vrai)
        {

            hotel * q = p->tete_h;
            while ((q!=NULL)&&(trouv2==faux))
            {

                if ((strcmp(q->nom,nom_hotel)== 0)&&(strcmp(q->ville,nom_ville)== 0))
                {

                    c =q->tete_ch;
                    while ((c!=NULL)&&(trouv3==faux))
                    {

                        if ((c->statut == 0 )&&(c->type == number))
                        {
                            strcpy(c->nom,nom_reservateur);
                            c->date_debut.jour=jj;
                            c->date_debut.mois=mm;
                            c->date_debut.annee=aaaa;
                            printf("%s vous  allez recuperer cette chambre a la date suivante : %d-%d-%d \n",nom_reservateur,jj,mm,aaaa);
                            printf("Votre sejour se termine a la date suivante : %d-%d-%d \n",jour,mois,annee);
                            c->date_fin.jour=jour;
                            c->date_fin.mois=mois;
                            c->date_fin.annee=annee;
                            c->statut=occupe;
                            q->nb_occ=q->nb_occ+1;
                            q->nb_lib=q->nb_lib-1;
                            if (c == q->tete_ch)
                            {
                                q->occ_ch=q->tete_ch;
                                q->lib_ch=q->tete_ch->suiv;
                                trouv3=vrai;
                                trouv2=vrai;
                            }
                            else
                            {
                                m->suiv=c->suiv;
                                c->suiv=q->tete_ch;
                                q->tete_ch=c;
                                q->occ_ch=q->tete_ch;
                                while (c != NULL)
                                {
                                    if (c->statut==0)
                                    {
                                        q->lib_ch=c;
                                        break;
                                    }
                                    else
                                    {
                                        c=c->suiv;
                                    }
                                }
                                trouv3=vrai;
                                trouv2=vrai;

                            }


                        }
                        else
                        {
                            m=c;
                            c=c->suiv;
                        }
                    }
                    if (trouv3 == faux)
                    {
                        color(15,12);
                        printf("Desole l'hotel que vous avez choisis est saturee \n");
                        color(15,0);
                    }
                    if (trouv2 == faux )
                    {
                        color(15,12);
                        printf("Le nom de l'hotel que vous avez choisis n'existe pas dans la base !\n");
                        color(15,0);
                    }
                }
                else
                {
                    q=q->suiv;
                }
            }
        }
        return (tete);

}
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sauvgarder_reservation_dans_un_fichier(annuaire *tete)
{
    FILE * fic=fopen("chargement.txt","w");
    hotel * h=tete->tete_h;
    chambres * c;

        while (tete != NULL)
        {
            h=tete->tete_h;
            while ( h!=NULL )
            {
                c=h->tete_ch;
                while (c != NULL)
                {
                    if (c->statut == 1)
                    {
                        fprintf(fic," %s # %s # %s # %d # %d # %d # %d # %d # %d # %d #\n",h->nom,h->ville,c->nom,c->type,c->date_debut.jour,c->date_debut.mois,c->date_debut.annee,c->date_fin.jour,c->date_fin.mois,c->date_fin.annee);
                    }
                    c=c->suiv;
                }

                h=h->suiv;
            }
            tete=tete->suiv;
        }
    fclose(fic);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void affichage_status_de_reservation(annuaire *tete)
{
    annuaire *p=tete;
    hotel *h;
    chambres *c;
    color(15,0);
    while ( p != NULL)
    {
        h=p->tete_h;
        while (h != NULL)
        {
            color(15,6);
            printf("Le status de reservation de l'hotel : %s",h->nom);
            color(15,0);
            printf("\n");
            printf("La ville de l'hotel est : %s \n",h->ville);
            c=h->tete_ch;
            while (c != NULL)
            {
                if ((c->statut==1)&&(c->type==1))
                {
                    color(15,0);
                    printf("     ");
                    color(15,4);
                    printf("Le nom est : %s",c->nom);
                    color(15,0);
                    printf("\n");
                    printf("              le type de la chambre est : a deux \n");
                    printf("              le numero de la chambre est : %d \n",c->nemuro);
                    printf("              la date du debut est : %d-%d-%d \n",c->date_debut.jour,c->date_debut.mois,c->date_debut.annee);
                    printf("              la date du fin est : %d-%d-%d \n",c->date_fin.jour,c->date_fin.mois,c->date_fin.annee);
                }
                else
                {
                    if ((c->statut==1)&&(c->type==0))
                    {
                        color(15,0);
                        printf("     ");
                        color(15,4);
                        printf("Le nom est : %s",c->nom);
                        color(15,0);
                        printf("\n");
                        printf("          le type de la chambre est : individuelle \n");
                        printf("          le numero de la chambre est : %d \n",c->nemuro);
                        printf("          la date du debut est : %d-%d-%d \n",c->date_debut.jour,c->date_debut.mois,c->date_debut.annee);
                        printf("          la date du fin est : %d-%d-%d \n",c->date_fin.jour,c->date_fin.mois,c->date_fin.annee);
                    }
                }
                c=c->suiv;
            }
            printf("Le nombre de chambre occupee de l'hotel %s est : %d\n",h->nom,h->nb_occ);
            printf("Le nombre de chambre libre de l'hotel %s est : %d\n",h->nom,h->nb_lib);
            printf("\n\n") ;
            h=h->suiv;
        }
        p=p->suiv;
    }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rechercher_reservation_effectuer_par_une_personne (annuaire *tete ,char nom_reservateur[26])
{
    annuaire * p=tete;
    hotel * h;
    chambres *c;
    booleen trouv=faux;
    while (( p != NULL) && (trouv == faux))
    {
        h=p->tete_h;
        while ((h != NULL) && (trouv == faux))
        {
            c=h->tete_ch;
            while ((c != NULL)&&(trouv == faux))
            {
                if (strcmp(c->nom,nom_reservateur)==0)
                {
                    color(15,1);
                    printf("Les donnee rechercher par rapport a la reservation du Mr(melle/Mme) %s sont les suivant :",nom_reservateur);
                    color(15,0);
                    printf("\n");
                    printf("    Le nom d'hotel est: %s \n",h->nom);
                    printf("    La ville de l'hotel est : %s \n",h->ville);
                    printf("    Le numerp de la chambre est : %d \n",c->nemuro);
                    trouv=vrai;
                }
                c=c->suiv;
            }
            h=h->suiv;
        }

        p=p->suiv;
    }
    if (trouv==faux)
    {
        color(15,12);
        printf("La resrvation sous le nom %s n'existe pas dans notre base !!! merci de verifier le nom",nom_reservateur);
        color(15,0);
        printf("\n\n");
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void liberer_chambre_ayant_une_date_fin(annuaire *tete)
{
    annuaire *p=tete;
    hotel *h;
    chambres *c;
    SYSTEMTIME t;
    GetSystemTime(&t);
    date date_du_jour;
    date_du_jour.jour=t.wDay;
    date_du_jour.mois=t.wMonth;
    date_du_jour.annee=t.wYear;
    while (p != NULL)
    {
        h=p->tete_h;
        while (h != NULL)
        {
            c=h->tete_ch;
            while ( c != NULL)
            {
                if (c->statut == occupe)
                {

                    if (comparer_entre_deux_date(c->date_fin,date_du_jour) == 1)
                    {
                        c->statut=libre;
                        h->nb_occ=h->nb_occ-1;
                        h->nb_lib=h->nb_lib+1;
                        c->date_debut.jour=0;
                        c->date_debut.mois=0;
                        c->date_debut.annee=0;
                        c->date_fin.jour=0;
                        c->date_fin.mois=0;
                        c->date_fin.annee=0;
                        strcpy(c->nom,"vide\0");
                    }
                }
                c=c->suiv;
            }
            h=h->suiv;
        }
        p=p->suiv;
    }
}
//////////////////////////////////////////////////////////////////////////////////
int comparer_entre_deux_date(date date_a_comparer, date date_a_entrer) //Retourne 1 si date_a_comparer<=a date_a_entrer // retourne 0 sinon
{
    if(date_a_entrer.annee == date_a_comparer.annee)
    {
        if(date_a_entrer.mois == date_a_comparer.mois)
        {
            if((date_a_comparer.mois == 1) ||(date_a_comparer.mois == 3) ||(date_a_comparer.mois == 5) ||(date_a_comparer.mois == 7) ||(date_a_comparer.mois == 8) ||(date_a_comparer.mois == 10) ||(date_a_comparer.mois == 12))
            {
                if ((date_a_entrer.jour < date_a_comparer.jour) || (date_a_entrer.jour > 31)) return 0;
                else return 1;

            }
            else if((date_a_comparer.mois == 4) ||(date_a_comparer.mois == 6) ||(date_a_comparer.mois == 9) ||(date_a_comparer.mois == 11))
            {

                if ((date_a_entrer.jour < date_a_comparer.jour) || (date_a_entrer.jour > 30)) return 0;
                else return 1;
            }
            else
            {
                if((date_a_comparer.annee % 4) == 0)
                {
                    if ((date_a_entrer.jour < date_a_comparer.jour) || (date_a_entrer.jour > 29)) return 0;
                    else return 1;
                }
                else
                {
                    if ((date_a_entrer.jour < date_a_comparer.jour) || (date_a_entrer.jour > 28)) return 0;
                    else return 1;
                }
            }
        }
        else if((date_a_entrer.mois > date_a_comparer.mois) && (date_a_entrer.mois <= 12))
        {
            if((date_a_entrer.mois == 1) ||(date_a_entrer.mois == 3) ||(date_a_entrer.mois == 5) ||(date_a_entrer.mois == 7) ||(date_a_entrer.mois == 8) ||(date_a_entrer.mois == 10) ||(date_a_entrer.mois == 12))
            {
                if ((date_a_entrer.jour <= 0) || (date_a_entrer.jour > 31)) return 0;
                else return 1;
            }
            else if((date_a_entrer.mois == 4) ||(date_a_entrer.mois == 6) ||(date_a_entrer.mois == 9) ||(date_a_entrer.mois == 11))
            {
                if ((date_a_entrer.jour <= 0) || (date_a_entrer.jour > 30)) return 0;
                else return 1;
            }
            else
            {
                if((date_a_comparer.annee % 4) == 0)
                {
                    if ((date_a_entrer.jour <= 0) || (date_a_entrer.jour > 29)) return 0;
                    else return 1;
                }
                else
                {
                    if ((date_a_entrer.jour <= 0) || (date_a_entrer.jour > 28)) return 0;
                    else return 1;
                }
            }
        }
        else
            return 0;
    }
    else if (date_a_entrer.annee > date_a_comparer.annee)
    {
        if ((date_a_entrer.mois >0) || (date_a_entrer.mois <= 12))
        {
            if((date_a_entrer.mois == 1) ||(date_a_entrer.mois == 3) ||(date_a_entrer.mois == 5) ||(date_a_entrer.mois == 7) ||(date_a_entrer.mois == 8) ||(date_a_entrer.mois == 10) ||(date_a_entrer.mois == 12))
            {
                if ((date_a_entrer.jour <= 0) || (date_a_entrer.jour > 31)) return 0;
                else return 1;
            }
            else if((date_a_entrer.mois == 4) ||(date_a_entrer.mois == 6) ||(date_a_entrer.mois == 9) ||(date_a_entrer.mois == 11))
            {
                if ((date_a_entrer.jour <= 0) || (date_a_entrer.jour > 30)) return 0;
                else return 1;
            }
            else
            {
                if((date_a_entrer.annee % 4) == 0)
                {
                    if ((date_a_entrer.jour <= 0) || (date_a_entrer.jour > 29)) return 0;
                    else return 1;
                }
                else
                {
                    if ((date_a_entrer.jour <= 0) || (date_a_entrer.jour > 28)) return 0;
                    else return 1;
                }
            }
        }
        else return 0;
    }
    else
        return 0;
}
