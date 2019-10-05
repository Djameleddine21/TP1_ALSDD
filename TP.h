#ifndef TP_H_INCLUDED
#define TP_H_INCLUDED

// definition des structures
typedef enum booleen
{
        faux,vrai
}booleen;

typedef enum {
        individuel,deux
}type_chmbre;

typedef enum{
    libre,occupe
}statut_chambre;

typedef struct date
{
    int jour;
    int mois;
    int annee;
} date;

struct liste_chambres
{
    int nemuro ;
    type_chmbre type ;          //  individuelle ou à deux
    statut_chambre statut ;    //   libre ou occupée
    date date_debut;
    date date_fin;
    char nom[26];
    int prix ;
    struct liste_chambres *suiv ;
};
typedef struct liste_chambres chambres ;

struct liste_hotel
{
   char nom[26] ;
   char ville[26];
   int capacite ;
   chambres *tete_ch ;
   chambres *occ_ch ;
   chambres *lib_ch;
   int ch_individuel;
   int ch_deux;
   int nb_occ;
   int nb_lib;
   struct liste_hotel *suiv;
};
typedef struct liste_hotel hotel ;

struct annuaire_hotel
{
    char alpha;
    hotel *tete_h ;
   struct annuaire_hotel *suiv ;
};
typedef struct annuaire_hotel annuaire ;
///////////////////////// *** LES MODULES POUR AFFICHE LE MENU *** ///////////////////////////////////////////////////
void gotoxy(int xpos, int ypos);
void color(int t,int f);
int delay(int x);
void clr_pro(int t,int lig );
void chargement();
int ecrire(char ss[],int tm);
void esi (int x, int y,int fond,int couleur,int t);
void textbackground(int bcolor);
int wherey();
int afficher(int i);
/////////////////////////// *** L ' IMPLEMENTAION DES MODULES   *** /////////////////////////////////////////////////////
annuaire * suppression_hotel(char nom_hotel[26],char ville_hotel[26],annuaire *tete);
chambres* liberer_toute_les_chambres(chambres *tete);
void reservation(char nom[26],annuaire * tete);
void afficher_tout_les_hotels(annuaire * tete);
annuaire * rajouter_hotel(annuaire *tete,char nom[26]);
chambres * remplir_chambres(int m,int n,int a);
void inserer_hotel(hotel *ha,char nom[26],char ville[26]);
void creat_annuaire(annuaire *q,char nom[26],char ville[26]);
annuaire * ajouter_hotels_depuis_un_fichier(annuaire *tete);
void inserer_hotel_autaumatique(hotel *ha,char nom[26],char ville[26],int v,int m,int n,int a,int nb_occ,int nb_lib);
void creat_annuaire_automatique(annuaire *q,char nom[26],char ville[26],int v,int m,int n,int a,int nb_occ,int nb_lib);
annuaire * ajouter_hotels_automatiquement(annuaire *tete,char nom[26], char ville[26],int prix ,int v,int nb_individuel,int nb_deux,int nb_occ,int nb_lib );
void modifier_reservation(annuaire *tete,char nom_hotel[26],char nom_ville[26],char nom[26]);
hotel * trier_hotel(hotel *tete_h);
annuaire * trier_annuaire(annuaire *tete);
void supprimer_reservation(annuaire *tete,char nom_h[26],char ville[26],char nom[26]) ;
void recherche_chambre(annuaire *tete) ;
chambres * reserve_chambres(hotel *h,chambres *c) ;
void rechercher_reservation_effectuer_par_une_personne (annuaire *tete ,char nom_reservateur[26]) ;
void affichage_status_de_reservation(annuaire *tete) ;
void sauvgarder_reservation_dans_un_fichier(annuaire *tete) ;
annuaire * reservation_auto(annuaire * tete,char nom_reservateur[26],char nom_hotel[26], char nom_ville[26],int number,int jj,int mm,int aaaa,int jour,int mois,int annee);
annuaire * charger_reservation_depuis_un_fichier(annuaire *tete) ;
void liberer_chambre_ayant_une_date_fin(annuaire *tete) ;
int comparer_entre_deux_date(date date_a_comparer, date date_a_entrer) ;
void sauvgarde_structhotel (annuaire * tete);
///////////////////////////////// *** LA MACHINE ABSTRAITE *** ///////////////////////////////////////////////////////
annuaire * allouer_annuaire(annuaire *p) ;
hotel * allouer_hotel(hotel *h) ;
chambres * allouer_chambre(chambres *c) ;
void aff_adr_annuaire(annuaire **p,annuaire **q) ;
void aff_adr_hotel(hotel **h,hotel **l) ;
void aff_adr_chambre(chambres **c,chambres **ca) ;
void liberer_annuaire(annuaire *p) ;
void liberer_hotel(hotel *h) ;
void liberer_chambre(hotel *c);
int prix_hotel (hotel *h) ;
int capacite_hotel(hotel *h) ;
char nom_hotel(hotel *h) ;
char ville_hotel(hotel *h) ;
int nb_chambre_occ(hotel *h) ;  // le nombres des chambres occupees
int nb_chambre_lib(hotel *h) ;  // le nombre des chambres linres
int nb_chambre_ind(hotel *h) ;  // le nombre des chambres individuelles
int nb_chambre_deux(hotel *h) ; // le nombres des chambres a deux
annuaire * suiv_annuaire(annuaire *p) ;
hotel * suiv_hotel(hotel *h) ;
chambres * suiv_chambre(chambres *c) ;
int num_chambre (chambres *c) ;
char valeur_annuaire (annuaire *p) ;
hotel * tete_hotel (annuaire *p) ;
chambres * tete_chambre (hotel *h) ;
chambres * occ_chambre (hotel *h) ;
chambres * lib_chambre (hotel *h) ;
void aff_prix(chambres **c,int prix ) ;
void aff_numero(chambres **c ,int n) ;
int statut_ch (chambres *c) ;
int type_ch(chambres *c) ;

#endif // TP_H_INCLUDED
