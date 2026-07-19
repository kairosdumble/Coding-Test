#include <string>
#include <vector>
using namespace std;
vector<vector<int>> answer;

void move(int n, int from, int to, int bet){
    if(n == 1) {
        answer.push_back({from, to});
        return;
    }
    
    move(n-1,from,bet,to);
    
    answer.push_back({from, to});
    
    move(n-1,bet,to,from);
}

vector<vector<int>> solution(int n) {
    move(n, 1,3,2);
    return answer;
}