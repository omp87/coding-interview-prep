#include <stdio.h>
#include <vector>

using namespace std;
int main(int argc, char* argv[])
{
    unsigned long int check_value = 0xdeadbeefbeefdead;
    unsigned long int mask = 1;
    vector<int> zeros;

    for(int i = 0; i < 64; i++)
    {
        if((check_value & (mask << i )) == 0)
        {
            zeros.push_back(i);
        }
    }

    int best_start = 0;
    int best_difference = -1;
    int this_difference;

    for(int i = 0; i < zeros.size()-2; i++ )
    {
        this_difference = zeros[i+2] - zeros[i];
        if(this_difference > best_difference)
        {
            printf("best difference: %d\n", best_difference);
            best_difference = this_difference;
            best_start = zeros[i+1];
        }
    }

    printf("best position: %d\n", best_start);
}
