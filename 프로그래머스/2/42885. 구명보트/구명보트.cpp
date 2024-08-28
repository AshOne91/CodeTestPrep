#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int thinPeople = 0;
    int obesePeople = people.size() - 1;

    while (thinPeople <= obesePeople) {
        if (people[thinPeople] + people[obesePeople] <= limit) {
            // 가장 가벼운 사람과 가장 무거운 사람이 함께 탈 수 있는 경우
            thinPeople++;
        }
        // 가장 무거운 사람만 태우고 다음으로 이동
        obesePeople--;
        answer++;
    }

    return answer;
}