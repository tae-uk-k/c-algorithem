// 백준알고리즘 1158번 :: 조세퍼스 문제
#include<iostream>
using namespace std;
int N, M;
struct node
{
	int data;
	struct node *next = 0;
	struct node *prev = 0;
};

struct node *head = 0;
void addToDLL(int v)
{
	for (int i = 1; i <= v; i++) 
	{
		struct node *new_node = (struct node *)malloc(sizeof(struct node));
		new_node->data = i;
		new_node->next = 0;
		new_node->prev = 0;
		if (head == 0) head = new_node;
		else
		{
			struct node *cur = head;
			while (cur->next != 0)
			{
				cur = cur->next;
			}
			cur->next = new_node;
			new_node->prev = cur;
		}
		if (i == v)
		{
			new_node->next = head;
			head->prev = new_node;
		}
	}
	return;
}
void print(int m)
{
	cout << '<';
	struct node *cur = head;
	struct node *prev = cur;

	for (int n = 0; n < N; n++)
	{
		for (int i = 1; i < m; i++)
		{
			cur = cur->next;
		}
		struct node *temp = cur->next;
		if (n == N - 1) {
			cout << cur->data << '>';
			free(cur);
			return;
		}
		else cout << cur->data << ','<< ' ';
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		free(cur);
		cur = temp;
	}
	return;
}
int main(void)
{
	cin >> N >> M;
	addToDLL(N);
	print(M);

	return 0;
}
