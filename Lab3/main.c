#include "lab3.h"

void p1(void)
{
    int base=2;
    int exp=7;
    struct functionCall * array=createStructArray(exp+1);
    initArray(array, exp+1);
    printArray(array, exp+1);
    freeArray(array);
}

void p2(void)
{
    int base=2;
    int exp=7;
    struct functionCall * array=createStructArray(exp+1);
    recordRecursiveCalls(array, exp, base);
    printArray(array,exp+1);
    freeArray(array);
}

int main( int argc, char *argv[] )
{
    if( argc < 2 )
   	{
        printf("Expecting at least one argument. Please try again\n");
   	}
    else if(argc==2)
    {
        if(atoi(argv[1])==3)
        {
            printf("Expecting two arguments for this part. Please try again.\n");
        }
        else
        {
            if(atoi(argv[1])==1)
            {
                p1();
            }
            else if(atoi(argv[1])==2)
            {
                p2();
            }
            else
            {
                printf("Incorrect argument supplied.\n");
            }
        }
    }
    else
    {
        printf("The argument supplied is %s\n", argv[1]);
    }
}
