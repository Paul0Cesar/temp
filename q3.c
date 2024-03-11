#include <stdio.h>

int _pow(int number, int size)
{
    if (size == 0)
    {
        return 1;
    }
    int result = number;
    for (int i = 0; i < size - 1; i++)
    {
        result = result * number;
    }
    return result;
}

int check_geometric_progression(int *sequence, int size)
{
    if (sequence[0] == 0)
    {
        return -1;
    }
    int diff = sequence[1] / sequence[0];
    for (int i = 0; i < size; i++) // Geometric Progression
    {
        int next_term = sequence[0] * _pow(diff, i);
        if (next_term != sequence[i])
        {
            return -1;
        }
    }
    int last_term = sequence[0] * _pow(diff, size);
    return last_term;
}

int check_arithmetic_progression(int *sequence, int size)
{
    int diff = sequence[1] - sequence[0];
    for (int i = 0; i < size; i++) // Arithmetic Progressions
    {
        int next_term = sequence[0] + (i * diff);
        if (next_term != sequence[i])
        {
            return -1;
        }
    }
    int last_term = sequence[0] + ((size)*diff);
    return last_term;
}

int check_mix_progression(int *sequence, int size)
{
    int new_sequence[size - 1];
    for (int i = 0; i < size - 1; i++)
    {
        int value = sequence[i + 1] - sequence[i];
        new_sequence[i] = value;
    }
    int next = check_arithmetic_progression(new_sequence, size - 1);
    int last_term = sequence[size - 1] + next;
    return last_term;
}

void find_next_term(int *sequence, int size)
{
    int result = check_arithmetic_progression(sequence, size);
    if (result != -1)
    {
        printf("Last term:%d \n", result);
        return;
    }
    result = check_geometric_progression(sequence, size);
    if (result != -1)
    {
        printf("Last term:%d \n", result);
        return;
    }
    result = check_mix_progression(sequence, size);
    if (result != -1)
    {
        printf("Last term:%d \n", result);
        return;
    }
}

int main()
{
    // int size = 0;
    // printf("Enter the number of elements:");
    // scanf("%d", &size);

    // int sequence[size];

    // for (int i = 0; i < size; i++)
    // {
    //     scanf("%d", &sequence[i]);
    // }
    // find_next_term(sequence, size);
    // find_next_term([1,3,5,7], 4);

    int sequence_1[] = {1, 3, 5, 7};
    find_next_term(sequence_1, 4); // NEXT: 9

    int sequence_2[] = {2, 4, 8, 16, 32, 64};
    find_next_term(sequence_2, 6); // NEXT : 128

    int sequence_3[] = {0, 1, 4, 9, 16, 25, 36};
    find_next_term(sequence_3, 7); // NEXT : 49

    int sequence_4[] = {4, 16, 36, 64};
    find_next_term(sequence_4, 4); // NEXT : 100

    return 0;
}