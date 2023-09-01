// #include<array>

// array<int,4> a={1,2,3,4};
// int size=a.size();
// bool empyty=a.empty()=>whether the array is empty or not
// char at index int b=a.at(index)
// a.front()
// a.back()

// #include<vector>

// vector<int> a;
// vector<int> a(5,1); =>initialize every element with 1 with a size of 5
// vector<int> b(a)=>copies vector a to b
// a.capacity()=> gives the amount of memory allocated to the vector
// a.push_back(no.)=> appends
// a.pop_back()=> pops
// a.at(index)=> returns the no. at that place
// a.size()=>gives the no. of element present in the vector
// a.front()=>gives the front element of vec.
// a.back()=>gives the back of the vec.
// a.clear()=>makes the size of vector 0
// a.begin()=>start elemnt iterator
// a.end()=>end element iterator

// #include<deque>

// no continuos memory allocation
// can perform push and pop operations at both ends
// dynamic
// deque<int> d;
// d.push_back();
// d.pop_back()
// d.push_front()
// d.empty()
// d.size()
// d.erase(d.begin(),d.begin()+2)


// #include<list>
// list<int> l(5,100);
// doubly linked list se hoti hai implementation
// l.push_back()
// l.push_front()
// begin()
// empty()
// back()
// erase()
// end()


// #include<stack>
// stack<datatype> s;
// s.push();
// s.top()
// s.pop()
// s.size()
// s.empty()

// #include<queue>
// queue<datatype> s;
// s.push();
// s.front()
// s.pop()
// s.size()
// s.empty()



// #include<queue>

// priority_queue<int> a;=>max heap priority queue

// priority_queue<int,vector<int>, greater<int>> mini;=>for min heap priority queue

// a.push()
// a.top()
// a.pop()
// a.size()


// #include<set>
// takes only unique elements
// returns elements in sorted order
// set<int> s;
// s.insert(int)
// s.erase()
// s.begin()
// s.end()
// s.size()
// s.count(element)=>tells wether the element is present
// set<int>::iterator itr=s.find(element)=> gives the reference of the iterator for that element 
// cout<<*it;


// #include<map>

// stores data in the form of key-value pairs

// all keys are unique and all the keys can point to only one value 
// which means a key has only one value but a value can have multiple same keys

// map<int,string> m;

// m[1]="aditya";
// m[2]="pandey";
// ordered map returns keys in sorted order
// unordered map doesnt
// same with set
// m.count(key)
// m.erase(key)
// find erase insert count has time comp of log n for ordered map but for unordered one it o(1) because 
// unordered map is implemented using hash table whereas the ordered one is done using balanced tree


// for alogorithms

// #include <algorithm>

// binary_search(v.begin(),v.end(),element);
// lower_bound(v.begin(),v.end(),number)
// upper_bound(v.begin(),v.end(),number)
// max(a,b)
// min(a,b)
// reverse(s.begin(),s.end())
// rotate(vector.begin(),vector.begin()+n,v.end())

// sort(v.begin(),v.end())=> cobo of 3 sorting=>quick,heap,insertion known as intro sort
// swap(a,b)

