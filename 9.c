//a
#include <stdio.h>
void read_adjacency_matrix(int a[10][10], int n) 
{ 
 int  i, j; 
 
 for (i = 0; i < n; i++) 
 { 
  for (j = 0; j < n; j++) 
  { 
   scanf("%d", &a[i][j]); 
  }  
 } 
}

void bfs(int a[10][10], int n, int u) 
{ 
 int  f, r, q[10], v; 
int s[10] = {0};   
 
 printf("The nodes visited from %d : ", u); 
 f = 0, r = -1;   
 q[++r] = u;   
 
 s[u] = 1;  
 printf("%d\t", u); 
 
 while ( f <= r ) 
 { 
  u = q[f++];    
  for (v = 0; v < n; v++) 
  { 
   if (a[u][v] == 1)  
   { 
    if (s[v] == 0)   
    { 
     printf("%d\t", v);   
     s[v] = 1;       
     q[++r] = v;       
    } 
   } 
  } 
 } 
 printf("\n"); 
} 
void main() 
{ 
 int  n, a[10][10], source, i, j; 
 
 printf("Enter the number of nodes :"); 
 scanf("%d", &n); 
 
 printf("Enter the adjacency matrix:\n"); 
 for (i = 0; i < n; i++) 
 { 
  for (j = 0; j < n; j++) scanf("%d", &a[i][j]); 
 } 
 
 for (source = 0; source < n; source++) 
  bfs(a, n, source); 
}


//b
#include <stdio.h>
int a[10][10], s[10], n;  // Global variables 
void read_adjacency_matrix(int a[10][10], int n) 
{ 
 int  i, j; 
 
 for (i = 0; i < n; i++) 
 { 
  for (j = 0; j < n; j++) 
  { 
   scanf("%d", &a[i][j]); 
  }  
 } 
}

void dfs(int u) 
{ 
 int v; 
  
 s[u] = 1; 
  
 printf("%d ", u); 
 
 for (v = 0; v < n; v++) 
 { 
  if (a[u][v] == 1 && s[v] == 0) dfs(v); 
 } 
} 
void main() 
{ 
 int i, source; 
  
 printf("Enter the number of nodes in the graph : "); 
 scanf("%d", &n); 
 printf("Enter the adjacency matrix:\n"); 
 read_adjacency_matrix(a, n); 
 
 for (source = 0; source < n; source++) 
 { 
  for (i = 0; i < n; i++) s[i] = 0; 
   
  printf("\nThe nodes reachable from %d: ", source); 
  dfs(source); 
 } 
}
