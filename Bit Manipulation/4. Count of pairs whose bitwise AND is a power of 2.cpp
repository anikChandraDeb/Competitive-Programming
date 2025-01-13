#include <bits/stdc++.h>
using namespace std;

long long countPairs(int arr[], int n)
{
	long long ans = 0, mx = 0;

	// create a hash map to store the frequency of each
	// integer in the array
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int ai = arr[i];
		// update the frequency of each integer in the
		// hash map
		mp[ai]++;
		// find the maximum value in the array
		mx = max(mx, (long long)ai);
	}
	// iterate through each integer i from 0 to mx
	for (int i = 0; i <= mx; ++i)
	{
	
		// if i is not present in the hash map, skip to
		// the next integer
		if (mp.find(i) == mp.end())
			continue;
	
		// iterate through each integer j from i to mx
		for (int j = i; j <= mx; ++j)
		{
		
			// if j is not present in the hash map, skip
			// to the next integer
			if (mp.find(j) == mp.end())
				continue;
		
			// check if the bitwise AND of i and j has
			// only one set bit
			if (__builtin_popcount(i & j) == 1) 
			{
			
				// if i is equal to j, add the product
				// of nCr(mp.get(i), 2) to the answer
				if (i == j)
					ans += ((long long)mp[i] * (mp[i] - 1))
						/ 2;
			
				// if i is not equal to j, add the
				// product of mp.get(i) and mp.get(j) to
				// the answer
				else
					ans += ((long long)mp[i]) * mp[j];
			}
		}
	}
	// return the answer
	return ans;
}

// Driver Code
int main()
{
	// Given array arr[]
	int arr[] = { 6, 4, 2, 3 };

	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << countPairs(arr, n);
	return 0;
}

// This code is contributed by Prajwal Kandekar

