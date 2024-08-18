class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                long long t=(long long)target-(long long)nums[i]-(long long)nums[j];
                int low=j+1,high=n-1;
                while(low<high)
                {
                    if(nums[low]+nums[high]>t)
                    high--;
                    else if(nums[low]+nums[high]<t)
                    low++;
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int ti=low,tj=high;
                        while(low<high && nums[low] ==nums[ti]) low++;
                        while(low<high && nums[high] ==nums[tj]) high--;

                    }
                }
                while(j+1<n && nums[j]==nums[j+1]) j++;
                
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return ans;

    }
};
#______________________________________________________________________________________________________________________________________________
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        vector<int>path;
        DFS(res, nums, 0, target, 0, 0, path);
        return res;
    }
    
    void DFS(vector<vector<int>>& res, vector<int>& nums, int pos, int target, int count, int sum, vector<int>& path){
        if(count == 4){
            if(sum == target) res.push_back(path);
            return;
        }
        for(int i = pos; i < nums.size(); i++){
            if(i != pos && nums[i] == nums[i - 1]) continue;
            if(sum + nums[i] + (3 - count) * nums[nums.size() - 1] < target) continue;
            if(sum + (4 - count)* nums[i] > target) break;
            path.push_back(nums[i]);
            DFS(res, nums, i + 1, target, count + 1, sum + nums[i], path);
            path.pop_back();
        }
    }
};
