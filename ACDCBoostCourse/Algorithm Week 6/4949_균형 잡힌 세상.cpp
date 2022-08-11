//
//  4949_균형 잡힌 세상.cpp
//  BoostCourse
//
//  Created by 이의진 on 2022/08/10.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool checkSentence(string sentence) {
    stack<char> bracketStack;
    for (char letter: sentence) {
        switch (letter) {
            case '[':
                bracketStack.push('[');
                break;
                
            case '(':
                bracketStack.push('(');
                break;
                
            case ']':
                if (bracketStack.empty() || bracketStack.top() == '(') {
                    return false;
                }
                bracketStack.pop();
                break;
                
            case ')':
                if (bracketStack.empty() || bracketStack.top() == '[') {
                    return false;
                }
                bracketStack.pop();
                break;
                
            default:
                break;
        }
    }
    return bracketStack.empty() ? true : false;
}

int main(){
    while(1){
        string sentence;
        getline(cin, sentence);
        if (sentence == ".") {
            break;
        }

        if (checkSentence(sentence)) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
    return 0;
}
