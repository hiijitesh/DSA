class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n), suff(n), prod(n);
        prefix[0] = 1;
        suff[n-1] = 1;

        for(int i = 1; i < n; ++i){
            prefix[i] = nums[i-1]*prefix[i-1];
        }

        for(int i = n-2; i >= 0; --i){
            suff[i] = nums[i+1]*suff[i+1];
        }

        for(int i = 0; i < n; i++){
            prod[i] = prefix[i]*suff[i];
        }

        return prod;
    }
};