/*Jennifer Nguyen
2320560
jenguyen@chapman.edu
CPSC 350-02
Assignment 1: C++ Review*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(int argc, char** argv){

    //accept command line argument of text file name
    //check argument
    if(argc < 2){
        cout << "Invalid usage, please provide an input file" << endl;
        exit(-1);
    }

    bool firstWrite = true; //used to have name and id print only once
    string fileName = argv[1];

    while(fileName != "no"){

        int countNucleotide = 0;
        int countBigram = 0;
        int countA = 0;
        int countAA = 0;
        int countAC = 0;
        int countAG = 0;
        int countAT = 0;
        int countC = 0;
        int countCA = 0;
        int countCC = 0;
        int countCG = 0;
        int countCT = 0;
        int countG = 0;
        int countGA = 0;
        int countGC = 0;
        int countGG = 0;
        int countGT = 0;
        int countT = 0;
        int countTA = 0;
        int countTC = 0;
        int countTG = 0;
        int countTT = 0;

        int countStr = 0;
        int totalStrlen = 0;

        //open file
        string line;
        ifstream inputFile(fileName);
        if(inputFile.is_open()){
            //read line by line
            while(getline(inputFile,line)){

                string bigram = "  ";
                for(int i = 0; i < (line.length()-1); ++i){
                    //capitalize char
                    line[i] = toupper(line[i]);
                    ++countNucleotide;

                    //to prevent double counting bigrams
                    if(i % 2 != 0){
                        ++countBigram;
                        bigram = line[i-1];
                        bigram += line[i];
                        if(bigram == "AA"){
                            ++countAA;
                        }
                        else if(bigram == "AC"){
                            ++countAC;
                        }
                        else if(bigram == "AG"){
                            ++countAG;
                        }
                        else if(bigram == "AT"){
                            ++countAT;
                        }
                        else if(bigram == "CA"){
                            ++countCA;
                        }
                        else if(bigram == "CC"){
                            ++countCC;
                        }
                        else if(bigram == "CG"){
                            ++countCG;
                        }
                        else if(bigram == "CT"){
                            ++countCT;
                        }
                        else if(bigram == "GA"){
                            ++countGA;
                        }
                        else if(bigram == "GC"){
                            ++countGC;
                        }
                        else if(bigram == "GG"){
                            ++countGG;
                        }
                        else if(bigram == "GT"){
                            ++countGT;
                        }
                        else if(bigram == "TA"){
                            ++countTA;
                        }
                        else if(bigram == "TC"){
                            ++countTC;
                        }
                        else if(bigram == "TG"){
                            ++countTG;
                        }
                        else if(bigram == "TT"){
                            ++countTT;
                        }
                        else{
                            //invalid bigram
                            --countBigram;
                        }
                    }

                    if(line[i] == 'A'){
                        ++countA;
                    }
                    else if(line[i] == 'C'){
                        ++countC;
                    }
                    else if(line[i] == 'G'){
                        ++countG;
                    }
                    else if(line[i] == 'T'){
                        ++countT;
                    }

                }

                //update string stats
                ++countStr;
                totalStrlen += (line.length()-1);
            }
            inputFile.close();
        }

        float mean = (float)totalStrlen/countStr;
        float differences = 0;
        float variance = 0;
        float stddev = 0;

        //read file again to calculate standard deviation
        ifstream readAgain(fileName);
        if(readAgain.is_open()){
            //read line by line
            while(getline(readAgain,line)){
                float temp = (line.length() - 1) - mean;
                differences += (temp*temp);
            }
            readAgain.close();
        }
        variance = differences/countStr;
        stddev = sqrt(variance);

        float probA = (float)countA/countNucleotide;
        float probC = (float)countC/countNucleotide;
        float probG = (float)countG/countNucleotide;
        float probT = (float)countT/countNucleotide;
        float probAA = (float)countAA/countBigram;
        float probAC = (float)countAC/countBigram;
        float probAG = (float)countAG/countBigram;
        float probAT = (float)countAT/countBigram;
        float probCA = (float)countCA/countBigram;
        float probCC = (float)countCC/countBigram;
        float probCG = (float)countCG/countBigram;
        float probCT = (float)countCT/countBigram;
        float probGA = (float)countGA/countBigram;
        float probGC = (float)countGC/countBigram;
        float probGG = (float)countGG/countBigram;
        float probGT = (float)countGT/countBigram;
        float probTA = (float)countTA/countBigram;
        float probTC = (float)countTC/countBigram;
        float probTG = (float)countTG/countBigram;
        float probTT = (float)countTT/countBigram;

        //open output file
        ofstream outputFile;
        outputFile.open("Nguyen.txt",ios::app);
        if(firstWrite == true){
            //print name and ID
            outputFile << "Jennifer Nguyen" << endl << "2320560" << endl;
            firstWrite = false;
        }
        outputFile << endl;
        //print stats for file
        outputFile << "Sum of length of DNA strings: " << totalStrlen << endl;
        outputFile << "Mean of length of DNA strings: " << mean << endl;
        outputFile << "Variance of length of DNA strings: " << variance << endl;
        outputFile << "Standard deviation of length of DNA strings: " << stddev << endl;
        outputFile << "Probability of nucleotides" << endl
        << "    A: " << probA << endl
        << "    C: " << probC << endl
        << "    G: " << probG << endl
        << "    T: " << probT << endl;
        outputFile << "Probability of bigrams" << endl
        << "    AA: " << probAA << endl
        << "    AC: " << probAC << endl
        << "    AG: " << probAG << endl
        << "    AT: " << probAT << endl
        << "    CA: " << probCA << endl
        << "    CC: " << probCC << endl
        << "    CG: " << probCG << endl
        << "    CT: " << probCT << endl
        << "    GA: " << probGA << endl
        << "    GC: " << probGC << endl
        << "    GG: " << probGG << endl
        << "    GT: " << probGT << endl
        << "    TA: " << probTA << endl
        << "    TC: " << probTC << endl
        << "    TG: " << probTG << endl
        << "    TT: " << probTT << endl;
        outputFile << endl;

        //generate 1000 strings with same stats
        for(int j = 0; j < 1000; ++j){
            float varA = (float)(rand())/(float)(RAND_MAX);
            float varB = (float)(rand())/(float)(RAND_MAX);
            float varC = sqrt(-2 * log(varA)) * cos(2 * M_PI * varB);
            float varD = (stddev * varC) + mean;
            for(int k = 0; k < varD; ++k){
                float varN = (float)(rand())/(float)(RAND_MAX);
                if(varN < probA){
                    outputFile << "A";
                }
                else if(varN < (probA + probC)){
                    outputFile << "C";
                }
                else if(varN < (probA + probC + probG)){
                    outputFile << "G";
                }
                else{
                    outputFile << "T";
                }
            }
            outputFile << endl;
        }

        outputFile.close();

        //ask if repeat
        cout << "Another file? yes/no" << endl;
        cin >> fileName;
        if(fileName == "yes"){
            cout << "What is the file's name?" << endl;
            cin >> fileName;
        }
        else{
            fileName = "no";
        }

    }

    return 0;
}
