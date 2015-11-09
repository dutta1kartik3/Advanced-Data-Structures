#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct WordDictionary {
    int isleaf;
	char value;
	struct WordDictionary* children[26];
    
};

/** Initialize your data structure here. */
struct WordDictionary* wordDictionaryCreate() {
    struct WordDictionary* root=(struct WordDictionary*)malloc(sizeof(struct WordDictionary));
int i;	
    for(i=0;i<26;i++)
	{
		root->children[i]=NULL;
	}
	return root;
}

/** Inserts a word into the trie. */
void addWord(struct WordDictionary* temp, char* str) {
	int i=0;
	while(i<strlen(str) && temp!=NULL)
	{
		int index=str[i]-'a';
		if(temp->children[index]==NULL)
		{
			temp->children[index]=(struct WordDictionary*)malloc(sizeof(struct WordDictionary));
			temp->children[index]->value=str[i];
			int j;
			for(j=0;j<26;j++)
			{
			    temp->children[index]->children[j]=NULL;
			}
			if(i==strlen(str)-1)
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
			if(i==strlen(str))
			{
				temp->children[index]->isleaf=1;
			}
			temp=temp->children[index];
		}
	}

}

/** Returns if the word is in the trie. */
int search(struct WordDictionary* root, char* str) {
	int i=0;
	while(i<strlen(str) && root!=NULL)
	{
		if(str[i]=='.')
		{
			int flag=0;
			int j;
			for(j=0;j<26;j++)
			{
				if(root->children[j]!=NULL)
				{
					//printf("kk%dkk",j);
					if(i+1==strlen(str))
						return 1;
					char copy[strlen(str)];
					int m=0;
					int k;
					for(k=i+1;k<strlen(str);k++)
					{
						copy[m++]=str[k];
					}
					copy[m]='\0';
					printf("%s",copy);
					int ans=search(root->children[j],copy);
					//printf("%d",ans);
					if(ans==1)
					{
					//	printf("gg");
						flag=1;
						return 1;

					}

				}

			}

				return 0;
			i++;

		}

		else

		{

			int index=str[i]-'a';
			if(root->children[index]==NULL)
			{
				return 0;
			}
			else
			{

				i++;
				if(i==strlen(str) && root->children[index]->isleaf==0)
				{
					return 0;
				}
				root=root->children[index];

			}

		}

	}

	if(i<strlen(str))
		return 0;

	return 1;
    
}
//Returns if there is any word in the trie 
//    that starts with the given prefix. 

// Deallocates memory previously allocated for the TrieNode. 
void wordDictionaryFree(struct WordDictionary* root) {
    if(root!=NULL)
    {
	    int i;
        for(i=0;i<26;i++)
        {
            wordDictionaryFree(root->children[i]);
        }
        free(root);
    }
    
}
int main()
{
// Your Trie object will be instantiated and called as such:
 struct WordDictionary* node = wordDictionaryCreate();
 char arr[4];
 arr[0]='b';
 arr[1]='a';
 arr[2]='d';
 arr[3]='\0';

 char arr1[4];
 arr1[0]='d';
 arr1[1]='a';
 arr1[2]='d';
 arr1[3]='\0';

 char arr2[4];
 arr2[0]='m';
 arr2[1]='a';
 arr2[2]='d';
 arr2[3]='\0';
 
 char arr3[4];
 arr3[0]='b';
 arr3[1]='.';
 arr3[2]='.';
 arr3[3]='\0';
 addWord(node, arr);
 addWord(node,arr1);
 addWord(node,arr2);
 printf("%d",search(node,arr3));
// search(node, "key");
// trieFree(node);
}
