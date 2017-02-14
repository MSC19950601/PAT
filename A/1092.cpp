#include <iostream>

int main() {

    std::string s, ss;
    std::cin >> s >> ss;
    int a[1000] = { 0 };
    std::string::iterator it = s.begin();
    for (; it != s.end(); it++)
        a[*it]++;
    int sum = 0, flag = 1;
    for (it = ss.begin(); it != ss.end(); it++)
    {
        a[*it]--;
        if (a[*it] < 0)
            flag = 0;
    }
    for (int i = 0; i < 1000; i++)
    {
        if (flag)
            sum += a[i];
        else if (a[i] < 0)
            sum += (-a[i]);
    }
    printf("%s %d\n", flag ? "Yes" : "No", sum);

    return 0;
}
