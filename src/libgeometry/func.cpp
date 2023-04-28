#include "func.h"

int FigurName(char* Inpur_array)
{
    char figure[7] = "circle";
    char arr[N];
    int k = 1;


    for (size_t i = 0; i < strlen(Inpur_array); i++)
    {
        if (Inpur_array[i] != '(')
        {
            arr[i] = Inpur_array[i];
        }

        else
        {
            break;
        }
    }

    if (strcmp(arr, figure) == 0)
    {
        k = 0;
    }

    return k;
}

int FigurParametrs(char* Inpur_array)
{
    int k = 0;
    int cnt = 0;


    for (size_t i = 7; Inpur_array[i] != ',' && i < strlen(Inpur_array); i++)
    {
        if ((Inpur_array[i] != '.' && Inpur_array[i] != ' ') && !(Inpur_array[i] >= 48 && Inpur_array[i] <= Y))
        {
            k++;
            printf("Figure coordinates entered incorrectly\n\n");

            return 1;
        }
        if (Inpur_array[i] == '.' && Inpur_array[i + 1] == ')')
        {
            cnt = cnt + 2;
        }

        if (Inpur_array[i] >= Z && Inpur_array[i] <= Y && Inpur_array[i + 1] == ' ')
        {
            cnt++;
        }


    }

    if (cnt + 1 != 2)
    {
        k++;
        printf("Figure coordinates entered incorrectly\n\n");
        return k;
    }

    size_t id = 0;
    for (size_t i = 0; i != strlen(Inpur_array); i++)
    {
        if (Inpur_array[i] == ',')
        {
            id = i + 1;
            i = strlen(Inpur_array) - 1;
        }
    }

    for (; Inpur_array[id] != ')' && id < strlen(Inpur_array); id++)
    {
        if ((Inpur_array[id] != '.' && Inpur_array[id] != ' ') && !(Inpur_array[id] >= Z && Inpur_array[id] <= Y))
        {
            k++;
            printf("Figure radius entered incorrectly\n\n");
            return 1;
        }
        if (Inpur_array[id] == '.' && Inpur_array[id + 1] == ' ')
        {
            cnt = cnt + 2;
        }
        if (Inpur_array[id] >= Z && Inpur_array[id] <= Y && Inpur_array[id + 1] == ' ')
        {
            cnt++;
        }
    }
    if (cnt != 1)
    {
        k++;
        printf("Figure radius entered incorrectly\n\n");
    }
    return k;

}


int Ckecker(char* Inpur_array)
{
    int k = 1, FirstLatters = 0;
    int EndLatters;
    if (Inpur_array[strlen(Inpur_array) - 1] == '\n')
        EndLatters = strlen(Inpur_array) - 2;
    else
        EndLatters = strlen(Inpur_array) - 1;
    for (size_t i = 0; i < strlen(Inpur_array); i++) {
        if (Inpur_array[i] == ')') {
            FirstLatters = i;
            break;
        }
    }
    if (FirstLatters == EndLatters)
        k = 0;
    return k;
}

int finaler(char* Inpur_array)
{
    printf("%s", Inpur_array);

    if (FigurName(Inpur_array))
    {
        printf("Incorrect input of figure name\n\n");
    }
    if (FigurParametrs(Inpur_array))
    {
        return 0;
    }
    if (Ckecker(Inpur_array))
    {
        printf("\n Wrong final symbol\n\n");
    }
    return 0;
}
