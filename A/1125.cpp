// Given some segments of rope, you are supposed to chain them into one rope. Each time you may only fold two segments into loops and chain them into one piece, as shown by the figure. The resulting chain will be treated as another segment of rope and can be folded again. After each chaining, the lengths of the original two segments will be halved.

// Your job is to make the longest possible rope out of N given segments.

// Input Specification:

// Each input file contains one test case. For each case, the first line gives a positive integer N (2 <= N <= 104). Then N positive integer lengths of the segments are given in the next line, separated by spaces. All the integers are no more than 104.

// Output Specification:

// For each case, print in a line the length of the longest possible rope that can be made by the given segments. The result must be rounded to the nearest integer that is no greater than the maximum length.

//依然是暴力，送分题，然而考试时想得太复杂，现在才解决= =
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a;
int maxLength = 0;

int main()
{
	cin >> n;
	int temp; 
	for(int i = 0; i < n; i++)
	{
		cin >> temp;
		a.push_back(temp);
	}
	sort(a.begin(), a.end());
	double ans = (a[0] + a[1]) / 2;
	for (int i = 2; i < n; i++)
	{
		ans = (ans + a[i] ) / 2;
	}
	maxLength = (int)ans;
	cout << maxLength;
	system("pause");
	return 0;
}