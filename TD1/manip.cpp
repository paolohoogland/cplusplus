#include "manip.h"

int main()
{
    int a = 1;
    int b = 2;
    int c = addInts(a, b);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;

    int &d = c;
    replaceIntsRef(a, b, d);
    std::cout << "after replacing c, c = " << c << std::endl;

    replaceIntsPointers(a, b, &c);
    std::cout << "after replacing c w/pointers, c = " << c << std::endl;

    std::cout << "Table of random ints:" << std::endl;
    int *table = new int[5];
    table = fillTable(table, 5);
    showTable(table, 5);

    std::cout << "Table of random ints sorted:" << std::endl;
    sortTable(table, 5);
    showTable(table, 5);

    return 0;
}

int addInts(int a, int b)
{
    return a + b;
}

void replaceIntsRef(int a, int b, int &d)
{
    d = a + b;
}

void replaceIntsPointers(int a, int b, int *c)
{
    *c = a + b;
}

int *fillTable(int *table, int size)
{
    for (int i = 0; i < size; i++)
    {
        table[i] = randomInt();
    }
    return table;
}

void showTable(int *table, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << table[i] << std::endl;
    }
}

int randomInt()
{
    return rand() % 100;
}

void inverseTwoElementsWithRef(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sortTable(int *table, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (table[j] > table[j + 1])
            {
                inverseTwoElementsWithRef(table[j], table[j + 1]);
            }
        }
    }
}