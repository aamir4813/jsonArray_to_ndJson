/*
	Convert your json object to ndJson to load in Elastic Search Cluster or Kibana
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll id;
void doSome(string &a){
    int n = a.size();
    stack<char> s;
    string temp = "";
    bool here = false;
    int button = 0;
    ll i = 0;
    for(auto x : a){
        if(s.empty() and (x == ',' or x == ' ')){
            continue;
        }
        temp += x;
        if(x == '\"' and  a[i-1] != '\\' ){
            button = 1-button;
        }
        if(x == '{' and button == 0){
            s.push(x);
        }
        else if(x == '}'){
            if(button == 0){
                s.pop();
            }
        }
        if(s.size() == 0 ){
            cout << "{\"index\" : {\"_index\" : \"movies\" , \"_type\" : \"movie\" , \"_id\" :" << id++ <<" }}" << endl;
            cout << temp << endl;
            temp = "";
        }
        ++i;
    }
}

int main(){
    string s;
    // cin >> s;
    getline(cin, s);
    id = 1;
    doSome(s);

}
