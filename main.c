#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void insert(int x)
{
    struct Node *p,*t,*last;
    if(first==NULL)
    {
       t=(struct Node *)malloc(sizeof(struct Node));
       t->data=x;
       t->next=NULL;
       first=t;
       last=t;
    }
    else
    {
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data=x;
        last->next=p;
        last=p;
        p->next=NULL;
    }
}
void display(struct Node *q)
{
    int sum=0;
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q=q->next;
    }
};
int countNode(struct Node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count=count+1;
        p=p->next;
    }
    return count;
}
int sumNode(struct Node *p)
{
    int sum=0;
    while(p!=0)
    {
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}
int Delete(int pos)
{
    struct Node *p,*q;
    int x=-1,i;
    if(pos==1)
    {
        x=first->data;
        p=first;
        first=first->next;
        free(p);
    }
    else
    {
        p=first;
        q=NULL;
        for(i=0; i<pos-1&&p; i++)
        {
            q=p;
            p=p->next;
        }
        if(p)
        {
            q->next=p->next;
            x=p->data;
            free(p);
        }
        return x;
}

int main()
{
    insert(1);
    insert(1);
    insert(1);
    insert(9);
    display(first);
   // printf("%d\n",Delete(1));
    //display(first);

    //printf("sum of nodes=%d",sumNode(first));
}
