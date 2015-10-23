#include<bits/stdc++.h>
using namespace std;
struct node
{
	int isleaf;
	char value;
	struct node* children[26];
};
void preorder(struct node* root)
{
	if(root!=NULL)
	{
		cout << root->isleaf << " " << root->value << "\n";
		for(int i=0;i<26;i++)
		{
			preorder(root->children[i]);
		}
	}
}
void insert(struct node** root,string str)
{
	struct node* temp=(*root);
	int i=0;
	while(i<str.length() && temp!=NULL)
	{
		int index=str[i]-'a';
		if(temp->children[index]==NULL)
		{
			temp->children[index]=(struct node*)malloc(sizeof(struct node));
			temp->children[index]->value=str[i];
			if(i==str.length()-1)
			{
				temp->children[index]->isleaf=1;
			}
			else
			{
				temp->children[index]->isleaf=0;
			}
			i++;
			temp=temp->children[index];
		}
		else
		{
			i++;
			temp=temp->children[index];
		}
	}
}

int search(struct node* root,string str)
{
	int i=0;
	while(i<str.length() && root!=NULL)
	{
		int index=str[i]-'a';
		if(root->children[index]==NULL)
		{
			return 0;
		}
		else
		{
			i++;
			root=root->children[index];
		}
	}
	return 1;
}

int main()
{
	vector<string> myvec;
	myvec.push_back("the");
	myvec.push_back("a");
	myvec.push_back("there");
	myvec.push_back("their");
	myvec.push_back("answer");
	myvec.push_back("any");
	myvec.push_back("by");
	myvec.push_back("bye");
	struct node* root=(struct node*)malloc(sizeof(struct node));
	root->value=':';
	for(int i=0;i<26;i++)
	{
		root->children[i]=NULL;
	}
	for(int i=0;i<myvec.size();i++)
	{
		insert(&root,myvec[i]);
	}
	preorder(root);
	vector<string> to_search;
	to_search.push_back("the");
	to_search.push_back("these");
	to_search.push_back("their");
	to_search.push_back("thaw");
	for(int i=0;i<to_search.size();i++)
	{
		if(search(root,to_search[i]) ==0)
		{
			cout << "Not present\n";
		}
		else
		{
			cout << "Present\n";
		}
	}
	return 0;
}
