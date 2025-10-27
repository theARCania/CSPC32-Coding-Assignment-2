#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>

struct Node {
    struct Node* left;
    struct Node* right;
};
typedef struct Node Node;

Node* createNode();
Node* buildTree(int* level_order, int n);
void freeTree(Node* node);

struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
};
typedef struct QueueNode QueueNode;

struct Queue {
    QueueNode* front;
    QueueNode* rear;
};
typedef struct Queue Queue;

Queue* createQueue();
void enqueue(Queue* q, Node* treeNode);
Node* dequeue(Queue* q);
int isQueueEmpty(Queue* q);
void freeQueue(Queue* q);





#endif
