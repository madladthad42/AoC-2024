#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

int main(){

    ifstream input;
    input.open("input.txt");

    int levels[15], spot;
    string inlin, temp = "";
    bool ascending;//going up or down?
    bool valid = true;//breaks loop when wrong
    bool safeguard;

    int counter = 0;
    stringstream steam;

    while(!input.eof()){
        getline(input, inlin);//process whole line right now so we can reuse later

        spot = 0;
        valid = true;

        steam.str(inlin);
        int i = 0;
        while(steam >> temp){
            levels[spot] = stoi(temp);
            spot++;
        }
        steam.clear();

        if(levels[0] < levels[1])//initial check
            ascending = true;
        else
            ascending = false;

        safeguard = true;
        for(int i = 0; i < spot-1; i++){//go to second to last elem
            if(abs(levels[i] - levels[i+1]) > 3 || levels[i] == levels[i+1]){//difference is > 3 or no difference
                valid = false;
            }
            if(ascending && levels[i] > levels[i+1])
                valid = false;
            if(!ascending && levels[i] < levels[i+1])
                valid = false;
            if(!valid){
                if(safeguard){
                    safeguard = false;


                    i = 0;//restart the test
                }

                break;
            }
        }
        if(valid)
            counter++;
    }
    cout << counter;
    input.close();

}