#include<iostream>

int main()
{
    int num;
    std::cin>>num;
    
    if (num >= 90 && 100 >= num)
    {
        std::cout<<"A"<<std::endl;
        return 0;
    }else if (num >= 80 && 89 >= num)
    {
        std::cout<<"B"<<std::endl;
        return 0;
    }else if (num >= 70 && 79 >= num)
    {
        std::cout<<"C"<<std::endl;
        return 0;
    }else if (num >= 60 && 69 >= num)
    {
        std::cout<<"D"<<std::endl;
        return 0;
    }
    std::cout<<"F"<<std::endl;
    return 0;
}