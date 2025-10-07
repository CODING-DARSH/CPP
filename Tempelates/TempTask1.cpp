#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Swapper {
    T a, b;

public:
    Swapper(T x, T y) {
        a = x;
        b = y;
    }
    void swapValues() {
        T temp = a;
        a = b;
        b = temp;
    }

    void showValues() const {
        cout << "A = " << a << ", B = " << b << endl;
    }
};

int main() {
    Swapper<int> intSwap(10, 20);
    cout << "Before swap: ";
    intSwap.showValues();

    intSwap.swapValues();
    cout << "After swap: ";
    intSwap.showValues();

    Swapper<string> strSwap("Hello", "World");
    cout << "Before swap (string): ";
    strSwap.showValues();

    strSwap.swapValues();
    cout << "After swap (string): ";
    strSwap.showValues();

    Swapper<float> floatSwap(1.5, 9.8);
    cout << "Before swap (float): ";
    floatSwap.showValues();

    floatSwap.swapValues();
    cout << "After swap (float): ";
    floatSwap.showValues();
}
