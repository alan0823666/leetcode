class Solution {
public:
    void merge(vector<int>& nums, int start, int mid, int end, int maxele) {
        //cout << " inter " << start << " " << mid << " " << end << endl;
        int i = start, j = mid+1, k = start;
        while(i <= mid && j <= end) {
            //cout << " i, j" << i << " " << j << endl;
            if(nums[i] % maxele <= nums[j] % maxele) {
                 nums[k] = nums[k] + (nums[i] % maxele) * maxele;
                 k++;
                 i++;
            }
            else{
                 nums[k] = nums[k] + (nums[j] % maxele) * maxele;
                 k++;
                 j++;
            }
        }
        //cout << " inter " << start << " " << mid << " " << end << endl;
        while (i <= mid) {
            nums[k] = nums[k] + (nums[i] % maxele) * maxele;
            k++;
            i++;
        }
        while (j <= end) {
            nums[k] = nums[k] + (nums[j] % maxele) * maxele;
            k++;
            j++;
        }
        for (int x = start; x <= end; x++)
            nums[x] = nums[x] / maxele;
        //cout << " inter " << start << " " << mid << " " << end << endl;
    }
    void mergeSortRec(vector<int>& nums, int beg, int end, int maxele) {
        //cout << beg << " " << end << endl;
        if (beg < end) {
            int mid = (beg + end) / 2;
            mergeSortRec(nums, beg, mid, maxele);
            mergeSortRec(nums, mid + 1, end, maxele);
            merge(nums, beg, mid, end, maxele);
        }
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int maxele = -1;
        for(int i=0; i<n; i++) {
            maxele = max(maxele, nums[i]);
        }
        mergeSortRec(nums, 0, n-1, maxele+1);
    }
};