#include <iostream>
#include <stack>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 50;

// tree struct
struct node {
  int data;
  node *left;
  node *right;
};

int pre[maxn], in[maxn], post[maxn];

int n; // node number

node *create(int preL, int preR, int inL, int inR) {
  if (preL > preR) {
    return NULL;
  }
  node *root_right_now = new node;
  root_right_now->data = pre[preL];
  int i;
  for (i = inL; i <= inR; i++) {
    if (in[i] == pre[preL]) {
      break;
    }
  }
  int numLeft = i - inL;
  root_right_now->left = create(preL + 1, preL + numLeft, inL, i - 1);
  root_right_now->right = create(preL + numLeft + 1, preR, i + 1, inR);
  return root_right_now;
}

int num_output = 0;
// post travel
void postOrder(node *root) {
  if (root == NULL) {
    return;
  }
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data;
  num_output++;
  if (num_output < n) {
    cout << " ";
  }
}

int main() {
  cin >> n;
  char str[5];
  stack<int> st;
  int x, preIndex = 0, inIndex = 0;
  for (int i = 0; i < 2*n; i++) {
    scanf("%s",&str);
    if (strcmp(str,"Push") == 0) {
        cin >> x;
        pre[preIndex++] = x;
        st.push(x);  
    }else { 
        in[inIndex++] = st.top();
        st.pop();
    }
  }
  node *root = create(0, n - 1, 0, n - 1);
  postOrder(root);
  return 0;
}