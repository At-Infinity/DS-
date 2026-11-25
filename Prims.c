
#include<stdio.h>
#define INF 999
int a,b,u,v,n,i,j,ne=1,visited[10]={0},min,mincost=0,cost[10][10];
void main(){
printf("Enter the number of nodes: ");
scanf("%d",&n);
85
printf("Enter the adjacency matrix:\n");
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
scanf("%d",&cost[i][j]);
if(cost[i][j]==0)cost[i][j]=INF;
}
}
visited[1]=1;
printf("\nEdges in the Minimum Spanning Tree:\n");
while(ne<n){
min=INF;
for(i=1;i<=n;i++){
if(visited[i]){
for(j=1;j<=n;j++){
if(cost[i][j]<min&&!visited[j]){
min=cost[i][j];
a=u=i;
b=v=j;
}
}
}
}
if(!visited[u]||!visited[v]){
printf("Edge %d: (%d, %d) Cost: %d\n",ne++,a,b,min);
86
mincost+=min;
visited[b]=1;
}
cost[a][b]=cost[b][a]=INF;
}
printf("\nMinimum Cost = %d\n",mincost);
}
