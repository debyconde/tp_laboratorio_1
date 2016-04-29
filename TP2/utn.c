#include <stdio.h>
#include <string.h>
#include "utn.h"
#define CANT 20
/*DEFINICION DE LAS FUNCIONES*/
void Menu()
    {
        system("cls");
        printf("\t\t\t MENU PRINCIPAL\n");
        printf("\t\t\t***************\n\n\n");
        printf("1 - Agregar una persona.\n");
        printf("2 - Borrar una persona.\n");
        printf("3 - Imprimir lista ordenada por nombre.\n");
        printf("4 - Imprimir grafico de edades.\n");
        printf("5 - Salir.\n\n\n");
        printf("Elija opcion: ");
    }

void ValidarCadena(char cadena[])
    {
        char aux[512];
        fflush(stdin);
        gets(aux);

    /*VALIDA QUE SE INGRESE UN MAXIMO DE 30 CARACTERES*/
    while (strlen(aux)<1 || strlen(aux)>30)
        {
            printf("\nReingrese nombre, maximo 30 caracteres:\n ");
            gets(aux);
        }
            strcpy(cadena, aux);
            return;
    }

int Validar_Edad (int dato, int min, int max)
{

    if (dato < min || dato > max)
        {
            printf("Reingrese edad (1-150): ");
            scanf("%d", &dato);
            system("pause>>null");
        }

            return dato;
}

long int val_dni (long int dato, long int min, long int max)
    {
        while(dato < min || dato > max)
            {
                printf("Reingrese dni: ");
                scanf("%ld", &dato);

            }

                return dato;
}

long int dniRepetido (struct persona lista[], long int dato)
    {
        int i,auxdni;
        for (i = 0; i < CANT; i++)
            {
                if (lista[i].dni == dato)
                    {
                        printf("Ya existe este dni, reingrese: ");
                        scanf("%ld", &dato);
                    }
            }
            return dato;
    }

void IngresoDatos(struct persona lista[])
{
    int i, libre=0, auxedad, dniExist;
    long int doc;
    system("cls");
    printf("AGREGAR UNA PERSONA\n");
    printf("*******************\n\n");
    for(i=0;i<CANT;i++)
        { /*BUSCA UN LUGAR VACIO PARA GUARDAR*/
            if(lista[i].estado == 0)
                {
                    printf("Ingrese nombre: ");
                    ValidarCadena(lista[i].nombre);

            do{
                    printf("Ingrese dni: ");
                    scanf("%ld", &doc);
                    doc = val_dni(doc, 7000000, 94000000);
                    dniExist = dniRepetido(lista, doc);
                    lista[i].dni = doc;
            }while(dniExist == 1);



                    printf("Ingrese edad: ");
                    scanf("%d", &auxedad);
                    auxedad=Validar_Edad(auxedad,1,150);
                    lista[i].edad = auxedad;
                    lista[i].estado=1;
                    libre=1;
                    break;
            }
        }
         /* SI RECORRE TODO EL VECTOR DICE SI NO QUEDA ESPACIO O SI FUE GUARDADO*/
            if(libre==0)
            {
                    printf("No queda memoria suficiente para seguir guardando datos\n");
                    system ("pause");
                    return 0;
            }
            else
            {
                    printf("\nEl dato fue guardado exitosamente");
                    printf("\nPresione ENTER para continuar...");
                    system("pause>>null");
                    return 1;
            }
}


int BajaDatos(struct persona lista[CANT])
{
    int i=0;
    long int auxdni;
    system("cls");
    printf("BORRAR UNA PERSONA\n");
    printf("******************\n");
/*INGRESA DNI PARA DAR DE BAJA*/
    printf("\nIngrese dni que quiere dar de baja: \n");
    scanf("%ld",& auxdni);

    for(i=0;i<CANT;i++)
        {
            if(auxdni==lista[i].dni)
                {
                    lista[i].estado=0;
                    printf("\n SE BORRO PERSONA \n");
                    system("pause");
                    return 0;

                }


            else
                {
                    lista[i].estado=1;
                    printf("\n DNI NO ENCONTRADO \n");
                    system("pause>>null");
                    return;
                }
                system("pause");
        }
}



void OrdenarDatos(struct persona lista[])
{
    int i,j;
    struct persona aux;
    system("cls");
    printf("\nORDENAR PERSONAS\n");
    printf("****************\n");

    for(i=0;i<CANT-1;i++)
    {
        for(j=i+1;j<CANT;j++)
        {
            if(stricmp(lista[i].nombre,lista[j].nombre)>0)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }

    printf("\nnombre\t\t\tdni\t\tedad\n");
    for(i=0;i<CANT;i++)
   {
       if(lista[i].estado!=0)
       {
          printf("%s\t\t\t%ld \t%d\n", lista[i].nombre, lista[i].dni, lista[i].edad);
       }
   }
    getch();
}


void grafico(struct persona lista [])
{

 int i, menor18=0, medio=0, mayor35=0, flag2=0, mayor;

    system("cls");
    printf("GRAFICO\n");
    printf("*******\n\n");

    for(i=0;i<CANT;i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].edad<=18)
            {
                menor18++;
            }

            if (lista[i].edad>=19&&lista[i].edad<=35)
            {
                medio++;
            }

            if(lista[i].edad>=36)
            {
                mayor35++;
            }
        }
    }

        if(menor18>=medio&&menor18>=mayor35)
        {
            mayor=menor18;
        }

        if(medio>=menor18&&medio>=mayor35)
        {
            mayor=medio;
        }

        if(mayor35>=menor18&&mayor35>=medio)
        {
            mayor=mayor35;
        }

        for(i=mayor; i>0; i--)
        {
            if (i<=menor18)
        {
            printf("*");
        }
        if(i<=medio)
        {
            flag2=1;
            printf("\t*");
        }
        if(i<=mayor35)
        {
            if(flag2==0)
                printf("\t\t*");
            if(flag2==1)
                printf("\t*");
        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
        }
        printf("<18\t19-35\t>35\n");

        return 0;

}
