#include "src/Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
    string fileName = "data.csv";
    size_t n;
    double S;
    double* w = nullptr;
    double* r = nullptr;

    if (!ImportVectors(fileName, S, n, w, r))
    {
        cerr << "Something goes wrong with import" << endl;
        return -1;
    }
    else
        cout << "Import successful" << endl;

    double rate = RateOfReturn(n, w, r);
    double value = FinalValue(S, n, w, r);

    string outputFileName = "result.txt";
    if (!ExportResult(outputFileName, S, n, w, r, rate, value))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    else
        cout<< "Export successful"<< endl;

    delete[] w;
    delete[] r;

  return 0;
}

