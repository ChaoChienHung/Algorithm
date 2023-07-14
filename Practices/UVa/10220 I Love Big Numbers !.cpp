#include <iostream>

using namespace std;

int main(){
    int input, digit, dp[1001], ans[3000], max;
    max = ans[0] = dp[1] = dp[0] = digit = 1;
    while(cin>>input){
        if(input<max) cout<<dp[input]<<endl;
        else{
            for(int i=max+1;i<=input;i++){
                dp[i] = 0;
                for(int j=0;j<digit;j++){
                    ans[j]*=i;
                }
                for(int j=0;j<digit;j++){
                    if(ans[j]>9){
                        if(j==digit-1){
                            ans[digit++] = ans[j]/10;
                        }
                        else{
                            ans[j+1] += ans[j]/10;
                        }
                        ans[j]%=10;
                    }
                    dp[i] += ans[j];
                }
            }
            max = input;
            cout<<dp[input]<<endl;
        }
    }
    return 0;
}
