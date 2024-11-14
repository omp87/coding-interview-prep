#include <stdio.h>

int one_counter(unsigned int value)
{
    int count = 0;
    unsigned int mask = 1;
    for(int i = 0; i < 32; i++)
    {
        if(value & (mask << i))
        {
            count++;
        }
    }
    return count;
}

int main(int argc, char* argv[])
{
    unsigned int value = 0x0fbfff0f;
    unsigned int down = 0;
    unsigned int up = 0;

    int check_count = one_counter(value);
    unsigned int this_value = value;

    int this_count = -1;
    while(this_count != check_count)
    {
        this_value = this_value -1;
        this_count = one_counter(this_value);
        printf("down: %x\n", this_value);
    }
    down = this_value;
    
    this_count = -1;
    this_value = value;
    while(this_count != check_count)
    {
        this_value = this_value + 1;
        this_count = one_counter(this_value);
        printf("up: %x\n", this_value);
    }
    up = this_value;


    printf("%x\t%x\n", down, up);

    return 0;
}