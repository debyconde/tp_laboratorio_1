#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "funciones.h"


void agregar_pelicula(movie pelicula, FILE *parch)
{
   int flag=0;

   int aux_duracion, aux_Puntaje;

            printf("\t\t\tAGREGAR PELICULA\n\n");
           printf("\t\t\t*****************\n\n");

          getValidString("Ingrese Titulo: ","El titulo debe estar compuesto solo por letras\n", pelicula.titulo);
           getValidString("Ingrese Genero: ","El genero debe estar compuesto solo por letras\n", pelicula.genero);
            getValidString("Ingrese Descripcion: ","La descripcion debe estar compuesta solo por letras\n", pelicula.descripcion);
            aux_Puntaje=getValidInt("Ingrese puntaje: " ,"el puntaje debe ser numerico\n",1,10);
           getValidString("Ingrese link de imagen:  ","Error reingrese..\n", pelicula.link_deimagen);
            aux_duracion=getValidInt("Ingrese duracion de la pelicula: " ,"La duracion debe ser numerica\n",1,10000);

           fseek(parch, 0L, SEEK_END);
           fflush(parch);
           fwrite(&pelicula, sizeof(movie), 1, parch );

           flag=1;

    if(flag==0)
    {
        printf("No lo encontro\n");
        system("pause");
    }
    else
    {
        printf("La pelicula se guardo con exito\n");
        system("pause");
    }
}


void borrar_pelicula(movie pelicula, FILE *parch)
{

    char tituloAux[256];
    int flag=0;
    printf("\t\tBORRAR PELICULA\n");
    printf("\t\t***************\n\n");

    printf("\n Ingrese titulo de la pelicula que desea borrar: \n");
    fflush(stdin);
    gets(tituloAux);

rewind(parch);
    while(!feof(parch))
        {
            fread(&pelicula, sizeof(movie), 1, parch );
    if(stricmp(tituloAux,pelicula.titulo)==0)
        {
        //flag=1;
        pelicula.estado=0;
        fseek(parch,(-1)*sizeof(movie),SEEK_CUR);
        fflush(parch);
        fwrite(&pelicula, sizeof(movie), 1, parch );
        printf("\nPELICULA BORRADA LOGICAMENTE\n");
        flag=1;
        system("pause");
        return 0;
        }

        }
    if(flag==0)
        {
        pelicula.estado=1;
        printf("NO SE ENCONTRO LA PELICULA\n");
        system("pause");
        }

}

void Modificar_pelicula(movie pelicula, FILE *parch)
{
    int flag=0,opc;
    char auxChar[256];
    int aux_duracion,aux_Puntaje;
    printf("\t\tMODIFICAR PELICULA\n");
    printf("\t\t******************\n\n");
    printf ("Ingrese pelicula que desea modificar:");
    fflush(stdin);
    gets(auxChar);
    rewind(parch);
    while(!feof(parch)){
            fread(&pelicula, sizeof(movie), 1, parch );
            if(stricmp(auxChar, pelicula.titulo)==0)
        {
            printf("PELICULA ENCONTRADA");
            printf("Modificar\n");
            printf("\n1-Titulo");
            printf("\n2-Descripcion");
            printf("\n3-Duracion");
            printf("\n4-Genero");
            printf("\n5-Puntaje");
            printf("\n6-Link de imagen");
            printf("\n7-Volver al menu principal");
            printf("\nElija opcion:");
            scanf("%d",&opc);

            switch(opc)
            {
                case 1:
                    getValidString("Ingrese nuevo Titulo: ","El titulo debe estar compuesto solo por letras\n", pelicula.titulo);
                break;
                case 2:

            getValidString("Ingrese Descripcion: ","La descripcion debe estar compuesta solo por letras\n", pelicula.descripcion);




                break;
                case 3:
                    aux_duracion=getValidInt("Ingrese duracion de la pelicula: " ,"La duracion debe ser numerica\n",1,10000);
                break;
                case 4:
                    getValidString("Ingrese Genero: ","El genero debe estar compuesto solo por letras\n", pelicula.genero);
                break;
                case 5:
                    aux_Puntaje=getValidInt("Ingrese puntaje: " ,"el puntaje debe ser numerico\n",1,10);
                break;
                case 6:
                    getValidString("Ingrese link de imagen:  ","Error reingrese..\n", pelicula.link_deimagen);

            }



                fseek(parch,(-1)*sizeof(movie),SEEK_CUR);
                fwrite(&pelicula, sizeof(movie), 1, parch );
                flag=1;
                system("pause");
                return 0;

                }

                }

        if(flag==0)
        {
            printf("la pelicula no existe");



    }
}


int generar_paginaweb(movie pelicula,FILE*parch)
{
    FILE*f;
    f=fopen("index.html","w");
    int retorno=-1;

    if(f!=NULL)
    {
        fprintf(f,"\n    <title>Listado de  peliculas</title>");
        fprintf(f,"\n</head>");
        fprintf(f,"\n<body>");

            if(pelicula.estado==0)
            {
                fprintf(f,"\n<!-- Repetir esto para cada pelicula -->");
                fprintf(f,"\n<article class='col-md-4 article-intro'>");
                fprintf(f,"\n<a href='#'>");
                fprintf(f,"\n<img class='img-responsive img-rounded' src='%s' alt=''>",pelicula.link_deimagen);
                fprintf(f,"\n</a>");
                fprintf(f,"\n<h3>");
                fprintf(f,"\n<a href='#'>%s</a>",pelicula.titulo);
                fprintf(f,"\n</h3>");
                fprintf(f,"\n<ul>");
                fprintf(f,"\n<li>Género:%s</li>",pelicula.genero);
                fprintf(f,"\n<li>Puntaje:%d</li>",pelicula.puntaje);
                fprintf(f,"\n<li>Duración:%d</li>	",pelicula.duracion);
                fprintf(f,"\n</ul>");
                fprintf(f,"\n<p>%s</p>",pelicula.descripcion);
                fprintf(f," \n</article>");
                fprintf(f,"	\n<!-- Repetir esto para cada pelicula -->");
            }
        fprintf(f,"</body>");
        fprintf(f,"</html>");
        retorno=0;
    }
    fclose(f);
    printf("PAGINA CREADA\n");
    system("pause");
    return retorno;
}
