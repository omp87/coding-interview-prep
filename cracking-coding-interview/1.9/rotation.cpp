#include <stdio.h>

using namespace std;


int get_string_length(const char* mystring)
{
    int i = 0;
    while(mystring[i] != 0)
    {
        i++;
    }
    return i;
}


int main(int argc, char* argv[])
{
    const char* string_1 = "thisismystring";
    const char* string_2 = "tringthisismys";


    int return_value = 1;
    int string_1_length = get_string_length(string_1);
    int string_2_length = get_string_length(string_2);
    if(string_1_length != string_2_length)
    {
        return 0;
    }

    for(int offset = 0; offset < string_1_length; offset++)
    {
        bool full_match = true;
        for(int i = 0; i < string_1_length; i++)
        {
            if(string_1[i] != string_2[(i+offset)%string_1_length])
            {
                full_match = false;
            }
        }
        if(full_match)
        {
            printf("match\n");
            return 1;
        }
    }
    
    return 0;
}