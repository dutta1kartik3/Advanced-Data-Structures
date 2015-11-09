#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	struct node* next;
};
int current_size=0;
void print(struct node* root)
{
	while(root!=NULL)
	{
		cout << root->val << " ";
		root=root->next;
	}
}
int main()
{
	struct node* root=NULL;
	int size_of_cache;
	cin >> size_of_cache;
	map<int,struct node*> mymap;
	int n;
	cin >> n;
	while(n--)
	{
		int a;
		cin >> a;
		if(mymap.find(a)==mymap.end() && current_size<size_of_cache )
		{
			struct node* temp=(struct node*)malloc(sizeof(struct node));
			temp->val=a;
			temp->next=root;
			root=temp;
			mymap[a]=root;
			current_size++;
		}
		else if(mymap.find(a)==mymap.end() && current_size>=size_of_cache)
		{
			struct node* temp=(struct node*)malloc(sizeof(struct node));
			temp->val=a;
			temp->next=root;
			root=temp;
			mymap[a]=root;
			struct node* t=root;
			while(t->next->next!=NULL)
			{
				t=t->next;
			}
			int del=t->next->val;
			t->next=NULL;
			mymap.erase(del);
		}
		else if(mymap.find(a)!=mymap.end())
		{
			struct node* t=root;
			struct node* prev=root;
			while(t->next!=NULL)
			{
				if(t->next->val==a)
				{
					break;
				}
				else
				{
					t=t->next;
				}
			}
			struct node* temp=(struct node*)malloc(sizeof(struct node));
			temp->val=t->next->val;
			temp->next=root;
			root=temp;
			t->next=t->next->next;
			mymap[temp->val]=root;
		}
	}
	print(root);
	return 0;
}




