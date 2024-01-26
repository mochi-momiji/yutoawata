#include <iostream>
#include <stack>
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
};

vector<pos> road;
vector<pos> check;

pos target(6, 6);

void PushVector(vector<pos> &vec,int pos_x,int pos_y){
    pos ret(pos_x, pos_y);
    vec.emplace_back(ret);
    arr[pos_y][pos_x] = false;
}

vector<pos> CheckBrunch(pos start){
     vector<pos>result;
     int up = start.y - 1;
     int down = start.y + 1;
     int right = start.x + 1;
     int left = start.x - 1;

    if(arr[up][start.x] == true){
        if(up >= FIRST_INDEX){
            PushVector(result, start.x, up);
        }
    }

    if(arr[start.y][left] == true){
        if(left >= FIRST_INDEX){
            PushVector(result, left, start.y);
        }
    }

    if(arr[start.y][right] == true){
        if(right < X_INDEX){
            PushVector(result, right, start.y);
        }
    }

    if(arr[down][start.x] == true){
        if(down < Y_INDEX){
            PushVector(result, start.x, down);
        }
    }

    return result;
}

vector<pos> DFS(vector<pos> array ,pos t){
    cout <<"("<< t.x << "," << t.y << ")" << endl;
    if(t.x == target.x && t.y == target.y){
        array.push_back(t);
        return array;
    }

    vector<pos> brunch = CheckBrunch(t);
    if(brunch.size() > 0){
        array.push_back(t);
        for(int i = 0; i < brunch.size(); i++){
            vector<pos> result = DFS(array,brunch[i]);
            if(!result.empty()){
                return result;
            }
        }
    }
    vector<pos> empty_arr;
    return empty_arr;
}

int main()
{
    pos start = {2, 3};
    arr[start.y][start.x] = false;
    road = DFS(road,start);

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