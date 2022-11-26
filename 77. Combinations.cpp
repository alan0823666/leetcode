class Solution
{
public:
	vector<vector<int>> combine(int n, int k)
	{
		vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, 0); // [0, 0, 0 ,0]
		while (i >= 0) {
			p[i]++;
			if (p[i] > n)
				--i;
			else if (i == k - 1)
				result.push_back(p);
			else {
				++i;
				p[i] = p[i - 1]; // 把小的往前推 //當完成一個push P[i]永久加一 //i其實就是P的size-1
			}
		}
		return result;
	}
};