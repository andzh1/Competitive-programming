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

matrix power(matrix A, int power) //Defined only if A.width = A.height
{
    if(power == 0) return generateIdentityMatrix(A.height);
    matrix answer = A; 
    power--;
    while(power--) answer = multiplication(answer, A);
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
For input.height = 3 multiplier will be {0       1      0}
                                        {0       0      1}
                                        {C[0]  C[1]  C[2]}, C[i] = coefficients[i].
 */
matrix generateMatrixForSolvingRecurrentExpression(matrix input, vector <intType> coefficients) 
{
    matrix multiplier;
    multiplier.height = input.height;
    multiplier.width = input.height;
    for(int i = 0; i < multiplier.width*(multiplier.height - 1); i++ ) multiplier.numbers.push_back(0);
    for(int i = 0; i < multiplier.width; i++ ) multiplier.numbers.push_back(coefficients[i]);
    for(int i = 0; i < (multiplier.height - 1); i++ ) multiplier.change(i+1, i, switchFlag);
    return multiplier;
}

/* Description
We want to calculate recurrent expression: f(n) = C1*f(n-1) + C2*f(n-2) + ... Ck*f(n-k), 
with given f(0)...f(k-1) - input and C1...Ck (coefficients).
coefficients[i] = C[k-i] */
matrix getRecurrentExpression(matrix input, vector <intType> coefficients, intType n) //We want to calculate recurrent expression: f(n) = C1*f(n-1) + C2*f(n-2) + ... Ck*f(n-k). 
{
    matrix multiplier = generateMatrixForSolvingRecurrentExpression(input, coefficients);
    matrix multiplierInPower = smartPower(multiplier, n);
    multiplierInPower.height = multiplier.height;
    multiplierInPower.width = multiplier.width;
    return multiplication(multiplierInPower, input);
}

int main(){
    matrix A, B;
    A.height = 3;
    A.width = 1;
    A.numbers.push_back(0);
    A.numbers.push_back(0);
    A.numbers.push_back(1);
    B.height = 2; //Unless multiplication of matrices A & B is undefined.
    B.width = 2;
    // int input;
    // for(int i = 0; i < A.width*A.height; i++){
    //     cin >> input;
    //     A.numbers.push_back(input);
    // }
    // for(int i = 0; i < B.width*B.height; i++){
    //     cin >> input;
    //     B.numbers.push_back(input);
    // }
    // matrix answer = multiplication(B, A);
    // for(int i = 0; i < 2; i++) cout << answer.number(0, i) << '\n';
    vector <int> coefficients;
    coefficients.push_back(1);
    coefficients.push_back(1);
    coefficients.push_back(1);
    int requiredPower;
    cin >> requiredPower;
    matrix answer = getRecurrentExpression(A, coefficients, requiredPower);
    // for(int y = 0; y < answer.height; y++){
    //     for(int x = 0; x < answer.width; x++) cout << answer.number(x, y) << " ";
    //     cout << '\n';
    // }
    cout << answer.number(0, 0);
}
