#include<bits/stdc++.h>
using namespace std;
int construct_tree(int arr[100000],int first,int last,int i,int segment_tree[100000])
{
	if(first==last)
	{
		segment_tree[i]=arr[first];
		return segment_tree[i];
	}
	else
	{
		int mid=(first+last)/2;
		segment_tree[i]=min(construct_tree(arr,first,mid,2*i+1,segment_tree),construct_tree(arr,mid+1,last,2*i+2,segment_tree));
		return segment_tree[i];
	}
}
int range_min(int rmq_min,int rmq_max,int first,int last,int i,int segment_tree[100000])
{
	if(first>=rmq_min && last<=rmq_max)
	{
		return segment_tree[i];
	}
	if(last<rmq_min || rmq_max<first)
	{
		return INT_MAX;
	}
	int mid=(first+last)/2;
	return min(range_min(rmq_min,rmq_max,first,mid,2*i+1,segment_tree),range_min(rmq_min,rmq_max,mid+1,last,2*i+2,segment_tree));
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
	construct_tree(arr,0,n-1,0,segment_tree);
	for(int i=0;i<=2*n+2;i++)
	{
		cout << segment_tree[i] << " ";
	}
	int rmq_min,rmq_max;
	cin >> rmq_min >> rmq_max;
	cout << range_min(rmq_min,rmq_max,0,n-1,0,segment_tree);
	return 0;
}

