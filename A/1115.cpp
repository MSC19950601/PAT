#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int cnt[1005];
int maxdepth = -1;

//tree struct
struct node{
    int val;
    node* left;
    node* right;
    node(int v):val(v),left(nullptr),right(nullptr){}
};

//tree build
void build(node* &root, int val)
{
    if (root == nullptr)
    {
        root = new node(val);
        return;
    }
    if (val <= root->val)
        build(root->left,val);
    else
        build(root->right,val);
}

//calculate depth
void find(node* &root, int dep)
{
    if (root == nullptr)
    {
        maxdepth = std::max(dep,maxdepth);
        return;
    }
    cnt[dep]++;
    find(root->left,dep + 1);
    find(root->right,dep + 1);
}

int main() {

    int n;
    std::cin >> n;
    node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int v;
        std::cin >> v;
        build(root,v);
    }

    find(root,0);

    std::cout << cnt[maxdepth - 1] << " + " << cnt[maxdepth - 2] << " = " << cnt[maxdepth - 1] + cnt[maxdepth - 2];

    return 0;
}
