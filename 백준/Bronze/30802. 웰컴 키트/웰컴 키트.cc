#include<iostream>

int main()
{
    // 참가자의 수
    int N;
    std::cin>>N;
    // 사이즈별 신청자의 수
    int S, M, L, XL, XXL, XXXL;
    std::cin>>S>>M>>L>>XL>>XXL>>XXXL;
    // 티셔츠와 펜의 묶음 수
    int T, P;
    std::cin>>T>>P;
    
    //첫줄 티셔츠T장씩 최소 몇 묶음 주문?
    int tCount = 0;
    if ((S != 0)) tCount += (S / T);
    if ((S % T) > 0) tCount += 1;
    if ((M != 0)) tCount += (M / T);
    if ((M % T) > 0) tCount += 1;
    if ((L != 0)) tCount += (L / T);
    if ((L % T) > 0) tCount += 1;
    if ((XL != 0)) tCount += (XL / T);
    if ((XL % T) > 0) tCount += 1;
    if ((XXL != 0)) tCount += (XXL / T);
    if ((XXL % T) > 0) tCount += 1;
    if ((XXXL != 0)) tCount += (XXXL / T);
    if ((XXXL % T) > 0) tCount += 1;
    std::cout<<tCount<<std::endl;
    // P자루씩 최대 몇 묶음 주문, 그 때 펜을 한 자루씩 몇개 주문하는지
    int penSet = N / P;
    std::cout<<penSet<<" "<<(N - (penSet * P))<<std::endl;
    return 0;
}