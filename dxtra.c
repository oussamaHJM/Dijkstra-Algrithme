/* DATE LE 01/05/2017
 * OBJET : mini-projet Le Chemin plus court(ISGA SETTAT)
 * Algorithme: Dijkstra
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define INFINITY 9999
#define VRAI 1
#define FAUX 0
#include "dxtra.h"
                                                /*      IMPLEMENTATIONS     */

int creation_ID(int x,int y)   /* permet de cree le ID d'un noeud */
{
    return ((x*10)+y);
}


void creation_du_graphe( noeud H[20],int nbrPoint)   /* saisir  les coordonnées des noeuds du graph et l enregister dans un tableau H */
{  int i;
    for(i=0;i<nbrPoint;i++)
    {
        printf("\n\n** Le point %d **\n\n",i+1);
        printf("\nX : ");
        scanf("%d",&H[i].x);
        printf("\nY : ");
        scanf("%d",&H[i].y);
        H[i].id = creation_ID(H[i].x,H[i].y); /*  creation d' ID pour chaque noeud du tableau H */
    }
}


void affichage_du_graphe(noeud H[20],int nbrPoint)  /* l' Affichage du tableau H */
{
    int i;
    for(i=0;i<nbrPoint;i++)
    {
        printf("\n\n** Le point %d **\n\n",i+1);
        printf("\nX : %d",H[i].x);
        printf("\nY  : %d",H[i].y);
        printf("\nID : %d",H[i].id);
        printf("\npoid : %f",H[i].poid);
    }
}


void affichage_Matrice_lison(int nbrPoint,noeud Mlis[20][20])
{
    int i,j;
     for(i=0;i<nbrPoint+1;i++)
    {
       for(j=0;j<nbrPoint+1;j++)
       {
           printf("%d    ",Mlis[i][j].l); /* Affichage des ID*/
       }
        printf("\n");
    }
}


void affichage_lisons(int nbrPoint,noeud Mlis[20][20]) /* Affichage de toutes les liaisons du graph */
{
    int i,j;
    for(i=1;i<nbrPoint+1;i++)
    {
       for(j=0;j<nbrPoint+1;j++)
       {
           if(Mlis[i][j].l == 1)
               printf("%d <<--------->> %d \n",Mlis[i][0].id,Mlis[0][j].id);
       }
    }
}


void calcul_poid(int nbrPoint,noeud Mlis[20][20]) /* Calcule poid d'un noeud paraport au noeud avec lequel il est liee  */
{
    int i,j;
    float S;
    for(i=0;i<nbrPoint+1;i++)
    {
        for(j=0;j<nbrPoint+1;j++)
        {
            if(Mlis[i][j].l == 1)
            {
                S = (Mlis[i][0].x-Mlis[0][j].x)*(Mlis[i][0].x-Mlis[0][j].x)+(Mlis[i][0].y-Mlis[0][j].y)*(Mlis[i][0].y-Mlis[0][j].y);
                Mlis[i][j].poid = sqrt(S);
                //printf("poid = %.3f\n",Mlis[i][j].poid);
            }
        }
    }
}


