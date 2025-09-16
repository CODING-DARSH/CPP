#include<iostream>
#include<string>
using namespace std;

int main(){
    string str1="Darsh";
    cout<<"str1="<<str1[0]<<endl;
    cout<<"str1 at ="<<str1.at(0)<<endl;    //it will give first value inside string
    cout<<"str1 front= "<<str1.front()<<endl;   //it will give first value inside string
    cout<<"str1 back= "<<str1.back()<<endl;     //it will give last value inside string
    cout<<"str1 size= "<<str1.size()<<endl;         //it will give size of string   which start from 0 and ends at n-1
    cout<<"str1 length = "<<str1.length()<<endl;        //it will give length of string  which start from 0 and ends at n-1
    cout<<"str1 capacity= "<<str1.capacity()<<endl;    //it will give capaciy of string  which is 15 default after 15 it will increase it with exact characters
    cout<<"str1 capacity= "<<str1.replace(3,1,"d")<<endl;  // 3 is index number 1 is after 3 how many numbers 3 will be replaced first and then what to replace
    cout<<"str1 capacity= "<<str1.empty()<<endl;    // it will give 0 if char are ther else 1 if string is empty
    cout<<"str1 insert= "<<str1.insert(3,"V")<<endl;  //it will insert 3 at third index
    cout<<"str1 capacity= "<<str1.append(" Vithlani")<<endl;    // it will things at last of ending of string
}