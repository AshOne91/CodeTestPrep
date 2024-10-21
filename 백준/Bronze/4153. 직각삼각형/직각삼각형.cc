#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    std::vector<int> v;
    for(;;)
    {
        int A, B, C;
        std::cin>>A>>B>>C;
        if(A == 0)
        {
            return 0;
        }
        v.push_back(A);
        v.push_back(B);
        v.push_back(C);
        std::sort(v.begin(), v.end(), [](auto& lhs, auto& rhs){
            return lhs > rhs;
        });
        
        int a = v[0] * v[0];
        int b = v[1] * v[1];
        int c = v[2] * v[2];
        if (a == (b + c))
        {
            std::cout<<"right"<<std::endl;
        }
        else
        {
            std::cout<<"wrong"<<std::endl;
        }
        v.clear();
    }
    return 0;
}