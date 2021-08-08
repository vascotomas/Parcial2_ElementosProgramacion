#include<stdio.h>
int estaDentroDelRango(int,int,int);
int leerYValidar(int,int);
void cargadatos (int [],float [],int);
void limpiar(int[],int);
void limpiarfloat(float[],int);
void mostrar1 (int[],float[],int);
int busqueda_secuencial (int[],int,int);
int leerYValidarSucursal(int,int);
int ingresoticket ();
void mostrarA (int[],int [] [4],int);
void ordenarvectoresparalelos (int [],float[],int );
float maximo(float [], int);
void mostrarMaximo(int [],int,int );
void ordenar_por_burbujeo (float [],int [], int );

int main ()
{
    int tam=4,codpiz,poscod,posuc,cantpiz,b,m,montomax;
    int vcod[tam],pizzaventa[4][4]= {{0}},vsucursales[]= {1,2,3,4};
    float recaudacion=0,vprecio[tam],montoporventa,vmontos[4];


    limpiar(vcod,tam);
    limpiarfloat (vprecio,tam);
    limpiarfloat(vmontos,tam);

    cargadatos(vcod,vprecio,tam);
    printf("\n----------------\n");
    mostrar1 (vcod,vprecio,tam);
    printf("\n----------------\n");


////INGRESO TICKET
    int bandera=0,ticket/*,aux*/;

    ticket=ingresoticket();

///INGRESO VENTA

    while(ticket!=0)
    {
        codpiz=leerYValidar(100,999);
        poscod=busqueda_secuencial(vcod,tam,codpiz);

        if(poscod>=0)
        {
            posuc=leerYValidarSucursal(1,4);

            bandera=0;

            do
            {
                if(bandera ==1 )
                    printf("\nDATO INCORRECTO, ");

                bandera=1;

                printf("INGRESE CANTIDAD DE PIZZAS COMPRADAS: \n");
                scanf("%d",&cantpiz);

            }
            while(cantpiz<1);



            pizzaventa[poscod][posuc-1]+=cantpiz; ///CANTIDAD DE PIZZAS MATRIZ

            montoporventa=vprecio[poscod]*cantpiz;

            if(montoporventa>1500)
                montoporventa-=10;

            if(posuc==2)
                montoporventa-= montoporventa*0.05;

            recaudacion+=montoporventa;



            vmontos[posuc-1]+=montoporventa;

            printf("\n----------------\n");

        }

        else
            printf("CODIGO DE PIZZA NO EXISTENTE \n");

        printf("\n----------------\n");

        ticket=ingresoticket();



    }

    mostrarA(vcod,pizzaventa,tam);

    printf("\n----------------\n");

    ordenarvectoresparalelos (vsucursales,vmontos,tam-1);

    for(b=0; b<tam; b++)
        printf("SUCURSAL %d RECAUDO: $ %.2f \n",vsucursales[b],vmontos[b]);

    printf("\n----------------\n");

    montomax=maximo(vmontos,tam);
    printf("LA/S SUCURSAL/ES CON MAYOR RECAUDACION SON: ");
    for (m=0; m<tam; m++)
    {
        if(vmontos[m] == montomax)
            printf("NRO %d",vsucursales[m]);
    }

    printf("\n----------------\n");


    printf("RECAUDACION TOTAL: $ %f ",recaudacion);

    return 0;
}

void cargadatos (int vc[],float vpr[],int N)
{
    int i,cod,aux,flag=0,pos;
    float precio;

    for (i=0; i<N; i++)
    {

        cod=leerYValidar(100,999);
        vc[i]+=cod;

        do
        {
            if( flag == 1)
                printf("\nDATO INCORRECTO, ");

            flag = 1;

            printf("INGRESE PRECIO DE LA PIZZA:   \n");
            scanf("%f",&precio);

            if(precio>=1)
                aux=1;
            else
                aux=0;


        }
        while (aux == 0);
        vpr[i]+=precio;
        flag=0;

        printf("\n----------------\n");

    }

}


int estaDentroDelRango(int limiteInferior, int limiteSuperior, int valorAControlar)
{
    int aux;

    if(valorAControlar >= limiteInferior && valorAControlar <= limiteSuperior)
        aux=1;
    else
        aux=0;

    return aux;
}
int leerYValidar(int li, int ls)
{
    int valor, b = 0;
    do
    {
        if( b == 1)
            printf("\nDATO INCORRECTO, ");

        b = 1;

        printf("INGRESE UN CODIGO DE PIZZA ENTRE %d Y %d:   \n", li, ls);
        scanf("%d",&valor);

    }
    while (estaDentroDelRango(li, ls, valor) == 0);

    return valor;
}

void limpiar(int v[],int n)
{
    int i;
    for(i=0; i<n; i++)
        v[i]=0;
}
void limpiarfloat(float v[],int n)
{
    int i;
    for(i=0; i<n; i++)
        v[i]=0;
}



void mostrar1 (int vcod[],float vpre[],int N)
{
    int i;

    printf("COD:\t PRECIOS:\n");
    for (i=0; i<N; i++)
        printf("%d\t %.2f\n",vcod[i],vpre[i]);



}


int busqueda_secuencial (int v[], int cant, int elem)
{
    int i, pos;
    i = 0;
    pos = -1;
    while(i < cant && pos == -1)
    {
        if(v[i] == elem)
            pos = i;
        else
            i++;
    }
    return pos;
}




int leerYValidarSucursal(int li, int ls)
{
    int valor, b = 0;
    do
    {
        if( b == 1)
            printf("\nDATO INCORRECTO, ");

        b = 1;

        printf("INGRESE UNA SUCURSAL   \n", li, ls);
        scanf("%d",&valor);

    }
    while (estaDentroDelRango(li, ls, valor) == 0);

    return valor;


}

int ingresoticket ()
{
    int bandera=0,ticket;

    do
    {
        if(bandera ==1 )
            printf("\nDATO INCORRECTO, ");

        bandera=1;

        printf("INGRESE NUMERO DE TICKET:   \n");
        scanf("%d",&ticket);

        if(ticket>=1)
            bandera=0;





    }
    while (ticket<0);

    return ticket;
}

void mostrarA (int vcod[],int mapizza [] [4],int CC)
{
    int i, f,c;

    printf("PROD\tSUC1\tSUC 2\tSUC3\tSUC4\tSUC5\tSUC6\tSUC7\tSUC8\tSUC9\tSUC10\n");


    for(f=0; f<CC; f++)
    {
        printf("%d",vcod[f]);

        for (c=0; c<CC; c++)
        {
            printf("\t%3d",mapizza[f][c]);
        }
        printf("\n");

    }


}

void ordenarvectoresparalelos (int vc[],float vp[],int N)
{
    int i,j,aux;
    float auxf;

    for (i=0; i<N-1; i++)
    {
        for(j=0; j<N-1-i; j++)
        {
            if(vp[j]<vp[j+1])
            {
                aux=vc[j];
                vc[j]=vc[j+1];
                vc[j+1]=aux;

                auxf=vp[j];
                vp[j]=vp[j+1];
                vp[j+1]=auxf;
            }
        }
    }
}

float maximo(float v[], int N)
{
    int i;
    float max = v[0];
    for (i=1; i<N; i++) //se comienza en 1 ya que el primero se tomó como referencia
    {
        if (v[i]>max)
            max = v[i];
    }
    return max;
}
