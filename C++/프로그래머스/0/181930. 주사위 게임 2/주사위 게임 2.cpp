#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

int solution(int a, int b, int c) {
    set<int> s{a,b,c};
    if(s.size() == 1){
        return 27 * pow(a,6);
    }else if(s.size() == 2){
        return (a+b+c) * (a*a +b*b+c*c);
    }
    else{
        return a+b+c;
    }
}