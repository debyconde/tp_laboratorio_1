float sumar(float a,float b)
    {
        float suma;
        suma = a + b;
        return suma;
    }

    float restar(float a,float b)
    {
        float resta;
        resta = a - b;
        return resta;
    }

    float multiplicar(float a,float b)
    {
        float mult;
        mult = a * b;
        return mult;
    }


    float dividir(float a,float b)
    {
        float div;
        if (b==0)
        {
            printf("ERROR, no se puede dividir por cero!!!!!!!!!\n");
        }
        else
        {
        div = a / b;
        }
        return div;
    }


    int factorial(int num1)
    {
        int facto;

    if(num1==0)
    {

        return 1;
    }
    else
    {
        return num1*factorial(num1-1);

    }
}

    float todas_operaciones(float a,float b)
    {
       int factorialAux;
       float suma, resta, mult, div;

       suma = sumar(a,b);
       resta = restar(a,b);
       mult = multiplicar(a,b);
       div = dividir(a,b);
       factorialAux = factorial((int)a);

       printf("La suma es %.2f \n\n",suma);
       printf("La resta es %.2f \n\n",resta);
       printf("La multiplicacion es %.2f \n\n",mult);
       printf("La division es %.2f \n\n", div);
       printf("El factorial de: %d! es %d \n\n",(int)a, factorialAux);
}
