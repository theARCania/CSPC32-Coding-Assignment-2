#include "tree.h"





Node* createNode() {
 
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for tree node");
        exit(0);
    }

    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void freeTree(Node* node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);

}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        perror("Failed to allocate memory for queue");
        exit(0);
    }

    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Node* treeNode) {
  
    QueueNode* qNode = (QueueNode*)malloc(sizeof(QueueNode));
    
    if (qNode == NULL) {
        perror("Failed to allocate memory for queue node");
        exit(0);
    }
    qNode->treeNode = treeNode;
    
    qNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = qNode;
        q->rear = qNode;
        return;
    
    }
    
    q->rear->next = qNode;
    q->rear = qNode;
}


Node* dequeue(Queue* q) {
    if (q->front == NULL) {
  
      return NULL;
    }
    
    QueueNode* temp = q->front;
    Node* treeNode = temp->treeNode;
    
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    
    }
    
    free(temp);
    return treeNode;
}


int isQueueEmpty(Queue* q) {
    return q->front == NULL;

}

void freeQueue(Queue* q) {

    while (!isQueueEmpty(q)) {
        dequeue(q);
    }
  

  free(q);
}

Node* buildTree(int* level_order, int n) {
    if (n == 0 || level_order[0] == 0) {
        return NULL;
    }


    
    Node* root = createNode();
    
    Queue* q = createQueue();
    enqueue(q, root);

    int i = 1;
    while (i < n) {
        Node* current = dequeue(q);

        if (level_order[i] == 1) {
            current->left = createNode();
            enqueue(q, current->left);
        } else {
            current->left = NULL;
    
      }
        i++;

        if (i < n) {
            if (level_order[i] == 1) {
                current->right = createNode();
                enqueue(q, current->right);
            } else {
                current->right = NULL;
            }
            i++;
        } else {
            current->right = NULL;
        }
    }


    freeQueue(q);
    return root;
}



















