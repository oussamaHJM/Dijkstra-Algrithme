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

int main()
{
    noeud point[20],Mlis[20][20];
    float djikstra[20][20],distance[20];;
    int nbrPoint,source,choix,i,j,Destinataire,s,des,inSet[20],q[20],parent[20];
    printf("*************************************************************\n");
    printf("*            * BIENVENU DANS NOTRE PROGRAMME *              *\n");
    printf("*            * * * * * * * * * * * * * * * * *              *\n");
    printf("*                                                           *\n");
    printf("*            REALISE PAR :                                  *\n");
    printf("*                                                           *\n");
    printf("*               - HAFID MOHAMED                             *\n");
    printf("*                 -  El-HAJJAM OUSSAMA                      *\n");
    printf("*                   -  BOULKOL OUMAIMA                      *\n");
    printf("*                                                           *\n");
    printf("*            ENCADRE PAR :                                  *\n");
    printf("*                    - Mr. EL GHOLAMI KHALID                *\n");
    printf("*************************************************************\n\n");
    printf("\ntapper 1 pour lancée à partir du ficher de configuration:");
    scanf("%d",&j);
    if(j==1)
    {
        nbrPoint=Fichier_Config(point,Mlis);
    }
    else
    {
        printf("\nDne le nbr de point  : ");
        scanf("%d",&nbrPoint);
        printf("\n\n*********** Les points du graph **************\n\n");
        creation_du_graphe(point,nbrPoint);
        printf("\n\n**********************************************\n\n");
        creation_des_liaisons(point,nbrPoint,Mlis);
    }
    printf("\n\n**********************************************\n\n");
        affichage_du_graphe(point,nbrPoint);
        printf("\n");
        //affichage_lisons(nbrPoint,Mlis);
    for(i=0;i<nbrPoint;i++)
    {
        distance[i]=INFINITY;
        inSet[i]=0;
        q[i] = 1;
        parent[i] = -1;
    }
    printf("\n\n***********************************************\n\n");


    printf("\nEntrer une source : \n");
    scanf("%d",&source);
    s = indice(Mlis,nbrPoint,source);
    distance[s - 1] = 0 ; /* La distance d un noeud a lui meme est 0 */
    do
    {
        printf("\nEntrer une distination : \n");
        scanf("%d",&Destinataire);
        printf("\nIndice source : %d\n",indice(Mlis,nbrPoint,source));
        printf("\nIndice destination : %d\n",indice(Mlis,nbrPoint,Destinataire));
        des = indice(Mlis,nbrPoint,Destinataire);

        djikst_ra(Mlis,djikstra,nbrPoint,distance,inSet,q,parent,s,des);

        printf("\nVoulez changer La Destination :\n * Si OUI tapez ---> 1\n * Si NON tapez ---> 2\n");
        printf("\nDnez Votre choix : ");
        scanf("%d",&choix);
    }
    while(choix == 1);
    printf("\n");
                printf("*************************************************************\n");
                printf("*                                                           *\n");
                printf("*                    FIN  PROGRAMME                         *\n");
                printf("*                                                           *\n");
                printf("*************************************************************\n\n");
  return 0;

}
