#include <stdio.h>

int main(int argc, char* argv[])
{
    const char* source = "Hello, World!";
    const char* check = "Goodbye, Moon!";


    int letter_array[256];
    int check_letter_array[256];
    for(int i = 0; i < 256; i++)
    {
        letter_array[i] = 0;
        check_letter_array[i] = 0;
    }
    
    int i = 0;
    while(source[i] != 0)
    {
        letter_array[source[i]] = letter_array[source[i]] + 1;
        i++;
    }

    i = 0;
    while(check[i] != 0)
    {
        check_letter_array[check[i]] = check_letter_array[check[i]] + 1;
        i++;
    }

    bool match = true;
    for(int i = 0; i < 256; i++)
    {
        if(letter_array[i] != check_letter_array[i])
        {
            match = false;
            printf("%c\n", (char)i);
        }
    }

    return 0;
}