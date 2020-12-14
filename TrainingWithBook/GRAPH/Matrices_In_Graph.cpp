#include <bits/stdc++.h>
using namespace std; 

typedef int intType;

/* ATTENTION!
This structure (and all functions) works only for matrices with <= 1000 elements because max size of vector is 1000 */
struct matrix
{
    int width;
    int height;
    vector <intType> numbers;
    intType number(int x, int y){
        return numbers[y*width + x];
    }
    void change(int x, int y, intType f(intType)){
        numbers[y*width + x] = f(number(x, y));
    }
    /* 0-------------> Ox 
       |
       |
       |
       |
      \|/ Oy
     */
};

matrix addition(matrix A, matrix B) //Defined only for input matrices with same heights & wigths
{
    matrix answer;
    answer.height = A.height;
    answer.width = A.width;
    for(int i = 0; i < answer.height*answer.width; i++) answer.numbers.push_back(A.numbers[i] + B.numbers[i]);
    return answer;
}

matrix multiplication(matrix A, matrix B) //Defined only for input matrices with A.width = B.height; it's assotiative (A*(B*C) == (A*B)*C).
{
    matrix answer;
    answer.height = A.height;
    answer.width = B.width;
    for(int i = 0; i < answer.height*answer.width; i++) answer.numbers.push_back(0);
    for(int y = 0; y < answer.height; y++) {
        for(int x = 0; x < answer.width; x++){
            for(int i = 0; i < A.width; i++) answer.numbers[y*answer.width + x] += A.number(i, y)*B.number(x, i);
        }
    }
    return answer;
}

intType switchFlag(intType input){
    return (input == 0)? 1 : 0;
}

matrix generateIdentityMatrix(int size) // Returns matrix A: A(i, j) = 1 for all (i == j) & 0 for all (i != j).
{
    matrix answer;
    answer.height = size;
    answer.width = size;
    for(int i = 0; i < size*size; i++) answer.numbers.push_back(0);
    for(int i = 0; i < size; i++) answer.change(i, i, switchFlag);
    return answer;
}

matrix smartPower(matrix A, int power) // Power, but takes O(log n) time. Same as power(), defined only if A.width = A.height.
{
    if(power == 0) return generateIdentityMatrix(A.height);
    if(power == 1) return A;
    if(power % 2 == 1) return multiplication(A, smartPower(A, power - 1));
    if(power % 2 == 0) return multiplication(smartPower(A, power/2), smartPower(A, power/2));
}

/* Description
Returns new adjacency matrix, where adj(x, y) - amount of different pathes between vertices x & y
of length 'requiredLengthOfPathes' (adj(x, y) != adj(y, x), if graph is directed) */
matrix pathesOfRequiredLength(matrix adj, int requiredLengthOfPathes)
{
    return smartPower(adj, requiredLengthOfPathes);
}


int main(){
    matrix adj;
    int amountOfVertices = 6;
    adj.height = amountOfVertices;
    adj.width = amountOfVertices;
    int amountOfEdges;
    cin >> amountOfEdges;
    for(int i = 0; i < amountOfVertices*amountOfVertices; i++) adj.numbers.push_back(0);
    for(int i = 0; i < amountOfEdges; i++){
        int a, b;
        cin >> a >> b;
        adj.change(a-1, b-1, switchFlag);
    }
    int requiredLengthOfPath;
    cin >> requiredLengthOfPath;
    matrix newAdj = smartPower(adj, requiredLengthOfPath);
    int counter = 0;
    for(int y = 0; y < adj.height; y++){
        for(int x = 0; x < adj.width; x++){
            if(newAdj.number(x ,y) == 2) counter ++;
        }
    }
    cout << counter;
}
