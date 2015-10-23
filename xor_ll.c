#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* npx;
};
struct node* Xor(struct node* a,struct node* b)
{
	return (struct node*)((unsigned int)(a)^(unsigned int)(b));
}
void insert(struct node** head,int val)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->npx=Xor(NULL,(*head));
	if((*head)!=NULL)
	{
		struct node* next=Xor((*head)->npx,NULL);
		(*head)->npx=Xor(temp,next);
	}
	(*head)=temp;
}
void print(struct node* head)
{
	struct node* prev=NULL;
	while(head!=NULL)
	{
		cout << head->data << " ";
		struct node* nextptr=Xor(prev,head->npx);
		prev=head;
		head=nextptr;
	}
}
int main()
{
	struct node* head=NULL;
	int n;
	cin >> n;
	while(n--)
	{
		int a;
		cin >> a;
		insert(&head,a);
	}
	print(head);
	return 0;
}

