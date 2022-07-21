#include <iostream>
using namespace std;

string changeNum(string n){
    int sum = 0;
    for(int i=0; i<n.length(); i++)
        sum += n[i] - '0';
    
    return to_string(sum);
}

int main(){
    string x;
    int cnt = 0;
    cin >> x;
    while(x.length() != 1){
        x = changeNum(x);
        cnt++;
    }

    cout << cnt << "\n";
    (x == "3" || x == "6" || x == "9") ? cout << "YES\n" : cout << "NO\n";

    return 0;
}
