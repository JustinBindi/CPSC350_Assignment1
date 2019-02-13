#include <iostream>
#include <fstream>
#include <string> //dont know if needed
using namespace std;

int main(int argc, char * argv[])
{
    string fileName = argv[1];
    string line;

    ifstream myFile (fileName);

    while(!myFile.eof())
    {
      getline(myFile, line);
      cout << line << endl;

    }

    myFile.close();




    return 0;
}
