#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;


int main() {

    int size = 80;
    char buffer[size];

    ifstream fileForRead("data.txt");
    //cout << fileForRead.rdbuf();
    fileForRead.read(buffer,size);
    cout << buffer << "\n";

    string string1 = string (buffer);
    cout << "Number of spaces in the file: " << count(string1.begin(),string1.end(),' ') << "\n";
    cout << "String 'test' find on pozition: " << string1.find("test") << "\n";

    int it = string1.find("-",0);         //ищем количество вхождений символа - в строку string1
    while (it != string::npos){                  //пока количество вхождений не нулевое
        string1.replace(it,1," ");    //меняем местами - и _
        it = string1.find("-",it);        //снова ищем символ - в строке
    }
    cout << string1 << "\n";

    string input;
    cout << "Input number for paste to page: ";
    cin >> input;

    int it2 = string1.find("1",0);         //ищем количество вхождений символа 1 в строку string1
    while (it2 != string::npos){                  //пока количество вхождений не нулевое
        string1.replace(it2,1," ");     //заменяем число пробелом
        string1.append("\t");
        string1.append(input);                 //вставляем число в конец файла
        it2 = string1.find("1",it);        //снова ищем символ - в строке
    }
    cout << string1 <<"\n";


    //шифратор
    char nameA[50], nameB[50], key[50];
    int indexKey = 0, index = 0;

    printf("Enter a filename to encrypt: " );
    scanf( "%s", nameA );
    printf( "Enter a filename for the encrypted file: " );
    scanf( "%s", nameB );
    printf( "Enter key: " );
    scanf( "%s", key );

    FILE *in = fopen( nameA, "r" );
    FILE *out = fopen( nameB, "w" );
    if (( in != NULL )) {
        while ( true ) {
            char ch = getc( in );
            char newCh = ch ^ key[indexKey];

            if ( feof( in )) {
                break;
            }
            printf( "%c ", key[indexKey] );
            putc( newCh, out );
            if ( indexKey < strlen( key ) - 1 ) {
                indexKey++;
            } else {
                indexKey = 0;
            }

            index++;
        }
        fclose( in );
        fclose( out );
    } else {
        printf( "Files %s and %s not open!", nameA, nameB );
    }
    cin.ignore();
    cin.get();
}


