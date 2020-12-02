#include <string>
#include <vector>
#include <iostream>

using namespace std;

int key_size, lock_size,allsize;

vector<pair<int,int>> print_v(vector<vector<int>> &temp){
    vector<pair<int,int> > a;
    for(int i=0; i<temp.size(); i++){
        for(int j=0; j<temp[i].size(); j++){
            if(temp[i][j]==1){
                a.push_back(make_pair(i,j));
            }
        }
    }
    return a;
}

vector<vector<int>> turn(vector<vector<int> > &key){
    int key_size= key.size();
    vector<vector<int> > temp(key_size, vector<int>(key_size));

    for(int x=0; x<key_size; x++){
        for(int y=0; y<key_size; y++){
            temp[y][(key_size-1) - x] = key[x][y];
        }
    }
    return temp;
}

bool check(vector<vector<int> > &map){
    for(int i= key_size ; i<key_size+lock_size; i++){
        for(int j= key_size; j<key_size+lock_size; j++){
            if(map[i][j]!=1) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    key_size = key.size();
    lock_size = lock.size();
    allsize = 2*key_size+ lock_size;
    vector< vector<int> > map(allsize, vector<int>(allsize));
    for(int i= 0; i<lock_size; i++){
        for(int j = 0; j<lock_size; j++){
            map[i+key_size][j+key_size] = lock[i][j];
        }   
    }
    vector< vector< pair<int,int> > > keys;

    keys.push_back(print_v(key));
    for(int i=0; i<3; i++){
        key = turn(key);
        keys.push_back(print_v(key));
    }
    for(int k =0 ; k<keys.size(); k++){
        for(int i=0; i<=key_size+lock_size; i++){
            for(int j=0; j<=key_size+lock_size; j++){
                for(int g=0; g<keys[k].size(); g++){
                    pair<int,int> a = keys[k][g];
                    int x = a.first + i;
                    int y = a.second + j;
                    if(map[x][y]==0){
                        map[x][y] =1;
                    }else{
                        map[x][y] =2;
                    }
                }
                if(check(map)) return true;
                for(int g=0; g<keys[k].size(); g++){
                    pair<int,int> a = keys[k][g];
                    int x = a.first + i;
                    int y = a.second + j;
                    if(map[x][y]==2){
                        map[x][y] =1;
                    }else if(map[x][y] ==1){
                        map[x][y] = 0;
                    }
                }
            }
        }
    }
    return answer;
}
