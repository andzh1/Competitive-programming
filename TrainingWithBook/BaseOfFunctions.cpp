#include <bits/stdc++.h>
using namespace std; 
#define loop(a,b) for(int i = a; i < b; i++)


int main(){
    //ARRAY
    int arrayA[] = {1,2,3,4,5};
    int arrayB[] = {5,3,1,2,4};
    
    sort(arrayB, arrayB+5); //makes arrayB[] increasing
    
    swap(arrayA[0], arrayA[4]); //swaps arrayA[0] & arrayA[4]

    //VECTOR
    vector<int> vectorA = {1, 3, 2, 7, 4, 6, 5};
    
    vector<int> vectorB(6,0);// all 6 elements of vectorB = 0
    
    int i = vectorA.size();//finds size of vectorA
    
    i = vectorA.back();//i = last element of vector
    
    sort(vectorA.begin(), vectorA.end()); //makes vectorA increasing
    
    sort(vectorA.rbegin(), vectorA.rend()); //makes vectorA decreasing

    reverse(vectorA.begin(), vectorA.end());//reverses vectorA
    
    vectorA.push_back(8); //puts 8 in the end of vectorA
    
    vectorA.pop_back(); //removes last element of vectorA
    
    for(auto i:vectorA){
        cout << i;
    }//outputs all vectorAs' elements
    
    //DEQUE
    deque <int> dequeA;
    dequeA.push_back(5);//[5]
    dequeA.push_front(2);//[2,5]
    dequeA.pop_back();//[2]
    dequeA.push_back(5);//[2,5]
    dequeA.pop_front();//[5]

    //STACK
    stack <int> stackA;
    stackA.push(2);//[2]
    stackA.push(5);//[2,5]
    
    cout << stackA.top();// 5

    stackA.pop();// [2]

    //QUEUE
    queue <int> queueA;
    queueA.push(2);// [2]
    queueA.push(5);// [2,5]

    cout << queueA.front();// 2
    cout << queueA.back();// 5
    queueA.pop();//[5]

    //SET
    set <int> setA;
    
    setA.insert(3);//add "3" to setA
    
    cout << setA.count(3);//outputs amount of "3" int setA =1
    
    setA.erase(3);//deletes "3" from setA
    
    // In sets all elements are different, so if setA includes "3", setA.count(3) = 1, and if not - setA.count() = 0
    // In sets all elements are already sorted
    
    cout << setA.size();//outputs size of setA

    for(auto x : setA){
        cout << x;
    }//outputs all elements of setA

    auto it = setA.find(3);//tries to find "3" in setA
    if(it == setA.end()){
        //there is no "3" in setA (if setA doesn't contain "3", setA.find() will return end())
    }
    
    auto first = setA.begin();//position of first & smallest element of setA
    auto last = setA.end(); last--;//position of largest element of setA; [last--;] - because end() points on position, which is after position of the last element

    cout << *setA.lower_bound(4);//returns minimun element of setA, which is bigger than 4 or equals to 4
    cout << *setA.upper_bound(4);//returns minimun element of setA, which is bigger than 4

    //MULTISET
    multiset <int> multisetA;
    multisetA.insert(5);//[5]
    multisetA.insert(5);//[5, 5]

    multisetA.erase(5);//deletes all elements from multisetA, which are equal to 5
    multisetA.count(5);
    multisetA.erase(multisetA.find(5));//deletes only 1 element, which is equal to 5

    //MAP
    map <string, int> mapA;
    mapA["monkey"] = 3;
    cout << mapA["monkey"];//3
    cout << mapA["qq"];//element called "qq" automatically adds to mapA with value of 0; this string of code outputs "0"

    if(mapA.count("qq")){
        //we can find "qq" in mapA as a key
    }

    for(auto x: mapA){
        cout << x.first << " " << x.second;
    }//outputs all elements of maPA

    //PRIORITY_QUEUE - smth more on page 76

    priority_queue <int> priority_queueA;
    priority_queueA.push(3);//adds 3 to priority_queueA
    priority_queueA.push(7);
    priority_queueA.push(5);
    priority_queueA.push(2);
    
    cout << priority_queueA.top();//outputs max element of priority_queueA =7

    priority_queueA.pop();//deletes maximum element of priority_queueA

    //policy-based structure - page 76

    //BITSET
    bitset <5> bit; // 5 - length of bitset
    bit[1] = 7497; //{b[1] = x, x != 0} ==> {b[1] = 1;}
    bitset<10> a;
    a.flip(); //reverse all elements
    a.set(); //all are true now
    a.reset(); //all are false now
    a.flip(1); //reverse 1st element
    a.count(); //counts all true elements
    cout << a[4]; //cout 4th element
    bit.count();//counts amount of "1" in bit

    //FILES
    freopen("input.txt", "r", stdin);//now we can read inputs from "input.txt" like we are reading them with stdin
    freopen("output.txt", "w", stdout);//now we can output in "output.txt" like we are printing them with stdout

    //INTEGER
    int intA = INT_MAX;// makes intA equal to maximum possible integer value
    int intB = INT_MIN;// makes intB equal to minimum possible integer value
    intB = 2;
    int a = 1<<4;
    
    __builtin_popcount(intA);//counts amount of "1" in binary representation of intA
    
    intA = 1 << intB;//intA = 2^intB;

    //STRING
    string stringA = "monkey";
    
    sort(stringA.begin(), stringA.end());
    stringA.find(',');
}
