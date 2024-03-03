#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

#define N 50 //максимальное кол-во слов в файле
#define M 25 //максимальное кол-во букв в слове

bool root(char* rootToA,char* A){
    for(int i=0;rootToA[i]!=0;i++){
        if(rootToA[i]!=A[i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    char wordBuffer[M],wordsArr[N][M];
    int wordsNumber=0,longestWordsIndexes[N],wordsRootedToLongestIndexes[N][N],mostImportantWordsIndexes[N],
    maxRootedWords=0,rootedCounter,numberOfMostImportantWords=0;
    ifstream wordsInput("test5");
    while(wordsInput.peek()!=EOF)
    {
        wordsInput >> wordsArr[wordsNumber++];
    }
    wordsInput.close();
    wordsNumber--;


    for(int i=0;i<wordsNumber;i++){//самое важное
        rootedCounter = 0;
        for(int j=0;j<wordsNumber;j++){
            if(i==j){
                continue;
            }
            if(root(wordsArr[i],wordsArr[j])){
                rootedCounter++;
            }
        }
        if(rootedCounter==maxRootedWords){
            mostImportantWordsIndexes[numberOfMostImportantWords++] = i;
        }
        if(rootedCounter>maxRootedWords){
            maxRootedWords = rootedCounter;
            numberOfMostImportantWords = 0;
            mostImportantWordsIndexes[numberOfMostImportantWords++] = i;
        }
    }


    if(maxRootedWords!=0){
        for(int i=0;i<numberOfMostImportantWords;i++){
            cout << wordsArr[mostImportantWordsIndexes[i]] << "\t";
        }
        cout << maxRootedWords << endl;
    } else {
        cout << "NO" << endl;
    }

    /*for(int i=0;i<wordsNumber;i++){
        cout << "0" << wordsArr[i] << "0\n";
    }*/

    return 0;
}
