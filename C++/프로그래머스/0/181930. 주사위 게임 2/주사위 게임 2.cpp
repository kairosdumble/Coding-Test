#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int a, int b, int c) {
    if( a == b && b == c){
        return 27 * pow(a,6);
    }else if((a==b && b!=c) || (a==c && a!=b) || (b==c && a!=b)){
        return (a+b+c) * (a*a +b*b+c*c);
    }
    else{
        return a+b+c;
    }
}