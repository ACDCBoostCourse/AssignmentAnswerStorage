//
//  level 2.cpp
//  BoostCourse
//
//  Created by 이의진 on 2022/07/13.
//

#include "level 2.hpp"

#include<iostream>
using namespace std;
int main()
{
    int N;
    double avg = 0,max = 0;
    double arr[1000] = { 0, };
    cin >> N;

    for (int i = 0;i < N;i++)
    {
        cin >> arr[i];
        if (max <= arr[i])
            max = arr[i];
    }

    for (int k = 0;k < N;k++)
    {
        arr[k] = arr[k] / max * 100;
        avg = avg + arr[k]/N;
    }
    cout << avg << "\n";
    return 0;
}
