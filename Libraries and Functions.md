C++ Libraries and Usages
------------------------
------------------------

Iostream
--------


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

List
----

Map
---

Algorithm
---------


