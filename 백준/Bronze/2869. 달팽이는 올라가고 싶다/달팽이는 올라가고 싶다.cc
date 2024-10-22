#include <iostream>
#include <cmath>

int main()
{
    int A, B, V;
    std::cin >> A >> B >> V;

    // 낮에 올라가는 미터 A, 밤에 미끄러지는 미터 B, 정상 높이 V
    int day = (V - B) / (A - B);
    
    // 정상에 도달하는 데 정확히 맞아떨어지지 않으면 하루 더 필요
    if ((V - B) % (A - B) != 0) {
        day += 1;
    }

    std::cout << day << std::endl;

    return 0;
}