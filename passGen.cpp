#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <fstream>

using namespace std;
/*  old style
using std::cout;
using std::cin;
using std::endl;
*/
class PassGen {
/*=============================func input output string===========================*/
public:
    void displayMessage()
    {
        int passLenght;
        int numOfPasswords;
        char * filename = new char;

        cout << "������ ����� ��஫� ��� �����樨: ";
        cin >> passLenght;
        cout << "������ ������⢮ ��஫�� ��� �����樨: ";
        cin >> numOfPasswords;
        cout << "�㤥� ᣥ���஢��� ��஫��: " << numOfPasswords << "." << endl;
        cout << endl;
        cout << "������ ��� 䠩�� ��� �����: ";
        cin >> filename;
/*==============================out stream FILE =================================*/
        //std::ofstream outFile(filename);
        ofstream outFile(filename);

        for (int k = 0; k < numOfPasswords; k++) {
            for (int i = 0; i < passLenght; ++i) {
                numOfChars(passLenght);
                passGenerator(passLenght);
                outFile << password [i];
            }
            outFile << endl;
        }
        outFile.close();        // ������� 䠩� ��஫��

        cout << "��஫� �ᯥ譮 ᣥ���஢��� � ����ᠭ� � 䠩� " << filename << "" << endl;
    }

    void passGenerator(int passLenght)
    {
        password = new char [passLenght];

        for (int i = 0; i < numOfNumbers; ++i) {
            password [i] = char(rand() % 10 + 48);
        }
        for (int i = numOfNumbers; i < numOfNumbers + numOfBigChars; ++i) {
            password [i] = char(rand() % 26 + 65);
        }
        for (int i = numOfNumbers + numOfBigChars; i < passLenght; ++i) {
            password [i] = char(rand() % 26 + 97);
        }
           random_shuffle(password, password + passLenght);
         //std::random_shuffle(password, password + passLenght);
    }

    void numOfChars(int passLenght)
    {
        numOfSmallChars = rand() % passLenght;
        int charRandEnd = passLenght - numOfSmallChars;
        numOfBigChars = rand() % charRandEnd;
        numOfNumbers = passLenght - numOfSmallChars - numOfBigChars;
    }

private:
    int numOfSmallChars;
    int numOfBigChars;
    int numOfNumbers;
    char * password;
};

int main()
{
    srand(time(NULL));
    PassGen * pass = new PassGen;
    pass->displayMessage();
    return 0;
}
