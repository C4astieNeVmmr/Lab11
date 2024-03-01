#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main(){
    int x,i=0,n=100;
    char charBuf,*str1 = new char[n],*str2 = new char[n],*strBuf = new char[1];
    //char str3[] = "testtest1",str4[] = "testtesttest2";

    /*cout << "enter x with cin:" << endl;
    cin >> x;
    cout << "x = " << x << " with cout"<< endl;

    cout << "enter x with scanf:" << endl;
    scanf("%d",&x);
    printf("x = %d with printf\n\n\n",x);*/


    FILE *fileToRead = fopen("to_fprintf_fscanf_Task1","r");
    fscanf(fileToRead,"%c",&charBuf);
    while(!feof(fileToRead)){
        str1[i] = charBuf;
        fscanf(fileToRead,"%c",&charBuf);
        //cout << str1[i] << "\t" << (int) str1[i] << endl;
        i++;
    }
    fclose(fileToRead);
    cout << "read from file with fscanf:\n" << str1 << endl;

    FILE *fileToWrite = fopen("to_fprintf_fscanf_Task1","a");
    fprintf(fileToWrite,"%c",'|');
    fclose(fileToWrite);


    ifstream streamToRead("to_fstream_Task1");
    while(streamToRead.peek()!=EOF){
        streamToRead.read(strBuf,1);
        strcat(str2,strBuf);
    }
    streamToRead.close();
    cout << "read from file with ifstream:\n" << str2 << endl;

    ofstream streamToWrite("to_fstream_Task1");
    streamToWrite.write(str2,strlen(str2));
    streamToWrite.write("@",1);
    streamToWrite.close();

    delete[] str1,str2,strBuf;
    return 0;
}