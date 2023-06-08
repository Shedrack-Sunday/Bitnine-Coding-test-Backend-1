#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    enum TypeTag {
        ADD,
        SUB,
        MUL,
        DIV
    } type;
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* makeFunc(enum TypeTag type) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    node->value = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int fibonacci(int n) {
    if (n <= 1)
        return n;

    int* fib = (int*)malloc((n + 1) * sizeof(int));
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    int result = fib[n];
    free(fib);
    return result;
}

void calc(Node* node) {
    if (node == NULL)
        return;

    switch (node->type) {
        case ADD:
            node->value = node->left->value + node->right->value;
            printf("add : %d\n", node->value);
            break;
        case SUB:
            node->value = node->left->value - node->right->value;
            printf("sub : %d\n", node->value);
            break;
        case MUL:
            node->value = node->left->value * node->right->value;
            printf("mul : %d\n", node->value);
            break;
        case DIV:
            node->value = node->left->value / node->right->value;
            printf("div : %d\n", node->value);
            break;
        default:
            break;
    }
}

int main() {
    Node* add = (*makeFunc(ADD));
    add->left = makeFunc(10);
    add->right = makeFunc(6);

    Node* mul = (*makeFunc(MUL));
    mul->left = makeFunc(5);
    mul->right = makeFunc(4);

    Node* sub = (*makeFunc(SUB));
    sub->left = mul;
    sub->right = add;

    Node* fibo = (*makeFunc(SUB));
    fibo->left = sub;
    fibo->right = NULL;

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    printf("fibo : %d\n", fibonacci(fibo->value));

    return 0;
}
