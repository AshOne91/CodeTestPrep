#include<iostream>

int main()
{
    int one, two, three, four, five;
    std::cin>>one>>two>>three>>four>>five;
    
    int value = one*one + two*two + three*three + four*four + five*five;
    value %= 10;
    std::cout<<value;
    return 0;
}