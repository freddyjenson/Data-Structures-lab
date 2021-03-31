#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
}*top=NULL,*temp;
typedef struct node NODE;
void push(int d)
{
NODE *newnode;
newnode=(NODE*)malloc(sizeof(NODE));
if(!newnode)
{
printf("\nOVERFLOW");
return;
}
newnode->data=d;
newnode->next=top;
top=newnode;
}
void pop()
{
if(top==NULL)
{
printf("\n\nUNDERFLOW...!");
return;
}
printf("%d Deleted... !",top->data);
top=top->next;
}
void search(int i)
{
int c=0;
if(top==NULL)
{
printf("\n\nStack is empty...!");
return;
}
temp=top;
c++;
while(temp)
{
if(temp->data==i)
{
printf("\n\n%d found at node %d",i,c);
return;
}
temp=temp->next;
c++;
}
printf("\n\n%d not found...!",i);
}
void display()
{
if(top==NULL)
{
printf("\nStack is empty!");
return;
}
else
{
temp=top;
printf("\nTACK from top to bottom: \n");
while(temp!=NULL)
{
printf("%d -> ",temp->data);
temp=temp->next;
}
}
}
void main()
{
int ch,data;
do
{
printf("\nEnter choice to perform: ");
printf("\n1.Push\n2.Pop\n3.Search\n4.Display\n5.Exit\nChoice:");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("\nEnter data: ");
scanf("%d",&data);
push(data);
break;
case 2:pop();
break;
case 3:printf("\nEnter search item: ");
scanf("%d",&data);
search(data);
break;
case 4:display();
break;
case 5:exit(0);
default:printf("\nInvalid Choice");
}} while(ch);
}