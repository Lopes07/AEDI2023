#include <stdio.h>
#include <stdlib.h>
/*Lucas Lopes Silva - Turma M2*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


/*Função para adicionar o valor da folha em um array*/
void addLeaf(struct TreeNode* root, int* array, int* count) {
    if(root->left == NULL && root->right == NULL){
        array[(*count) ++] = root->val;
        return;
    }

    if(root->left){
        addLeaf(root->left, array, count);
    }
    if(root->right) {
        addLeaf(root->right, array, count);
    }

    return;
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2){
    int root1Array[200]= {}, root2Array[200] = {}, count1 = 0, count2 = 0;
    
    addLeaf(root1, root1Array, &count1);
    addLeaf(root2, root2Array, &count2);

    if(memcmp(root1Array, root2Array, 200) == 0){
        return true;
    }

    return false;
}