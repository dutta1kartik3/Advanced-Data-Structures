#include<bits/stdc++.h>
using namespace std;
int construct_tree(int segment_tree[100000],int i,int arr[100000],int first,int last)
{
	if(first==last)
	{
		segment_tree[i]=arr[first];
		return segment_tree[i];
	}
	else
	{
		int mid=(first+last)/2;
		segment_tree[i]=construct_tree(segment_tree,2*i+1,arr,first,mid)+construct_tree(segment_tree,2*i+2,arr,mid+1,last);
		return segment_tree[i];

	}
}
int get_sum(int segment_tree[100000],int min_range,int max_range,int i,int first,int last)
{
	if(first>=min_range && last<=max_range)
	{
		return segment_tree[i];
	}
	if(min_range>last || max_range<first)
	{
		return 0;
	}
	int mid=(first+last)/2;
	return get_sum(segment_tree,min_range,max_range,2*i+1,first,mid)+get_sum(segment_tree,min_range,max_range,2*i+2,mid+1,last);
}
void update(int segment_tree[100000],int index,int first,int last,int diff,int i)
{
	if(index<first || index>last)
		return;
	else
	{
		segment_tree[i]=segment_tree[i]+diff;
		if(first!=last)
		{
		int mid=(first+last)/2;
		update(segment_tree,index,first,mid,diff,2*i+1);
		update(segment_tree,index,mid+1,last,diff,2*i+2);
		}
	}
}
int main()
{
	int n;
	cin >> n;
	int arr[100000];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int segment_tree[100000]={0};
	construct_tree(segment_tree,0,arr,0,n-1);
	for(int i=0;i<=2*n+2;i++)
	{
		cout << segment_tree[i] << " ";
	}
	cout << "\n";
	int min_range,max_range;
	cin >> min_range >> max_range;
	int sum=get_sum(segment_tree,min_range,max_range,0,0,n-1);
	cout << sum << "\n";
	int index,val;
	cin >> index >> val;
	int diff=val-arr[index];
	arr[index]=val;
	update(segment_tree,index,0,n-1,diff,0);
	sum=get_sum(segment_tree,min_range,max_range,0,0,n-1);
	cout << sum << "\n";
	return 0;
}
