#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>

using namespace std;

bool is_clear(string t){
    for(int i=0;i<t.size();i++){
        if(t[i]!='.')
            return false;
    }
    return true;
}

string erase_alpha(string next, char c){
    
    for(int i=0;i<next.size();i++){
        if(next[i]==c)
            next[i] = '.';
    }
    return next;
}

string erase_col(string next, int col){
    
    for(int i=0;i<4;i++){
        next[col + i*4]='.';
    }
    return next;
}

string erase_row(string next, int row){
    for(int i=0;i<4;i++){
        next[row*4 +i] ='.';
    }
    return next;
}

bool find_answer(string matrix){
    map<string, int> state;
    queue<string> mat;
    string cur_mat;
    int cnt=0;

    mat.push(matrix);
    state[matrix]=0;

    while(!mat.empty()){
        cur_mat = mat.front();
        mat.pop();

        cout<<state[cur_mat]<<endl;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cout<<cur_mat[i*4+j];
            }
            cout<<endl;
        }
        cout<<endl;

        if(is_clear(cur_mat) && state[cur_mat] % 2){
            return state[cur_mat];
        }
            
        for(int i=0;i<6;i++){
            string next = erase_alpha(cur_mat, 'a'+i);
            if(state.find(next)==state.end()){
                state[next]=state[cur_mat]+1;
                mat.push(next);
            }
        }
        for(int i=0;i<4;i++){
            string next = erase_row(cur_mat, i);
            if(state.find(next)==state.end()){
                state[next]=state[cur_mat]+1;
                mat.push(next);
            }
            next = erase_col(cur_mat, i);
            if(state.find(next)==state.end()){
                state[next]=state[cur_mat]+1;
                mat.push(next);
            }
        }
    }
    return 0;
}

int main(){
    string square;
    string temp;
    for(int i=0;i<4;i++){
        cin>>temp;
        square +=temp;
    }

    if(find_answer(square) % 2){
        cout<<"win";
    }
    else{
        cout<<"lose";
    }

}