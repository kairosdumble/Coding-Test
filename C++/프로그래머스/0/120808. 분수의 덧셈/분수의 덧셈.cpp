#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b){
    int temp;
    while(a != 0){
        temp = b;
        b = a;
        a = temp % a;
    }
    return b;
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector <int> answer;
    answer.push_back(numer1 * denom2 + numer2 * denom1);
    answer.push_back(denom1 * denom2);
    int gcd = GCD(answer[0], answer[1]);
    
    return {answer[0]/gcd, answer[1]/gcd};
}