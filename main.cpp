#include <iostream>
#include <numeric>
#include <math.h>
#include <vector>
using namespace std;

vector<int> value;

int decipher(int cipher){

    //Squaring method

    //Break into x * (x^2)^3 mod(55)

    // x= cipher
    int val = pow(cipher, 2);
    int currentValue = val % 55;
    val = pow(currentValue, 2);

    int tmp = val % 55;
    val = cipher * currentValue;
    val = val % 55;
    val = tmp * val;
    value.push_back(val % 55);
    return val % 55;
}

void message() {
    std::vector<char> englishAlphabetUpper({
                                                   'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                                                   'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'});

    for(int i = 0; i<value.size(); i++){
        if (value.at(i) == 28) {
            cout << " ";
        }
        else {
            cout << englishAlphabetUpper.at(value.at(i) - 2);
        }
    }
}
int main() {




    int array[] = {19, 14 , 51 ,  20  ,   7   , 10  ,  21,
    7  ,  10  ,  25  ,   7  ,  26  ,  27  ,  12,
    10  ,  26  ,  33  ,  25  ,   7  ,  21,   14,
    8 ,   21 ,    7  ,  21    ,14  ,  51 ,    7,
    17 ,   26    , 8   , 52   , 25 ,    7 ,    9,
    8   ,  20 ,   20    ,26   , 21   ,  7 ,   27,
    51   ,  7  ,  39 ,   51  ,   8    , 9   , 14,
    51  ,  15 ,    7  ,  15  ,  26  ,   7  ,  20,
    26   , 21    , 7  ,   8  ,  15 ,   11  ,  33,
    25   , 21    , 7   , 21 ,   14   , 51  ,   7,
    17  ,  26   ,  8   , 52   , 25   ,  7  ,   8,
    15   , 11   , 33  ,  25   , 21   ,  7  ,  21,
    14  ,  51   ,  7  ,   8  ,   9  ,  21    ,10,
    26   , 20  ,   7 ,   25 ,   21 ,   51,    18,
    25};


    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {

        if (i % 7 == 0) {
            cout << decipher(array[i]) << "\n";
        }
        else {
            cout << decipher(array[i]) << "     ";
        }

    }

    message();

    return 0;
}
