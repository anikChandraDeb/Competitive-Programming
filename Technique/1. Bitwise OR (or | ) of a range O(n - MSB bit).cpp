// C++ Program to find the bitwise
// OR of all the integers in range L-R
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
// Returns the Most Significant Bit
// Position (MSB)
int position(lli N)
{
	int msb_p = -1;
	while (N) {
		N = N >> 1;
		msb_p++;
	}
	return msb_p;
}

// Returns the Bitwise OR of all
// integers between L and R
lli or_range(lli L,lli R)
{
	lli res = 0;

	// Find the MSB position in L
	int msb_p1 = position(L);

	// Find the MSB position in R
	int msb_p2 = position(R);

	while (msb_p1 == msb_p2) {
		lli res_val = (1 << msb_p1);

		// Add this value until msb_p1 and
		// msb_p2 are same;
		res += res_val;

		L -= res_val;
		R -= res_val;

		// Calculate msb_p1 and msb_p2
		msb_p1 = position(L);
		msb_p2 = position(R);
	}
	// Find the max of msb_p1 and msb_p2
	msb_p1 = max(msb_p1, msb_p2);

	// Set all the bits from msb_p1 upto
	// 0th bit in the result
	for (int i = msb_p1; i >= 0; i--) {
		lli res_val = (1 << i);
		res += res_val;
	}
	return res;
}

// Driver Code
int main()
{
	int L = 12, R = 18;
	cout << or_range(L, R) << endl;
	return 0;
}
