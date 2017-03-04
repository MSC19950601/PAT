// John got a full mark on PAT. He was so happy that he decided to hold a raffle（抽奖） for his followers on Weibo -- that is, he would select winners from every N followers who forwarded his post, and give away gifts. Now you are supposed to help him generate the list of winners.

// Input Specification:

// Each input file contains one test case. For each case, the first line gives three positive integers M (<= 1000), N and S, being the total number of forwards, the skip number of winners, and the index of the first winner (the indices start from 1). Then M lines follow, each gives the nickname (a nonempty string of no more than 20 characters, with no white space or return) of a follower who has forwarded John's post.

// Note: it is possible that someone would forward more than once, but no one can win more than once. Hence if the current candidate of a winner has won before, we must skip him/her and consider the next one.

// Output Specification:

// For each case, print the list of winners in the same order as in the input, each nickname occupies a line. If there is no winner yet, print "Keep going..." instead.

//一道暴力题，写得不怎么优雅，过就行，但是今天考试竟然没注意下标！崩溃！
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


vector<string> name;
vector<string> winner;
int m,n,s;  

bool isGet(string s) {
    for (int i = 0; i < winner.size(); i++) {
        if ( s == winner[i]) {
            return true;
        }
    }
    return false;
}

void find_ans(vector<string> ori) {
    
    for(int i = s; i <= m; i += n) {
        if (winner.size() == 0) {
            winner.push_back(ori[i - 1]);
        }else {
            string temp = ori[i - 1];
            bool flag = isGet(temp);
            if(flag == false) {
                winner.push_back(temp);
            }else {
                for (int j = i + 1; j <= m; j++) {
                     bool flag2 = isGet(ori[j - 1]);
                     if(flag2 == true)
                        continue;
                     else {
                        winner.push_back(ori[j - 1]);
                        i = j + 1;
                        break;
                     }      
                }
            }
        }
    } 
}

int main() {
    cin >> m >> n >> s;

    string temp;
    for(int i = 0; i < m; i++) {
        cin >> temp;
        name.push_back(temp);
    }

    if (s > m) {
        cout << "Keep going..." << endl;
    } else {
        find_ans(name);
    }

    for(int i = 0; i < winner.size(); i++) {
        cout << winner[i] << endl;
    }

    return 0;
}