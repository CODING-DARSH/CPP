#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>

using namespace std;
//sort()
int main(){

    vector<int> v={100,20,34,56,78,120,1,24,54};
    //sum
    int sum = accumulate(v.begin(),v.end(),0);
    cout<<"\n sum of v="<<sum;
    //sum of array
    vector<int> v1={1,2,3,4,5};

    int prod = accumulate(v1.begin(),v1.end(),1,[](int a,int b){
        return a * b;
    });
    cout<<"\n prod"<<prod;

    vector<string> v3={"hi","hello","ok"};
    int all = accumulate(v3.begin(),v3.end(),0,[](int s1,string str){
        return s1 + str.length();
    });
    cout<<"\n all "<<all;
    cout<<"\n";
    vector <int> v4={10,20,30,40};
    auto it1=lower_bound(v4.begin(),v4.end(),30);   //>= it will still return 2 index and 30 becoz this works on = to logic
    cout<<"------------------->"<<(it1-v4.begin());
    cout<<"\n"<<*it1;
    auto it2=upper_bound(v4.begin(),v4.end(),30);       //> it will return 3 index becoz it will go for greater index
    cout<<"------------------->"<<(it2-v4.begin());


    cout<<"\n";
    vector <int> v5={10,20,30,40};
    auto it3=remove(v4.begin(),v4.end(),30);
    cout<<(it3-v5.begin()); 
}