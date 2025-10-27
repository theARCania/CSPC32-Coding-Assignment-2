#include "phones.h"

int gPhoneCount = 0; // init global



// post-order dfs
int dfsPhones(Node* node) {
    if (node == NULL) {

      return 2; // null is covered
    }


    // get child states
    int leftState = dfsPhones(node->left);
    int rightState = dfsPhones(node->right);

    if (leftState == 0 || rightState == 0) {
        gPhoneCount++;
        return 1;
    }

    if (leftState == 1 || rightState == 1) {
        return 2; //
    }

    // both childs covered (2)
    return 0; 
}





