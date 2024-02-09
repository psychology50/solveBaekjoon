#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

typedef unsigned long long ull;
using namespace std;

int main(){
    ull a, b, c; scanf("%llu%llu",&a, &b);
    if(b%2) c = b/2 + 1;
    else c = b/2;
    vector<ull> v;
    string s = "";
    vector<ull>::iterator iter = v.end();
    while(v.size() <= 60){
    	
        vector<ull>::iterator t = find(v.begin(), v.end(), a);
    	if(t != v.end()){
            iter = t;
            break;
        }
        else v.push_back(a);
        
        if(a >= c) s += "*";
        else s += "-";
        if(a > b){
        	a -= b;
        	a *= 2;
        }
        else{
        	a = b-a;
        	if(b >= 2*a) a = b-2*a;
        	else a = b - 2*a + b;
        }
    }
    if(iter == v.begin()) printf("%s\n",s.c_str());
    else printf("-1\n");
    
    return 0;
}