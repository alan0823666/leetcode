class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        using namespace std;
        sort(nums.begin(), nums.end());
        
        int N = nums.size();
        
        vector<vector<int>> ans;
        
        for(int n1 = 0; n1 < N-3; n1++) {
            for(int n2 = n1+1; n2 < N-2; n2++) {
                long long int T = (long long int)target - nums[n1] - nums[n2];
                int start = n2 + 1, end = N - 1;
                while(start < end) {
                    long long int sum = (long long int)nums[start] + nums[end]; 
                    if(sum == T) {
                        vector<int> tmp = {nums[n1], nums[n2], nums[start], nums[end]};
                        ans.push_back(tmp);
                        while(end > 0 && nums[end - 1] == nums[end])
                           end -= 1;
                        while(start < N-1 && nums[start + 1] == nums[start])
                           start += 1;
                        end -= 1, start += 1;
                    }
                    else if(sum > T) {
                        end -= 1; 
                       //while(end > 0 && nums[end - 1] == nums[end])
                       //    end -= 1;
                    }
                    else if(sum < T) {
                        start += 1; 
                        //while(start < N-1 && nums[start + 1] == nums[start])
                        //   start += 1;
                    }
                }
                while(n2 < N-1 && nums[n2+1] == nums[n2])
                    n2 += 1;
            }
            while(n1 < N-1 && nums[n1+1] == nums[n1])
                n1 += 1;
        }
        
        
        return ans;
    }
};