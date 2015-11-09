#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct TrieNode {
    int isleaf;
	char value;
	struct TrieNode* children[26];
    
};

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
    struct TrieNode* root=(struct TrieNode*)malloc(sizeof(struct TrieNode));
	root->value=':';
	int i;
	for(i=0;i<26;i++)
	{
		root->children[i]=NULL;
	}
	return root;
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* temp, char* str) {
	int i=0;
	while(i<strlen(str) && temp!=NULL)
	{
		int index=str[i]-'a';
		if(temp->children[index]==NULL)
		{
			temp->children[index]=(struct TrieNode*)malloc(sizeof(struct TrieNode));
			temp->children[index]->value=str[i];
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
			temp=temp->children[index];
		}
	}
    
}

/** Returns if the word is in the trie. */
int search(struct TrieNode* root, char* str) {
    int i=0;
	while(i<strlen(str) && root!=NULL)
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
	if(i<strlen(str))
	return 0;
	return 1;
    
}

/** Returns if there is any word in the trie 
    that starts with the given prefix. */
int startsWith(struct TrieNode* root, char* prefix) {
    int i=0;
	while(i<strlen(prefix) && root!=NULL)
	{
		int index=prefix[i]-'a';
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
	if(i<strlen(prefix))
	{
//		printf("gg");
		return 0;
	}
	return 1;
    
    
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
    if(root!=NULL)
    {
	    int i;
        for(i=0;i<26;i++)
        {
            trieFree(root->children[i]);
        }
        free(root);
    }
    
}

int main()
{

// Your Trie object will be instantiated and called as such:
 struct TrieNode* node = trieCreate();
 insert(node, "ab");
printf("%d",search(node, "a"));
printf("%d",startsWith(node,"a"));
// trieFree(node);
return 0;
}
