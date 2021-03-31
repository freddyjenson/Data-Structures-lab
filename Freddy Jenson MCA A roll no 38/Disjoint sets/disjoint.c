#include <stdio.h>
struct disjointset
{
int parent[10];
int rank[10];
int n;
}d;
void makeSet()
{
for (int i = 0; i < d.n; i++) {
d.parent[i] = i;
d.rank[i]=0;
}
}
void displaySet()
{
printf("\nParent Array\n");
for (int i = 0; i < d.n; i++)
{
printf("%d ",d.parent[i]);
}
printf("\nRank Array\n");
for (int i = 0; i < d.n; i++)
{
printf("%d ",d.rank[i]);
}
printf("\n");
}
int find(int x)
{
if (d.parent[x] != x)
{
d.parent[x] = find(d.parent[x]);
}
return d.parent[x];
}
void Union(int x, int y)
{
int xset = find(x);
int yset = find(y);
if (xset == yset)
{ return; }
if (d.rank[xset] < d.rank[yset])
{
d.parent[xset] = yset;
d.rank[xset]=-1;
}
else if (d.rank[xset] > d.rank[yset])
{
d.parent[yset] = xset;
d.rank[yset]=-1;
}
else
{
d.parent[yset] = xset;
d.rank[xset] = d.rank[xset] + 1;
d.rank[yset]=-1;
}
}
int main()
{
int n,x,y;
printf("How many elements ?");
scanf("%d",&d.n);
makeSet();
int ch,wish;
do
{
printf("\n___MENU_\n");
printf("1. Union \n2.Find\n3.Display\n");
printf("enter choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter elements to perform union");
scanf("%d %d",&x,&y);
Union(x, y);
break;
case 2: printf("Enter elements to check if connected components");
scanf("%d %d",&x,&y);
if (find(x) == find(y))
{
printf("Connected components\n") ;
}
else
{
printf("Not onnected components \n") ;
}
break;
case 3: displaySet();
break;
}
printf("\nDo you wish to continue ?(1/0)\n");
scanf("%d",&wish);
}while(wish==1);
return 0;
}