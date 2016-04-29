
/* ESTRUCTURA DE LOS DATOS QUE VOY A USAR */
struct persona
    {
    char nombre[31];
    long int dni;
    int edad;
    short int estado;
    };

/* DEFINICION DE PROTOTIPOS */
    void Menu();
    void ValidarCadena(char[]);
    int Validar_Edad (int,int,int);
    long int val_dni (long int, long int, long int);
    long int dniRepetido (struct persona[], long int);
    void IngresoDatos(struct persona []);
    int BajaDatos(struct persona []);
    void OrdenarDatos(struct persona []);
    void grafico(struct persona[]);
