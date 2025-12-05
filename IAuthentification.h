#pragma once
#include <string>
using namespace std;

class IAuthentification
{
public:
    virtual bool authenticate(const string& id, const string& code) = 0;
    virtual ~IAuthentification() = default;
};

