//
//  level 4.cpp
//  BoostCourse
//
//  Created by 이의진 on 2022/07/13.
//

#include "level 4.hpp"

#include <iostream>

#define NUM_SIZE 10000
#define TOTAL_SIZE NUM_SIZE + 1

bool field[TOTAL_SIZE];

void eratosthenes(void);
void solve(void);

int main(void)
{
    eratosthenes();
    solve();
    return 0;
}

void eratosthenes(void)
{
    std::fill_n(field, TOTAL_SIZE, true); // true로 초기화

    field[0] = field[1] = false;
    for (int i = 2; i < int(TOTAL_SIZE / 2); i++)
    {
        if (!field[i]) continue;

        int temp = 2;
        while (i * temp < TOTAL_SIZE)
        {
            field[i * temp] = false;
            temp++;
        }
    }
}

void find_partition(int n)
{
    int s = int(n / 2);
    for (int i = s; i > 1; i--)
    {
        if (!(field[i] && field[n - i])) continue;
        std::cout << i << " " << n - i << std::endl;
        break;
    }
}

void solve(void)
{
    int test_case;
    std::cin >> test_case;

    for (int t = 0; t < test_case; t++)
    {
        int n;
        std::cin >> n;

        find_partition(n);
    }
}
출처: https://suri78.tistory.com/242 [공부노트:티스토리]
