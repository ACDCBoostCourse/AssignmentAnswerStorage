//
//  17952_과제는 끝나지 않아.cpp
//  BoostCourse
//
//  Created by 이의진 on 2022/08/03.
//

#include <iostream>
using namespace std;

// 1. 과제는 score, time 이라는 구성 요소가 있으므로 이를 struct로 구현
struct Assignment {
    int score = -1;
    int time = -1;
};

int main(){
    
    // 2. 필요 변수 선언 및 입력 받기
    // n : 입력 값의 개수
    // assignments : 각 시간대별 Assignment 목록, 과제가 없는 시간대는 Assignment.score = -1, Assignment.time = - 1
    // buffer : 입력이 0인지 1인지 판별하는 로직을 넣기 위해 임시 저장하는 메모리
    // assignmentStack : 현재 진행 중인 작업 목록을 Stack으로 관리
    // stackElementCount : 현재 Stack의 원소 개수
    // result : 최종 결과
    
    int n;
    cin >> n;
    Assignment *assignments = new Assignment[n];
    int buffer;
    Assignment *assignmentStack = new Assignment[n];
    int stackElementCount = 0;
    int result = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> buffer;
        if (buffer == 1){
            cin >> assignments[i].score;
            cin >> assignments[i].time;
        }
    }
    
    // 매 분 반복을 수행
    for (int i = 0; i < n; i++) {
        // 3. 만약 해당 분에 과제가 있으면 과제를 Stack 에 Push!
        if (assignments[i].score != -1) {
            assignmentStack[stackElementCount] = assignments[i];
            stackElementCount += 1;
        }
        
        // 4. 과제 수행
        // 과제가 하나도 없는 경우 stackElementCount = 0 이므로 만약 이를 검증하지 않고 실행되어버리면 [] 안이 -1이 되어버림!!!
        // 백준 컴파일러 기준 동적할당된 포인터의 [] 안에 -1이 들어가면 오류를 발생시키지 않으나, delete 시킬 때 문제가 생기게 된다!
        // 기존 설명의 isEmpty 변수는 필요 없음!
        if (stackElementCount != 0){
            assignmentStack[stackElementCount - 1].time -= 1;
        }
        // 5. 만약 stack 최상단 과제가 다 끝나면 과제를 stack에서 제거 및 점수 갱신
        if(stackElementCount != 0){
            if (assignmentStack[stackElementCount - 1].time == 0) {
                result += assignmentStack[stackElementCount - 1].score;
                assignmentStack[stackElementCount - 1].score = -1;
                assignmentStack[stackElementCount - 1].time = -1;
                stackElementCount -= 1;
            }
        }
    }
    
    // 6. 결과 출력
    cout << result << endl;
    
    // 7. 동적 할당 해제
    delete [] assignments;
    delete [] assignmentStack;
    assignments = NULL;
    assignmentStack = NULL;
    
    return 0;
}

