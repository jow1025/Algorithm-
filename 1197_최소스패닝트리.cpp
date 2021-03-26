#include <iostream>
#include<cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int parent[100001];
int findParent(int node)
{
	if (node == parent[node])
		return node;
	return parent[node] = findParent(parent[node]);
}
void unionParent(int node1, int node2)
{
	node1 = findParent(node1); //node1이 속한 집합을 찾음
	node2 = findParent(node2); //node2가 속한 집합을 찾음
	if (node1 < node2)
		parent[node2] = node1; //node2 집합이 node1에 합쳐짐
	else
		parent[node1] = node2;
}
class edge
{
public:
	int node[2];
	int dis;
public:
	edge(int a, int b, int dis)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->dis = dis;
	}
	bool operator<(edge& edge)
	{
		return this->dis < edge.dis;
	}
};
int main(void)
{
	int V, E;
	scanf("%d %d", &V, &E);
	vector<edge> Edge;
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		Edge.push_back(edge(u, v, w));
	}
	sort(Edge.begin(), Edge.end());
	for (int i = 0; i < V; i++)
	{
		parent[i] = i;
	}
	long long result = 0;
	for (int i = 0; i < Edge.size(); i++)
	{
		if (findParent(Edge[i].node[0] - 1) != findParent(Edge[i].node[1] - 1))
		{
			result += Edge[i].dis;
			unionParent(Edge[i].node[0] - 1, Edge[i].node[1] - 1);
		}
	}
	printf("%d\n", result);
	return 0;
}