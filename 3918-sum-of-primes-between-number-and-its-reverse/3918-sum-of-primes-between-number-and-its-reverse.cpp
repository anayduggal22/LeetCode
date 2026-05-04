class Solution {
public:

    int prime(int n){

        if(n == 0 || n == 1){
            return 0;
        }
        for(int i = 2 ; i*i <= n; i++){
            if(n % i == 0){
                return 0;
            }
        }
        return 1;
    }
    
    int sumOfPrimesInRange(int n) {
        int r = 0;
        int temp = n;

        while(temp > 0){
            r = r*10 + temp % 10;

            temp /= 10;

        }

        int a = min(n,r);
        int b = max(n,r);

        int sum = 0;
        for(int i = a ; i <= b; i++){

            if(prime(i)){
                sum += i;
            }
        }

        return sum;
    }
};