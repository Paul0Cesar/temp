#include <stdio.h>

int main()
{
    int i=13;
    int sum=0;

    for(int k=0;k<i;k++){
        sum=sum+k;
    }
    printf("SUM: %d",sum); // SUM: 78
    return 0;
}