#include <iostream>
#include <string>
using namespace std; 




int power(int a, int b){

    int sum = a; 

    if(b == 0){ // base case for 0 power
        return 1 ; 
    }else if (a == 0){ // base case for 0 base 
        return 0; 
    }else if(b == 1){ // base case for exponent  == 1 
        return sum; 

    }

    for(int c = b; c > 1 ; --c){
        sum = sum * a; 

    }
    return sum; 
}

int sum_power(int powerSum){

    string stringPowerSum = to_string(powerSum); // cast int to string to iterate
    int sum = 0; 

    for(int i = 0; i < stringPowerSum.length(); ++i){
        sum += stoi(stringPowerSum.substr(i,1)); // converts the  string to int through each iteration. starts with 0 idex and the first number. if it was (i,0) it would have anything
    }
    
    return sum; 


}

int main(){

    int a; 
    int b; 

    cout << "Enter a "<< endl; 
    cin >> a; 
    cout << "Enter b "<< endl; 
    cin >> b; 

    cout <<  "a: " << a << endl;
    cout <<  "b: " << b << endl;
    cout <<  a << "^"<< b << " = " << power(a,b)<< endl;
    cout << "Sum of digits: " << sum_power(power(a,b))<<endl; 




}