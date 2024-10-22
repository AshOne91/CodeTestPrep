/*#include<iostream>
#include<vector>
#include<sstream>  // stringstream 사용

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    // 계수 정렬을 위한 배열
    std::vector<int> cnt(10001, 0);
    
    int N;
    std::cin >> N;
    
    // 입력받아서 카운트 증가
    for(int i = 0; i < N; ++i)
    {
        int num;
        std::cin >> num;
        cnt[num]++;
    }
    
    // 출력 스트림을 사용하여 한 번에 출력
    std::ostringstream output;
    for(int i = 1; i < cnt.size(); ++i)
    {
        if (cnt[i] > 0)
        {
            for(int j = 0; j < cnt[i]; ++j)
            {
                output << i << '\n';
            }
        }
    }
    
    // 한 번에 출력
    std::cout << output.str();
    
    return 0;
}*/
#include<iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt[10001] = { 0 };
	int n,count;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> count;
		cnt[count]++;
	}

	for (int i = 1; i < 10001; i++)
		for (int j = 0; j < cnt[i]; j++)
			cout << i<<'\n';

	return 0;
}