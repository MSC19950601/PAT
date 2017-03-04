// Suppose that all the keys in a binary tree are distinct positive integers. A unique binary tree can be determined by a given pair of postorder and inorder traversal sequences. And it is a simple standard routine to print the numbers in level-order. However, if you think the problem is too simple, then you are too naive. This time you are supposed to print the numbers in "zigzagging order" -- that is, starting from the root, print the numbers level-by-level, alternating between left to right and right to left. For example, for the following tree you must output: 1 11 5 8 17 12 20 15.
// Input Specification:

// Each input file contains one test case. For each case, the first line gives a positive integer N (<= 30), the total number of nodes in the binary tree. The second line gives the inorder sequence and the third line gives the postorder sequence. All the numbers in a line are separated by a space.

// Output Specification:

// For each test case, print the zigzagging sequence of the tree in a line. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

//已知树后序遍历和中序遍历求树的之字形层序遍历
//传统建树方法
//对层序遍历进行修改
//维护两个栈，相邻两行分别存到两个栈中，进栈的顺序也不相同，一个栈是先进左子结点然后右子节点，另一个栈是先进右子节点然后左子结点，这样出栈的顺序就是我们想要的之字形了
//同样的考点可以见LeetCode-103

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

const int maxn = 31;

struct node
{
	int data;
	node* left;
	node* right;
};

int pre[maxn], in[maxn], post[maxn];
int n;
vector<vector<int>> ans;
vector<int> finalres;


node* create(int postL, int postR, int inL, int inR)
{
	if(postL > postR)
	{
		return nullptr;
	}
	node* root = new node;
	root->data = post[postR];
	int k;
	for(k = inL; k <= inR; k++)
	{
		if (in[k] == post[postR])
			break;
	}
	int numLeft = k - inL;
	root->left = create(postL, postL + numLeft - 1, inL, k - 1);
	root->right = create(postL + numLeft, postR - 1, k + 1, inR);
	return root;
}

void BFS(node* root)
{
	vector<int> out;
	stack<node*> s1;
	stack<node*> s2;
	s1.push(root);
	while (!s1.empty() || !s2.empty())
	{
		while (!s1.empty())
		{
			node* now = s1.top();
			s1.pop();
			out.push_back(now->data);
			if (now->right != nullptr) { s2.push(now->right); }
			if (now->left != nullptr) { s2.push(now->left); }
			
		}
		if (!out.empty()) { ans.push_back(out);  }
		out.clear();
		while (!s2.empty())
		{
			node* now = s2.top();
			s2.pop();
			out.push_back(now->data);
			if (now->left != nullptr) { s1.push(now->left); }
			if (now->right != nullptr) { s1.push(now->right); }	
		}
		if (!out.empty()) { ans.push_back(out); }
		out.clear();
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> in[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> post[i];
	}

	node* root = create(0, n - 1, 0, n - 1);
	BFS(root);

	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			finalres.push_back(ans[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << finalres[i];
		if (i < n - 1)
			cout << " ";
	}
//	system("pause");
	return 0;
}