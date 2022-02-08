class Solution {
public:
    int addDigits(int num) {
        if (num <= 9) return num;
         
        while (num >= 10) {
            // init
            int tmp = 0;
            
            while (num != 0) {
                tmp += num % 10;
                num /= 10;
            } 
            num = tmp;
        }
        return num;
    }
};

