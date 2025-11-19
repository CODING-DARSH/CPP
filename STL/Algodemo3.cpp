#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
    vector<int> v={1,2,3,4,5,6};
    auto i=find(v.begin(),v.end(),3);
    if(i!=v.end()){
        cout<<"found at index "<<(i-v.begin());
    }
    else{
        cout<<"not found";
    }
}
