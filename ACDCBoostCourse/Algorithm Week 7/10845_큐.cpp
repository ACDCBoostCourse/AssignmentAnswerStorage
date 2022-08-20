#include <iostream>
#include <string>
#define MAXSIZE 10000

using namespace std;

template <typename T>

class Queue{
    
private:
    T* arr;
    int topCursor;
    int rearCursor;
    int qSize;
    
public:
    Queue(){
        qSize = 0;
        arr = new T[MAXSIZE];
        topCursor = 0;
        rearCursor = 0;
    }
    
    ~Queue(){
        delete[] arr;
    }
    
    void push(T item){
        arr[topCursor] = item;
        topCursor++;
        qSize++;
    }
    
    T pop(){
        T buffer;
        if(qSize != 0){
            buffer = arr[rearCursor];
            arr[rearCursor] = 0;
            rearCursor++;
            qSize--;
            return buffer;
        }
        else{
            return -1;
        }
    }
    
    int size(){
        return qSize;
    }
    
    int empty(){
        return qSize == 0 ? 1 : 0;
    }
    
    int front(){
        if(qSize != 0){
            return arr[rearCursor];
        }
        else{
            return -1;
        }
    }
    
    int back(){
        if(qSize != 0){
            return arr[topCursor - 1];
        }
        else{
            return -1;
        }
    }
};

int main(){
    int commmandNum;
    string command;
    int item;
    Queue<int> queue;
    
    cin >> commmandNum;
    
    for(int i = 0; i < commmandNum; i++){
        cin >> command;
        
        if(command == "push"){
            cin >> item;
            queue.push(item);
        }
        else if(command == "pop"){
            cout << queue.pop() << endl;
        }
        else if(command == "size"){
            cout << queue.size() << endl;
        }
        else if(command == "empty"){
            cout << queue.empty() << endl;
        }
        else if(command == "front"){
            cout << queue.front() << endl;
        }
        else if(command == "back"){
            cout << queue.back() << endl;
        }
        
    }
}
