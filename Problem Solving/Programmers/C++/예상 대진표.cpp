

int solution(int n, int a, int b)
{
    int answer = 1;
    if(a<b) {
        int temp = a;
        a = b;
        b = temp;
    }
    while(a-b > 1) {
        a&1 ? a= a/2+1 : a= a/2;
        b&1 ? b= b/2+1 : b= b/2;
        answer++;
    }
    
    return answer;
}
