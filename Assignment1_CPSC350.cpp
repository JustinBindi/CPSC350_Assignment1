#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include<cmath>//square root and ^2
#include<stdlib.h>//rand()
using namespace std;

int main(int argc, char * argv[])
{
    srand(time(NULL));
    string fileName = argv[1];
    bool programRunning = true;
    while (programRunning)
    {
      string line;
      string bigram;
      string charSelection;
      string generatedString;
      string newStrings;
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
      int totalBigrams = 0;
      double aaProb = 0;
      double atProb = 0;
      double agProb = 0;
      double acProb = 0;
      double taProb = 0;
      double ttProb = 0;
      double tgProb = 0;
      double tcProb = 0;
      double gaProb = 0;
      double gtProb = 0;
      double ggProb = 0;
      double gcProb = 0;
      double caProb = 0;
      double ctProb = 0;
      double cgProb = 0;
      double ccProb = 0;
      double aProb = 0;
      double tProb = 0;
      double gProb = 0;
      double cProb = 0;
      double Gaussian1 = 0;
      double Gaussian2 = 0;


      ifstream myFile (fileName);

      while(!myFile.eof())
      {
        getline(myFile, line);
        lineLength = line.length();

        if (line != "")
        {
          numofLines++;
        }

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

              if (char1 == 'a' && char2 == 'a')
              {
                aaCount++;
              }
              if (char1 == 'a' && char2 == 't')
              {
                atCount++;
              }
              if (char1 == 'a' && char2 == 'g')
              {
                agCount++;
              }
              if (char1 == 'a' && char2 == 'c')
              {
                acCount++;
              }
              if (char1 == 't' && char2 == 'a')
              {
                taCount++;
              }
              if (char1 == 't' && char2 == 't')
              {
                ttCount++;
              }
              if (char1 == 't' && char2 == 'g')
              {
                tgCount++;
              }
              if (char1 == 't' && char2 == 'c')
              {
                tcCount++;
              }
              if (char1 == 'g' && char2 == 'a')
              {
                gaCount++;
              }
              if (char1 == 'g' && char2 == 't')
              {
                gtCount++;
              }
              if (char1 == 'g' && char2 == 'g')
              {
                ggCount++;
              }
              if (char1 == 'g' && char2 == 'c')
              {
                gcCount++;
              }
              if (char1 == 'c' && char2 == 'a')
              {
                caCount++;
              }
              if (char1 == 'c' && char2 == 't')
              {
                ctCount++;
              }
              if (char1 == 'c' && char2 == 'g')
              {
                cgCount++;
              }
              if (char1 == 'c' && char2 == 'c')
              {
                ccCount++;
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

          totalChar++;
          size_t found = line.find_first_not_of("agctACGT");

          if (found != string::npos)
          {
            totalChar--;
            numofLines--;
            break;
          }
          else if (letter == 'a')
          {
            aCount++;
          }
          else if (letter == 't')
          {
            tCount++;
          }
          else if (letter == 'g')
          {
            gCount++;
          }
          else if (letter == 'c')
          {
            cCount++;
          }
        }
      }
      sum = totalChar;
      mean = sum/numofLines;

      totalBigrams = sum/2;

      aProb += (aCount);
      tProb += (tCount);
      gProb += (gCount);
      cProb += (cCount);

      aProb /= (sum);
      tProb /= (sum);
      gProb /= (sum);
      cProb /= (sum);

      aProb *= 100;
      tProb *= 100;
      gProb *= 100;
      cProb *= 100;

      aaProb += (aaCount);
      atProb += (atCount);
      agProb += (agCount);
      acProb += (acCount);
      taProb += (taCount);
      ttProb += (ttCount);
      tgProb += (tgCount);
      tcProb += (tcCount);
      gaProb += (gaCount);
      gtProb += (gtCount);
      ggProb += (ggCount);
      gcProb += (gcCount);
      caProb += (caCount);
      ctProb += (ctCount);
      cgProb += (cgCount);
      ccProb += (ccCount);

      aaProb /= (totalBigrams);
      atProb /= (totalBigrams);
      agProb /= (totalBigrams);
      acProb /= (totalBigrams);
      taProb /= (totalBigrams);
      ttProb /= (totalBigrams);
      tgProb /= (totalBigrams);
      tcProb /= (totalBigrams);
      gaProb /= (totalBigrams);
      gtProb /= (totalBigrams);
      ggProb /= (totalBigrams);
      gcProb /= (totalBigrams);
      caProb /= (totalBigrams);
      ctProb /= (totalBigrams);
      cgProb /= (totalBigrams);
      ccProb /= (totalBigrams);

      aaProb *= 100;
      atProb *= 100;
      agProb *= 100;
      acProb *= 100;
      taProb *= 100;
      ttProb *= 100;
      tgProb *= 100;
      tcProb *= 100;
      gaProb *= 100;
      gtProb *= 100;
      ggProb *= 100;
      gcProb *= 100;
      caProb *= 100;
      ctProb *= 100;
      cgProb *= 100;
      ccProb *= 100;

      myFile.clear();
      myFile.seekg(0);

      while(!myFile.eof())
      {
        getline(myFile, line);
        lineLength = line.length();

        size_t found = line.find_first_not_of("agctACGT");

        if (found != string::npos)
        {}
        else if (line != "")
        {
          variance += (pow(lineLength - mean, 2));
        }
      }
      
      variance /= numofLines;
      standardDeviation = sqrt(variance);
      myFile.close();

      double roundAProb = round(aProb);
      double roundTProb = round(tProb);
      double roundGProb = round(gProb);
      double roundCProb = round(cProb);

      string numofA(roundAProb, 'A');
      string numofT(roundTProb, 'T');
      string numofG(roundGProb, 'G');
      string numofC(roundCProb, 'C');
      charSelection += numofA;
      charSelection += numofT;
      charSelection += numofG;
      charSelection += numofC;

      ofstream newFile ("justinbindi.txt");
      if (newFile.is_open())
      {
        newFile << "Justin Bindi" << endl;
        newFile << "2288002\n" << endl;
        newFile << "Sum: " << sum << endl;
        newFile << "Mean: " << mean << endl;
        newFile << "Variance: " << variance << endl;
        newFile << "Standard Deviation: " << standardDeviation << endl;
        newFile << "Probability of the 'A' nucleotide: " << aProb << "%" << endl;
        newFile << "Probability of the 'T' nucleotide: " << tProb << "%" << endl;
        newFile << "Probability of the 'G' nucleotide: " << gProb << "%" << endl;
        newFile << "Probability of the 'C' nucleotide: " << cProb << "%" << endl;
        newFile << "Probability of the 'AA' nucleotide bigram: " << aaProb << "%" << endl;
        newFile << "Probability of the 'AT' nucleotide bigram: " << atProb << "%" << endl;
        newFile << "Probability of the 'AG' nucleotide bigram: " << agProb << "%" << endl;
        newFile << "Probability of the 'AC' nucleotide bigram: " << acProb << "%" << endl;
        newFile << "Probability of the 'TA' nucleotide bigram: " << taProb << "%" << endl;
        newFile << "Probability of the 'TT' nucleotide bigram: " << ttProb << "%" << endl;
        newFile << "Probability of the 'TG' nucleotide bigram: " << tgProb << "%" << endl;
        newFile << "Probability of the 'TC' nucleotide bigram: " << tcProb << "%" << endl;
        newFile << "Probability of the 'GA' nucleotide bigram: " << gaProb << "%" << endl;
        newFile << "Probability of the 'GT' nucleotide bigram: " << gtProb << "%" << endl;
        newFile << "Probability of the 'GG' nucleotide bigram: " << ggProb << "%" << endl;
        newFile << "Probability of the 'GC' nucleotide bigram: " << gcProb << "%" << endl;
        newFile << "Probability of the 'CA' nucleotide bigram: " << caProb << "%" << endl;
        newFile << "Probability of the 'CT' nucleotide bigram: " << ctProb << "%" << endl;
        newFile << "Probability of the 'CG' nucleotide bigram: " << cgProb << "%" << endl;
        newFile << "Probability of the 'CC' nucleotide bigram: " << ccProb << "%" << endl;

        for (int i = 0; i < 1000; i++)
        {
          newStrings = "";

          double rand1 = ((double) rand() / (RAND_MAX));
          double rand2 = ((double) rand() / (RAND_MAX));

          Gaussian1 = sqrt(-2 * log(rand1)) * cos ( rand2 * M_PI * 2);
          Gaussian2 = standardDeviation * Gaussian1 + mean;

          for (int i = 0; i < Gaussian2 - 1; i++)
          {
            int rand3 = rand() % 100;
            newStrings += charSelection[rand3];
          }

          newFile << "" << endl;
          newFile << newStrings << endl;
        }


      }

      string answer;
      string goodAnswer;
      string answer2;
      cout << "Do you want to process another list?" << endl;
      cout << "Type 'Yes' or 'No'." << endl;
      cin >> answer;

      for (char letters : answer)
      {
        goodAnswer += tolower(letters);
      }

      if (goodAnswer == "yes")
      {
        cout << "What is the name of the file?" << endl;
        cin >> answer2;
        fileName = answer2;
      }
      else
      {
        programRunning = false;
      }
    }
    return 0;
}
