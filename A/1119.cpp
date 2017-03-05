#include <iostream>


using namespace std;

const int maxn = 31;

struct node {
    int v;
    node* left;
    node* right;
};

int pre[maxn], in[maxn], post[maxn];

int n;

bool flag = true;

node* create(int preL, int preR, int postL, int postR) {
    if (preL > preR) {
        return NULL;
    }
    node* root = new node;
    root->v = pre[preL];
    if (preL == preR) {
        return root;
    }
    int k = 0;
    //寻找根节点
    for (k = preL + 1; k <= preR; k++) {
        if(pre[k] == post[postR-1])
            break;
    }
    int numLeft = k - preL - 1;
    if (numLeft > 0) {
        root->left =  create(preL+1, k - 1, postL, postL - 1 + numLeft);
        root->right = create(k, preR, postL + numLeft ,postR-1);
    }else {
        flag  = false;
        root->right = create(k, preR, postL + numLeft ,postR-1);
    }
    return root;
}

int precnt = 0;
void inOrder(node* root) {
    if(root == NULL) {
        return;
    }
    
    inOrder(root->left);
    in[precnt++] = root->v;
    inOrder(root->right);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }

    node* root;
    root = create(0,n-1,0,n-1);
    if (flag) cout << "Yes\n";  
    else cout << "No\n";

    inOrder(root);  


    for(int i = 0; i < n; i++) {
        cout << in[i];
        if(i < n-1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;   
}