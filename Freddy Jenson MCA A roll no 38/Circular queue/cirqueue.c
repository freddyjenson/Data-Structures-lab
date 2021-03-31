#include<stdlib.h>
#include<stdio.h>
#define SIZE 6
int front=-1,rear=-1;
int CQueue[SIZE];
void insert();
int delete();
void display();
void search();
int main()
{
int w,no;
for(;;)
{
printf("\n Menu \n");
printf("\n #####\n");
printf("\n1. Insert");
printf("\n2. Delete");
printf("\n3. Display");
printf("\n4. Search");
printf("\n5. EXIT");
printf("\nEnter any option : \n");
scanf("%d",&w);
switch(w)
{
case 1:
insert();
break;
case 2:
no=delete();
break;
case 3:
display();
break;
case 4:
search();
case 5:
exit(0);
default:
printf("\nInvalid Option!!\n");
}
}
}
void insert()
{
int no;
if((front ==0 && rear == SIZE-1) || front == rear+1)
{
printf("\nCircular Queue Is Full !\n");
return;
}
printf("\nEnter a number to Insert :\n");
scanf("%d",&no);
if(front==-1)
front=front+1;
if(rear==SIZE-1)
rear=0;
else rear=rear+1;
CQueue[rear]=no;
}
int delete()
{
int e;
if(front==-1)
{
printf("\nThe Circular Queue is Empty !!\n");
}
e=CQueue[front];
if(front==SIZE-1)
front=0;
else if(front==rear)
{
front=-1;
rear=-1;
}
else front=front+1;
printf("\n%d was deleted !\n",e);
return e;
}
void display()
{
int i;
if(front==-1)
{
printf("\nThe Circular Queue is Empty!. Nothing To Display !!\n");
return;
}
i=front;
if(front<=rear)
{
printf("\n\n");
while(i<=rear)
printf("%d ",CQueue[i++]);
printf("\n");
}
else
{
printf("\n\n");
while(i<=SIZE-1)
printf("%d ",CQueue[i++]) ;
i=0;
while(i<=rear)
printf("%d ",CQueue[i++]);
printf("\n");
}
}
void search()
{
int item,i,c=0;
printf("Enter the element which is to be searched");
scanf("%d", &item);
for(i=front;i<=rear;i++)
{
if(item==CQueue[i])
{
printf("item found at location %d ",i+1);
c++;
}
}
if(c==0)
printf("item not found");
}