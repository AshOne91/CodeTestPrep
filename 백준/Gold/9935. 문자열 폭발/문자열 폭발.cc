#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string input, bomb;
    cin >> input >> bomb;

    string result;
    int bombSize = bomb.size();

    for (char c : input) {
        result.push_back(c);

        // Check if the end of the result matches the bomb string
        if (result.size() >= bombSize && result.substr(result.size() - bombSize, bombSize) == bomb) {
            result.erase(result.size() - bombSize, bombSize);
        }
    }

    if (result.empty()) {
        cout << "FRULA";
    } else {
        cout << result;
    }

    return 0;
}
