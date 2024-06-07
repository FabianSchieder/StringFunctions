#include <stdio.h>
#include <stdlib.h>

size_t strlen(const char* string);
char* strcpy(char* dest, const char* src);
char* strcat(char* dest, const char* src);
int strcmp(char* str1, char* str2);

int main(void)
{
//---------------------------------------------strlen()--------------------------------------------------

    char* string = malloc(7 * sizeof(char));
    strcpy(string, "Fabian");

    size_t size = strlen(string);
    printf("Das Wort ist %d Zeichen lang.", size);

//---------------------------------------------strcpy()--------------------------------------------------

    char* string1 = malloc(7 * sizeof(char));
    strcpy(string1, "Fabian");

    char* string2 = malloc(strlen(string1) + 1);
    strcpy(string2, string1);

    printf("\nKopie: %s", string2);

//---------------------------------------------strcat()--------------------------------------------------

    char* dest = malloc(9 * sizeof(char));
    strcpy(dest, "Schieder");

    char* src = malloc(7 * sizeof(char));
    strcpy(src, "Fabian");

    dest = realloc(dest, strlen(dest) + strlen(src) + 1);
    strcat(dest, src);
    printf("\nZusammengehaengt: %s", dest);

//---------------------------------------------strcpm()--------------------------------------------------

    char* str1 = malloc(7 * sizeof(char));
    strcpy(str1, "Fabian");

    char* str2 = malloc(7 * sizeof(char));
    strcpy(str2, "Fasians");

    printf("\nUnterschiede: %d", strcmp(str1, str2));

    //-----------------------------------------------------------------------------------------------

    free(string);
    free(string1);
    free(string2);
    free(dest);
    free(src);
    free(str1);
    free(str2);

    return 0;
}

size_t strlen(const char* string)
{
    int counter = 0;

    while (string[counter] != '\0')
    {
        counter++;
    }

    return counter;
}

char* strcpy(char* dest, const char* src)
{
    int i = 0;
    for(i; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }

    dest[i + 1] = '\0';

    return dest;
}

char* strcat(char* dest, const char* src)
{
    size_t length = strlen(dest);
    int i = 0;

    for(i; src[i] != '\0'; i++)
    {
        dest[length + i] = src[i];
    }

    dest[length + i] = '\0';

    return dest;
}

int strcmp(char* str1, char* str2)
{
    int diff = 0;
    size_t length = strlen(str1);
    diff = strlen(str2) - strlen(str1);
    if(length > strlen(str2))
    {
        length = strlen(str2);
        diff = strlen(str1) - strlen(str2);
    }

    for(int i = 0; i < length; i++)
    {
        if(str1[i] != str2[i])
        {
            diff++;
        }
    }

    return diff;
}