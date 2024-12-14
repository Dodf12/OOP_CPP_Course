int helper(int& m)
{
	int *p = new int[3];
	for (int i = 0; i < 3; i++)
	{
		*(p+i) = m - i;
	}
	m = p[2];
	return m + 1;
}

int main()
{
	int n = 4;
	int *p = &n;
	*p = 2 * n;
	int v = helper(n);
	cout << (v + *p) << endl;
}