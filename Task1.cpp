#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
#define N 200

int main(){
    int x,i=0,n=N;
    char charBuf,*str1 = new char[n],*str2 = new char[n],*strBuf = new char[1];

    cout << "enter x with cin:" << endl;
    cin >> x;
    cout << "x = " << x << " with cout"<< endl;

    cout << "enter x with scanf:" << endl;
    scanf("%d",&x);
    printf("x = %d with printf\n\n\n",x);


    FILE *fileToRead = fopen("to_fprintf_fscanf_Task1","r");
    fscanf(fileToRead,"%c",&charBuf);
    while(!feof(fileToRead)&&i<n){
        str1[i] = charBuf;
        fscanf(fileToRead,"%c",&charBuf);
        i++;
    }
    fclose(fileToRead);
    cout << "read from file with fscanf:\n" << str1 << endl;
    str1[i-1] = 0;
    cout << "read from file with fscanf:\n" << str1 << endl;
    
    FILE *fileToWrite = fopen("to_fprintf_fscanf_Task1","w");
    fprintf(fileToWrite,"%s",str1);
    fprintf(fileToWrite,"%s","|\n");
    fclose(fileToWrite);


    i = 0;
    ifstream streamToRead("to_fstream_Task1");
    while(streamToRead.peek()!=EOF && i<n){
        streamToRead.read(strBuf,1);
        strcat(str2,strBuf);
        i++;
    }
    streamToRead.close();
    str2[i-1] = 0;
    cout << "read from file with ifstream:\n" << str2 << endl;

    ofstream streamToWrite("to_fstream_Task1");
    streamToWrite.write(str2,strlen(str2));
    streamToWrite.write("@\n",2);
    streamToWrite.close();

    delete[] str1,str2,strBuf;
    return 0;
}