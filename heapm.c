#include<stdio.h>
#include<conio.h>
int k[50];
int child,parent,q,key,n,t,i;
int current,parent,child,i,maxnodes;
void min();
void max();
void crheap(int k[],int n);
void crheapd(int k[],int n);
void processheap(int k[],int n);
void processheapd(int k[],int n);
void main()
{
      int choice,n;
      printf("\n 1.Max Heap");
      printf("\n 2.Min Heap");
      printf("\n 3.Exit");
      printf("\n Enter your choice");
      scanf("%d",&choice);
      switch(choice)
      {
           case 1:max();
                  break;
      
           case 2:min();
                  break;
           case 3:break;
       }

}
void max()
{
    int ch,e,n,i,j,t,r;
    do
    {
      printf("\n 1.Insert");
      printf("\n 2.Delete");
      printf("\n 3.Exit");
      printf("\n Enter your choice");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1:  printf("\n enter the no. of elements: ");
                   scanf(" %d",&n);
                   printf("\n Now enter the array elements: ");
                   for(i=1;i<=n;i++)
                       scanf(" %d",&k[i]);
                   crheap(k,n);
                   break; 
           case 2: processheap(k,n);
                   break;               
      }
    }while(ch!=3);
}

void crheap(int k[],int n)
{
 int i,q, parent,child,temp;
 for(q=2;q<=n;q++)
 {
  child=q;
  parent=(int)child/2;
  while(child >1 && k[child] > k[parent])
  {
    temp=k[child];
    k[child]= k[parent];
    k[parent]=temp;
    child=parent;
    parent=(int)child/2;
    if(parent < 1)
       parent=1;
  }
 }
 printf("\n Now the array in heap form is: ");
 for(i=1;i<=n;i++)
     printf(" %3d",k[i]);
}
/* function to sort a heap */
void processheap(int k[],int n)
{
  int current,parent,child,i,maxnodes;
 for(maxnodes=n;maxnodes>=2;maxnodes--)
 {
  current=k[maxnodes];
  k[maxnodes]=k[1];  
  /* adjust the array to be a heap of size n-1 */
  parent=1;
  /* obtain the larger of the root's children */
  if(maxnodes-1>=3&&k[3]>k[2])
  {
      child=3;
  }
  else
  {
      child=2;
  }
  /* move keys upwards to find place for current */
  while(child<=maxnodes-1&&k[child]>=current)
  {
   k[parent]=k[child];
   parent=child;
   child=child*2;
   if(child+1<=maxnodes-1&&k[child+1]>k[child])
             child=child+1;
  }
  k[parent]=current;
 }/* end of for */
 printf("\n The sorted array is : ");
 for(i=1;i<=n;i++)
 {
     printf("%4d",k[i]);
 }

}
void min()
{
       int ch,e,n,i,j,t,r;
    do
    {
      printf("\n 1.Insert");
      printf("\n 2.Delete");
      printf("\n 3.Exit");
      printf("\n Enter your choice");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1: 
                   printf("\n enter the no. of elements: ");
                   scanf(" %d",&n);
                   printf("\n Now enter the array elements: ");
                   for(i=1;i<=n;i++)
                       scanf(" %d",&k[i]);
                   crheapd(k,n);
                   break; 
           case 2: processheapd(k,n);
                   break;               
      }
    }while(ch!=3);
}
void crheapd(int k[],int n)
{
 int i,q, parent,child,temp;
 for(q=2;q<=n;q++)
 {
  child=q;
  parent=(int)child/2;
  while(child >1 && k[child] < k[parent])
  {
    temp=k[child];
    k[child]= k[parent];
    k[parent]=temp;
    child=parent;
    parent=(int)child/2;
    if(parent < 1)
       parent=1;
  }
 }
 printf("\n Now the array in heap form is: ");
  for(i=1;i<=n;i++)
    printf(" %3d",k[i]);
}
/* function to sort a heap */
void processheapd(int k[],int n)
{
 int current,parent,child,i,maxnodes;
 for(maxnodes=n;maxnodes>=2;maxnodes--)
 {
  current=k[maxnodes];
  k[maxnodes]=k[1];
  /* adjust the array to be a heap of size n-1 */
  parent=1;
  /* obtain the larger of the root's children */
  if(maxnodes-1>=3&&k[3]<k[2])
  {
      child=3;
  }
  else
  {
      child=2;
  }
  /* move keys upwards to find place for current */
  while(child<=maxnodes-1&&k[child]<=current)
  {
   k[parent]=k[child];
   parent=child;
   child=child*2;
   if(child+1<=maxnodes-1&&k[child+1]<k[child])
             child=child+1;
  }
  k[parent]=current;
 } /* end of for */
 printf("\n The sorted array is : ");
 for(i=1;i<=n;i++)
 {
     printf("%4d",k[i]);
 }
}

/*output:

C:\Users\Tejal\Desktop>heapm

 1.Max Heap
 2.Min Heap
 3.Exit
 Enter your choice1

 1.Insert
 2.Delete
 3.Exit
 Enter your choice1

 enter the no. of elements: 11

 Now enter the array elements: 21 15 25 3 5 12 7 19 45 2 9

 Now the array in heap form is:   45  25  21  19   9  12   7   3  15   2   5
 1.Insert
 2.Delete
 3.Exit
 Enter your choice2

 The sorted array is :    2   3   5   7   9  12  15  19  21  25  45
 1.Insert
 2.Delete
 3.Exit
 Enter your choice3

for min heap
C:\Users\Tejal\Desktop>heapm

 1.Max Heap
 2.Min Heap
 3.Exit
 Enter your choice2

 1.Insert
 2.Delete
 3.Exit
 Enter your choice1

 enter the no. of elements: 11

 Now enter the array elements: 21 15 25 3 5 12 7 19 45 2 9

 Now the array in heap form is:    2   3   7  19   5  25  12  21  45  15   9
 1.Insert
 2.Delete
 3.Exit
 Enter your choice2

 The sorted array is :   45  25  21  19  15  12   9   7   5   3   2
 1.Insert
 2.Delete
 3.Exit
 Enter your choice3
*/