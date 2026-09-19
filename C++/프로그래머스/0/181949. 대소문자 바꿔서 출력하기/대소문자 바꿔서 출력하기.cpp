#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for(int i = 0 ; i <str.size() ; i ++){
        if(65<=str[i] && str[i] <= 90 ){
            str[i] += 32;
            continue;
        }
        if(97<= str[i] && str[i] <=122){
            str[i] -= 32;
        }
    }
    cout << str;
    return 0;
}