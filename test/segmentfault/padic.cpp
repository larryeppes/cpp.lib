//
// Created by PC on 2018/1/3.
//
#include <iostream>

/// 返回长度不超过n的二进制数中, 所有不包含101数码段的二进制数个数
/// \return
int main1() {
    int match;
    int n;
    std::cout << "input value of n: ";
    std::cin >> n;

    int count = 0;
    for (int i = 0; i < (1 << n); i++) {
        match = 0;
        for (int j = 0; j <= n - 3; j++) {
            if (((i & (7 << j)) ^ (5 << j)) == 0) // bin(7)=111; bin(5)=101
            {
                match = 1;
                break;
            }
        }
        if (match == 0)
            count++;
    }
    return count;
}

