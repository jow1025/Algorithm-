#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

int graph[1001][1001];
int DFS_visited[1001];
int BFS_visited[1001];

int front = 0;
int rear = 0;
int queue[1001];
void dfs(int v, int n);//시작점,탐색점 개수
void bfs(int v, int n);
int main()
{
	int n, m, v;
	int v1, v2;
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &v1, &v2);
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}
	dfs(v, n);
	printf("\n");
	bfs(v, n);
}
void dfs(int v, int n)//시작점,탐색할 정점개수
{
	DFS_visited[v] = 1;
	printf("%d ", v);
	int w;
	for (w = 1; w <= n; w++)
	{
		if (!DFS_visited[w] && graph[v][w] == 1)
		{
			dfs(w, n);
		}
	}
}
void bfs(int v, int n)
{
	printf("%d ", v);
	int pop;
	queue[0] = v;
	rear++;
	BFS_visited[v] = 1;
	//front=-1,rear=0;
	while (front != rear)
	{
		pop = queue[front];
		front++;
		for (int i = 1; i <= n; i++)
		{
			if (graph[pop][i] == 1 && BFS_visited[i] == 0)
			{
				printf("%d ", i);
				queue[rear] = i;
				rear++;
				BFS_visited[i] = 1;
			}
		}
	}

}