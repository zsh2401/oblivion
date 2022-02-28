long long fac(long long x)
{
    if (x <= 1)
    {
        return 1;
    }
    return x * fac(x);
}