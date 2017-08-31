#include<iostream>
#include<string>
#include<cstdio>
#include<sstream>

using namespace std;

string transToHan(char bit){
    string pinyin;
    switch(bit)
    {
        case '0':  
        pinyin = "ling";  
        break;  
    case '1':  
        pinyin = "yi";  
        break;  
    case '2':  
        pinyin = "er";  
        break;  
    case '3':  
        pinyin = "san";  
        break;  
    case '4':  
        pinyin = "si";  
        break;  
    case '5':  
        pinyin = "wu";  
        break;  
    case '6':  
        pinyin = "liu";  
        break;  
    case '7':  
        pinyin = "qi";  
        break;  
    case'8':  
        pinyin = "ba";  
        break;  
    case '9':  
        pinyin = "jiu";  
        break;  
    default:  
        cout<<"default"<<endl;  
        break;  
    }
    return pinyin;
}

int getBitnum(int num)
{
    int bitnum;
    while(num > 0){
        num = num/10;
        bitnum++;
    }
    return bitnum;
}

int main()
{
    int sum = 0;
    string input;
    cin >> input;
    for (int i = 0; i < input.size(); i++){
        sum += (int)input.at(i) - 48;
    }

    string output = "";
    int bitnum = getBitnum(sum);

    stringstream ss;
    ss << sum;
    string res = ss.str();

    for (int i = 0; i < res.size(); i++){
        if (i != res.size() - 1)
            cout << transToHan(res.at(i)) << " ";
        else
        cout << transToHan(res.at(i));
    }

    // printf("%d", sum);
    // printf("%d", bitnum);
    return 0;
}