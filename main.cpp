#include <iostream>
#include <fstream>

using namespace std;

void quickSort(int* array, int rightIndex, int leftIndex=0);
int quickPart(int* array, int startIndex, int length);

int main(){

    ifstream input;
    input.open("input.txt");

    int leftList[1000];
    int rightList[1000];

    for(int i = 0; i < 1000; i++)
        input >> leftList[i] >> rightList[i];

    quickSort(leftList, 999);//give it right index, ! length
    quickSort(rightList, 999);

    int distance = 0;
    for(int i = 0; i < 1000; i++){
        if(leftList[i] >= rightList[i])
            distance += leftList[i]-rightList[i];
        else
            distance += rightList[i] - leftList[i];
    }

    cout << distance;

    return 1;
}

void quickSort(int* array, int rightIndex, int leftIndex){
    if(leftIndex < rightIndex){
        int q = quickPart(array, leftIndex, rightIndex);//gives index of poing dividing sorted arrays
        quickSort(array, q, leftIndex);//leftmost array
        quickSort(array, rightIndex, q+1); //rightmost array
    }
}

int quickPart(int* array, int leftIndex, int rightIndex){
    //my notes say Hoare Partitioning :)
    int num = array[leftIndex];//partition around first num
    int front = leftIndex;
    int back = rightIndex;
    int swapVar;
    while(true){//to infinity!
	    while(array[back] > num)//while our last num is bigger than pivot, move in
		    back--;
	    while(array[front] < num) //while our first num is smaller than pivot, move out
		    front++;
	    if (front<back){//swap front and back as long as we havent passed each other
		    swapVar = array[front];
		    array[front] = array[back];
		    array[back] = swapVar;
            back--;
            front++;
	    }
	    else return back;//when i == j, return the index seperating the two new arrays
    }
}