void creation_des_liaisons(noeud H[20], int nbrPoint,noeud Mlis[20][20]) /* creation des liaisons (S'il a une liaison en on met "1" Sinon "0"  */
{
    int c,i,j,ch,idl,k;
 /* les deux boucle permet de copie les noeuds de H[] dans un matrice Mlis[][] dans  le premier ligne et le premier colonne en commancant par 1 a le nombre de noeuds +1*/

    for(j=1;j<nbrPoint+1;j++)
    {
        Mlis[0][j] = H[j-1];
    }
    for(i=1;i<nbrPoint+1;i++)
    {
        Mlis[i][0] = H[i-1];
    }
 /* *************************************************************************************************************************************************** */
    for(i=1;i<nbrPoint+1;i++)
    {
        printf("\nDner les liaisons pour %d :",Mlis[i][0].id);    /* Mlis[i][0] equivalent a H[i] avec i commance de 1 pour bien visibler les liaisons ( Mlis[0][0]= NULL) */
        c=0;
        do
        {
            printf("\nVoulez ajouter une liaison:\n1 --> OUI\n2 --> Non\n");
            scanf("%d",&ch);
            if(ch == 1)
            {
                printf("%d -------> ",Mlis[i][0].id);
                scanf("%d",&idl);
                printf("%d -------> %d",Mlis[i][0].id,idl);
                for(k=1;k<nbrPoint+1;k++)
                {
                    if(idl == Mlis[0][k].id)
                    {
                        Mlis[i][k].l = 1;
                    }
                }
                c++;
            }
        }
        while((ch != 2)&&(c<nbrPoint+1)); /* Redemander le saisi des liaisons si il y a plus que un */
                                                /* Avec une condition d Arret lorsqu ' on depasse le dernier noeud */
    }
    printf("\n");

    affichage_lisons(nbrPoint,Mlis); /* Affichage des liaisons */
    calcul_poid(nbrPoint,Mlis);   /* Calcule poid de chaque noeud */
    affichage_Matrice_lison(nbrPoint,Mlis); /* Affichage des liasons dans le meme Matrice */
}


void print_Resultat(int nbrPoint,int parent[20],float distance[20])  /* extraire le le résultat de Djikstra */
{
    int i;
    for(i=0;i<nbrPoint;i++)
       {
           printf("i = %d parent = %d distance from source = %.2f\n",i +1,parent[i],distance[i]) ;
       }
}


int check_empty(int nbrPoint,int q[20])    /* test sur Q ensemble des noeuds */
{
    int i,s = 0;
    for(i=0;i<nbrPoint;i++)
    {
        s = s + q[i];     //Somme des 1 , Si le Resultat est egal a 0 alors l ensemble Q est vide
    }
    if(s == 0)
       return VRAI;
    else
        return FAUX;
}


int Extraire_indice_Min(int nbrPoint,float distance[20],int inSet[20],int q[20])  /* comparer les poids des noeuds liee avec le pere est retourner la position du minimum */
{
    int i,ps;
    float min = INFINITY;
    for(i=0;i<nbrPoint;i++)
    {
        if(distance[i] <= min &&inSet[i] == 0)
        {
            min = distance[i];
            ps = i;
        }
    }
    q[ps] = 0;
    return ps;
}


void Extraire_court_chemin(int parent[20],int nbrPoint,noeud Mlis[20][20],int indiceS,int indiceD)   /* permet d afficher le chemin plus court d une maniere itérative on commancant par La distination */
{
    int j,temp,d=nbrPoint;
    indiceS = indiceS;
    indiceD = indiceD;
    t chemin[20];
    for(j=0;j<nbrPoint;j++)
    {
        chemin[j].suivant = j+1;                        /* Rassembler les noeuds et ses parents dans un seul tableau chemin[] */
        chemin[j].precedent = parent[j];
    }
    printf("%d",Mlis[0][indiceD].id);
    temp = indiceD;
    while(chemin[d].precedent != -1)
    {
        if(chemin[d].suivant == temp)
        {
                temp = chemin[d].precedent;
                printf(" <- %d",Mlis[0][chemin[d].precedent].id);
            }
        d--;
    }
}


void Extraire_distance_minimal(int destination,float distance[20])
{
        printf("\n\n La distance minimal : %.3f \n\n",distance[destination-1]);   /* Extraire la distance minimal de tout le chemin parcouru */
}


int indice(noeud Mlis[20][20],int nbrPoint,int point) /* transformer un ID a un indice */
{
    int i;
    for(i=1;i<nbrPoint+1;i++)
    {
        if(point == Mlis[0][i].id)
            return i;
    }
}


