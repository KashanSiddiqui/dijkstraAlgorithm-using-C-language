 #include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define IN 99
#define N 9
//int dijkstra(int cost[][N], int source, int target);
int dijsktra(int cost[][N],int source,int target)
{
    int dist[N],prev[N],selected[N]={0},i,m,min,start,d,j;
    char path[N];
    for(i=1;i< N;i++)
    {
        dist[i] = IN;	
        prev[i] = -1;	
    }
    start = source;
    selected[start]=1;
    dist[start] = 0;
    while(selected[target] ==0)
    {
        min = IN;
        m = 0;
        for(i=1;i< N;i++)
        {
            d = dist[start] +cost[start][i];
            if(d< dist[i]&&selected[i]==0)
            {
                dist[i] = d;
                prev[i] = start;
            }
            if(min>dist[i] && selected[i]==0)
            {
                min = dist[i];
                m = i;//hold current node
            }
        }
        start = m;
        selected[start] = 1;
    }
    start = target;
    j = 0;
    while(start != -1)
    {
        path[j++] = start+65;
        start = prev[start];
    }
    path[j]='\0';
    strrev(path);
    int k=0;
    while(path[k]!=NULL){
    printf("%c -->", path[k]);
	k++;
	}
    return dist[target];
}
int main()
{
    int cost[N][N],i,j,w,ch,co,choice;
    int source, target,x,y,Source ,Target,sh;
    int Cost[9][9] = { { 0, 20, 30, 99, 50, 99, 40, 99, 99 },
					 { 20, 0, 30, 99, 70, 99, 99, 50, 99 },
					 { 30, 30,0, 99, 99, 99, 90, 20, 60 },
					 { 99, 99, 99, 0, 60, 99, 10, 99, 99 },
					 { 50, 70, 99, 60, 0, 99, 40, 99, 99 },
					 { 99, 99, 99, 99, 99, 0, 99, 10, 40 },
					 { 40, 99, 90, 10, 40, 99, 0, 99, 99 },
					 { 99, 50, 20, 99, 99, 10, 99, 0, 40 },
					 { 99, 99, 60, 99, 99, 40, 99, 40, 0 }};
    printf("\t The Shortest Path Algorithm ( DIJKSTRA'S ALGORITHM in C) \n\n");
    printf("\t\t\t Data Structure\n\n");
    printf("\t\t\t    Final Lab\n\n");
    printf("How You Want To calculate :\n");
    printf("1) Use BuiltIn Graph\n");
    printf("2)Create Your Own\n");
    scanf("%d",&choice);
    switch(choice){
    	case 1:
    	 
				 printf("\nEnter the source:");
    			scanf("%d", &Source);
    			printf("\nEnter the target");
    			scanf("%d", &Target);
				 sh = dijsktra(Cost,Source,Target);
    			printf(" END");
    			printf("\nThe Shortest Path: %d",sh);
    		
    		break;
    	case 2:
    		for(i=1;i< N;i++)
    for(j=1;j< N;j++)
    cost[i][j] = IN;
    for(x=1;x< N;x++)
    {
        for(y=x+1;y< N;y++)
        {
            printf("Enter weight between nodes %d and %d: ",x,y);
            scanf("%d",&w);
            cost [x][y] = cost[y][x] = w;
        }
        printf("\n");
    }
    printf("\nEnter the source:");
    scanf("%d", &source);
    printf("\nEnter the target");
    scanf("%d", &target);
    co = dijsktra(cost,source,target);
    printf(" END");
    printf("\nThe Shortest Path: %d",co);

    		break;
    	default:
    		printf("Wrong Selection\n");
}	
}
	

