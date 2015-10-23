struct TrieNode {
    int isleaf;
	char value;
	struct TrieNode* children[26];
    
};

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
    struct TrieNode* root=(struct TrieNode*)malloc(sizeof(struct TrieNode));
	for(int i=0;i<26;i++)
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
			for(int i=0;i<26;i++)
			{
			    temp->children[index]->children[i]=NULL;
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
bool search(struct TrieNode* root, char* str) {
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
bool startsWith(struct TrieNode* root, char* prefix) {
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
	return 0;
	return 1;
    
    
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
    if(root!=NULL)
    {
        for(int i=0;i<26;i++)
        {
            trieFree(root->children[i]);
        }
        free(root);
    }
    
}

// Your Trie object will be instantiated and called as such:
// struct TrieNode* node = trieCreate();
// insert(node, "somestring");
// search(node, "key");
// trieFree(node);