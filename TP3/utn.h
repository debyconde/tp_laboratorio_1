typedef struct
{
    char titulo[31];
    char genero[31];
    int duracion;
    char descripcion[81];
    int puntaje;
    char link_deimagen[81];
    short int estado;
}movie;


void agregar_pelicula(movie pelicula, FILE *parch);
void borrar_pelicula(movie pelicula, FILE *parch);
void modificar_pelicula(movie pelicula, FILE *parch);
int generar_paginaweb(movie pelicula,FILE*parch);

