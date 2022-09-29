class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum_even = 0;
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i]%2 == 0) sum_even += nums[i];
        }
        
        for(int i = 0; i < queries.size(); ++i){
            if(queries[i][0] == 0){
                ans.push_back(sum_even);
            }else{
                if(nums[queries[i][1]]%2 == 0) sum_even -= nums[queries[i][1]];
                if((nums[queries[i][1]] + queries[i][0])%2 == 0){
                    nums[queries[i][1]] += queries[i][0];
                    sum_even += nums[queries[i][1]];
                }else{
                    nums[queries[i][1]] += queries[i][0];
                }
                ans.push_back(sum_even);
            }
        }
        return ans;
    }
};