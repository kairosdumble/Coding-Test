#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(),greater<int>());
    
    for(int h = citations[0] ; h>=0 ; h--){
        for(int i = 0 ; i < citations.size() ; i++){
            if(citations[i] >= h&&  i >=h-1 && citations[i+1]<=h){
                return h;
            }
        }
    }
}