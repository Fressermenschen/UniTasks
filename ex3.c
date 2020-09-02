#include <stdio.h>
#include <stdlib.h>

typedef struct NodeClass {
    int value;
    int idx;
    struct NodeClass *nextNode;
} NodeClass;

void insert_node(int idx, struct NodeClass *listHeaderNode, int data)
{
    struct NodeClass* currentNode = NULL;
    struct NodeClass* theNode = NULL;
    currentNode = (struct NodeClass*)malloc(sizeof(struct NodeClass));
    theNode = (struct NodeClass*)malloc(sizeof(struct NodeClass));
    
    currentNode = listHeaderNode;
    theNode->value = data;
    
    while (currentNode->nextNode != NULL){
        currentNode = currentNode->nextNode;
        
        if (currentNode->idx == idx - 1){
            theNode->nextNode = currentNode->nextNode;
            currentNode->nextNode = theNode;
            theNode->idx = theNode->idx;
        }
        if (currentNode->idx > idx){
            currentNode->idx = currentNode->idx + 1;
        }
    }
    
    if (idx == currentNode->idx){
        currentNode->nextNode = theNode;
        theNode->idx = idx;
    }
}

void delete_node(int idx, struct NodeClass *listHeaderNode)
{
    struct NodeClass* currentNode = NULL;
    struct NodeClass* postNode = NULL;
    currentNode = (struct NodeClass*)malloc(sizeof(struct NodeClass));
    postNode = (struct NodeClass*)malloc(sizeof(struct NodeClass));
    currentNode = listHeaderNode;
    postNode = currentNode->nextNode;
    
    while (postNode->nextNode != NULL){
        currentNode = currentNode->nextNode;
        postNode = currentNode->nextNode;
        
        if (currentNode->idx == idx - 1){
            currentNode->nextNode = postNode->nextNode;
        }
        if (currentNode->idx >= idx){
            currentNode->idx = currentNode->idx - 1;
        }
    }
}

void print_list(struct NodeClass *listHeaderNode)
{
    while (listHeaderNode->nextNode != NULL){
        printf("%d ", listHeaderNode->value);
    }
}

int main()
{
    struct NodeClass* head = (struct NodeClass*)malloc(sizeof(struct NodeClass));
    head->value = 1;
    head->idx = 0;
    
    insert_node(1, head, 2);
    
    print_list(head);
    
    insert_node(1, head, 3);
    
    print_list(head);
    
    delete_node(1, head);
    
    print_list(head);
}
