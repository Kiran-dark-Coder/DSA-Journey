class Solution {
public:
    vector<vector<int>>ans;
    void solve(int index, vector<int>&nums,vector<int>temp)
    {
        //base condition
        if(index==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        //pick element 
        temp.push_back(nums[index]);
        solve(index+1,nums,temp);

        //not pick
        temp.pop_back();
        solve(index+1, nums, temp);

        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        //empty subset
        solve(0,nums,temp);
        return ans;
    }
};