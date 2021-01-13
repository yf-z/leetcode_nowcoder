class Solution {
public:
    vector<int> stack;
    vector<int> order;

    void push(int value) {
        stack.push_back(value);
        order.push_back(value);
        sort(order.begin(), order.end());
    }
    void pop() {
        if (stack.size() > 0) {
            if (stack.back() == order.front()) {
                stack.pop_back();
                order.erase(order.begin());
            }
            else {
                stack.pop_back();
                order = stack;
                sort(order.begin(), order.end());
            }
        }
    }
    int top() {
        return stack.back();
    }
    int min() {
        return order.front();
    }
};