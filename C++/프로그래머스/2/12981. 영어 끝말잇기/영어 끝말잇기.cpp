#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_set<string> said_word;
    for(int i =0;i< words.size();i++){
        if(!said_word.insert(words[i]).second||      // 이미 존재하는 값이거나
          (i>0 && (words[i-1].back() != words[i].front()))){
              return {i%n +1, i/n+1};
          }
    }
    return {0,0};
}