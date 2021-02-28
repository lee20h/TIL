class Solution {
public:
    int divide(int dividend, int divisor) {
        int ans = 0;
        if(divisor==INT_MIN) 
            return dividend==INT_MIN ? 1 : 0;
        if(dividend==INT_MIN) {
            if(divisor==-1) return INT_MAX;
            if(divisor==1) return INT_MIN;
            ans++;
            dividend+=abs(divisor);
        }
        
        int x=abs(dividend);
        int y=abs(divisor);
        bool sgn = (dividend<0)^(divisor<0);
        int b=1;
        while(x>0)
        {
            if(x>=y)
            {
                x-=y;
                ans+=b;
                if(y>>30) continue;
                b<<=1;
                y<<=1;
            }
            else
            {
                if(divisor>x) break;
                b>>=1;
                y>>=1;
            }
        }
        return sgn?-ans:ans;
    }
};
