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
    int wordsNumber=0,
    //длиннейшие слова     слова для которых длиннейшие=корневые          слова для которых текущее длиннейшее=корневое
    longestWordsIndexes[N],wordsRootedToLongestIndexes[N][N],   maxLen=0,bufferRootedToCurrentLongestIndexes[N],
    //кол-во слов для которых длиннейшее=корневое для каждого длиннейшего  кол-во слов для которых текущее длиннейшее=корневое
    numberOfRootedToLongestIndexes[N],                                     numberOfRootedToCurrentLongest,
    //кол-во длиннейших  важнейшие слова по индексам                   //счётчик слов, для которых текущее-корневое
    numberOfLongest=0,   mostImportantWordsIndexes[N],maxRootedWords=0,rootedCounter,
    //кол-во важнейших слов
    numberOfMostImportantWords=0;
    ifstream wordsInput("test5");
    while(wordsInput.peek()!=EOF)
    {
        wordsInput >> wordsArr[wordsNumber++];
    }
    wordsInput.close();
    wordsNumber--;


    for(int i=0;i<wordsNumber;i++){//самое длинное
        if(maxLen>strlen(wordsArr[i])){
            continue;
        }
        numberOfRootedToCurrentLongest = 0;
        for(int j=0;j<wordsNumber;j++){//находи все слова, для которых wordsArr[i] - корневое
            if(i==j){
                continue;
            }
            if(root(wordsArr[i],wordsArr[j])){
                bufferRootedToCurrentLongestIndexes[numberOfRootedToCurrentLongest++]=j;
            }
        }
        if(numberOfRootedToCurrentLongest==0){ //если wordsArr[i] не является корневым ни для каких слов
            continue;
        }
        if(maxLen==strlen(wordsArr[i])){ //если wordsArr[i] такой же длинный как предыдущие длиннейшие, добавляем его в конец
            longestWordsIndexes[numberOfLongest] = i;
            for(int j=0;j<numberOfRootedToCurrentLongest;j++){
                wordsRootedToLongestIndexes[numberOfLongest][j] = bufferRootedToCurrentLongestIndexes[j];
            }
            numberOfRootedToLongestIndexes[numberOfLongest] = numberOfRootedToCurrentLongest;
            numberOfLongest++;
        }
        if(maxLen<strlen(wordsArr[i])){ //если wordsArr[i] длинее предыдущих длиннейших, сбрасываем количество длиннейших 
            maxLen = strlen(wordsArr[i]); //и записываем его поверх старых
            longestWordsIndexes[0] = i;
            for(int j=0;j<numberOfRootedToCurrentLongest;j++){
                wordsRootedToLongestIndexes[0][j] = bufferRootedToCurrentLongestIndexes[j];
            }
            numberOfRootedToLongestIndexes[0] = numberOfRootedToCurrentLongest;
            numberOfLongest=1;
        }
    }

    for(int i=0;i<numberOfLongest;i++){//выводим длиннейшие
        cout << "longest word: " << wordsArr[longestWordsIndexes[i]] << "\twords for which it is a root:";
        for(int j=0;j<numberOfRootedToLongestIndexes[i];j++){
            cout << "\t" << wordsArr[wordsRootedToLongestIndexes[i][j]];
        }
        cout << endl;
    }


    for(int i=0;i<wordsNumber;i++){//самое важное
        rootedCounter = 0;
        for(int j=0;j<wordsNumber;j++){//считаем кол-во слов для которых wordsArr[i]-корневое
            if(i==j){
                continue;
            }
            if(root(wordsArr[i],wordsArr[j])){
                rootedCounter++;
            }
        }
        if(rootedCounter==maxRootedWords){//если новое слово такое же важное как предыдущие важнейшие,
            mostImportantWordsIndexes[numberOfMostImportantWords++] = i;//то дописываем его в конец
        }
        if(rootedCounter>maxRootedWords){//если новое слово ваднее предыдущих важнейших, то обнуляем их
            maxRootedWords = rootedCounter;//кол-во и записываем новое поверх старых
            numberOfMostImportantWords = 0;
            mostImportantWordsIndexes[numberOfMostImportantWords++] = i;
        }
    }


    if(maxRootedWords!=0){//выводим важнейшие
        cout << "the most important words: ";
        for(int i=0;i<numberOfMostImportantWords;i++){
            cout << wordsArr[mostImportantWordsIndexes[i]] << "\t";
        }
        cout << "number of words rooted to the most important: " << maxRootedWords << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
