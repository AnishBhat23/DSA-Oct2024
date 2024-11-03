#include<bits/stdc++.h>
using namespace std;

void print()
{
    cout << "ANish";
}

int sum(int a, int b)
{
    return a+b;
}

void explainPair()
{
    pair<int,int> p = {1,3};
    cout << p.first << " " << p.second << endl;
    pair<int, pair<int,int>> q = {1,{3,4}};
    cout << q.first << " " << q.second.second << " " << q.second.first << endl; 
    pair<int,int> arr[] = {{1,2},{3,4},{5,6}};
    cout << arr[1].second << endl;
}

void explainVector()
{
    vector<int> v;

    v.push_back(1);
    v.emplace_back(2);
    v.emplace_back(3);
    v.emplace_back(4);
    v.emplace_back(5);
    v.emplace_back(6);

    vector<pair<int,int>>vec;

    vec.push_back({1,2});
    vec.emplace_back(1,2);

    vector<int> v1(5,100);

    vector<int> v2(5);

    vector<int> v3(5,20);
    vector<int> v4(v1);

    vector<int>::iterator it = v.begin();

    it++;
    cout << *(it) << endl;

    it = it+2;
    cout << *(it) << endl;

    vector<int>::iterator it1 = v.end();
    //vector<int>::iterator it2 = v.rend();
    //vector<int>::iterator it3 = v.rbegin();
    
    cout << v[0] << " " << v.at(0) << endl;

    cout << v.back() << endl;

    for(vector<int>::iterator it4 = v.begin(); it4 != v.end(); it4++)
    {
        cout << *(it4) << " ";
    }
    cout << endl;

    for(auto it5 = v.begin(); it5 != v.end(); it5++)
    {
        cout << *(it5) << " ";
    }
    cout << endl;

    for(auto it6: v)
    {
        cout << it6 << " ";
    }
    cout << endl;

    v.erase(v.begin()+1);

    v.erase(v.begin() + 2, v.begin() + 4);

    for(auto it6: v)
    {
        cout << it6 << " ";
    }
    cout << endl;

    vector<int> v5(2,100);
    v5.insert(v5.begin(), 300);
    v5.insert(v5.begin() + 1, 2, 10);
    
    vector<int> copy(2, 50);
    v5.insert(v5.begin(), copy.begin(), copy.end());

    cout << v5.size() << endl;

    v5.pop_back();

    v1.swap(v2);

    v5.clear();

    cout << v5.empty() << endl;
}


void explainList()
{
    list<int> ls;

    ls.push_back(2);
    ls.emplace_back(4);

    ls.push_front(5);
    ls.emplace_front(6); //{};

    for(auto it7 : ls)
    {
        cout << it7 << " ";
    }
    cout << endl;
}

void explainDeque()
{
    deque<int>dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(4);
    dq.emplace_front(3);

    dq.pop_back();
    dq.pop_front();

    dq.back();
    dq.front();
}

void explainStack() //LIFO
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(3);
    st.emplace(5);
    
    cout << st.top() << endl;

    st.pop();

    cout << st.top() << endl;

    cout << st.size() << endl;

    cout << st.empty() << endl;

    stack<int> st1, st2;

    st1.swap(st2);
}


void explainQueue() //FIFO
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(4);

    q.back() += 5;

    cout << q.back() << endl;

    cout << q.front() << endl;

    q.pop();

    cout << q.front() << endl;

    //size swap empty same as stack
}

void explainPQ()
{
    priority_queue<int> pq;

    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10);

    cout << pq.top() << endl;

    pq.pop();

    cout << pq.top() << endl;

    //size swap empty function same as others

    //Min heap
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(5);
    pq1.push(2);
    pq1.push(8);
    pq1.emplace(10);

    cout << pq1.top() << endl;

    //push -> O(log(n))
    //top  -> O(1)
    //pop  -> O(log(n))
}

void explainSet()
{
    set<int> st;
    st.insert(1);
    st.emplace(2);
    st.insert(2);
    st.insert(4);
    st.insert(3); //{1,2,3,4} 

    //Everything is sorted and only unique elements are stored

    //begin, end, rbegin, rend, size, empty and swap are same as those of above

    auto it = st.find(3);

    auto it1 = st.find(6);

    st.erase(5); //takes logarithmic time

    int cnt = st.count(1);

    auto it2 = st.find(3);
    st.erase(it2); // takes constant time

    auto it3 = st.find(2);
    auto it4 = st.find(4);

    st.erase(it3,it4);

    //lower_bound() and upper_bound() function works the same way

    auto it5 = st.lower_bound(2);
    auto it6 = st.upper_bound(3);
    
}

void explainMultiSet()
{
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);

    //ms.erase(1);

    int cnt = ms.count(1);

    ms.erase(ms.find(1));

    for(auto it : ms)
    {
        cout << it << " ";
    }
    cout << endl;

    ms.erase(ms.find(1));

    for(auto it : ms)
    {
        cout << it << " ";
    }
    cout << endl;

    //rest all functions same as set
}

void explainUSet()
{
    unordered_set<int> st;

    // lower_bound and upper_bound does not work
    // rest all functions are same as above
    // does not store in any particular order
    // better complexity than set in most cases except when collision happens

    //time complexity is O(1) usually, worst case is O(n)
}

void explainMap()
{
    map<int, int> mpp;
    map<int, pair<int, int>> mpp1;
    map<pair<int, int>, int> mpp2;

    mpp[1] = 2;
    mpp.emplace(3,1);

    mpp.insert({2,4});

    //map stores unique keys in sorted order

    mpp2[{2,3}] = 10;

    for(auto it: mpp)
    {
        cout << it.first << " " << it.second << endl;
    }

    cout << mpp[1] << endl;
    cout << mpp[5] << endl;

    auto it2 = mpp.find(3);
    cout << it2->second << endl;

    auto it3 = mpp.find(5);

    auto it4 = mpp.lower_bound(2);
    auto it5 = mpp.upper_bound(3);

    // erase, swap, size, empty, are same as above
    // O(log(n))
}

void explainMultiMap()
{
    // everything same as map, only it can store multiple duplicate keys
    // only mpp[key] cannot be used here
}

void explainUnorderedMap()
{
    // same as set and unordered_set difference
    // O(1) to O(n)
}

bool comp(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.second < p2.second)
        return true;
    if(p1.second > p2.second)
        return false;
    // if same
    if(p1.first > p2.first)
        return true;
    return false;
}

void explainExtra()
{
    //sort(a, a+n);  //sort from a to a+n
    //sort(v.begin(), v.end());

    //sort(a+2, a+4);

    //sort(a, a+n, greater<int>); //sort in descending order

    pair<int,int> a[] = {{1,2}, {2,1}, {4,1}};

    // sort it according to second element
    // if second element is same then sort according to first element but in descending

    sort(a, a+3, comp);

    int num = 7;
    int cnt = __builtin_popcount(num);
    cout << cnt << endl;

    long long num2 = 165786578687;
    int cnt2 = __builtin_popcountll(num2);
    cout << cnt2 << endl;

    string s = "123";

    do
    {
        cout << s << endl;
    }while(next_permutation(s.begin(),s.end()));

    //int maxi = *max_element(a, a+n); // returns the iteratore to max element.

}

int main()
{
    int a,b,c;
    cin >> a >> b;
    c = sum(a,b);
    //cout << c;
    //explainPair();
    //explainVector();
    //explainList();
    //explainQueue();
    //explainPQ();
    //explainMultiSet();
    //explainMap();
    explainExtra();

    return 0;
}