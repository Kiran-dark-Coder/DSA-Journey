class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>result = {-1,-1};
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        result[0] = left;
        result[1] = right;
        return result;
    }

    int binarySearch(vector<int>& nums, int target, bool isSearchingLeft){
        int low = 0;
        int high = nums.size() - 1;
        int idx = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid]>target){
                high = mid -1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                idx = mid;
                if(isSearchingLeft){
                    high = mid -1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        return idx;
    }
};