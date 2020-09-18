#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool check[101]; 

long long solution(string expression) {
    long long answer = 0;
    char op[3]={'+','-','*'};
    sort(op,op+3);
    long long now=0;
    vector<long long> nums;
    vector<char> ops;
    for(int i=0;i<expression.length();i++){ // 문자열 파싱 
        if(isdigit(expression[i])){
            now*=10;
            now+=expression[i]-'0';
        }else {
            nums.push_back(now);
            now = 0;
            ops.push_back(expression[i]);
        }
    }
    nums.push_back(now);
    
    vector<long long> newnums(nums.size());
    do{
        memset(check, false, sizeof(check));
        newnums = nums;
        for(int i=0;i<3;i++){ // 연산자 우선순위
            for(int j=0;j<ops.size();j++){
                if (ops[j]==op[i]){
                    int k,t;
                    for(k=j;k>=0;k--){
                        if (!check[k]) break;
                    }
                    for(t=j+1;t<nums.size();t++){
                        if (!check[t]) break;
                    }
                    check[t]=true;
                    switch(op[i]){
                        case '*' : newnums[k]*=newnums[t];
                            break;
                        case '+' : newnums[k]+=newnums[t];
                            break;
                        case '-' : newnums[k]-=newnums[t];
                            break;
                    }
                }
            }
        }
        newnums[0]= abs(newnums[0]); // 모든 연산이 0번에 결과가 저장됨
        if (newnums[0] > answer) answer = newnums[0];
    } while(next_permutation(op,op+3));
    return answer;
}
