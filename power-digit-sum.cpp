#include <iostream>
#include <string>
using namespace std; 

//  I thought about the sum of a = 6 and b = 12 what would be the sum of the digits of
//the value n = ab?  0 times this week >_<


unsigned long long int pow(unsigned int a, unsigned int b){

    int sum = a; 

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

long long  sum_power(long long  powerSum){

    long long  sum = 0; 

    while(powerSum != 0 ){
        sum += powerSum %10;
        powerSum /= 10; 

    }
    
    return sum; 


}

int main(){

    int a; 
    int b; 

    cout << "Enter a "<< endl; 
    cin >> a; 

    if(a < 0 ){
        cout<< "Invalid Input" << endl; 
    }

    cout << "Enter b "<< endl; 
    cin >> b; 

    if(b < 0  ){
        cout<< "Invalid Input" << endl; 
    }

    cout <<  "a: " << a << endl;
    cout <<  "b: " << b << endl;
    cout <<  a << "^"<< b << " = " << pow(a,b)<< endl;
    cout << "Sum of digits: " << sum_power(pow(a,b))<<endl; 
    return 0; 



}