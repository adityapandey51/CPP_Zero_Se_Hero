// Subtract the product and the sum of thedigits of an integer

class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0;
        int prod=1;
        while(n!=0){
            int rem =n%10;
            sum=sum+rem;
            prod=prod*rem;
            n=n/10;
        }
        return (prod-sum);
    }
};