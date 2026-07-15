// Last updated: 7/15/2026, 6:36:44 PM
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long ni=0;
        long long a=0;
        long long i=1;
        while (n>0){
            a=n%10;
            sum+=a;
            n=n/10;
            if (a!=0){
                ni=ni+(a*i);
                i=i*10;
            }
            else{
                continue;
            }
        }
        long long res=sum*ni;
        return res;
        
    }
};