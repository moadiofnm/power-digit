#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
using namespace std; 

//  I thought about the sum of a = 6 and b = 12 what would be the sum of the digits of
//the value n = ab?  0 times this week >_<


unsigned long long int power(unsigned int a, unsigned int b){

    long long sum = a; 

    if(b == 0){ // base case for 0 power
        return 1 ; 
    }else if (a == 0){ // base case for 0 base 
        return 0; 
    }else if(b == 1){ // base case for exponent  == 1 
        return a; 

    }else{
        for(int c = b; c > 1 ; --c){
            sum = sum * a; 
        }
       
    }
    return sum; 
    
}

// changed my initial sum approach. I learned from shawn's appoach using mod to get the indices
// of the sum rather than iterating and casting.
// the mod is taking the last value and adding it to the sum. after the powersum is divide. 

long long power_(long long  powerSum){
    long long  sum = 0; 
    while(powerSum != 0 ){
        sum += powerSum %10;
        powerSum /= 10; 
    }
    return sum; 


}

vector<int> vectorize_digits(unsigned long long n){
    vector<int>digits ; 

    while(n > 0){
        int v = n % 10; 
        digits.push_back(v); 
        n /= 10 ; 
    }
    return digits; 
}

int sum_vector(vector<int> v){
    int sum = 0; 
    for(int  i = 0 ; i < v.size(); i++){
        sum += v.at(i);
    }
    return sum; 
    
}

// Brenden should me a simpler and slightly better way to print just appending to the string with a for loop.

string vec_to_string(vector<int> vec){
    string a  = "{"; 
    for(int  i = vec.size()-1 ; i >= 0; i--){
        a += to_string(vec.at(i));
        if (i > 0) {
            a += ", ";
        }
    }
    a += "}";
    
    return a; 
}

// for string vectors 
string Print(vector<string> vec){
    string a  = "{"; 
    for(int  i = vec.size()-1 ; i >= 0; i--){
        a += (vec.at(i));
        if (i > 0) {
            a += ", ";
        }
    }
    a += "}";
    
    return a; 

}


int test() {

    vector <int> digit; 
    digit.push_back(3);
    digit.push_back(2);
    digit.push_back(1);

    vector <int> digit3; 
    digit3.push_back(6);
    digit3.push_back(5);
    digit3.push_back(4);

    vector <int> digit4; 
    digit4.push_back(2);
    digit4.push_back(1);
    digit4.push_back(1);

    vector <string> digit2;
    digit2.push_back("3");
    digit2.push_back("2");
    digit2.push_back("1");
    
    
// testing strings 
    // cout << vec_to_string(digit) << "vec_to_String"<< endl;
    // cout << Print(digit2) << "toString"; 

    cout << "Testing started" << endl;

   assert(vectorize_digits(123)  == digit); 
   assert(vectorize_digits(456)  == digit3);
   assert(vectorize_digits(112)  == digit4);
   assert(vec_to_string(digit) == Print(digit2));
   assert(sum_vector(digit)  == 6);
   assert(sum_vector(digit3)  == 15);
   assert(sum_vector(digit4)  == 4);
   assert(power(2,15)  == 32768);
   assert(power(10,10)  == 10000000000);
   assert(power(13,3)  == 2197);
   
   cout << "All tests passed" << endl;
   
   return 0;
}



int main(){

    test(); 

    int a; 
    int b; 

    cout << "Enter a "<< endl; 
    cin >> a; 
    cout << "Enter b "<< endl; 
    cin >> b; 

    if(a > 0 && b > 0 ){
        if(b * log(a) < 64 *log(2)){
            cout <<  "a: " << a << endl;
            cout <<  "b: " << b << endl;
            cout <<  a << "^"<< b << " = " << pow(a,b)<< endl; 
            cout << "Sum of digits: " << sum_vector(vectorize_digits(pow(a,b))) <<endl; 
        }else{
            cout<< "Overflow Error" << endl; 
        }
    }else{
        cout << "Invalid Input"<< endl; 
    }

    // old code
    // cout <<  "a: " << a << endl;
    // cout <<  "b: " << b << endl;
    // cout <<  a << "^"<< b << " = " << pow(a,b)<< endl;
    // cout << "Sum of digits: " << power(pow(a,b))<<endl; 
    return 0; 



}
// task 3 

/* a. What is the mistake? tep 0 is balanced: True
b. Where (what line number) is the mistake on? It should be step 1 not step 0. At step zero the balace was false.
c. How did you find the mistake? Describe the process you followed. I went through the depth and checked the runs taken so far. It was a small mistake and easy to miss. but I went over the code mant times. 
d. On a scale of 1-10, how much fun was it finding the mistake? */
// -1000000 I hate recursion 