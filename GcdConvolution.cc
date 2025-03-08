template<typename T>
std::vector<T> gcdConvolution(std::vector<T> a, std::vector<T> b)
{
    int n = a.size();
    std::vector<T> A(n);
    std::vector<T> B(n);
    std::vector<T> D(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j += i+1)
        {
            A[i] += a[j];
            B[i] += b[j];
        }
        D[i] = A[i] * B[i];
    }
    std::vector<T> d(n);
    for (int i = n-1; i >= 0; i--)
    {
        d[i] = D[i];
        for (int j = 2*i+1; j < n; j += i + 1)
        {
            d[i] -= d[j];
            d[i] = (d[i]);
        }
    }
    return d;

}