#include <iostream>
#include <vector>

using namespace std;

const int MAX = 64;
const int FIRST_INDEX = 0;
const int X_INDEX = 8;
const int Y_INDEX = 8;

bool arr[Y_INDEX][X_INDEX] =
{
    {true,true,false,true,true,true,true,true,},
    {true,false,false,true,false,true,false,true,},
    {true,false,false,true,false,true,false,true,},
    {true,true,true,true,false,true,false,true,},
    {true,false,true,false,false,false,true,true,},
    {true,false,true,false,false,true,true,false,},
    {true,true,true,false,false,false,true,false,},
    {true,false,true,true,true,false,true,false,}
};

struct pos{
    pos(){}
    pos(int pos_x,int pos_y){
        x = pos_x;
        y = pos_y;
    }
    int x = 0;
    int y = 0;
    int distance = 0;
};

vector<pos> road;
vector<pos> check;

pos target(6, 6);

void PushVector(int pos_x,int pos_y){
    pos ret(pos_x, pos_y);
    check.emplace_back(ret);
    arr[pos_y][pos_x] = false;
}

int CheckBrunch(pos start){
     int up = start.y - 1;
     int down = start.y + 1;
     int right = start.x + 1;
     int left = start.x - 1;
     int brunch_num = 0;

    if(arr[up][start.x] == true){
        if(up >= FIRST_INDEX){
            PushVector(start.x, up);
            brunch_num++;
        }
    }

    if(arr[start.y][left] == true){
        if(left >= FIRST_INDEX){
            PushVector(left, start.y);
            brunch_num++;
        }
    }

    if(arr[down][start.x] == true){
        if(down < Y_INDEX){
            PushVector(start.x, down);
            brunch_num++;
        }
    }

    if(arr[start.y][right] == true){
        if(right < X_INDEX){
            PushVector(right, start.y);
            brunch_num++;
        }
    }
    return brunch_num;
}

vector<pos> BFS(vector<pos> array ,pos t){
    cout <<"("<< t.x << "," << t.y << ")";
    if(t.x == target.x && t.y == target.y){
        array.push_back(t);
        return array;
    }

    int brunch_num = 0;

    brunch_num = CheckBrunch(t);
    if(brunch_num > 0){
        array.push_back(t);
    }
    for(int i = 0; i < check.size(); i++){
            pos next = check.front();
            check.erase(check.begin());
            vector<pos> result = BFS(array,next);
            if(!result.empty()){
                return result;
            }
            else{
                int top_index = array.size() - 1;
                array.erase(array.begin() + top_index);
            }
        }
    vector<pos> empty_arr;
    return empty_arr;
}

int main(){
    pos start = {2, 3};
    arr[start.y][start.x] = false;
    road = BFS(road,start);
    cout << endl;

    if(road.empty()){
        cout << "road is empty";
    }
    else{
        int result_index = road.size() - 1;
        for(int i = 0; i < road.size(); i++){
            cout << "(" << road[i].x << "," << road[i].y << ")";
        }
    }
    return 0;
}