#include<stdio.h>
#include<stdbool.h>

#define MAX 10

int adj[MAX][MAX];
int a[MAX];
int n;

bool issafe(int i,int k )
{
     if(adj[a[k-1]][i]==0)
     return false;
     for(int j=0;j<k;j++)
     {
        if(a[j]==i)
        return false;
      }
     return true;
}

bool fill(int k)
{
     if(k==n)
     return adj[a[k-1]][a[0]]==1;
     for(int i=1;i<n;i++)
     {
          if(issafe(i,k))
          {
              a[k]=i;
              if(fill(k+1))
                 return true;
                 a[k]=-1;
            }
        }
        return false;
}
              
void print()
{
     for(int i=0;i<n;i++)
          a[i]=-1;
          a[0]=0;
     if(fill(1))
     {
        printf("Hamiltonian cycle:");
        for(int i=0;i<n;i++)
        printf("%d  ",a[i]);
        printf("%d\n",a[0]);
     }    
     else
     {
        printf("not exits");
     }
}

int main() {
    printf("Enter the number of vertices (max %d): ", MAX);
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    print();
    return 0;
}

