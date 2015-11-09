#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[11]={3,2,-1,6,5,4,-3,3,7,2,3};
	int tree[12]={0};
	tree[0]=0;
	for(int i=0;i<11;i++)
	{
		int first=i+1;
		tree[first]+=arr[i];
		int next;
		while(1)
		{
			next=(first&((~first)+1))+first;
			if(next>=12)
				break;
			tree[next]+=arr[i];
			first=next;
		}
	}
	for(int i=0;i<12;i++)
	{
		cout << tree[i] << " ";
	}
	cout << "\n";
	int prefix_sum;
	cin >> prefix_sum;
	int sum=0;
	prefix_sum+=1;
	while(prefix_sum>0)
	{
		sum+=tree[prefix_sum];
		int parent=(prefix_sum-(prefix_sum & ((~prefix_sum)+1)));
		prefix_sum=parent;
	}
	cout << sum << "\n";

	return 0;
}



	
