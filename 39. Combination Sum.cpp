class Solution {
private:
    void BackTrack(vector<int>& arr,int target,int idx,vector<int>& temp,vector<vector<int>>& ans){
        if(idx == arr.size()){
            if(target == 0) ans.push_back(temp);
            return;
        }
        //pick up the element
        if(arr[idx] <= target){
            temp.push_back(arr[idx]);
            BackTrack(arr,target-arr[idx],idx,temp,ans);
            temp.pop_back();
        }
        //not pick up the element
        BackTrack(arr,target,idx+1,temp,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        BackTrack(candidates,target,0,temp,ans);
        return ans;
    }
};