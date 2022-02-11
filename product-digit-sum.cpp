#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
#include <assert.h>
using namespace std;

unsigned long long pow(unsigned int a,unsigned int b){
    int i;
    unsigned long long result=1;
    
    for(i=0;i<b;i++){
        
        unsigned long long b=result;
        result *= a;
        if (b>result){
            cout<< "WARNING!  Overflow Detected!"<< endl;
            cout<< "WARNING!  Overflow Detected!"<< endl;
        }
        

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

vector<int> vectorize_digits(unsigned long long num, int NumDig){
    vector<int> vecDig(NumDig);

    int i;
    unsigned long long a = pow(10,NumDig-1);

    for(i = 0; i<NumDig; i++){
            int eachNum = num / a;
            vecDig.at(i)=eachNum;
            num = num %a;
            a=a/10;
            
            
        
        }
    return vecDig;


}

int sum_vector(vector<int> n){
    int i;
    int b =0;
    for(i=0;i<n.size();++i){
        int eachNum;
        eachNum = n.at(i);
        //cout<<eachNum<<endl;
        b+=eachNum;

    }
    return b;

}


string vec_to_string(vector<int> n){
    int i;
    std::string toInsert = std::to_string(n.at(0));
    int a = n.at(0);
    string stringOut ("[");

    for(int i=0;i<n.size()-1;i++){
        std::string toInsert = std::to_string(n.at(i));
        toInsert=toInsert+", ";
        stringOut.append(toInsert);

    }
    std::string finalNum = std::to_string(n.at(n.size()-1));
    stringOut.append(finalNum);
    stringOut.append("]");

    return stringOut;


}

void test(){
    int ansSum1 = sum_vector({2,5});
    assert(ansSum1 == 7);
    int ansSum2 = sum_vector({1,3,7});
    assert(ansSum2 == 11);
    int ansSum3 = sum_vector({2,4,6,8});
    assert(ansSum3 == 20);

    vector<int> vecOut1 = vectorize_digits(22,2);
    vector<int> ansVector1 = {2,2};
    assert(vecOut1 == ansVector1);
    vector<int> vecOut2 = vectorize_digits(323,3);
    vector<int> ansVector2 = {3,2,3};
    assert(vecOut2 == ansVector2);

    string ansStr1 = vec_to_string({2,5});
    assert(ansStr1 == "[2, 5]");
    string ansStr2 = vec_to_string({1,8,9});
    assert(ansStr2 == "[1, 8, 9]");


    cout << "ALL TESTS PASSED!" << endl;
}

int main(){
    test();


    unsigned int inputUnder;
    unsigned int inputPower;
    cout<< "a:";
    cin >> inputUnder;
    cout<< "b:";
    cin >> inputPower;
    //cout<<inputUnder<<"+"<<inputPower<< endl;
    if(inputPower<=0 || inputUnder<0){
        cout << "invalid input"<<endl;
    }
    else{
        unsigned long long finalOut;
        unsigned long long forCheck=1;
        unsigned long long resultCheck;
        int numDig;
        int sumInt;
        int sumVec;
        finalOut = pow(inputUnder, inputPower);
        
        
        
            numDig = getNumDig(finalOut);
            cout <<inputUnder<<"^"<<inputPower<<" = "<< finalOut<<endl;
            sumInt = getSum(finalOut, numDig);
            cout << "Sum of Digits by intCal: " << sumInt <<endl;

            vector<int> vectorOut;
            vectorOut = vectorize_digits(finalOut, numDig);
            sumVec = sum_vector(vectorOut);
    
            cout << "Sum of Digits by vector: " << sumVec <<endl;
            cout << "the string is " << vec_to_string(vectorOut)<<endl;
            
        
    
    
    }


    return 0;
}
// I use power 1 times pre day in average