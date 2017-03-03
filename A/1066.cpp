#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

struct node {
  int value, height;
  node *left, *right;
} * root;

node *newNode(int v) {
  node *Node = new node;
  Node->value = v;
  Node->height = 1;
  Node->left = Node->right = NULL;
  return Node;
}

int getHeight(node *root) {
  if (root == NULL)
    return 0;
  return root->height;
}

void updateHeight(node *root) {
  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

int getBalanceFactor(node *root) {
  return getHeight(root->left) - getHeight(root->right);
}

void L(node *&root) {
  node *temp = root->right;
  root->right = temp->left;
  temp->left = root;
  updateHeight(root);
  updateHeight(temp);
  root = temp;
}

void R(node *&root) {
  node *temp = root->left;
  root->left = temp->right;
  temp->right = root;
  updateHeight(root);
  updateHeight(temp);
  root = temp;
}

void insert(node *&root, int v) {
  if (root == NULL) {
    root = newNode(v);
    return;
  }
  if (v < root->value) {
    insert(root->left, v);
    updateHeight(root);
    if (getBalanceFactor(root) == 2) {
      if (getBalanceFactor(root->left) == 1) { // LL
        R(root);
      } else if (getBalanceFactor(root->left) == -1) { // LR
        L(root->left);
        R(root);
      }
    }
  } else {
    insert(root->right, v);
    updateHeight(root);
    if (getBalanceFactor(root) == -2) {
      if (getBalanceFactor(root->right) == -1) { // RR
        L(root);
      } else if (getBalanceFactor(root->right) == 1) { // RL
        R(root->right);
        L(root);
      }
    }
  }
}

int main() {
  int n, v;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v);
    insert(root, v);
  }
  printf("%d\n", root->value);
  return 0;
}
