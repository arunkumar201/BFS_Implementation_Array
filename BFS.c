/* **node must be contain Zero(0)**.
eg. 0 1
 1 4
 3 5
 9 4*/
#include<stdio.h>
#include<stdlib.h>
#define n 4
int a[n][4];
int visited[n];
int queue[n];
int f=-1,r=-1;
void enqueue(int i);
int dequeue();
void BFS();
int isEmpty();


   


void create_empty();
void print();
void add_edge(int s,int dest);

int  main()
{   
    int s,dest;
    int p,i;
    create_empty();
    printf("\nplease enter number of the pairs of source and destination vertices\n");
    scanf("%d",&p);
     for(i=0;i<p;i++)
       { 
        scanf("%d %d",&s,&dest);  
         add_edge(s,dest);
       }
       print();
       printf("BFS traversal is :\n");
       BFS();
       return 0;
}

void BFS()
{
    int v,u;
    for(v=0; v<n; v++)
      visited[v]=0;
    
     printf("enter the starting vertex:\n");
    scanf("%d",&v);
     
   printf("%d",v);

   visited[v]=1;
   enqueue(v);
   while(!isEmpty())
   {
       u=dequeue();
       for(v=0;v<n;v++)
       {
           if(visited[v]==0 && a[u][v]==1)
           {
               printf(" %d",v);
               visited[v]=1;
               enqueue(v);
           }
       }
   }
}

   int isEmpty()
   {
       if((f==-1 && r==-1)|| f>r)
       {
           return 1;
       }
       else
       return 0;
   }
      
   
   
    int dequeue()
{
    int v;
      if(f==-1 && r==-1)
      {
            printf("Queue is empty:\n");
            exit(1);
      }
      
      else if(f==r)
      
      {    
          v=queue[f];
         f=r=-1;
      }
      else
      {
        v=queue[f];
      f++;
    
     }
      return v;
}

void enqueue(int x)
{
      if(r==(n-1))
      {
            printf("\n Queue is full \n:");
            exit(1);
      }
      else if(f==-1&& r==-1)
      {
            f=r=0;
            queue[r]=x;
            r++;
      }
      else
      {
               queue[r]=x;
              r++;
      }
}

void create_empty()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            a[i][j]=0;
        }
    }
}
void add_edge(int s,int dest)
{  
     
    a[s][dest]=1;
    
        
 }
 void print()
 {
     int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",a[i][j]);
            
        }
        printf("\n");
    } 
 }
