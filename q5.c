#include <stdio.h>

void reverse(char *text)
{
    int i = 0;
    int counter = 0;

    while (text[i] != '\0')
    {
        counter++;
        i++;
    }

    int size = i;
    char new_text[size];

    for (int j = 0; j < size; j++)
    {
        new_text[j] = text[i - 1];
        i--;
    }

    printf("    Text: %s\n", text);
    printf("    New Text: %s\n", new_text);
    printf("    ----------------\n");
}

int main()
{

    char text[] = "Hello World!";
    reverse(text);
    char text2[] = "The last of us";
    reverse(text2);

    return 0;
}