#pragma once

#include <iostream>
#include <vector>

using namespace std;

bool ImportVectors(const string& fileName,
                   double& S,
                   size_t& n,
                   double*& w,
                   double*& r);

double RateOfReturn(const size_t& n,
                    const double* const& w,
                    const double* const& r);

double FinalValue(const double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r);

bool ExportResult(const string& outputFileName,
                  const double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& rate,
                  const double& value);

string ArrayToString(const size_t& n,
                     const double* const& v);
