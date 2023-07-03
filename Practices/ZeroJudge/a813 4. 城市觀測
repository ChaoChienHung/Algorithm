/*=================================================================================================================================================
ZeroJudge a813 4. 城市觀測
Language : C++
Source : https://zerojudge.tw/ShowProblem?problemid=a813
解題想法 : 
根據題目所述，在第 a 棟房子能看見 第 b 棟房子所需條件為第 a 棟房子與第 b 棟房子之間沒有其他房子超過 a 或 b，因此我們可以得到以下結論 : 
    1. 無論 a 是高於或矮於 b，只要 a 與 b 之間沒有比這兩棟房其中一棟高，a 即能看見 b
    2. a 若能看見 b，則 b 也能看見 a，亦即題目所求之總數一次加 2

因此，相比起將所有房子紀錄在一陣列之中，我們只需要紀錄較為高的建築物即可，因為在將一棟房子與其他房子作比較時，較矮的建築物會被較高的建築物遮住，因此不必納入考量。
比如以下圖例 :

 D      C       B      A
 __ 
|  |           __     __
|  |    __    |  |   |  |
| 4|   | 2|   | 3|   | 3|
|__|___|__|___|__|___|__|__  以此圖為例，在 A 建築物的視角裡，是不存在 B 建築物的

且由於我們是由左往又輸入建築物的高度，因此我們能由此圖觀察出我們所需要的資料結構為高度嚴格遞減的 Stack。因此，當我們輸入的建築物高度高於 myStack.top() 時，我們
需要將原先的值 pop 出，並因當前的建築物高度高於 myStack.top()，因此對於被 pop 出的建築物而言，當前的建築物為她向右看唯一能看見的房子，因此 total + 1。倘若當前
房子與 myStack.top() 高度相當，則我們可以以另外一個 Stack 紀錄，抑或是以 pair 紀錄，原因是倘若下一棟房子比前些相同高度的房子高時，對於該房子而言，這群相同高度
的房子都是看得見的，而反之亦然。最後，myStack 越底層的房子越高，因此只要 myStack 在 push 入當前房子前不為空，則意味著當前房子左方存在著比他高的建築物。而由於只
有當 a 與 b 之間沒有比這兩棟房其中一棟高，a 才能看見 b，因此實際上只有 myStack.top() 前一棟房子才看得見新 push 的房子，所以我們只要讓 total + 1 即可。因此，
我們需判斷 myStack.size() 在 push 後是否為 2，即可判斷在 push 之前是否已有房子於 myStack 之中 (亦即當前房子左邊是否有高於當前房子的建築物)，只要有，total 就
需要 + 1。最後，因為 a 若能看見 b，則 b 也能看見 a，所以total * 2。

References : 
    1. https://yuihuang.com/zj-a813/

===================================================================================================================================================

Stack 版本

=================================================================================================================================================*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long total;
    int num, height;
    stack <int> myStack, counts;

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> height;
        while (!myStack.empty() && myStack.top() < height) {
            total += counts.top();
            counts.pop();
            myStack.pop();
        }
        if (!myStack.empty() && (myStack.top() == height)) {
            total += counts.top();
            counts.top()++;
        }
        else {
            myStack.push(height);
            counts.push(1);
        }
        if (myStack.size() > 1)
            total++;
    }
    cout << total * 2 << endl;
    return 0;
}

/*=================================================================================================================================================

Pair 版本

=================================================================================================================================================*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int num, height;
    long long total = 0;
    cin >> num;
    stack<pair<int, int>> myStack;
    
    for (int i = 0; i < num; ++i) {
        cin >> height;
        while (!myStack.empty() && height > myStack.top().first) {
            total += myStack.top().second;
            myStack.pop();
        }
        if (!myStack.empty() && myStack.top().first == height) {
            total += myStack.top().second;
            myStack.top().second++;
        }
        else
            myStack.emplace(height, 1);

        if (myStack.size() > 1)
            total++;
    }
    cout << total * 2 << endl;
    
    return 0;
}
