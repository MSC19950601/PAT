#include <iostream>
#include <vector>
#include <algorithm>

int n = 0;
std::vector<int > input;

int cal(int value)
{
    int temp = 0;

    if(value >=1000)
    {
        temp = value/1000 + (value%1000)/100 + (value%100)/10 + value%10;
    }
    else if(value >=100 && value <= 999)
    {
        temp = value/100 + (value%100)/10 + value%10;
    }
    else if(value>=10 && value <= 99)
    {
        temp = value/10 + value%10;
    }
    else
        temp = value;
    return temp;
}

int main() {

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;
        input.push_back(tmp);
    }

    std::vector<int> result;
    for (int j = 0; j < input.size(); ++j) {
        int tmp = 0;
        tmp = cal(input[j]);
        result.push_back(tmp);
    }
    std::sort(result.begin(),result.end());
    auto it = std::unique(result.begin(),result.end());
    result.erase(it,result.end());
    std::cout << result.size() << std::endl;
    for (int k = 0; k < result.size() - 1; ++k) {
        std::cout << result[k] << " ";
    }
    std::cout << result[result.size() - 1];

    return 0;
}
