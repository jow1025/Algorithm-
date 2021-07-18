//c++ Ŭ���� ���� ����

/*#include <iostream>
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
	node1 = findParent(node1); //node1�� ���� ������ ã��
	node2 = findParent(node2); //node2�� ���� ������ ã��
	if (node1 < node2)
		parent[node2] = node1; //node2 ������ node1�� ������
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
*/


//c++���� ����

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct {
	int v1, v2, val;
}graph;
int v, e, res;
vector<graph>tree;
int parent[10001];
bool cmp(const graph& a1, const graph& a2)
{
	return a1.val < a2.val;
}
int find_parent(int a)
{
	if (a == parent[a])return a;
	//���2�� ���1�� �����յǾ��ִٸ� ���2�� 1��ȯ(�θ�)
	return parent[a] = find_parent(parent[parent[a]]);
}
void union_parent(int a, int b)
{
	//�θ� ã�� �� ���� ������ �θ� ��������(������)
	a = find_parent(a);
	b = find_parent(b);
	//a > b ? (parent[a] = b) : (parent[b] = a);
	if (a < b)parent[b] = a;
	else parent[a] = b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	graph g;
	cin >> v >> e;

	for (int i = 1; i <= v; i++)
		parent[i] = i;
	for (int i = 1; i <= e; i++) {
		cin >> g.v1 >> g.v2 >> g.val;
		tree.push_back(g);
	}
	
	//������ ���� ���� 
	sort(tree.begin(), tree.end(), cmp);

	//����!
	//������ ������ŭ ����,������ �Է¹����Ƿ� 
	//���� ������ŭ Ž���� �ƴ� ����������ŭ(==tree.size())���ƾ���
	for (int i = 0; i <tree.size() ; i++) {
		//�θ� ã�Ƽ� �������� ã��. �θ� ������ 
		if (find_parent(tree[i].v1) != find_parent(tree[i].v2))
		{
			res += tree[i].val;
			//��� �� ��ħ
			union_parent(tree[i].v1, tree[i].v2);
		}
	}
	cout << res << endl;
	return 0;
}
