#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_CHAR 256    //try with 26 -'a' version for lower case only

//Trie
struct node
{
    bool terminal;
    struct node* nodeWords[NUM_CHAR];
};

struct node* createNode()
{
    struct node *newNode = malloc(sizeof *newNode);
    for (int i = 0; i < NUM_CHAR; ++i) newNode->nodeWords[i] = NULL;
    newNode->terminal = false;
    return newNode;
};

bool insert(struct node **root, char *textWords){
    if(*root==NULL) *root = createNode();
    unsigned char *text = (unsigned char *) textWords;
    struct node *tmp = *root;
    int length = strlen(textWords);
    for(int ch=0; ch<length; ++ch){
        if (tmp->nodeWords[text[ch]] == NULL) tmp->nodeWords[text[ch]] = createNode();
        tmp = tmp->nodeWords[text[ch]];
    }
    if(tmp->terminal) return false;
    else {tmp->terminal = true; return true;}
}

void print_rec(struct node *node, unsigned char *prefix, int length) {
    unsigned char new_prefix[length + 2];
    memcpy(new_prefix, prefix, length);
    new_prefix[length + 1] = 0; //null
    if (node->terminal) { printf("Word: %s\n", prefix); }
    for (int i = 0; i < NUM_CHAR; i++) {
        if (node->nodeWords[i] != NULL) {
            new_prefix[length] = i;
            print_rec(node->nodeWords[i], new_prefix, length + 1);
        }
    }
}
void print(struct node* root){
    if(root == NULL) { printf("trie is empty"); return; }
    print_rec(root, NULL, 0);
}



