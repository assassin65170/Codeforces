#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
string brokenKeyboard(string s)
{
    if(s.length() == 1)
        return s;
    int ct = 1;
    string res = "";
    for (int i=0;i<s.length() - 1;++i) {
        int j = i + 1;
        if(s[i] == s[j])
            ++ct;
        else
        {
            if(ct % 2 != 0)
                res+=s[i];
            ct = 1;
        }
        if(j == s.length() - 1 && ct % 2 != 0)
            res+=s[j];
    }
    sort(res.begin(), res.end());
    auto it = unique(res.begin(), res.end());
    res.erase(it, res.end());
    return res;
}
 
int main()
{
    int testcase = 0;
    cin >> testcase;
    for(int i=0;i<testcase;++i)
    {
        string s = "";
        cin >> s;
        cout << brokenKeyboard(s) << endl;
    }
    return 0;
}
