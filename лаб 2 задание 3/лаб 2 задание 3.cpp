#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;
void replaceDigits(const char* inputFilename, const char* outputFilename) {
    ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        cout << "Ошибка открытия файла " << inputFilename << endl;
        return;
    }

    
    cout << "файл " << inputFilename << ":" << std::endl;
    char ch;
    while (inputFile.get(ch)) {
        cout << ch;
    }
    inputFile.close();

    ofstream outputFile(outputFilename);

    inputFile.open(inputFilename); 
    while (inputFile.get(ch)) {
        if (isdigit(ch)) {
            outputFile << '*';
        }
        else {
            outputFile << ch;
        }
    }

    inputFile.close();
    outputFile.close();

    ifstream outputFileCheck(outputFilename);
    
    cout << endl;
    cout << "файл " << outputFilename << ":" << endl;
    while (outputFileCheck.get(ch)) {
        cout << ch;
    }
    outputFileCheck.close();

}

int main() {
    setlocale(LC_ALL, "RU");
    const char* inputFilename = "a3.txt";
    const char* outputFilename = "a4.txt";

    replaceDigits(inputFilename, outputFilename);

    return 0;
}