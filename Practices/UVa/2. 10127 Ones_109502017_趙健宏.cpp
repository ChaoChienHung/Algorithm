#include <iostream>

using namespace std;

int main(){
    int input, digit, div;
    while(cin>>input){
        digit = div = 1;
        while(div % input != 0){
            div %= input;
            div *= 10;
            div += 1;
            digit++;
        }
        cout<<digit<<endl;
    }
    return 0;
}