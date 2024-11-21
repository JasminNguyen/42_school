#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i= 0;
    int temp = 0;
    while(i < size -1) //make sure that we are not out of bounds, we move until the second to last i -> cause [i + 1]
    {
        if(tab[i] > tab[i + 1])
        {
            temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = temp;
            i = 0;
        }
        else //only move forward if there is no swap needed
        i++;
    }
}

int main(void)
{
    unsigned int i = 0;
    int array[] = {1, 2, 3, -2, -44, 1200};
    unsigned int size = 6;
    sort_int_tab(array, size);
    while(i < size)
    {
        printf("array[%d]: %d\n", i, array[i]);
        i++;
    }
}
