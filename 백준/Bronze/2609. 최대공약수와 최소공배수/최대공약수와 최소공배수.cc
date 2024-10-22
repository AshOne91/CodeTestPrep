#include<iostream>

int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int a, b;
    std::cin>>a>>b;
    std::cout<<gcd(a, b)<<std::endl;
    std::cout<<lcm(a, b)<<std::endl;
    return 0;
}