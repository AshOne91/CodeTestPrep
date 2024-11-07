#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int T;
    std::cin >> T;
    
    for (int i = 0; i < T; ++i)
    {
        std::string cmd;
        int N;
        std::string str;
        std::cin >> cmd;
        std::cin >> N;
        std::cin >> str;
        
        std::deque<int> dq;
        bool dir = true;
        bool flag = true;
        
        std::string temp;
        for (int j = 1; j < (int)str.size(); ++j)
        {
            if (str[j] == ',' || str[j] == ']')
            {
                if (!temp.empty())
                {
                    dq.push_back(std::stoi(temp));
                    temp.clear();
                }
            }
            else
            {
                temp += str[j];
            }
        }
        
        for (int j = 0; j < (int)cmd.size(); ++j)
        {
            if (cmd[j] == 'R')
            {
                dir = !dir;
            }
            else if (cmd[j] == 'D')
            {
                if (dq.empty())
                {
                    flag = false;
                    break;
                }
                else
                {
                    if (dir)
                        dq.pop_front();
                    else
                        dq.pop_back();
                }
            }
        }
        
        if (!flag)
            std::cout << "error\n";
        else
        {
            if (!dir)
                std::reverse(dq.begin(), dq.end());
            
            std::cout << "[";
            for (int j = 0; j < (int)dq.size(); ++j)
            {
                std::cout << dq[j];
                if (j < (int)dq.size() - 1)
                    std::cout << ",";
            }
            std::cout << "]\n";
        }
    }
}
