#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

/** Inserts a word into the data structure. */
void addWord(struct WordDictionary* temp, char* str) {
    int i=0;
	while(i<strlen(str) && temp!=NULL)
	{
		int index=str[i]-'a';
		if(temp->children[index]==NULL)
		{
			temp->children[index]=(struct WordDictionary*)malloc(sizeof(struct WordDictionary));
			temp->children[index]->value=str[i];
			int i;
			for(i=0;i<26;i++)
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

/** Returns if the word is in the data structure. A word could
    contain the dot character '.' to represent any one letter. */
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
	                if(i+1==strlen(str))
	                return 1;
	                char* copy;
	                int m=0;
			int k;
	                for(k=i+1;k<strlen(str);k++)
	                {
	                    copy[m++]=str[k];
	                }
	                copy[m]='\0';
	                int ans=search(root->children[j],copy);
	                if(ans==1)
	                {
	                    flag=1;
	                   return 1;
	                }
	            }
	        }
	        if(flag==0)
	        {
	            return 0;
	        }
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

/** Deallocates memory previously allocated for the data structure. */
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
// Your WordDictionary object will be instantiated and called as such:
 struct WordDictionary* wordDictionary = wordDictionaryCreate();
 char arr[2];
 arr[0]='a';
 arr[1]='\0';
 addWord(wordDictionary, arr);
// addWord(wordDictionary,"a");
//printf("%d", search(wordDictionary, "."));
// wordDictionaryFree(wordDictionary);
}
