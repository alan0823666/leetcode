class Solution {
public:
    
    int find_kth(vector<int>& nums1, vector<int>& nums2, int L1, int len1, int L2, int len2, int k) {
	if(len1 == 0)
		return nums2[L2 + k-1];
	else if(len2 == 0)
		return nums1[L1 + k-1];
	else if(k == 1)
		return std::min(nums1[L1], nums2[L2]);
	int nums1_med = 100000000;
	int nums2_med = 100000000;
	if(len1 >= k/2)
		nums1_med = nums1[L1 + k/2 - 1];
	if(len2 >= k/2)
		nums2_med = nums2[L2 + k/2 - 1];

	if(nums1_med > nums2_med) {
		return find_kth(nums1, nums2, L1, len1, L2 + k/2, len2 - k/2, k - k/2);
    }
	else  {
		return find_kth(nums1, nums2, L1 + k/2, len1 - k/2, L2, len2, k - k/2);
    }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        int L = (n + m + 1)/2;
        int R = (n + m + 2)/2;
        int A = find_kth(nums1, nums2, 0, n, 0, m, L);
        int B = find_kth(nums1, nums2, 0, n, 0, m, R);
        double ret = double(A + B)/2;
        return ret;