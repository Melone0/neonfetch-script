#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


int main () {
    ifstream file;
     file.open("/home/melone/Dokumente/.bashtest");
    
    if (file.fail())
    {
        cout << "file failed";
        return 1;
    }
    
    stringstream buffer;

    buffer << file.rdbuf();

    string file_content;

    file_content = buffer.str();

    file.close();

    cout << file_content;

}