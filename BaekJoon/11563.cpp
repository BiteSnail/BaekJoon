#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class pos{
    public:
    double x;
    double y;
    pos(double _x, double _y) : x(_x), y(_y){}
    pos() : x(0.0), y(0.0){}
    //bool operator==(const pos & ot) { return this->x == ot.x && this->y== ot.y;}
};

double dis(const pos & a, const pos & b){
    return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));
}

int main(void){
    vector<pos> sinchon;
    vector<pos> yeonahn;
    int n, m;
    double result = 99999999;
    cin>> n>> m;
    sinchon.resize(n*2);
    yeonahn.resize(m*2);
    for(int i=0;i<n*2;i++){
        cin>> sinchon[i].x >> sinchon[i].y;
    }
    for(int i=0;i<m*2;i++){
        cin>>yeonahn[i].x >> yeonahn[i].y;
    }

    for(int i=0;i<sinchon.size();i++){
        for(int j=0;j<yeonahn.size();j++){
            result = min(result, dis(sinchon[i],yeonahn[j]));
        }
    }

    cout<<result;
    return 0;
}