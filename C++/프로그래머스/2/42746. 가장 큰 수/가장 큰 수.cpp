#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string&b){
    return a+b > b+a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector <string> v;
    for(auto number : numbers){
        v.push_back(to_string(number));
    }
    sort(v.begin(),v.end(),compare);
    
    for(const string& s:v){
       answer += s;
    }
    
    if(v[0] == "0"){
        return "0";
    }
        
    return answer;
}