#include <stdio.h>

int strlen(char* string);
void strcpy(char* dest, char* src);
void strcat(char* dest, char* src);
int strcmp(char* str1, char* str2);

int main()
{
    char string[] = "Fabian";

    int size = strlen(string);
    printf("Das Wort ist %d Zeichen lang.", size);

    char string1[] = "Fabian";
    char string2[strlen(string1)];

    strcpy(string2, string1);

    printf("\nKopie: %s", string2);

    char dest[] = "Schieder";
    char src[] = "Fabian";

    strcat(dest, src);
    printf("\nZusammengehaengt: %s", string1);

    return 0;
}

int strlen(char* string)
{
    int counter = 0;

    while (string[counter] != '\0')
    {
        counter++;
    }

    return counter;
}

void strcpy(char* dest, char* src)
{
    int i = 0;
    for(i; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }

    dest[i + 1] = '\0';
}

void strcat(char* dest, char* src)
{
    int i = 0;
    for(i; i < strlen(src); i++)
    {
        dest[strlen(dest) + i + 1] += src[i];
    }

    dest[i + 1] = '\0';
}
