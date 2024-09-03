#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    //합산해 가며 최대값을 저장
    for(int i = (triangle.size() - 1); i > 0 /*마지막은 순회 할 필요 없음*/ ;--i)
    {
        for(int j = 0; j < (triangle[i].size() - 1)/*마지막은 순회 할 필요 없음*/; ++j)
        {
            // 왼쪽합
            int leftValue = triangle[i][j] + triangle[i-1][j];
            // 오른쪽 합
            int rightValue = triangle[i][j + 1] + triangle[i-1][j];
            triangle[i-1][j] = max(leftValue, rightValue);
        }
    }
    return triangle[0][0];
}