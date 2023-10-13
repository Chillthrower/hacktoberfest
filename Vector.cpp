#include<stdio.h>
#include<stdlib.h>

//replicating vector used in c++ in c

struct IntVector
{
    int *data;
    int size;
    int capacity;
};

IntVector* CreateVector()
{
    IntVector *vector = (IntVector*)malloc(sizeof(IntVector));
    if (vector)
    {
        vector->data = NULL;
        vector->size = 0;
        vector->capacity = 0;
    }

    return vector;    
}

void PushBack(struct IntVector *vector, int val)
{
    if (vector->size >= vector->capacity)
    {
        int new_capacity = (vector->capacity == 0) ? 1 : vector->capacity * 2;
        int* new_data = (int*)realloc(vector->data, new_capacity * sizeof(int));
        vector->data = new_data;
        vector->capacity = new_capacity;
    }

    vector->data[vector->size] = val;
    vector->size++;
}

int at(struct IntVector *vector, int index)
{
    if(index < vector->size)
    {
        return vector->data[index];
    }
    else
    {
        return 0;
    }
}   

void freeVector(struct IntVector *vector)
{
    if(vector)
    {
        free(vector->data);
        free(vector);
    }
}

int main()
{
    IntVector *vector = CreateVector();
    PushBack(vector, 10);
    PushBack(vector, 20);
    PushBack(vector, 30);

    printf("%d\n", at(vector, 0));
    printf("%d\n", at(vector, 1));


}

