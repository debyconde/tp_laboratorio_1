#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
int main()
{
    float num1=0.0,num2=0.0,resultado;
    int fact;
    int nfactor;
    int opcion=0;

                while(opcion <9)
                {
                printf("\n\t\t \t * CALCULADORA * \n\n");
                printf("1.Ingresar 1er Operando: (A= %.2f)\n\n",num1);
                printf("2.Ingresar 2do operando: (B= %.2f)\n\n",num2);
                printf("3.Calcular la Suma (A+B)\n\n");
                printf("4.Calcular la Resta (A-B)\n\n");
                printf("5.Calcular la Multiplicacion (A*B)\n\n");
                printf("6.Calcular la Division (A/B)\n\n");
                printf("7.Calcular el Factorial (A!)\n\n");
                printf("8.Calcular todas las operaciones\n\n");
                printf("9.Salir\n\n");
                printf("\n \t\t\t *** Elija opcion ***\n\n");

                printf("Ingrese opcion: ");
                fflush(stdin);
                scanf("%d",&opcion);
                system("cls");

                            switch(opcion)
                            {

                                case 1: printf("\nIngrese primer operando:\n");
                                        scanf("%f",&num1);
                                        break;
                                case 2: printf("\nIngrese segundo operando:\n");
                                        scanf("%f",&num2);
                                        break;
                                case 3: resultado = sumar(num1,num2);
                                        printf("La suma es %.2f \n\n",resultado);
                                        break;
                                case 4: resultado = restar(num1,num2);
                                        printf("La resta es %.2f \n\n",resultado);
                                        break;
                                case 5: resultado = multiplicar(num1,num2);
                                        printf("La multiplicacion es %.2f \n\n",resultado);
                                        break;
                                case 6: resultado = dividir(num1,num2);
                                        printf("La division es %.2f \n\n", resultado);
                                        break;
                                case 7: nfactor=(int)num1;
                                        fact = factorial(nfactor);
                                        printf("El factorial de: %d! es %d \n\n",nfactor, fact);
                                        break;
                                case 8: resultado=todas_operaciones(num1,num2);
                                        break;
                                case 9: printf("USTED SALIO DEL PROGRAMA..");
                                        break;
                                    }

        }

	return 0;
    }
