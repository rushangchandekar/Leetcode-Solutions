#include <stdio.h>
#include <vector>
#include <stack>
#include <iostream> 

using namespace std;

int main(){
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    vector<int> ans(price.size(), 0);
    stack<int> s;

    for(int i = 0; i < price.size(); i++) {
        // Pop elements from the stack while price is greater than or equal to the top element
        while(!s.empty() && price[s.top()] <= price[i]) {
            s.pop();
        }

        // If stack is empty, it means the current price is greater than all previous prices
        if(s.empty()) {
            ans[i] = i + 1;  // span is the index + 1
        } else {
            ans[i] = i - s.top(); // Calculate span: current index - index of last higher price
        }

        s.push(i);  // Push the current index onto the stack
    }

    // Output the result
    for(int val : ans) {
        cout << val << " ";  // Output each value in the result array
    }
    cout << endl;  // Output a newline

    return 0;
}
