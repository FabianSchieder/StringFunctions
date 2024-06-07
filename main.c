#include <stdio.h>

int strlen(const char* string);
char* strcpy(char* dest, const char* src);
char* strcat(char* dest, const char* src);
int strcmp(char* str1, char* str2);

int main(void)
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
    printf("\nZusammengehaengt: %s", dest);
    
    char str1[] = "Fabian";
    char str2[] = "Fabias";

    if(strcmp(str1, str2) == 0)
    {
        printf("\nDie Strings sind gleich.");
    }
    else if(strcmp(str1, str2) == -1)
    {
        printf("\nDie Strings sind nicht gleich.");
    }

    return 0;
}

int strlen(const char* string)
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
   if(strlen(str1) != strlen(str2))
   {
       return -1;
   }

    for(int i = 0; i < strlen(str1); i++)
    {
        if(str1[i] != str2[i])
        {
            return -1;
        }
    }

    return 0;
}