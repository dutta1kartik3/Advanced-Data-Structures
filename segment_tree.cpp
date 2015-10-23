#include<bits/stdc++.h>
using namespace std;
int size=0;
int construct_tree(int segment_tree[100000],int current_index,int start,int end,int arr[100000])
{
	if(start==end)
	{
		if(size<current_index)
			size=current_index;
		segment_tree[current_index]=arr[start];
		return arr[start];
	}
	int mid=(start+end)/2;
	segment_tree[current_index]=construct_tree(segment_tree,2*current_index+1,start,mid,arr)+construct_tree(segment_tree,2*current_index+2,mid+1,end,arr);
	return segment_tree[current_index];
}
int getsum(int segment_tree[100000],int start,int end,int left,int right,int current_index)
{
	if(start>=left && end<=right)
	{
		return segment_tree[current_index];
	}
	if(end<left || right<start)
	{
		return 0;
	}
	int mid=(start+end)/2;
	return getsum(segment_tree,start,mid,left,right,2*current_index+1)+getsum(segment_tree,mid+1,end,left,right,2*current_index+2);
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
	construct_tree(segment_tree,0,0,n-1,arr);
	for(int i=0;i<=size;i++)
	{
		cout << segment_tree[i] << " ";
	}
	cout << "\n";
	int left,right;
	cin >> left >> right;
	if(left<0 || right>n-1 || left>right)
	{
		cout << "invalid input";
		return 0;
	}
	int ans=getsum(segment_tree,0,n-1,left,right,0);
	cout << ans;
	return 0;
}

