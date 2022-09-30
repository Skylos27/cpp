#pragma once

#include <algorithm>
#include <ostream>
#include <initializer_list>
#include <cassert>

#include <vector>

#include "config.h"

class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector()
    {
    }

    Vector(std::initializer_list<int> list) : _list(list)
    {
    }
    // possibly more

// Public Member functions here
    Vector& operator+=(const Vector& rhs)
    {
        _list.insert(_list.end(), rhs.begin(), rhs.end());
        return *this;
    }

    Vector& operator+=(const int value)
    {
        _list.insert(_list.end(), value);
        return *this;
    }

    Vector& operator-=(const Vector& rhs)
    {
        int idx = 0;
        
        for (auto begin = rhs.begin(); begin != rhs.end(); begin++) 
            _list[idx++] -= *begin;
        return *this;
    }

    int &operator[](int index)
    {
        if (index >= _list.size())
            _list.resize(index + 1);
        return _list[index];
    }

    Vector operator+(const Vector &other)
    {
        Vector x{};
        int idx = 0;

        for (auto begin = other.begin(); begin != other.end(); begin++, idx++) { 
            int l = *begin, r;

            if (idx >= _list.size())
                r = 0;
            else
                r = _list[idx];

            x += (l + r);
        }

        return x;
    }

    Vector operator*(const int n)
    {
        Vector x;
        int idx = 0;
        
        for (auto begin = _list.begin(); begin != _list.end(); begin++) 
            x += (3 * _list[idx++]);

        return x;
    }

    Vector &operator*=(const int n)
    {
        int idx = 0;
        
        for (auto begin = _list.begin(); begin != _list.end(); begin++) 
            _list[idx++] *= n;

        return *this;
    }

    int operator*(const Vector &other)
    {
        int idx = 0;
        int res = 0;
        
        for (auto begin = other.begin(); begin != other.end(); begin++) 
            res += (*begin * _list[idx++]);

        return res;
    }

    std::vector<int>::const_iterator begin() const
    {
        return _list.begin();
    }

    std::vector<int>::const_iterator end() const
    {
        return _list.end();
    }

    bool isEmpty() const
    {
        return _list.empty();
    }

    // More to go

private:
// Private Member functions here (if necessary)

// Member variables are ALWAYS private, and they go here
    std::vector<int> _list;

};

std::ostream& operator<<(std::ostream& os, const Vector& vector)
{
    if (vector.isEmpty())
    {
        os << "{}";
        return os;
    }

    os << "{";

    for (auto begin = vector.begin(); begin != vector.end(); begin++) 
    {
        os << *begin;
        if (begin + 1 != vector.end()) os << ",";
    }

    os << "}";

    return os;
}

// Nonmember function operators go here