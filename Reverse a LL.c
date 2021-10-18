#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
void create(struct node **p,int n)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    struct node* last=*p;
    new->data=n;
    new->link=NULL;
    if(*p==NULL)
    {
        *p=new;
        
    }
    else
    {
        while(last->link!=NULL)
        {
            last=last->link;
        }
        last->link=new;
    }
}
void display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->link;
    }
}
void reverse(struct node **p)
{
    struct node *curr=*p,*prev=NULL,*next=NULL;
    while(curr!=NULL)
    {
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }
    *p=prev;
}
int main()
{
    struct node *p=NULL;
    int n,num;
    printf("How many numbers to insert into list:");
    scanf("%d",&n);
    printf("\nEnter %d numbers:",n);
    while(n--)
    {
        scanf("%d",&num);
        create(&p,num);
    }
    printf("\nThe list is:");
    display(p);
    reverse(&p);
    printf("\nThe reverse list is:");
    display(p);
}
