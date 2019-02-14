#include <iostream>
#include <fstream>
#include <string> //dont know if needed
#include <cstddef>
#include<cmath>//square root and ^2
using namespace std;

int main(int argc, char * argv[])
{
    string fileName = argv[1];
    string line;
    string bigram;
    int aCount = 0;
    int tCount = 0;
    int gCount = 0;
    int cCount = 0;
    int aaCount = 0;
    int atCount = 0;
    int agCount = 0;
    int acCount = 0;
    int taCount = 0;
    int ttCount = 0;
    int tgCount = 0;
    int tcCount = 0;
    int gaCount = 0;
    int gtCount = 0;
    int ggCount = 0;
    int gcCount = 0;
    int caCount = 0;
    int ctCount = 0;
    int cgCount = 0;
    int ccCount = 0;
    int lineLength = 0;
    int totalChar = 0;
    int numofLines = 0;
    int sum = 0;
    int mean = 0;
    int variance = 0;
    int standardDeviation = 0;

    ifstream myFile (fileName);

    while(!myFile.eof())
    {
      getline(myFile, line);
      cout << line << endl;
      lineLength = line.length();

      if (line != "")
      {
        numofLines++;
      }
      //cout << numofLines << endl;

      size_t found = line.find_first_not_of("agctACGT");

      if (found != string::npos)
      {}
      else
      {
        if (line != "")
        {
          for (int i = 0; i < lineLength-1; i+=2)
          {
            char char1 = tolower(line[i]);
            char char2 = tolower(line[i+1]);
            //bigram = char1 + char2;
            cout << char1 << endl;
            cout << char2 << endl;//line.at(i) + line.at(i + 1);
            //cout << bigram << endl;
            //cout << "" << endl;
            if (char1 == 'a' && char2 == 'a')
            {
              aaCount++;
              cout << aaCount << endl;
              cout << "" << endl;
            }
            if (char1 == 'a' && char2 == 't')
            {
              atCount++;
              cout << atCount << endl;
              cout << "" << endl;
            }
            if (char1 == 'a' && char2 == 'g')
            {
              agCount++;
              cout << agCount << endl;
              cout << "" << endl;
            }
            if (char1 == 'a' && char2 == 'c')
            {
              acCount++;
              cout << acCount << endl;
              cout << "" << endl;
            }
            if (char1 == 't' && char2 == 'a')
            {
              taCount++;
              cout << taCount << endl;
              cout << "" << endl;
            }
            if (char1 == 't' && char2 == 't')
            {
              ttCount++;
              cout << ttCount << endl;
              cout << "" << endl;
            }
            if (char1 == 't' && char2 == 'g')
            {
              tgCount++;
              cout << tgCount << endl;
              cout << "" << endl;
            }
            if (char1 == 't' && char2 == 'c')
            {
              tcCount++;
              cout << tcCount << endl;
              cout << "" << endl;
            }
            if (char1 == 'g' && char2 == 'a')
            {
              gaCount++;
              cout << gaCount << endl;
              cout << "" << endl;
            }
            if (char1 == 'g' && char2 == 't')
            {
              gtCount++;
              cout << gtCount << endl;
              cout << "" << endl;
            }
            if (char1 == 'g' && char2 == 'g')
            {
              ggCount++;
              cout << ggCount << endl;
              cout << "" << endl;
            }
            if (char1 == 'g' && char2 == 'c')
            {
              gcCount++;
              cout << gcCount << endl;
              cout << "" << endl;
            }
            if (char1 == 'c' && char2 == 'a')
            {
              caCount++;
              cout << caCount << endl;
              cout << "" << endl;
            }
            if (char1 == 'c' && char2 == 't')
            {
              ctCount++;
              cout << ctCount << endl;
              cout << "" << endl;
            }
            if (char1 == 'c' && char2 == 'g')
            {
              cgCount++;
              cout << cgCount << endl;
              cout << "" << endl;
            }
            if (char1 == 'c' && char2 == 'c')
            {
              ccCount++;
              cout << ccCount << endl;
              cout << "" << endl;
            }
          }
        }
      }

      for (char letter : line)
      {
        if (isupper(letter))
        {
          letter = tolower(letter);
        }
        /*if (line.find( !'a' || !'t' || !'g' || !'c') != string::npos)
        {
          break;
        }
        else
        {
          cout << letter << endl;

        }*/


        /*if (letter != 'a' || letter != 't' || letter != 'g' || letter != 'c')
        {

          //cout << "hello" << endl;
          break;

        }*/


          totalChar++;
        //}
          size_t found = line.find_first_not_of("agctACGT");

          if (found != string::npos)
          {
            //cout << found << endl;
            //cout << totalChar << endl;
            //totalChar - found;
            //cout << totalChar << endl;
            totalChar--;
            //cout << numofLines << endl;
            numofLines--;
            //cout << numofLines << endl;
            //cout << totalChar << endl;
            break;
          }
          else if (letter == 'a')
          {
            aCount++;
            /*cout << "a: " << endl;
            cout << aCount << endl;*/
          }
          else if (letter == 't')
          {
            tCount++;
            /*cout << "t: " << endl;
            cout << tCount << endl;*/
          }
          else if (letter == 'g')
          {
            gCount++;
            /*cout << "g: " << endl;
            cout << gCount << endl;*/
          }
          else if (letter == 'c')
          {
            cCount++;
            /*cout << "c: " << endl;
            cout << cCount << endl;*/
          }
          //cout << totalChar << endl;



        //}
        /*else
        {
          numofLines--;
          cout << numofLines << endl;

        }*/


      }


    }
    //myFile.close();
    cout << totalChar << endl;
    cout << numofLines << endl;

    sum = totalChar;
    mean = sum/numofLines;
    cout << sum << endl;
    cout << mean << endl;


    myFile.clear();
    myFile.seekg(0);


    //cout << 138/11 << endl;

    while(!myFile.eof())
    {
      getline(myFile, line);
      lineLength = line.length();
      //cout << lineLength << endl;

      size_t found = line.find_first_not_of("agctACGT");

      if (found != string::npos)
      {}
      else if (line != "")
      {
        variance += (pow(lineLength - mean, 2));
        //cout << lineLength << endl;
        //cout << mean << endl;
        //out << "variance" << endl;
        //cout << variance << endl;
      }
    }
    variance /= numofLines;
    cout << variance << endl;
    standardDeviation = sqrt(variance);
    cout << standardDeviation << endl;
    myFile.close();


    return 0;
}
