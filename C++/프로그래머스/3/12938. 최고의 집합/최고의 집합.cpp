#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    
    vector<int> answer;
    
    if(s<n) answer.push_back(-1);
    else{
        for(int i =0 ; i<n ; i ++){
            answer.push_back(s/n);    
        }
        for(int i =n-1; i >= n-s%n ; i--){
            answer[i] +=1;
        }
    }

    return answer;
}