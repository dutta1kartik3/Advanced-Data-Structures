#include<bits/stdc++.h>
using namespace std;
struct node
{
	int low;
	int high;
	int max;
	struct node* left;
	struct node* right;
};
void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout << root->low << " " << root->high << " " << root->max << "\n";
		inorder(root->right);
	}
}
void insert(struct node** root,int a,int b)
{
	if((*root)==NULL)
	{
		(*root)=(struct node*)malloc(sizeof(struct node));
		(*root)->max=b;
		(*root)->low=a;
		(*root)->high=b;
	}
	else
	{
		if(a>(*root)->low)
		{
			if((*root)->max<b)
			{
				(*root)->max=b;
			}
			insert(&((*root)->right),a,b);
		}
		else
		{
			if((*root)->max<b)
			{
				(*root)->max=b;
			}
			insert(&((*root)->left),a,b);
		}
	}
}

void search(struct node* root,int range_min,int range_max)
{
	if(max(root->low,range_min)<min(root->high,range_max))
	{
		cout << root->low << " " << root->high << "\n";
		return;
	}
	if(root->left!=NULL && range_min<root->left->max)
	{
		search(root->left,range_min,range_max);
	}
	else
	{
		search(root->right,range_min,range_max);
	}
}

int main()
{
	int n;
	cin >> n;
	struct node* root=NULL;
	while(n--)
	{
		int a,b;
		cin >> a >> b;
		insert(&root,a,b);
	}
	inorder(root);
	cout << "\n";
	int range_min,range_max;
	cin >> range_min >> range_max;
	search(root,range_min,range_max);
	return 0;
}
