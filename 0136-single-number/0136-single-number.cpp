class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = 0;
        for(int i : nums){
            size = size ^ i;
        }
        return size;
    }
};