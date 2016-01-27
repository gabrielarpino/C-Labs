#include <stdio.h>

void printList(int n, int list[n])
{
    int i;
    for(i=0;i<4;i++)
    {
        printf("%d ",list[i]);
    }
    printf("\n");
}

int main(void)
{
    FILE *fp=fopen("example.txt", "r");
    int list[4];
    fscanf(fp,"%d",&list[0]);
    fscanf(fp,"%d",&list[1]);
    fscanf(fp,"%d",&list[2]);
    fscanf(fp,"%d",&list[3]);
    printList(4, list);
    fclose(fp);
}
