#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>


void selectionSort(double arr[], int n);
void swap(int *xp, int *yp);

using namespace std;

int main() {
    ofstream fout;
    fout.open("Readings.txt");

    int num;

    default_random_engine generator(time(NULL));


    uniform_real_distribution<double>distribution(50.000,90.000);


    num = rand() % 513 + 512;

    double arr [num];

    for (int i = 0; i < num; i++) {

        double j = distribution((generator));

        fout << i << " " << fixed <<setprecision(3) << j << endl;
    }
    fout.close();

    ifstream fs;
    fs.open("Readings.txt");

    int count = 0;
    double sum = 0;
    double avg = 0;
    double highest = 0;
    double lowest = 90;
    double median = 0;
    double place = 0.000;

    int i = 0;

    while(!fs.eof()) {


        fs >> place;
        count++;
        if (count % 2 == 0) {
            sum += place;
            arr[i] = place;
            //cout << i << endl;
            i++;


            if (place > highest) {
                highest = place;
            }
            if (place < lowest) {
                lowest = place;
            }
        }
        //cout << fs.get() << endl;
    }
    count = count / 2;

    avg = sum / count;

    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);

    int spot = 0;

    if(!num % 2 == 0) {
        spot = num / 2;
        median = arr[spot];
    } else {
        spot = num / 2;
        median = (arr[spot] + arr[spot + 1]) / 2;

    }

    cout << "total readings" << count << endl;
    cout << "average" << avg << endl;
    cout << "highest" << highest << endl;
    cout << "lowest" << lowest << endl;
    cout << "median" << median << endl;

    for(int i = 0; i < num; i++) {
        cout << arr[i] << endl;
    }


    return 0;


}

void swap(double *xp, double *yp)
{
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(double arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}