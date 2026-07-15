// Last updated: 7/15/2026, 6:37:08 PM
class Solution {
public:
    int subtractProductAndSum(int n) {
        int nos=n;

        int sum=0;
        int prod=1;

        while (nos>0){
            int a=nos%10;
            prod*=a;
            sum+=a;
            nos=nos/10;
        }
        int res=prod-sum;

        return res;

           
    }
};