#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

//tree struct
struct node{
    int val;
    int height;
    node* left;
    node* right;
};

inline int getTreeHeight(node* root)
{
    if (root)
        return root->height;
    else
        return -1;
}

inline int max(int h1, int h2)
{
    return h1 > h2 ? h1 : h2;
}

node* LL(node* root)
{
    node* a;
    node* b;
    node* c;

    a = root;
    b = root->left;
    c = b->left;

//    rotate
    a->left = b->right;
    b->right = a;

//    change hegith
    if(a) { a->height = max(getTreeHeight(a->left),getTreeHeight(a->right)) + 1; }
    if(c) { c->height = max(getTreeHeight(c->left),getTreeHeight(c->right)) + 1; }

    return b;
}

node* RR(node* root)
{
    node* a;
    node* b;
    node* c;

    a = root;
    b = root->right;
    c = b->right;

    a->right = b->left;
    b->left = a;

    //    change hegith
    if(a) { a->height = max(getTreeHeight(a->left),getTreeHeight(a->right)) + 1; }
    if(c) { c->height = max(getTreeHeight(c->left),getTreeHeight(c->right)) + 1; }

    return b;
}

node* LR(node* root)
{
    root->left = RR(root->left);
    return LL(root);
}

node* RL(node* root)
{
    root->right = LL(root->right);
    return RR(root);
}

node* insert(node* root, int value)
{
    if(!root)
    {
        root = new node;
        root->val = value;
        root->height = 0;
        root->left = root->right = nullptr;
    }
    else
    {
        if(root->val > value) { root->left = insert(root->left,value); }
        else { root-> right = insert(root->right,value); }

        int h1 = getTreeHeight(root->left);
        int h2 = getTreeHeight(root->right);

        if (h1 > h2 + 1)
        {
            int h3 = getTreeHeight(root->left->left);
            int h4 = getTreeHeight(root->left->right);
            if(h3 > h4) { root = LL(root); }
            else { root = LR(root); }
        }
        else if (h1 + 1 < h2)
        {
            int h3 = getTreeHeight(root->right->left);
            int h4 = getTreeHeight(root->right->right);
            if(h3 > h4) { root = RL(root); }
            else { root = RR(root); }
        }
    }
}

bool levelorder(node* &root)
{
    std::queue<node*> que;
    node* tmp;
    bool leave = false;
    bool complete = true;

    que.push(root);
    printf("%d",root->val);

    while(!que.empty())
    {
        tmp = que.front();
        que.pop();
        if (tmp->left)
        {
            que.push(tmp->left);
            printf("%d",tmp->left->val);
        }
        if (tmp->right)
        {
            que.push(tmp->right);
            printf("%d",tmp->right->val);
        }
        if (!tmp->left && tmp->right)
        {
            complete = false;
        }
        if (leave && (tmp->left || tmp->right))
        {
            complete = false;
        }
        if (!tmp->left || !tmp->right)
        {
            leave = true;
        }
    }
    printf("\n");
    return complete;
}

int main() {

    int n,tmp;
    node* root = nullptr;
    scanf("%d",&n);

    for (int i = 0; i < n; ++i) {
        scanf("%d",&tmp);
        root = insert(root,tmp);
    }

    bool complete = levelorder(root);

    if (complete) { printf("YES"); }
    else { printf("NO"); }

    return 0;
}
