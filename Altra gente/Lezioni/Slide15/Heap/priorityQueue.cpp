#include <iostream>
#include <queue>

using std::priority_queue;
using std::cout;

int main(){

    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(1);

    cout << "pq.size() : " << pq.size() << "\n";
    cout << "pq.top() : " << pq.top() << "\n";
    cout << "We can use a priority qeue to sort: -->>\n";
    while(!pq.empty()){
        cout << pq.top() << "\t";
        pq.pop();
    }
    cout << "\n";
    return 0;
}
