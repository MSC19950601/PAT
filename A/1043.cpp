#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// tree struct
struct node {
  int data;
  node *left;
  node *right;
};

void insert(node* &root, int data) {
  if (root == NULL) {
    root = new node;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return;
  }
  if (data < root->data) {
    insert(root->left, data);
  } else {
    insert(root->right, data);
  }
}

void ReleaseTree(node* tree)  
{  
    std::queue<node*> q;  
    q.push(tree);  
    while(!q.empty())  
    {  
        node* p = q.front();  
        q.pop();  
        if(p)  
        {  
            q.push(p->left);  
            q.push(p->right);  
            delete p;  
        }  
    }  
} 

void preOrder(node* root, vector<int> &vi) {
  if (root == NULL) {
    return;
  }
  vi.push_back(root->data);
  preOrder(root->left, vi);
  preOrder(root->right, vi);
}

void postOrder(node* root, vector<int> &vi) {
  if (root == NULL) {
    return;
  }
  postOrder(root->left, vi);
  postOrder(root->right, vi);
  vi.push_back(root->data);
}

void preOrderM(node* root, vector<int> &vi) {
  if (root == NULL) {
    return;
  }
  vi.push_back(root->data);
  preOrderM(root->right, vi);
  preOrderM(root->left, vi);
}

void postOrderM(node* root, vector<int> &vi) {
  if (root == NULL) {
    return;
  }
  postOrderM(root->right, vi);
  postOrderM(root->left, vi);
  vi.push_back(root->data);
}

vector<int> origin;
vector<int> pre;
vector<int> post;
vector<int> preM;
vector<int> postM;

int main() {
  int n, data;
  node *root = NULL;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> data;
    origin.push_back(data);
    insert(root, data);
  }

  preOrder(root, pre);
  preOrderM(root, preM);
  postOrder(root, post);
  postOrderM(root, postM);

  if (pre == origin) {
    cout << "YES\n";
    for (int i = 0; i < post.size(); i++) {
      cout << post.at(i);
      if (i < post.size() - 1)
        cout << " ";
    }
  } else if (preM == origin) {
    cout << "YES\n";
    for (int i = 0; i < post.size(); i++) {
      cout << postM.at(i);
      if (i < postM.size() - 1)
        cout << " ";
    }
  } else {
    cout << "NO\n";
  }

  ReleaseTree(root); 
  return 0;
}