#include <fstream>
#include <string>
#include <iostream>

using namespace std;

//commented cout's are what I used for debugging

int main(){
    fstream inputFile;
    inputFile.open("input.txt");

    string in = "";
    string temp;
    long int total = 0;

    while(!inputFile.eof()){//put it all into one line
        inputFile >> temp;
        in += temp;
    }

    int numOne, numTwo, buildstage = 0;//first number, second number, stage in mul
    bool numBuild = false;//we getting a number?
    string numB;//number as we build it

    for(int i = 0; i < in.length(); i++){//go through one character at a time
        cout << in[i] << " ";
        if(buildstage == 0 && in[i] == 'm')//if it's a m move forwards
            buildstage++;
        else if(buildstage == 1 && in[i] == 'u')//if it's a u move forwards
            buildstage++;
        else if (buildstage == 1)//not a u and looking for a u restart
            buildstage = 0;
        else if(buildstage == 2 && in[i] == 'l')//etc for rest of mul(
            buildstage++;
        else if (buildstage == 2)
            buildstage = 0;
        else if(buildstage == 3 && in[i] == '(')
            buildstage++;
        else if (buildstage == 3)
            buildstage = 0;
        else if((buildstage == 4 || buildstage == 6) && isdigit(in[i])){//at a place where we want a number + we've found a digit
            if(!numBuild){//new number!
                numBuild = true;//looking for numbers now
                numB = "";//reset string
            }
            numB += in[i];//add the digit
        }
        else if((buildstage == 4 || buildstage == 6) && numBuild){//want numbers & looking for numbers & didn't find a number
            numBuild = false;//number over
            if(buildstage == 4)//if first, set first num
                numOne = stoi(numB);
            else
                numTwo = stoi(numB);//if second
            buildstage++;//move forwards
            if(in[i] == ',')//just do it here + now, easier that way
                buildstage++;
            else if(buildstage == 5)//wanted a ',' but didn't get one(above)
                buildstage = 0;
            else if(buildstage == 7 && in[i] == ')')//want a ) to close out mult, got it
                buildstage++;
            else if(buildstage == 7)//didn't get it
                buildstage = 0;
        }
        else if(buildstage == 5)//incase num shenanigans
            buildstage = 0;
        else if(buildstage == 7)//as above
            buildstage = 0;
        cout << buildstage << " " << numB << endl;
        if(buildstage == 8){//we did it!
            cout << endl << numOne << " x " << numTwo << " = " << numOne * numTwo << endl;
            total += numOne * numTwo;//add first and second to total
            cout << total << endl << endl;
            buildstage = 0;//start over
        }
    }
    cout << total;//gimme
    inputFile.close();//closing house
}