void djikst_ra(noeud Mlis[20][20],float djikstra[20][20],int nbrPoint,float distance[20],int inSet[20],int q[20],int parent[20],int indiceS,int indiceD )
{
    int i,j,u;
    int empty = check_empty(nbrPoint,q);
    for(i=0;i<nbrPoint;i++)
        for(j=0;j<nbrPoint;j++)
            djikstra[i][j] = 0;
    for(i=1;i<nbrPoint+1;i++)
        for(j=1;j<nbrPoint+1;j++)
            if(Mlis[i][j].l == 1)
                {djikstra[i-1][j-1] = Mlis[i][j].poid;}
    for(i=0;i<nbrPoint;i++)
    {
        for(j=0;j<nbrPoint;j++)
        {
            printf("  %.1f    ",djikstra[i][j]);
        }
        printf("\n");
    }

    while(empty != VRAI)  /* tester si l ensemble des noeuds Q est Vide  */
    {
        u = Extraire_indice_Min(nbrPoint,distance,inSet,q);
        inSet[u] = 1;   /* on note que le 1er noeud est parcouru */
        q[u] = 0;       /* suprimmer ce dernier de de lensemble Q */
        for(i=0;i<nbrPoint;i++)
        {
            if(djikstra[u][i] > 0)
            {
                if(distance[u] + djikstra[u][i] < distance[i])    /* comparer les distances des noeuds voisin du noeuds courant */
                {
                    distance[i] = distance[u] + djikstra[u][i];
                    parent[i] = u + 1;                /* Enregistrer le parent du noeud courant  */
                }
            }
        }
        empty = check_empty(nbrPoint,q);   /* Refaire le test jusqu' qu Q va etre Vide */
    }
    print_Resultat(nbrPoint,parent,distance);   /* voir la fonction */

    getchar();
    printf("\n\n*************************************************************\n\n");
    Extraire_distance_minimal(indiceD,distance);
    printf("\n\n*************************************************************\n\n");
    getchar();

    printf("\n\n************ << Le Court Chemin >>***************\n\n");
    Extraire_court_chemin(parent,nbrPoint,Mlis,indiceS,indiceD);
    printf("\n\n*************************************************\n\n");
}


int Fichier_Config(noeud H[20],noeud Mlis[20][20])
{
    char ch[500];
    int nbrPoint=0;
    noeud c;
    int i=0,h=0,ii=0,j,id1,l,p,m,n,chh=0;
    FILE * fichier;
    fichier=fopen("Fichier_Config.txt","r");
            if(fichier==NULL)
                printf("\nerreur\n");
            while(fgets(ch,80,fichier)!=NULL)
            {
                sscanf(ch,fichier);
                if(strstr(ch,"#")!=NULL)
                {
                }
                else
                {
                    if(strcmp(ch,"\n")==0)
                    {
                    }
                    else
                    {
                        if(strstr(ch,"id")!=NULL)
                        {
                            sscanf(ch,"id :%d   ,x=%d,y=%d,%d;",&l,&m,&n,&ii);
                            H[h].id=l;
                            H[h].x=m;
                            H[h].y=n;
                            nbrPoint++;
                            h++;
                            if(ii==1)
                            {
                                for(j=1;j<=nbrPoint;j++)
                                {
                                    Mlis[0][j] = H[j-1];
                                }
                                for(i=1;i<=nbrPoint;i++)
                                {
                                    Mlis[i][0] = H[i-1];
                                }
                            }
                        }
                        else if(strstr(ch,"ls")!=NULL)
                        {
                            sscanf(ch,"ls :%d<---->%d",&c.id,&id1);
                            for(j=1;j<nbrPoint+1;j++)
                                {
                                    if(c.id == Mlis[0][j].id)
                                    {
                                        p=j;
                                    }
                                }
                                for(j=1;j<nbrPoint+1;j++)
                                {
                                    if(id1 == Mlis[j][0].id)
                                    {
                                        chh=j;
                                    }
                                }
                                Mlis[p][chh].l = Mlis[chh][p].l = 1;
                        }
                    }
                }
            }
        fclose(fichier);
        calcul_poid(nbrPoint,Mlis);
        printf("nombre =%d  ",nbrPoint);
    return nbrPoint;
}

