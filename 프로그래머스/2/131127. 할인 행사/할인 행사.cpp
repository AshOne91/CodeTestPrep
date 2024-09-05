#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    // 원하는 제품과 그 수량을 기록하는 맵
    unordered_map<string, int> wantMap;
    for (int i = 0; i < want.size(); i++) {
        wantMap[want[i]] = number[i];
    }

    int totalDays = 0;
    int discountPeriod = 10; // 10일 동안 할인

    // 할인 목록을 순차적으로 확인 (sliding window 방식)
    for (int i = 0; i <= discount.size() - discountPeriod; i++) {
        unordered_map<string, int> currentDiscount;
        // i일부터 i + 9일까지의 할인 목록을 확인
        for (int j = i; j < i + discountPeriod; j++) {
            currentDiscount[discount[j]]++;
        }

        // 현재 할인 목록과 원하는 제품 리스트를 비교
        bool canRegister = true;
        for (const auto& item : wantMap) {
            if (currentDiscount[item.first] < item.second) {
                canRegister = false;
                break;
            }
        }

        // 원하는 제품을 모두 살 수 있다면 카운트 증가
        if (canRegister) {
            totalDays++;
        }
    }

    return totalDays;
}