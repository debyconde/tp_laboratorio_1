/*DECLARACION DE LIBRERIAS QUE SE VAN A UTILIZAR*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#define CANT 20



 /*ACA ESTA EL MAIN*/
int main ()
    {
        /*DECLARACION DE VARIABLES*/
    int i,opc1=0,bandera=0;
    struct persona lista[CANT];
        /*PUESTA DE FLAG EN 0*/
    for(i=0;i<CANT;i++)
        while(lista[i].estado=0)
        {

            bandera=0;
        }
            /*MENU PRINCIPAL*/
            while (opc1!=5)
            {
                Menu();
                /*LEE OPCION*/
                scanf("%d", &opc1);
                switch (opc1)
                {
                    case 1:/*OPCION PARA AGREGAR PERSONA*/
                            bandera=1;
                            IngresoDatos(lista);
                            break;
                    case 2:/*OPCION PARA BORRAR PERSONA*/
                            if (bandera==1)
                            {
                                BajaDatos(lista);
                                system("pause");
                                break;
                            }
                            else
                            {
                                printf("No hay datos cargados\n");
                                system("pause");
                            }

                            break;
                    case 3:/*OPCION PARA IMPRIMIR LISTA ORDENADA*/

                            if (bandera==1)
                            {
                                OrdenarDatos(lista);
                                system("pause");
                                break;
                            }
                            else
                            {
                                printf("No hay datos cargados\n");
                                system("pause");
                            }

                            break;
                case 4:/*OPCION PARA IMPRIMIR GRAFICO*/
                            if (bandera==1)
                            {
                                grafico(lista);
                                system("pause");
                                break;
                            }
                            else
                            {
                                printf("No hay datos cargados\n");
                                system("pause");
                            }
                            break;
            case 5:/*OPCION PARA SALIR*/
                            system("cls");
                            printf("Salio del programa");
                            system("pause>>null");
                            break;
                        default:
                            printf("ERROR, reingrese opcion (1-5)");
                            system("pause>>null");
                            break;
            }
         }
    return 0;
    }










