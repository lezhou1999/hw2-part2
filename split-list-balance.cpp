#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
#include <assert.h>
using namespace std;


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


void split(vector<int>& numbers, vector<int>& subSet,int m,int n, int ith, int& minValue){
    if(ith == n){
        int forCount = 0;
        for(int i = 0;i<n;i++){
            forCount += subSet.at(i);      
        }
        if(forCount == m){
            for(int j = 0;j<n;j++){
                //cout<<subSet.at(j)<<" ";
            }
            // cout<<endl;
            int sum = numbers.at(0);
            int Max = sum;

            for(int k=1;k<n+1;k++){
                if(subSet.at(k-1)!=1){
                    sum += numbers.at(k);
                }
                else{   
                    if(sum>Max){
                        Max=sum;
                    }
                    sum=numbers.at(k);
                }
            }

            if(sum>Max){
                Max=sum;
            }
            if (Max<minValue) {
                minValue=Max;
            }
            //cout<<" MaxValue is:"<<Max<<endl;
        }
        return;
    }
    subSet.at(ith) =0;
    split(numbers,subSet,m,n,ith+1, minValue);
    subSet.at(ith)=1;
    split(numbers,subSet,m,n,ith+1, minValue);
}

int split_vec(vector<int> vec, int m){
    vector<int> subSet;
    for(int i=0;i<1000;i++){
        subSet.push_back(0);
    }

    int minValue = INT_MAX;
    split(vec, subSet,m-1,vec.size()-1,0, minValue);
    return minValue;
}
int main(){
    vector<int> numbers1;
    numbers1.push_back(7);
    numbers1.push_back(2);
    numbers1.push_back(5);
    numbers1.push_back(10);
    numbers1.push_back(8);

    int m1=2;
    cout << "the sample is:" << vec_to_string(numbers1)<<endl;
    cout<<"Result1: "<<split_vec(numbers1,m1)<<endl;

    vector<int> numbers2;
    numbers2.push_back(1);
    numbers2.push_back(5);
    numbers2.push_back(4);
    numbers2.push_back(15);
    numbers2.push_back(7);

    int m2=3;
    cout << "the sample is:" << vec_to_string(numbers2)<<endl;
    cout<<"Result1: "<<split_vec(numbers2,m2)<<endl;

    vector<int> numbers3;
    numbers3.push_back(1);
    numbers3.push_back(2);
    numbers3.push_back(3);
    numbers3.push_back(4);
    numbers3.push_back(5);

    int m3=2;
    cout << "the sample is:" << vec_to_string(numbers3)<<endl;
    cout<<"Result1: "<<split_vec(numbers3,m3)<<endl;

    vector<int> numbers4;
    numbers4.push_back(1);
    numbers4.push_back(3);
    numbers4.push_back(5);
    numbers4.push_back(12);
    numbers4.push_back(4);
    numbers4.push_back(7);
    numbers4.push_back(6);

    int m4=4;
    cout << "the sample is:" << vec_to_string(numbers4)<<endl;
    cout<<"Result1: "<<split_vec(numbers4,m4)<<endl;

    vector<int> numbers5;
    numbers5.push_back(2);
    numbers5.push_back(3);
    numbers5.push_back(4);
    numbers5.push_back(5);
    numbers5.push_back(6);


    int m5=2;
    cout << "the sample is:" << vec_to_string(numbers5)<<endl;
    cout<<"Result1: "<<split_vec(numbers5,m5)<<endl;

    vector<int> numbers6;
    numbers6.push_back(1);
    numbers6.push_back(4);
    numbers6.push_back(4);


    int m6=3;
    cout << "the sample is:" << vec_to_string(numbers6)<<endl;
    cout<<"Result1: "<<split_vec(numbers6,m6)<<endl;
    
    
    
    
    return 0;
}