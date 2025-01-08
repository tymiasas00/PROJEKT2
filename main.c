#include <stdio.h>

extern float _calc(float x);
float calc(float x);

typedef enum { false, true } bool;

int main()
{

    float x, result;
    char input[10];
    int precision;
    bool keepRunning = true;

    while (keepRunning == true)
    {
        printf("Podaj liczbe x: ");
        if (scanf("%f", &x) != 1)
        {
            fprintf(stderr, "Error: Nieprawidlowe dane!\n");
            return 1;
        }
        printf("Podaj liczbe miejsc po przecinku: ");
        if (scanf("%d", &precision) != 1 || precision < 0 || precision > 7)
        {
            fprintf(stderr, "Error: Nieprawidlowe dane wejsciowe dla precyzji! Musi byc miedzy 0 a 7.\n");
            return 1;
        }

        // Pass the value of x to the assembly function
        result = calc(x); // The value of x is passed on the stack

        printf("1/x = %.*f\n", precision, result);

        printf("Wprowadz 'e' i nacisnij enter, aby zamknac program, lub nacisnij enter, aby kontynuowac: ");
        while (getchar() != '\n');
        fgets(input, sizeof(input), stdin);
        if ((input[0] == 'e' || input[0] == 'E') && (input[1] == '\n' || input[1] == '\0'))
        {
            printf("Program zakonczony prawidlowo!!\n");
            keepRunning = false;
        }
    }
    return 0;
}
