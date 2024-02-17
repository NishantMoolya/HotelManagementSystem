#include<stdio.h>
#include<stdlib.h>

void change(int **ptr){
    int *temp = (int *)malloc(sizeof(int));
    printf("\nIn function :%d",**ptr);
    printf("\nIn function :%d",ptr);
    //printf("\n%d",&b);
    printf("\nEnter the val:");
    scanf("%d",temp);
    printf("%d",*temp);
    printf("\n%d",&temp);
    *ptr = temp;
}

int main(){
    int a = 100;
    int *head;
    //printf("\n%d",&b);
    printf("\n%d",a);
    head = &a;
    printf("\n%d",head);
    printf("\n%d",*head);
    printf("\n%d",&head);
    change(&head);
    printf("\n%d",head);
    printf("\n%d",*head);
    free(head);
    return 0;
}