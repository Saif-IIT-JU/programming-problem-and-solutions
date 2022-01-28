class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> >triplets;
        sort(nums.begin(), nums.end());
        int i = 0, n = nums.size();
        for(i=0; i<n; )
        {
            vector<int>triplet(3,nums[i]);
            int l = i+1, r = n-1; int target = -nums[i];
            while(l<r){
                if(nums[l]+nums[r]==target){
                    triplet[1] = nums[l]; triplet[2] = nums[r];
                    triplets.push_back(triplet);
                    while(l+1<r && nums[l+1]==nums[l]) l++;
                    while(r-1>l && nums[r-1]==nums[r]) r--;
                    l++; r--;
                }
                else if(nums[l]+nums[r]>target) r--;
                else l++;
            }

            int j = i+1;
            while(j<n && nums[j]==nums[i]) j++;

            i = j;
        }

        return triplets;
    }
};
