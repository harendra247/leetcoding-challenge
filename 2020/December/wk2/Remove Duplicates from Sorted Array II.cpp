class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=1, count=1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) {
                if (count >= 2) continue;
                count++;
            } else if (nums[i] != nums[i-1]) {
                count = 1;
            }
            nums[j++] = nums[i];
        }
        
        return nums.size() ? j : 0;
    }
};
