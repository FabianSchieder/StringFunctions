#include <stdio.h>
#include <stdlib.h>

size_t strlen(const char* string);
char* strcpy(char* dest, const char* src);
char* strcat(char* dest, const char* src);
int strcmp(char* str1, char* str2);
char* createOnHeap(size_t, const char*);
void checkPointer(void* pointer);

int main(void)
{
    char* string = createOnHeap(7, "Fabian");
    char* string1 = createOnHeap(7, "Schieder");
    char* string2 = strcpy(createOnHeap(7, ""), string);
    char* dest = createOnHeap(strlen(string) + strlen(string1) + 1, string);
    strcat(dest, string1);

    printf("\nLaenge:            %llu", strlen(string));
    printf("\nKopie:             %s", string2);
    printf("\nZusammengehaengt:  %s", dest);
    printf("\nUnterschiede:      %d\n", strcmp(string, string1));

    free(string), free(string1), free(string2);

    return EXIT_SUCCESS;
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
    for(; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }

    dest[i] = '\0';

    return dest;
}

char* strcat(char* dest, const char* src)
{
    size_t length = strlen(dest);
    int i = 0;

    for(; src[i] != '\0'; i++)
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

char* createOnHeap(size_t size, const char* string)
{
    char* array = malloc(size * sizeof(char));
    strcpy(array, string);

    checkPointer(array);

    return array;
}

void checkPointer(void* pointer)
{
    if(pointer == NULL)
    {
        printf("Es ist ein Fehler bei einem Pointer aufgetreten!");
        exit(EXIT_FAILURE);
    }
}


//V2
//int strcmp(char* str1, char* str2)
//{
//    if(strlen( str1) != strlen(str2))
//    {
//        return 0;
//    }
//    for(int i = 0; i < strlen(str1);i++)
//    {
//        if(str1[i] != str2[i])
//        {
//            return 0;
//        }
//
//    }
//    return 1;
//}
