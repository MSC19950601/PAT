#include <iostream>
#include <vector>
#include <algorithm>

int n = 0;
std::vector<int > arr;

int main() {

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;
        arr.push_back(tmp);
    }

    std::sort(arr.begin(),arr.end());

    std::cout << n%2 << " ";

    int pre = 0;
    for (int j = 0; j < n/2; ++j) {
        pre += arr[j];
    }
    int next = 0;
    for (int k = n/2; k < n; ++k) {
        next += arr[k];
    }

    std::cout << next - pre;

    return 0;
}
