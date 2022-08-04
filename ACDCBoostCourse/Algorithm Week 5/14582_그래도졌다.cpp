#include <iostream>
using namespace std;

int solved_14582(){
    // 1. 필요한 변수 선언
    bool isAhead = false;
    int myTeamScore[9];
    int yourTeamScore[9];
    int myTeamAccumulatedScore = 0;
    int yourTeamAcculmulatedScore = 0;
    
    
    // 2. 입력 받기
    for(int i = 0; i < 9; i++){
        cin >> myTeamScore[i];
    }
    for(int i = 0; i < 9; i++){
        cin >> yourTeamScore[i];
    }
    
    // 3. 우리 팀이 이기고 있던 적이 있는지 판별, 해당 결과를 isAhead 변수에 저장
    for(int i = 0; i < 9; i++){
        myTeamAccumulatedScore += myTeamScore[i];
        if(!isAhead && (myTeamAccumulatedScore > yourTeamAcculmulatedScore)) {
            isAhead = true;
        }
        yourTeamAcculmulatedScore += yourTeamScore[i];
    }
    
    // 4. 이기고 있던 적이 있으며, 우리 팀이 지면 Yes, 그렇지 않으면 No
    if(isAhead && (myTeamAccumulatedScore < yourTeamAcculmulatedScore)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
