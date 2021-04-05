#include<stdio.h>
int count;
int visited[101];
int array[101][101];
void dfs(int v, int num);
int main()
{
	int num;//��ǻ�� ��
	int edge;//����� ��ǻ�� �� ��(������)
	scanf("%d", &num);
	scanf("%d", &edge);
	int num1, num2;
	for (int i = 1; i <= edge; i++) {
		scanf("%d %d", &num1, &num2);
		array[num1][num2] = 1;
		array[num2][num1] = 1;
	}
	dfs(1, num);

	printf("%d\n", count - 1);

}



void dfs(int v, int num)
{
	visited[v] = 1;
	count++;
	for (int w = 1; w <= num; w++)
	{
		if (array[v][w] && !visited[w]) {
			dfs(w, num);
		}

	}
}