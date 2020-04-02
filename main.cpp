#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int dif(int a, int b){
    int d = a -b;
    if(d < 0)
        d *= -1;

    return d;
}



vector<int> format(vector<int> &is, int umf){
    vector<int> NewD;
    int med = umf/2;
    for(auto b = is.begin(); b != is.end(); b++){
            if((*b) > med){
               NewD.push_back((-1) * dif(umf, *b));

            }else {
                NewD.push_back(*b);
            }
    }
    return NewD;

}


int main() {

    int umf, houses;
    cin >> umf >> houses;
    vector<int> h;
    for (int i = 0; i < houses; ++i) {
        int a;
        cin >> a;
        h.push_back(a);
    }

    vector<int> v =  format(h, umf);

    vector<int> dists;
    for(auto b = v.begin(); b != v.end(); b++){
        int before =0;
        int then = 0;
        if(b == v.begin()){
           before = *v.end();
        } else{
       //  then = *(b+1);
        }

        if(b == v.end()){
          then = *v.begin();
        } else{
     //     before = *(b-1);
        }

        dists.push_back(dif(*b, then) );
        dists.push_back(dif(*b, before) );

    }
    long dist = 0;
    for(auto b = dists.begin(); b != dists.end(); b++) {
        dist += *b;
    }
    dist /= 2;
    dist -= *max_element(dists.begin(), dists.end());
    cout << dist;


    return 0;
}
