#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int fail[21];

bool cmp(string a, string b) {
    return a.length() < b.length();
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    
    for (int t=0; t<phone_book.size(); t++) {
        string str = phone_book[t];
        for (int i=1,j=0; i<str.length(); i++) {
            while(j > 0 && str[i] != str[j])
                j = fail[j-1];
            if(str[i]==str[j])
                fail[i] = ++j;
        }
            for (int p=t+1; p<phone_book.size(); p++) {
                for (int i=0,j=0; i<str.length(); i++) {
                    while(j > 0 && phone_book[p][i] != str[j])
                            j = fail[j-1];
                    if(phone_book[p][i] == str[j]) {
                        if(j == str.length()-1) {
                            answer = false;
                            return answer;
                        }
                        else
                            j++;
                    }
                }
            }
    }
    return answer;
}
