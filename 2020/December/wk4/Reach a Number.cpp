class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int sum = 0;
        int step = 0;
        
        while (sum < target) {
            step++;
            sum +=step;
        }
        
        while ((sum-target) % 2) {
            step++;
            sum += step;
        }
        
        return step;
        
    }
};
