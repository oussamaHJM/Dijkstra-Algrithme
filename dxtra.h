#ifndef DXTRA_H_INCLUDED
#define DXTRA_H_INCLUDED

typedef struct noeud   /* Structure d un noeud de gragh */
{
    int x;
    int y;
    int id;
    int l;
    float poid;
}noeud;
typedef struct t   /* Structure sert a enregistrer le suivant et le preced dans un tableau de chemin */
{
   int precedent;
    int suivant;
}t;

int Fichier_Config(noeud H[20],noeud Mlis[20][20]);
void djikst_ra(noeud Mlis[20][20],float djikstra[20][20],int nbrPoint,float distance[20],int inSet[20],int q[20],int parent[20],int indiceS,int indiceD );
int indice(noeud Mlis[20][20],int nbrPoint,int point);
void Extraire_distance_minimal(int destination,float distance[20]);
void Extraire_court_chemin(int parent[20],int nbrPoint,noeud Mlis[20][20],int indiceS,int indiceD);
int Extraire_indice_Min(int nbrPoint,float distance[20],int inSet[20],int q[20]);
int check_empty(int nbrPoint,int q[20]);
void print_Resultat(int nbrPoint,int parent[20],float distance[20]);
void creation_des_liaisons(noeud H[20], int nbrPoint,noeud Mlis[20][20]);
void calcul_poid(int nbrPoint,noeud Mlis[20][20]);
void affichage_lisons(int nbrPoint,noeud Mlis[20][20]);
void affichage_Matrice_lison(int nbrPoint,noeud Mlis[20][20]);
void affichage_du_graphe(noeud H[20],int nbrPoint);
void creation_du_graphe( noeud H[20],int nbrPoint);
int creation_ID(int x,int y);


#endif // DXTRA_H_INCLUDED
