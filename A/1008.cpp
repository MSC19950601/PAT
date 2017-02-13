#include <iostream>
#include <vector>
#include <cstdio>

std::vector<int> arr;

int main() {
    int n;//input number
    std::cin >> n;

    int totalTime = 0;//output

    totalTime += 5 * n;

    for (int i = 0; i < n; ++i) {
        int tmp = -1;
        scanf("%d",&tmp);
        arr.push_back(tmp);
    }

    for (int i = 0; i < n - 1; ++i) {
        if(arr[i] < arr[i+1])
        {
            totalTime += (arr[i+1] - arr[i]) * 6;
        }
        else if (arr[i] > arr[i+1])
        {
            totalTime += (arr[i] - arr[i + 1]) * 4;
        }
        else
        {
            continue;
        }
    }
    totalTime += arr[0] * 6;

    std::cout << totalTime;

    return 0;
}