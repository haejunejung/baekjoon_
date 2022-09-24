#include <iostream>

long long state[8], dp[8];

int main(void)
{
    using namespace std;

	int d;
	cin >> d;

	state[0] = 1;
	while (d--)
	{
		dp[0] = state[1] + state[2];
		dp[1] = state[0] + state[2] + state[3];
		dp[2] = state[0] + state[1] + state[3] + state[4];
		dp[3] = state[1] + state[2] + state[4] + state[5];
		dp[4] = state[2] + state[3] + state[5] + state[6];
		dp[5] = state[3] + state[4] + state[7];
		dp[6] = state[4] + state[7];
		dp[7] = state[5] + state[6];

		for (int i = 0; i < 8; i++)
			state[i] = dp[i] % 1000000007;
	}

	cout << state[0] << endl;
	return 0;
}