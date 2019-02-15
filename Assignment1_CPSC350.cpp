#include <iostream>
#include <fstream> //Using this for reading and writing files.
#include <string> //Using this for strings.
#include <cstddef> //Using this for size_t
#include<cmath> //Using this for math functions used.
#include<stdlib.h> // Using this in order to use rand().
using namespace std;

int main(int argc, char * argv[])
{
    srand(time(NULL)); //Refreshes any calls of rand() for every time main is run.

    string fileName = argv[1]; //Takes in a user command line argument and
                                // uses it for the name of the file for reading/

    bool programRunning = true; //Sets a bool equal to true to continuously loop
    while (programRunning)      // a majority of the code.
    {
      string line; //Using this to represent each line of the file being read from.

      string charSelection; //Using this to create a string made of a certain number
                             // of each nucleotide so a random char can be picked
                              // from it to represent probability.

      string newStrings; //Using this to store a new string for the each of the
                          // 1000 new strings.

      int aCount = 0; //Using these to store values for the amount of each
      int tCount = 0;  // of the nucleotides.
      int gCount = 0;  // ...
      int cCount = 0;  // ...

      int aaCount = 0; //Using these to store values for the amount of each
      int atCount = 0;  // of the nucleotide totalChars.
      int agCount = 0;  // ...
      int acCount = 0;  // ...
      int taCount = 0;  // ...
      int ttCount = 0;  // ...
      int tgCount = 0;  // ...
      int tcCount = 0;  // ...
      int gaCount = 0;  // ...
      int gtCount = 0;  // ...
      int ggCount = 0;  // ...
      int gcCount = 0;  // ...
      int caCount = 0;  // ...
      int ctCount = 0;  // ...
      int cgCount = 0;  // ...
      int ccCount = 0;  // ...

      int lineLength = 0; //Using this to store the length of each line as it is
                           // read from the file.

      int totalChar = 0; //Using this to store the total number of characters in the file.

      int numofLines = 0; //Using this to store the number of lines in the file.

      int sum = 0; //Using this to store the value of the sum.
      int mean = 0; //Using this to store the value of the mean.
      int variance = 0; //Using this to store the value of the variance.
      int standardDeviation = 0; //Using this to store the value of the standard deviation.

      int totalBigrams = 0; //Using this to store the total number of bigram in
                             // the file.

      double aaProb = 0; //Using these to store values for the percentages of each
      double atProb = 0;  // of the nucleotide bigram probabilities/
      double agProb = 0;  // ...
      double acProb = 0;  // ...
      double taProb = 0;  // ...
      double ttProb = 0;  // ...
      double tgProb = 0;  // ...
      double tcProb = 0;  // ...
      double gaProb = 0;  // ...
      double gtProb = 0;  // ...
      double ggProb = 0;  // ...
      double gcProb = 0;  // ...
      double caProb = 0;  // ...
      double ctProb = 0;  // ...
      double cgProb = 0;  // ...
      double ccProb = 0;  // ...

      double aProb = 0; //Using these to store values for the percentages of each
      double tProb = 0;  // of the nucleotides probabilities.
      double gProb = 0;  // ...
      double cProb = 0;  // ...

      double Gaussian1 = 0; //Using these to store values that get a length using
      double Gaussian2 = 0;  // the Gaussian distribution.


      ifstream myFile (fileName); //Makes the file "fileName" available for reading.

      while(!myFile.eof()) //A while function that continues on the end of file.
      {
        getline(myFile, line); //Reads the file line by line.

        lineLength = line.length(); //Set a value of lineLength for each line's length.

        if (line != "") //Making sure program does not count empty lines.
        {
          numofLines++; //Adds one for each line in the file.
        }

        size_t found = line.find_first_not_of("agctACGT"); //Creats a size_t that
                                                            // is the vlaue of the
                                                            // first not nucleotide
                                                            // char.

        if (found != string::npos) //If a bad char is found in a line, does nothing.
        {}
        else //If no bad char is found in a line.
        {
          if (line != "") //If line is not empty.
          {
            for (int i = 0; i < lineLength-1; i+=2) //For the duration of each line,
                                                     // going up by two at a time.
            {
              char char1 = tolower(line[i]); //Creates two variables that are
              char char2 = tolower(line[i+1]); // lowercase versions of chars from file.

              if (char1 == 'a' && char2 == 'a') //If the chars taken two at a time
              {                                  // match one of these twelve options,
                aaCount++;                       // adds one to the count variable
              }                                  // for the respective nucleotide
              if (char1 == 'a' && char2 == 't')  // bigram.
              {                                  // ...
                atCount++;                       // ...
              }                                  // ...
              if (char1 == 'a' && char2 == 'g')  // ...
              {                                  // ...
                agCount++;                       // ...
              }                                  // ...
              if (char1 == 'a' && char2 == 'c')  // ...
              {                                  // ...
                acCount++;                       // ...
              }                                  // ...
              if (char1 == 't' && char2 == 'a')  // ...
              {                                  // ...
                taCount++;                       // ...
              }                                  // ...
              if (char1 == 't' && char2 == 't')  // ...
              {                                  // ...
                ttCount++;                       // ...
              }                                  // ...
              if (char1 == 't' && char2 == 'g')  // ...
              {                                  // ...
                tgCount++;                       // ...
              }                                  // ...
              if (char1 == 't' && char2 == 'c')  // ...
              {                                  // ...
                tcCount++;                       // ...
              }                                  // ...
              if (char1 == 'g' && char2 == 'a')  // ...
              {                                  // ...
                gaCount++;                       // ...
              }                                  // ...
              if (char1 == 'g' && char2 == 't')  // ...
              {                                  // ...
                gtCount++;                       // ...
              }                                  // ...
              if (char1 == 'g' && char2 == 'g')  // ...
              {                                  // ...
                ggCount++;                       // ...
              }                                  // ...
              if (char1 == 'g' && char2 == 'c')  // ...
              {                                  // ...
                gcCount++;                       // ...
              }                                  // ...
              if (char1 == 'c' && char2 == 'a')  // ...
              {                                  // ...
                caCount++;                       // ...
              }                                  // ...
              if (char1 == 'c' && char2 == 't')  // ...
              {                                  // ...
                ctCount++;                       // ...
              }                                  // ...
              if (char1 == 'c' && char2 == 'g')  // ...
              {                                  // ...
                cgCount++;                       // ...
              }                                  // ...
              if (char1 == 'c' && char2 == 'c')  // ...
              {                                  // ...
                ccCount++;                       // ...
              }                                  // ...
            }
          }
        }

        for (char letter : line) //For each char in a line.
        {
          if (isupper(letter)) //If the char is uppercase.
          {
            letter = tolower(letter); //Make the char lowercase.
          }

          totalChar++; //Adds one to this int for each char looped through.

          size_t found = line.find_first_not_of("agctACGT"); //Creats a size_t that
                                                              // is the vlaue of the
                                                              // first not nucleotide
                                                              // char.

          if (found != string::npos) //If a bad char is found in a line
          {
            totalChar--; //Subtract one from amount of total chars.
            numofLines--; //Subtract one from number of lines.
            break; //Break out of loop.
          }
          else if (letter == 'a') //If char is certain letter, add one to
          {                        // respective counter.
            aCount++;               // ...
          }                         // ...
          else if (letter == 't')   // ...
          {                         // ...
            tCount++;               // ...
          }                         // ...
          else if (letter == 'g')   // ...
          {                         // ...
            gCount++;               // ...
          }                         // ...
          else if (letter == 'c')   // ...
          {                         // ...
            cCount++;               // ...
          }                         // ...
        }
      }

      sum = totalChar; //Makes sum value the number of total chars.
      mean = sum/numofLines; //Calculates the mean using sum and number of lines.

      totalBigrams = sum/2; //Calculates the total number of nucleotide bigrams
                             // by dividing sum by 2.

      aProb += (aCount); //Calculates the probability of each nucleotide.
      tProb += (tCount);  // ...
      gProb += (gCount);  // ...
      cProb += (cCount);  // ...
                          // ...
      aProb /= (sum);     // ...
      tProb /= (sum);     // ...
      gProb /= (sum);     // ...
      cProb /= (sum);     // ...
                          // ...
      aProb *= 100;       // ...
      tProb *= 100;       // ...
      gProb *= 100;       // ...
      cProb *= 100;       // ...

      aaProb += (aaCount); // Calculates the probability of each nucleotide bigram.
      atProb += (atCount);    // ...
      agProb += (agCount);       // ...
      acProb += (acCount);        // ...
      taProb += (taCount);        // ...
      ttProb += (ttCount);        // ...
      tgProb += (tgCount);        // ...
      tcProb += (tcCount);        // ...
      gaProb += (gaCount);        // ...
      gtProb += (gtCount);        // ...
      ggProb += (ggCount);        // ...
      gcProb += (gcCount);        // ...
      caProb += (caCount);        // ...
      ctProb += (ctCount);        // ...
      cgProb += (cgCount);        // ...
      ccProb += (ccCount);        // ...
                                  // ...
      aaProb /= (totalBigrams);   // ...
      atProb /= (totalBigrams);   // ...
      agProb /= (totalBigrams);   // ...
      acProb /= (totalBigrams);   // ...
      taProb /= (totalBigrams);   // ...
      ttProb /= (totalBigrams);   // ...
      tgProb /= (totalBigrams);   // ...
      tcProb /= (totalBigrams);   // ...
      gaProb /= (totalBigrams);   // ...
      gtProb /= (totalBigrams);   // ...
      ggProb /= (totalBigrams);   // ...
      gcProb /= (totalBigrams);   // ...
      caProb /= (totalBigrams);   // ...
      ctProb /= (totalBigrams);   // ...
      cgProb /= (totalBigrams);   // ...
      ccProb /= (totalBigrams);   // ...
                                  // ...
      aaProb *= 100;              // ...
      atProb *= 100;              // ...
      agProb *= 100;              // ...
      acProb *= 100;              // ...
      taProb *= 100;              // ...
      ttProb *= 100;              // ...
      tgProb *= 100;              // ...
      tcProb *= 100;              // ...
      gaProb *= 100;              // ...
      gtProb *= 100;              // ...
      ggProb *= 100;              // ...
      gcProb *= 100;              // ...
      caProb *= 100;              // ...
      ctProb *= 100;              // ...
      cgProb *= 100;              // ...
      ccProb *= 100;              // ...

      myFile.clear(); //Makes it possible to go through the file again.
      myFile.seekg(0); // ...

      while(!myFile.eof()) //While the file is not ended.
      {
        getline(myFile, line); //Go through file line by line.
        lineLength = line.length(); //lineLength is the length of each line.

        size_t found = line.find_first_not_of("agctACGT"); //Creats a size_t that
                                                            // is the vlaue of the
                                                            // first not nucleotide
                                                            // char.

        if (found != string::npos) //If a bad char is found in a line, does nothing.
        {}
        else if (line != "") //Else if the file is not empty.
        {
          variance += (pow(lineLength - mean, 2)); //Calculate the variance using
        }                                           // lineLength and mean.
      }

      variance /= numofLines; //Finish calculating variance.
      standardDeviation = sqrt(variance); //Calculates standard deviation.
      myFile.close(); //Closes the file.

      double roundAProb = round(aProb); //Rounds the values of each nucleotide
      double roundTProb = round(tProb);  // birgram.
      double roundGProb = round(gProb);  // ...
      double roundCProb = round(cProb);  // ...

      string numofA(roundAProb, 'A'); //Creates string of A's that is roundAProb long.
      string numofT(roundTProb, 'T'); //Creates string of T's that is roundAProb long.
      string numofG(roundGProb, 'G'); //Creates string of G's that is roundAProb long.
      string numofC(roundCProb, 'C'); //Creates string of C's that is roundAProb long.

      charSelection += numofA; //Adds numof[nucleotide]'s to one string.
      charSelection += numofT;  //...
      charSelection += numofG;  //...
      charSelection += numofC;  //...

      ofstream newFile ("justinbindi.txt"); //Writes to/creates new file named
                                             // yourname.txt.
      if (newFile.is_open()) //If the new file created is open.
      {
        newFile << "Justin Bindi" << endl; //Write my name.
        newFile << "2288002\n" << endl; //Write my student id.
        newFile << "Sum: " << sum << endl; //Write the sum.
        newFile << "Mean: " << mean << endl; //Write the mean.
        newFile << "Variance: " << variance << endl; //Write the variance.
        newFile << "Standard Deviation: " << standardDeviation << endl; //Write the standard deviation.

        newFile << "Probability of the 'A' nucleotide: " << aProb << "%" << endl; //Writes probability
        newFile << "Probability of the 'T' nucleotide: " << tProb << "%" << endl;  // of each
        newFile << "Probability of the 'G' nucleotide: " << gProb << "%" << endl;  // nucleotide.
        newFile << "Probability of the 'C' nucleotide: " << cProb << "%" << endl;  // ...

        newFile << "Probability of the 'AA' nucleotide bigram: " << aaProb << "%" << endl; // Writes
        newFile << "Probability of the 'AT' nucleotide bigram: " << atProb << "%" << endl;  // probability
        newFile << "Probability of the 'AG' nucleotide bigram: " << agProb << "%" << endl;  // of each
        newFile << "Probability of the 'AC' nucleotide bigram: " << acProb << "%" << endl;  // nucleotide
        newFile << "Probability of the 'TA' nucleotide bigram: " << taProb << "%" << endl;  // bigram.
        newFile << "Probability of the 'TT' nucleotide bigram: " << ttProb << "%" << endl;  // ...
        newFile << "Probability of the 'TG' nucleotide bigram: " << tgProb << "%" << endl;  // ...
        newFile << "Probability of the 'TC' nucleotide bigram: " << tcProb << "%" << endl;  // ...
        newFile << "Probability of the 'GA' nucleotide bigram: " << gaProb << "%" << endl;  // ...
        newFile << "Probability of the 'GT' nucleotide bigram: " << gtProb << "%" << endl;  // ...
        newFile << "Probability of the 'GG' nucleotide bigram: " << ggProb << "%" << endl;  // ...
        newFile << "Probability of the 'GC' nucleotide bigram: " << gcProb << "%" << endl;  // ...
        newFile << "Probability of the 'CA' nucleotide bigram: " << caProb << "%" << endl;  // ...
        newFile << "Probability of the 'CT' nucleotide bigram: " << ctProb << "%" << endl;  // ...
        newFile << "Probability of the 'CG' nucleotide bigram: " << cgProb << "%" << endl;  // ...
        newFile << "Probability of the 'CC' nucleotide bigram: " << ccProb << "%" << endl;  // ...

        for (int i = 0; i < 1000; i++) //For 1000 times.
        {
          newStrings = ""; //Clears any value newStrings will be.

          double rand1 = ((double) rand() / (RAND_MAX)); //Makes two random doubles
          double rand2 = ((double) rand() / (RAND_MAX));  // between 0 and 1.

          Gaussian1 = sqrt(-2 * log(rand1)) * cos ( rand2 * M_PI * 2); // Calculates the
          Gaussian2 = standardDeviation * Gaussian1 + mean;             // Gaussian value.

          for (int i = 0; i < Gaussian2 - 1; i++) //For the length of the Gaussian value.
          {
            int rand3 = rand() % 100; //Choose random value 0 through 99.
            newStrings += charSelection[rand3]; //Picks a random char from the
          }                                      //charSelection string.

          newFile << "" << endl; //Writes empty line.
          newFile << newStrings << endl; //Writes the random new string created.
        }


      }

      string answer; //Using this for user's first input.
      string goodAnswer; //Using this for the user's input in lowercase.
      string answer2; //Using this to set a new file name if user chooses to
                       // go through another list.

      cout << "Do you want to process another list?" << endl; //Asks user a question.
      cout << "Type 'Yes' or 'No'." << endl; //Asks for user input.
      cin >> answer; //Gets user input and makes it answer string.

      for (char letters : answer) //For each char in user input.
      {
        goodAnswer += tolower(letters); //Makes user input lowercase.
      }

      if (goodAnswer == "yes") //If user input is Yes.
      {
        cout << "What is the name of the file?" << endl; //Asks name of another file.
        cin >> answer2; //Gets user input and makes it answer2 string.
        fileName = answer2; //Makes the user's second input the new fileName.
      }
      else //If user input is not Yes.
      {
        programRunning = false; //Stops the loop that continuously runs the code.
      }
    }
    return 0; //Returns 0.
}
