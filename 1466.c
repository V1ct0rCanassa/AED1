#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} Node;

Node* create(int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert(Node* root, int val) {
    if (root == NULL) return create(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void bfs(Node* root) {
    if (root == NULL) return;
    
    Node* queue[1000];
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    
    int first = 1;
    while(front < rear) {
        Node* current = queue[front++];
        
        if (!first) printf(" ");
        printf("%d", current->val);
        first = 0;
        
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
    printf("\n");
}

void free_tree(Node* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    int C, N, val;
    scanf("%d", &C);
    
    for (int i = 1; i <= C; i++) {
        scanf("%d", &N);
        Node* root = NULL;
        for (int j = 0; j < N; j++) {
            scanf("%d", &val);
            root = insert(root, val);
        }
        
        printf("Case %d:\n", i);
        bfs(root);
        printf("\n");
        
        free_tree(root);
    }
    
    return 0;
}
