#include<stdio.h>
#include<stdlib.h>
int in_degree[32000];
typedef struct graphNode
{
	int student;
	struct graphNode* link;
}graphNode;
typedef struct stackNode
{
	int data;
	struct stackNode* link;
}stackNode;
stackNode* top;
graphNode** head;
void insert_edge(int student_A, int student_B);
void topological_sort();
void push(int data);
int is_empty();
int pop();
int n, m;
int main()
{
	int a, b;
	scanf("%d%d", &n, &m);
	head = (graphNode**)malloc(sizeof(graphNode*) * n);
	for (int i = 0; i < n; i++)
	{
		head[i] = (graphNode*)malloc(sizeof(graphNode));
		head[i]->link = NULL;

	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		insert_edge(a - 1, b - 1);
	}
	topological_sort();
}
void insert_edge(int student_A, int student_B)
{
	graphNode* newNode = (graphNode*)malloc(sizeof(graphNode));
	newNode->student = student_B;
	newNode->link = head[student_A]->link;
	head[student_A]->link = newNode;
}
void topological_sort()
{
	graphNode* node;
	for (int i = 0; i < n; i++) {
		node = head[i]->link;
		while (node != NULL)
		{
			in_degree[node->student]++;
			node = node->link;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (in_degree[i] == 0)
			push(i);
	}
	while (!is_empty())
	{
		int w;
		w = pop();
		printf("%d ", w + 1);
		node = head[w]->link;
		while (node != NULL)
		{
			int u = node->student;
			in_degree[u]--;
			if (in_degree[u] == 0)push(u);
			node = node->link;
		}
	}

}
int is_empty()
{
	return top == NULL;
}
void push(int data)
{
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->data = data;
	newNode->link = top;
	top = newNode;
}
int pop()
{
	int item;
	stackNode* temp;
	if (is_empty())
		exit(1);

	temp = top;
	item = temp->data;
	top = top->link;
	free(temp);
	return item;
}