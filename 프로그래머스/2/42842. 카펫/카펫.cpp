#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    
    // 면적
    int totalSize = brown + yellow;
    
    //세로길이를 늘리면서
    for (int x = 3; x <= sqrt(totalSize); ++x)
    {
        
        // 사각형이 되는지
        if (totalSize % x == 0)
        {
            int y = totalSize / x;
            
            if (brown == (x + y - 2) * 2)
            {
                return {y, x};
            }
        }
    }
    return {};
}