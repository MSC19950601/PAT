#include <iostream>
#include <vector>
#include <algorithm>

//input
int n;
std::vector<int> arr;
std::vector<int> preOrder;
std::vector<int> levelOrder;
void preTraversal(int root)
{
    if(root > n)
        return;

    preTraversal(2 * root);
    preOrder.push_back(root);
    preTraversal(2 * root + 1);

}

int main() {

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int tmp = -1;
        scanf("%d",&tmp);
        arr.push_back(tmp);
        levelOrder.push_back(0);
    }
    levelOrder.push_back(0);
    std::sort(arr.begin(),arr.end());

    preTraversal(1);

    for (int i = 0; i < preOrder.size(); ++i) {
        levelOrder[preOrder[i]] = arr[i];
    }
//    for (int j = 0; j < preOrder.size(); ++j) {
//        std::cout << preOrder[j] << " ";
//    }
    for (int i = 1; i < n; ++i) {
        std::cout << levelOrder[i] << " ";
    }
    std::cout << levelOrder[n];
    return 0;
}

//对输入进行升序排序
//获得该输入建立完全二叉树后对应的层序序号
//层序序号为输出数组的下标
//顺序遍历下标把排序好的输入（同时遍历）放入输出数组