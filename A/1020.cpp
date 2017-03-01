#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 50;

// tree struct
struct node {
    int data;
    node* left;
    node* right;
};

int pre[maxn], in[maxn], post[maxn];

int n;// node number

node* create(int postL, int postR, int inL, int inR)
{
    if (postL > postR)
    {
        return NULL;
    }
    node* root_right_now = new node;
    root_right_now->data = post[postR];
    int i;
    for (i = inL; i <= inR; i++)
    {
        if (in[i] == post[postR])
        {
            break;
        }
    }
    int numLeft = i - inL;
    root_right_now->left = create(postL, postL + numLeft - 1, inL, i - 1);
    root_right_now->right = create(postL + numLeft, postR - 1, i + 1, inR);
    return root_right_now;
}

int num_output = 0;
// level travel
void BFS(node* root)
{
    std::queue<node*> que;
    
    que.push(root);
    while(!que.empty())
    {
        node* now = que.front();
        que.pop();
        cout << now->data;
        num_output++;
        if (num_output < n) { cout << " "; }
        if (now->left != NULL) { que.push(now->left); }
        if (now->right != NULL) { que.push(now->right); }
    }
}



int main()
{
    cin >> n;

    for (int i = 0; i < n; i++) { cin >> post[i]; }
    for (int i = 0; i < n; i++) { cin >> in[i]; }

    node* root = create(0, n-1, 0, n-1);
    BFS(root);

    return 0;     
}