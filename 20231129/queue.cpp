#include <iostream>
#include <vector>

using namespace std;

const int ALPHABET_INDEX = 26;
const char null = ' ';
const int ARRAY_INDEX = 5;

class Queue{
    char inputs[ARRAY_INDEX] = {null, null, null, null, null};
    bool is_null[ARRAY_INDEX];
    int enqueue_index = 0;
    int begin_index = 0;
public:
    void Enqueue(char input){
        if(!IsFull()){
            inputs[enqueue_index] = input;
            enqueue_index++;
            if(enqueue_index >= ARRAY_INDEX){
                enqueue_index = 0;
            }
            Draw(input);
        }
        else{
            cout<< "queue is Full" << endl;
        }
        
    }
    void Dequeue(int dequeue_num){
        for(int i = 0; i < dequeue_num;i ++){
            int num = inputs[begin_index];
            inputs[begin_index] = null;
            begin_index++;
            if(begin_index >= ARRAY_INDEX){
                begin_index = 0;
            }
            Draw(num,false);
        }
    }
    bool IsFull(){
        bool is_full = true;
        for(int i = 0;i < ARRAY_INDEX;i++){
            if(inputs[i] == null){
                is_full = false;
                return is_full;
            }
        }
        return is_full;
    }
    void Draw(char input, bool isEnqueue = true){
        if(isEnqueue){
            cout<<"Enqueue == " << input << endl;
        }
        else{
            cout<<"Dequeue == " << input << endl;
        }
        int index = begin_index;
        for(int i = 0;i < ARRAY_INDEX; i++){
            cout << inputs[index] << ", ";
            index++;
            if(index == ARRAY_INDEX){
                index = 0;
            }
        }
        cout << endl;
    }
};

int main(){
    Queue queue;
    
    int dequeue_num = 0;

    queue.Enqueue('A');
    queue.Enqueue('B');
    queue.Enqueue('C');
    queue.Enqueue('D');
    queue.Enqueue('E');

    dequeue_num = 1;
    queue.Dequeue(dequeue_num);

    queue.Enqueue('F');

    dequeue_num = 3;
    queue.Dequeue(dequeue_num);

    queue.Enqueue('G');
    queue.Enqueue('H');
    queue.Enqueue('I');

    dequeue_num = 5;
    queue.Dequeue(dequeue_num);

    queue.Enqueue('J');
    queue.Enqueue('K');
    queue.Enqueue('L');
    queue.Enqueue('M');
    queue.Enqueue('N');

    dequeue_num = 2;
    queue.Dequeue(dequeue_num);

    queue.Enqueue('O');
    queue.Enqueue('P');

     dequeue_num = 4;
    queue.Dequeue(dequeue_num);

    queue.Enqueue('Q');
    queue.Enqueue('R');
    queue.Enqueue('S');
    queue.Enqueue('T');

     dequeue_num = 2;
    queue.Dequeue(dequeue_num);

    queue.Enqueue('U');
    queue.Enqueue('V');

     dequeue_num = 4;
    queue.Dequeue(dequeue_num);
    queue.Enqueue('W');
    queue.Enqueue('X');
    queue.Enqueue('Y');
    queue.Enqueue('Z');
    return 0;

}