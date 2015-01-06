C++ Libraries and Usages
------------------------
------------------------

Iostream
--------

cstdio
------
1. Input from file via stdin
freopen(FILENAME, "r", stdin)


string
------
string str;

1. String length
str.length()

2. Get string till new line
getline(cin, str)

3. Int to string
to_string(int)

Cstring
-------
char *s; #null terminated string

1. String length
strlen(s);

2. initialize string/array
memset(int *ptr, value, sizeof(ptr))
	ex. memset(myarr, 0, sizeof(myarr))


climits
-------
INT_MAX		#Constant
INT_MIN		#Constant

cmath
-----
1. Absolute of number
abs(INT)

2. Max of two number
max(a, b);

stack
-----
stack<int> s;

1. Push
s.push(INT)

2. Pop
s.pop()

3. Top Element
INT = s.top()

4. Check if stack is empty
BOOL = s.empty()

5. Size of stack
INT = s.size()

6. Swap two stack
s.swap(s1)

queue
-----
queue<int> q;

1. Push
q.push(INT)

2. Pop
q.pop()

3. Front Element
INT = q.front()

4. Back Element
INT = q.back()

5. Check if stack is empty
BOOL = q.empty()

6. Size of stack
INT = q.size()

7. Swap two queue
q.swap(q1)

priority_queue
--------------
priority_queue<int> pq;

1. Push
pq.push(INT)

2. Pop
pq.pop()

3. Top Element
INT = pq.top()

4. Check if stack is empty
BOOL = pq.empty()

5. Size of stack
INT = pq.size()

6. Swap two stack
pq.swap(pq1)

Vector
------
vector<type> vec (n)    #initialize n elements with 0

1. Size of vector
vec.size()

2. Push element at back
vec.push_back()

3. Pop element from back
vec.pop_back()

4. Return vector iterator of begining
vector<type>::iterator it = vec.begin()

5. Return vector iterator of end
vector<type>::iterator it = vec.end()

6. check if vector is empty
vec.empty()

7. Access front element
vec.front()

8. Access back element
vec.back()

9. Resize or set size of vector
vec.resize(WIDTH)

List
----
list<type> my

1. Size of vector
my.size()

2. Push element at back
my.push_back()

3. Push element at front
my.push_front()

4. Pop element from back
my.pop_back()

5. Pop element from back
my.pop_back()

6. Return list iterator of begining
list<type>::iterator it = my.begin()

7. Return list iterator of end
list<type>::iterator it = my.end()

6. check if vector is empty
my.empty()

7. Access front element
my.front()

8. Access back element
my.back()

9. Insert element
my.insert(it, VALUE)

10. Remove element
my.remove(VALUE)

11. Sort element
my.sort()       # put Upper Case obove than lower case

12. Merger elements
my.merge(my1)


Map
---
map<key, type> my

1. Size of map
my.size()

2. Return map iterator of begining
map<key, type>::iterator it = my.begin()

3. Return map iterator of end
map<key, type>::iterator it = my.end()

4. Insert elements
my.insert(pair<key, type>(KEY, VALUE));
my[KEY] = VALUE;

5. Clear all the pair
my.clear();

6. Erase element having key
it = my.find(KEY)
my.erase(it)

7. check if map is empty
my.empty()

8. Size of map
my.size()

9. Max size a map can hold
my.max_size()

10. Find element
it = my.find(KEY)

Algorithm
---------

yr()=5