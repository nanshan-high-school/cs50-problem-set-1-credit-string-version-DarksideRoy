#include <iostream>
using namespace std;
// 27125 655249

int main() {
    string num;
    cout << "Enter your credit card number:";
    cin >> num;

    int firstTwo = (num[0] - '0') * 10 + (num[1] - '0');;
        
    int length = 0;

    for (int i = 0; num[i] != '\0'; i++) {
        length ++;
    }

    bool even = false;
    int total = 0;

    for (int j = length - 1; j >= 0; j--) {
        if (even) {
            total += ((num[j] - '0') * 2 % 10 + (num[j] - '0') * 2 / 10);
        } else {
            total += num[j] - '0';
        }
        even = !even;
    }
 
    if (total % 10 != 0) {
        cout << "It's not a available credit card number.";
        return 0;
    }

    if (length == 15 && (firstTwo == 34 || firstTwo == 37)) {
        cout << "American Express";
    } else if (length == 16 && (firstTwo > 50 && firstTwo < 56)) {
        cout << "MasterCard";
    } else if ((length == 13 || length == 16) && firstTwo / 10 == 4) {
        cout << "Visa";
    } else {
        cout << "It's not a available credit card number.";
    }
}
