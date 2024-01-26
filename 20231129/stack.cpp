#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

const char null = (char)"";

class Stack{
    vector<char> inputs;
public:
    void push(char input){
        inputs.emplace_back(input);
        Draw(input);
    }
    void pop(){
        int top_index = inputs.size() -1;
        char pop_char =inputs[top_index]; 
        inputs.erase(inputs.begin() + top_index);
        Draw(pop_char, false);
    }

    void Draw(char input, bool isInput = true){
        if(isInput){
            cout<<"push == "<< input << endl;
        }
        else{
            cout<<"pop == "<< input << endl;
        }
        for(int i = 0; i < inputs.size();i++){
            cout<<inputs[i]<<", ";
        }
        cout << endl;
    }
};

int main(){
    Stack stack;
    stack.push('A');
    stack.push('B');
    stack.push('C');
    stack.push('D');
    stack.push('E');
    stack.push('F');
    stack.push('G');
    stack.push('H');
    stack.push('I');
    stack.push('J');
    stack.push('K');
    stack.push('L');
    stack.push('M');
    stack.push('N');
    stack.push('O');
    stack.push('P');
    stack.push('Q');
    stack.push('R');
    stack.push('S');
    stack.push('T');
    stack.push('U');
    stack.push('V');
    stack.push('W');
    stack.push('X');
    stack.push('Y');
    stack.push('Z');

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    return 0;    
}