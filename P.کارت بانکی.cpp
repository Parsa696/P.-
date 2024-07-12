#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int CARD_LENGTH = 16;
const vector<string> VALID_PREFIXES = {"1234", "5678", "4321", "8765"}; // پیش‌شماره‌های معتبر

bool isValidPrefix(const string& cardNumber) {
    string prefix = cardNumber.substr(0, 4);
    return find(VALID_PREFIXES.begin(), VALID_PREFIXES.end(), prefix) != VALID_PREFIXES.end();
}

void printCardNumber(const vector<int>& cardNumber) {
    for (int i = 0; i < cardNumber.size(); i++) {
        cout << cardNumber[i];
        if ((i + 1) % 4 == 0 && i != cardNumber.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<int> cardNumber;
    int digit;
    string currentCard;

    cout << "لطفا 16 رقم شماره کارت بانکی را به ترتیب وارد کنید:\n";

    for (int i = 0; i < CARD_LENGTH; i++) {
        while (true) {
            cout << "رقم شماره " << i + 1 << ": ";
            cin >> digit;

            if (cin.fail() || digit < 0 || digit > 9) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "خطا: لطفا یک عدد صحیح بین 0 تا 9 وارد کنید.\n";
            } else {
                cardNumber.push_back(digit);
                currentCard += to_string(digit);

                // نمایش اطلاعات وارد شده تا کنون
                cout << "شماره کارت تا کنون: ";
                printCardNumber(cardNumber);

                // اعتبارسنجی پیش شماره کارت پس از وارد کردن 4 رقم اول
                if (i == 3) {
                    if (!isValidPrefix(currentCard)) {
                        cout << "خطا: پیش‌شماره کارت نامعتبر است.\n";
                        return 1; // خروج از برنامه
                    }
                }

                break;
            }
        }
    }

    // نمایش شماره کارت به صورت ۴ رقم ۴ رقم
    cout << "شماره کارت نهایی: ";
    printCardNumber(cardNumber);

    return 0;
}
