#include <stdio.h>
#include <time.h>

typedef struct items
{
    int weight;
    int price;
} materials;

int max(int a, int b) // max function
{
    return !(a < b) ? a : b;
}

void Knapsack(struct items elements[], int Weight, int length)
{
    int best_price[Weight + 1];
    int i, j;

    // initialize best price array
    for (i = 0; i <= Weight; i++) // for all the Weight
    {
        best_price[i] = 0;
    }
    // start knapsank process
    for (i = 0; i <= Weight; i++) // for all the Weight
    {
        for (j = 0; j < length; j++) // for all the items
        {
            if (elements[j].weight <= i) // if current element weight is smallest that Weight
            {
                best_price[i] = max(best_price[i], best_price[i - elements[j].weight] + elements[j].price);
            }
        }
    }
    printf("The best price is: %d\n", best_price[Weight]); // show the best price
}

int main()
{
    int B, item, i;

    printf("Enter the weight of your bag: ");
    scanf("%d", &B);

    printf("Enter how many items you want to store: ");
    scanf("%d", &item);

    materials elements[item]; // initialize the struct size

    for (i = 0; i < item; i++)
    {
        printf("Enter the weight of the %dth element: ", i + 1);
        scanf("%d", &elements[i].weight);
    }

    for (i = 0; i < item; i++)
    {
        printf("Enter the price of the %dth element: ", i + 1);
        scanf("%d", &elements[i].price);
    }
    int l = sizeof(elements) / sizeof(elements[0]); // length

    clock_t begin = clock(); // clock start

    Knapsack(elements, B, l); // parcing the struct elements, Weight, length to function

    clock_t end = clock(); // clock stop

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; // calculate the running time
    printf("The total run time is: %lf\n", time_spent);
    printf("\t\t***End Of Program***\n");
    return 0;
}
