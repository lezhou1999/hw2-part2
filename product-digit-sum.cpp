#include <iostream>
#include <climits>
using namespace std;

unsigned long long pow(unsigned int a,unsigned int b){
    int i;
    unsigned long long result=1;
    
    for(i=0;i<b;i++){
        result *= a;
        //cout<<result<<endl;
    }
    return result;
}

int getNumDig(unsigned long long a){
    int numDig =0;
    while(a != 0){
        a /=10;
        numDig ++;
    }
    
    return numDig;

}

int getSum(unsigned long long num, int NumDig){
    int i;
    unsigned long long a = pow(10,NumDig-1);

    int b = 0;
    for(i = 0; i<NumDig; i++){
            int eachNum = num / a;
            num = num % a;
            a= a/10;
            
            b+= eachNum;
        }
    //cout << "b is " << b <<endl;
    return b;
    
}

int main(){
    unsigned int inputUnder;
    unsigned int inputPower;
    cout<< "a:";
    cin >> inputUnder;
    cout<< "b:";
    cin >> inputPower;
    //cout<<inputUnder<<"+"<<inputPower<< endl;
    if(inputPower<0 || inputUnder<0){
        cout << "invalid input"<<endl;
    }
    else{
    unsigned long long finalOut;
    int numDig;
    int sum;
    finalOut = pow(inputUnder, inputPower);
    numDig = getNumDig(finalOut);
    cout <<inputUnder<<"^"<<inputPower<<" = "<< finalOut<<endl;
    sum = getSum(finalOut, numDig);
    cout << "Sum of Digits: " << sum <<endl;
    }


    return 0;
}