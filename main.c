#include <stdio.h>
#include <stdlib.h>

int validar(int,int,int);
void ordenar(int [],int [],int );

int main()
{
    int p_venta[50]={11,7,10,18,20,12,9,20,12,5,18,6,12,9,11,4,8,17,17,15,2,15,6,12,5,17,7,17,18,5,7,9,16,18,9,8,9,10,16,4,7,1,20,12,12,7,9,5,17,3};
    int vmesEnero[50],mes,prod,ventas,vmes[12]={0},x,i,mProduc[12][50]={{0}},vprod[50]={0},v1a12[12]={1,2,3,4,5,6,7,8,9,10,11,12},max;

    prod=validar(0,50,1);
    while(prod!=0)
    {
        mes=validar(1,12,2);
        printf("Ingrese las ventas: ");
        scanf("%d",&ventas);
        printf("\n");
        vmes[mes-1]+=ventas;

        vmesEnero[prod-1]+=ventas;


        mProduc[mes-1][prod-1]+=prod;

        prod=validar(0,50,1);                               //falta 2 y 3
    }


        ordenar(vmes,v1a12,12);
    printf("Mes                 Cantidad vendida\n");
        for(x=0;x<12;x++)
        {
            printf("%d              %d\n",v1a12[x],vmes[x]);//punto 4
        }
    printf("\nEl mes que mas vendio es: %d\n",v1a12[0]);//punto 1


    printf("El producto que vendio mas unidades en enero es: %d",vmesEnero[0]);//punto 2

    return 0;
}
int validar(int min,int max,int cual)
{
    int dato;

        do{
            if(cual==1)
            printf("Ingrese producto: ");
            else
            printf("Ingrese mes: ");
        scanf("%d",&dato);
        }while(dato<min||dato>max);

    return dato;
};
void ordenar(int cv[],int m[],int cant)
{
    int sen=0,x,aux,aux2;

    while(sen==0)
    {
        sen=1;
        for(x=0;x<cant-1;x++)
        {
            if(cv[x]<cv[x+1])
            {
                aux=cv[x];
                cv[x]=cv[x+1];
                cv[x+1]=aux;
                aux2=m[x];
                m[x]=m[x+1];
                m[x+1]=aux2;
                sen=0;
            }
        }
        cant=cant-1;
    }
};
