#include <iostream>
#include <string>
 
using namespace std;
 
int OX(string& s) {
    
    int cumulative = 0;
    int sum = 0;
 
    for(char &v : s) {
        /*
         * O 문자일 경우 누적합을 1 증가시킨 뒤
         * 해당 값에 대해 누적합
         */
        if(v == 'O') {
            cumulative++;
            sum += cumulative;
        }
        else {
            cumulative = 0;
        }
    }
    return sum;
}
 
int main(int argc, const char * argv[]) {
 
    int T;
    cin >> T;
 
    for(int i = 0; i < T; i++) {
        string s;
        cin >> s;
 
        cout << OX(s) << "\n";
    }
 
    return 0;
}
