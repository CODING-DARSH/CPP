#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    vector<int> v = {10, 2, 4, 8, 16, 18};

    int c = count_if(v.begin(), v.end(), [](int x) {
        return x % 2 == 0;
    });

    cout << c;
}

//count even numbers