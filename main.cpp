#include <iostream>
#include <string>
#include <array>
using namespace std;


//Prototyping functions
int seq1(int);
int seq2(int);
int retSeq1(int);
int gcd(int, int);
string reverseStr(string, int);
bool isPalindrome(string);
string toBinary(int);
double arrAverage(int[], int);
long findFractorial(int);

int main() {

    //1a) sequence t1 =3, tn = t(n-1)-2
    int termNum = 0;
    bool autoDecision = false;
    cout << "Sequence 1: For Automatic input enter 1, for Manuel enter 0:";
    cin >> autoDecision;
    if (autoDecision == 0){
        bool isValid2 = false;
        do {
            cout << "How many terms of the sequence would you like?";
            cin >> termNum;
            if(termNum <=0){
                cout << "Invalid input.\n";
                termNum = 8;
            } else {
                isValid2 = true;
            }
        } while(isValid2 == false);
    } else {
        termNum = 8;
    }
    cout << "The first " << termNum << " terms of seq 1 are:" << endl;
    seq1(termNum);


    //1b) Sequence where t1 = -1; tn = 2t(n-1) 
    int termNum2 = 0;
    bool autoDecision2 = false;
    cout << "\nSequence 2: For Automatic input enter 1, for Manuel enter 0:";
    cin >> autoDecision2;
    if (autoDecision2 == 0){
        bool isValid3 = false;
        do {
            cout << "How many terms of the sequence would you like?";
            cin >> termNum2;
            if(termNum2 <=0){
                cout << "Invalid input.\n";
                termNum2 = 8;
            } else {
                isValid3 = true;
            }
        }while (isValid3 == false);
    } else {
        termNum2 = 8;
    }
    cout << "The first " << termNum2 << " terms of seq 2 are:" << endl;
    seq2(termNum2);

    //Exercise 2 GCD

    int num1 = 0, num2 = 0;
    bool autoDecision4 = false;
    cout << "\nGDC: For Automatic input enter 1, for Manuel enter 0:";
    cin >> autoDecision4;
    if (autoDecision4 == 0){
        cout << "What is your first number?";
        cin >> num1;
        cout << "What is your second number?";
        cin >> num2;

    } else {
        num1 = 12;
        num2 = 3;
    }
    cout << "The gdc of " << num1 << " and "<< num2 << " is " << gcd(num1, num2) << endl;

//Inverse String, this will reverse and opposite the string backwards
    string inputStr = "";
    bool autoDecision5 = false;

    cout << "\nReverse String: For Automatic input enter 1, for Manuel enter 0:";
    cin >> autoDecision5;
    if (autoDecision5 == 0){
        cout << "What is your word?";
        cin.ignore();
        cin >> inputStr;

    } else {
        inputStr = "This is ok";
    }
    cout << "The inverse of \"" << inputStr << "\" is \"" << reverseStr(inputStr, inputStr.length()) << "\"" <<endl;

    bool tested = isPalindrome(inputStr);
    if (tested == true){
        cout << inputStr << " is a palindrome.\n";
    } else {
        cout << inputStr << " is not a palindrome.\n";
    }


    //This will convert integers to their Binary equivalents
    int convert = 0;
    bool autoDecision3 = false;
    cout << "\nInt to Binary: For Automatic input enter 1, for Manuel enter 0:";
    cin >> autoDecision3;
    if (autoDecision3 == 0){
        bool isValid = false;
        do{
            cout << "What positive integer would you like in binary?";
            cin >> convert;
            if(convert < 0){
                cout << "Invalid input.\n";
            } else {
                isValid = true;
            }
        } while (isValid == false);
    } else {
        convert = 5;
    }
    cout << convert <<" in binary is " << toBinary(convert)<<endl;

    //This will calculate the average of the values in an array of integers
    bool autoDecision6 = 0;
    int arrSize = 5;
    int *array;
    cout << "\nArray Average - For Automatic input enter 1, for Manuel enter 0:";
    cin >> autoDecision6;

    if(autoDecision6 == 1){
        array = new int[5];
        array[0] = 3;
        array[1] = 54;
        array[2] = 8;
        array[3] = 5;
        array[4] = 2;
    } else {
        bool isValid4 = false;

        do{
            cout << "How big is your array?";
            cin >> arrSize;

            if(arrSize < 0){
                cout << "Invalid input.\n";
            } else {
                isValid4 =true;
            }
        } while (isValid4 == false);

        array = new int[arrSize];

        for (int y = 0; y < arrSize; y++){
            cout << "What is the value for index " << y+1 << "?";
            cin >> array[y];
        }
    }

    cout << "\nThe average is " << arrAverage(array,arrSize);

    bool autoDecision7 = 0;
    int fracNum = 5;

    //This will calculate the nth order fractorial
    cout << "\n\nFractorial - For Automatic input enter 1, for Manuel enter 0:";
    cin >> autoDecision6;
    if(autoDecision6 == 0){
        bool isValid5 = false;
        do{
            cout << "\nWhich fractorial do you want?";
            cin >> fracNum;
            if(fracNum < 0){
                cout << "Invalid Input.";
            } else {
                isValid5 = true;
            }

        } while(isValid5 == false);
    }
    cout << "The fractorial is: " << findFractorial(fracNum);

}


int seq1(int maxTerm){
    if(maxTerm == 1){
        cout << 3 << endl;
        return 3;
    }
    int output = seq1(maxTerm-1) - 2;
    cout << output << endl;
    return output;
}

int seq2(int maxTerm){
    if(maxTerm == 1){
        cout << -1 << endl;
        return -1;
    }
    int output = 2*seq2(maxTerm-1);
    cout << output << endl;
    return output;
}

int gcd(int x, int y){
    if(y == 0){
        return x;
    } else {
        return gcd(y, x%y);
    }

}

string reverseStr(string input, int length){
    if (length == 1){
        return input.substr(0,1);
    }

    return input.substr(length-1,1) + reverseStr(input, length-1);

}

bool isPalindrome(string check){

    if (check == reverseStr(check, check.length())){
        return true;
    } else {
        return false;
    }

}

string toBinary(int decimal){

    if (decimal == 0){
        return "0";
    } else if (decimal == 1){
        return to_string(decimal % 2);
    }
    return toBinary(decimal/2) + to_string(decimal%2);
}

double arrAverage(int average[], int length){
    if(length == 1){
        return average[0];
    }
    return (arrAverage(average, length-1)*(length-1) + average[length-1])/length;
}

long findFractorial(int numFractorial){
    bool done = false;


    if(numFractorial == 1){
        return 1;
    }

    long lastFrac = findFractorial(numFractorial-1);
    long currentFrac = lastFrac;

    do{
        if(currentFrac % numFractorial == 0){
            return currentFrac;
        } else {
            currentFrac += lastFrac;
        }

    }while (done == false);
    return 0; //will never hit this line, only to prevent errors
}
