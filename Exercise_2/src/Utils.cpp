#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

bool ImportVectors(const string& fileName,
                   double& S,
                   size_t& n,
                   double*& w,
                   double*& r)
{
    ifstream ifstr(fileName);
    char sep;

    if(ifstr.fail())
    {
        cerr << "File not found" << endl;
        return false;
    }

    do{
        ifstr >> sep;
    }while(sep!=';');

    ifstr >> S;

    do{
        ifstr >> sep;
    }while(sep!=';');

    ifstr >> n;

    string vectorNames;
    ifstr >> vectorNames;

    w = new double[n];
    r = new double[n];

    for(unsigned int i = 0; i < n; i++)
    {
        ifstr >> w[i];
        ifstr >> sep;
        ifstr >> r[i];
    }

    ifstr.close();
    return true;
}

double RateOfReturn(const size_t& n,
                    const double* const& w,
                    const double* const& r)
{
    double rate = 0;

    for(unsigned int i = 0; i < n; i++)
    {
        rate += w[i]*r[i];
    }

    return rate;
}

double FinalValue(const double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r)
{
    double value = 0;

    for(unsigned int i = 0; i < n; i++)
    {
        value += (1+r[i])*S*w[i];
    }

    return value;
}

bool ExportResult(const string& outputFileName,
                  const double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& rate,
                  const double& value)
{
    ofstream ofstr(outputFileName);

    if (ofstr.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }


    ofstr << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    ofstr << "w = " << ArrayToString(n, w) << endl;
    ofstr << "r = " << ArrayToString(n, r) << endl;

    ofstr << "Rate of return of the portfolio: " << fixed << setprecision(4) << rate << endl;
    ofstr << "V: " << fixed << setprecision(2) << value << endl;

    ofstr.close();
    return true;
}


string ArrayToString(const size_t& n,
                     const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}

