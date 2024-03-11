#include <stdio.h>

int check_fibo(int number)
{
    if (number == 0 || number == 1)
    {
        return 1;
    }
    int n1 = 0;
    int n2 = 1;
    int next_term=n1+n2;

    while(next_term<number){
        n1=n2;
        n2=next_term;
        next_term=n1+n2;
        if(next_term==number){
            return 1;
        }
    }
    return 0;
}

int main()
{
    int number = 0;
    printf("Enter the number you want to check:");
    scanf("%d", &number);
    int result = check_fibo(number);
    if (result)
    {
        printf("Belongs!");
    }
    else
    {
        printf("Does not belong!");
    }
    return 0;
}