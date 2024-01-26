#include <iostream>
#include <vector>

struct pos{
    int x;
    int y;
}

vector<psos>

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

vector<pos> BFS(vector<pos> array ,pos t){
    cout <<"("<< t.x << "," << t.y << ")" << endl;
    if(t.x == target.x && t.y == target.y){
        array.push_back(t);
        return array;
    }

    vector<pos> brunch = CheckBrunch(t);
    if(brunch.size() > 0){
        array.push_back(t);
        for(int i = 0; i < brunch.size(); i++){
            vector<pos> result = BFS(array,brunch[i]);
            if(!result.empty()){
                return result;
            }
        }
    }
    vector<pos> empty_arr;
    return empty_arr;
}

int main(){
    return 0;
}