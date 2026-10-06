#include <stdio.h>
#include <string.h>
#define SIZE 20
int bitArray[SIZE] = {0};

// First hash function
int hash1(char str[])
{
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++)
        hash = (hash + str[i]) % SIZE;
    return hash;
}

// Second hash function
int hash2(char str[])
{
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++)
        hash = (hash * 31 + str[i]) % SIZE;
    return hash;
}

// Insert an element into Bloom Filter
void insert(char str[])
{
    int h1 = hash1(str);
    int h2 = hash2(str);
    bitArray[h1] = 1;
    bitArray[h2] = 1;
}


// Search for an element
int search(char str[])
{
    int h1 = hash1(str);
    int h2 = hash2(str);
    if (bitArray[h1] == 1 && bitArray[h2] == 1)
        return 1;
    return 0;
}

// Display Bloom Filter
void display()
{
    printf("\nBloom Filter:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", bitArray[i]);
    printf("\n");
}
int main()
{
    int n;
    char str[50];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        insert(str);
    }
    display();
    printf("\nEnter element to search: ");
    scanf("%s", str);

    if (search(str))
        printf("%s may be present in the set.\n", str);
    else
        printf("%s is definitely not present in the set.\n", str);
    return 0;
}


OUTPUT
Enter number of elements: 4
Enter the elements:
apple
mango
orange
banana

Bloom Filter:
0 1 0 1 0 0 1 0 1 0 1 0 0 0 1 0 0 1 0 0

Enter element to search: mango
mango may be present in the set.
