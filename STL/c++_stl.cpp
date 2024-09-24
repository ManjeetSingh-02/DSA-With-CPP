#include <bits/stdc++.h>
using namespace std;

void pairs()
{
    pair<int, int> p1 = {1, 3};                 // -----------------> (0)1 and (1)3
    pair<int, pair<int, int>> p2 = {1, {2, 3}}; // ----------> (0)1 and [1(0)2 and 1(1)3]
    pair<int, int> arr[] = {{1, 2}, {3, 4}};    // ----------> [0(0)1 and (1)2] and [1(0)3 and (1)4]
}

void vectors()
{
    vector<int> v1;
    v1.push_back(2);    //--------------------> {2}
    v1.emplace_back(1); // ----------------> {2, 1}

    vector<pair<int, int>> v2;
    v2.push_back({5, 6});  // Takes pair as {} -----------> {{5,6}}
    v2.emplace_back(7, 8); // Automatically assumes as pair -----------> {{5,6}, {7,8}}

    vector<int> v3(5, 100); // 5 instances of 100 created --------> {100, 100, 100, 100, 100}
    vector<int> v4(5);      // 5 instances of 0 created --------> {0, 0, 0, 0, 0}
    vector<int> v5(v4);     // copy v4 into v5

    // ITERATORS
    vector<int> v6(5, 10);
    vector<int>::iterator it1 = v6.begin(); // address of first element of vector
    // it1++; -------------------> iterate over a vector
    // cout << *(it1) << endl; --> element at that address
    // v6.end(); ----------------> address after the last element of vector
    // v6.rend(); ---------------> address before first element of vector
    // v6.rbegin(); -------------> address of last element of vector

    // v[0] == v.at(0)
    // v.back() == last element of vector

    vector<int> v7 = {10, 20, 30, 40, 50};
    for (vector<int>::iterator it = v7.begin(); it != v7.end(); it++)
        cout << *(it) << endl;
    for (auto it = v7.begin(); it != v7.end(); it++)
        cout << *(it) << endl;
    for (auto it : v7)
        cout << it << endl;

    // DELETE
    v7.erase(v7.begin());                 // --------> only deletes the value of the address pointed
    v7.erase(v7.begin(), v7.begin() + 3); // ---------> deletes the start but not end = [start, end)

    // INSERT
    vector<int> v8(2, 10);       // -----------> {10, 10}
    v8.insert(v8.begin(), 20);   // -------> {20, 10, 10}
    v8.insert(v8.begin(), 2, 5); // -----> {5, 5, 20, 10, 10}
    // v8.size() ------------------------> 5
    v8.pop_back(); // -------------------> takes last element out {5, 5, 20, 10}
    // v9 ---> {10, 20}
    // v10 --> {30, 40}
    // v9.swap(v10); --------------------> v9{30, 40} and v10{10, 20}
    // v8.empty() -----------------------> tells if empty or not
}

void lists()
{
    list<int> ls;
    ls.push_back(2);     // ---------> {2}
    ls.emplace_back(4);  // ---------> {2, 4}
    ls.push_front(3);    // ---------> {3, 2, 4}
    ls.emplace_front(5); // ---------> {5, 3, 2, 4}
    // begin, end, rbegin, rend, clear, insert, size, swap
    // same as vector
}

void stacks()
{
    stack<int> st;
    st.push(1);    // ---------> {1}
    st.push(2);    // ---------> {2, 1}
    st.push(3);    // ---------> {3, 2, 1}
    st.emplace(5); // ---------> {5, 3, 2, 1}
    st.top();      // prints 5
    st.pop();      // removes last element inserted from stack
    st.size();     // prints size of stack
    st.empty();    // tells stack is empty or not

    stack<int> stx;
    stx.swap(st); // swap two stacks
}

void queues()
{
    queue<int> q;
    q.push(1);    // ---------> {1}
    q.push(2);    // ---------> {1, 2}
    q.push(3);    // ---------> {1, 2, 3}
    q.emplace(5); // ---------> {1, 2, 3, 5}
    q.front();    // prints first element i.e. 1
    q.back() += 3;
    // {1, 2, 3, 8}
    q.back(); // prints last element i.e. 8
    q.pop();  // remove first element

    // size, swap, empty
    // same as stack
}

void pqueues()
{
    priority_queue<int> pq; // MAXIMUM PRIORITY QUEUE
    pq.push(2);             // ---------> {2}
    pq.push(5);             // ---------> {5, 2}
    pq.push(8);             // ---------> {8, 5, 2}
    pq.emplace(3);          // ---------> {8, 5, 3, 2}
    pq.top();               // prints first element --> 8
    pq.pop();               // remove first element

    priority_queue<int, vector<int>, greater<int>> pqx; // MINIMUM PRIORITY QUEUE
    pqx.push(2);                                        // ----------> {2}
    pqx.push(5);                                        // ----------> {2, 5}
    pqx.push(8);                                        // ----------> {2, 5, 8}
    pqx.emplace(10);                                    // ------> {2, 5, 8, 10}
    pq.top();                                           // prints first element --> 2
}

void sets()
{
    set<int> s; // SORTED and UNIQUE
    s.insert(1);
    s.insert(2);
    s.emplace(3);

    // begin(), end(), rend(), rbegin(), size(), swap(), empty() are same

    auto it = s.find(3); // returns iterator which points to the element
    auto it = s.find(6); // if not found, always return s.end();
    s.erase(3);          // removes 3
    s.count(3);          // gives occurence of `3` = 1
    auto it = s.find(3);
    s.erase(it);
    auto it1 = s.find(2);
    auto it2 = s.find(3);
    s.erase(it1, it2); // erase as [start, end)
    auto it = s.lower_bound(2);
    auto it = s.upper_bound(3);
}

void multisets()
{
    multiset<int> ms;        // only SORTED and NOT UNIQUE
    ms.insert(1);            // {1}
    ms.insert(1);            // {1, 1}
    ms.emplace(1);           // {1, 1, 1}
    ms.erase(1);             // remove all occurences of `1`
    int count = ms.count(1); // count no of `1`
    ms.erase(ms.find(1));    // remove one occurence of `1`

    // rest functions are same as set
}

void unorderedsets()
{
    unordered_set<int> us; // only UNIQUE and NOT SORTED

    // upper_bound and lower_bound don't work, rest all are same
    // no order of storing
}

void maps()
{
}

int main()
{
    pairs();
    vectors();
    lists();
    stacks();
    queues();
    pqueues();
    sets();
    multisets();
    unorderedsets();
    maps();
    return 0;
}