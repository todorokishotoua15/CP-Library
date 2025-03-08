long long ncr(int n, int r)
{
	long long num = 1, den = 1;
	if (n-r < r) {
			r = n-r;
	}
	if (r != 0) {
		while (r) {
			num *= n;
			den *= r;
			long long temp = __gcd(num,den);
			num /= temp;
			den /= temp;

			n--;
			r--;
		}
	}
	else {
		num = 1;
	}

	return num;
}