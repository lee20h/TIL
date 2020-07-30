#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    for(int k=1;k<=t;k++)
    {
        string a, b, c;
        cin>>a>>b;
        int n = a.size();
		int m = b.size();
		int len = max(n,m);
        if(n > m) {
        	for(int i=0; i<n-m; i++) {
        		b = "0" + b;	
			}
		}
        else {
        	for(int i=0; i<m-n; i++) {
        		a="0"+a;	
			}
		}
        int w=0,sum;
        for(int i=len-1;i>=0;i--)
        {
            sum = a[i] - '0' + b[i] - '0' + w;
            if(sum>=10) {
            	w=1;
				c.push_back(sum-10+'0');	
			}
            else {
            	w=0;
				c.push_back(sum+'0');
			}
        }
        if(w) c.push_back('1');
        reverse(c.begin(),c.end());
        cout<<'#'<<k<<' '<<c<<'\n';
    }
    return 0;
}

