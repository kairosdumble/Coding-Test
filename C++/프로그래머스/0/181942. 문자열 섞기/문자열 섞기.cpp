#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string str1, string str2) {
    string answer (str1.size() + str2.size(), ' ');
    for(int i = 0 ; i < str1.size()*2 ; i +=2 ){
        answer[i] = str1[i/2];
        answer[i+1] = str2[i/2];
        
    }
    cout << answer << '\n' ; 
    return answer;
}