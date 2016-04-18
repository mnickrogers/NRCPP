//
//  nr_stats.hpp
//  Copyright © 2016 Nicholas Rogers.
//

#pragma once

#ifndef nr_stats_hpp
#define nr_stats_hpp

#include <stdlib.h>
#include <math.h>
#include <vector>
#include <unordered_map>

namespace nr
{
    template <class T>
    T mean(T a[], size_t size, int avg_subtract = 0)
    {
        T sum = T();
        for (size_t i = 0; i < size; i++)
            sum += a[i];
        return sum /= size - avg_subtract;
    }
    
    template <class T>
    T mean(std::vector<T> v, int avg_subtract = 0)
    {
        T sum = T();
        for (size_t i = 0; i < v.size(); i++)
            sum += v[i];
        return sum /= v.size() - avg_subtract;
    }
    
    template <class T>
    T median(std::vector<T> v)
    {
        std::sort(v.begin(), v.end());
        size_t size = v.size();
        
        size_t mid = (size / 2);
        
        if (size % 2 != 0)
            return v[mid];
        
        mid -= 1;
        
        T avg = (v[mid] + v[mid + 1]) / 2;
        
        return avg;
    }
    
    template <class T>
    T median(T a[], size_t size)
    {
        size_t mid = (size / 2);
        std::sort(a, a + size);
        
        if (size % 2 != 0)
            return a[mid];
        
        mid -= 1;
        
        T avg = (a[mid] + a[mid + 1]) / 2;
        
        return avg;
    }
    
    template <class T>
    T mode(std::vector<T> v)
    {
        std::unordered_map<T, size_t> m;
        
        for (size_t i = 0; i < v.size(); i++)
            m[v[i]]++;
        
        T largest = T();
        size_t largestVal(0);
        
        for (typename std::unordered_map<T, size_t>::iterator i = m.begin(); i != m.end(); i++)
            if ((*i).first > largestVal)
                largest = (*i).second;
        
        return largest;
    }
    
    template <class T>
    T mode(T a[], size_t size)
    {
        std::unordered_map<T, size_t> m;
        
        for (size_t i = 0; i < size; i++)
            m[a[i]]++;
        
        T largest = T();
        size_t largestVal(0);
        
        for (typename std::unordered_map<T, size_t>::iterator i = m.begin(); i != m.end(); i++)
            if ((*i).first > largestVal)
                largest = (*i).second;
        
        return largest;
    }
    
    template <class T>
    T standard_deviation(std::vector<T> v, bool sample)
    {
        T mn = mean(v);
        
        for (size_t i = 0; i < v.size(); i++)
            v[i] = pow((v[i] - mn), 2);
        
        T sqr_mean = mean(v, sample);
        return sqrt(sqr_mean);
    }
    
    template <class T>
    T standard_deviation(T a[], size_t size, bool sample)
    {
        T mn = mean(a, size);
        
        for (size_t i = 0; i < size; i++)
            a[i] = pow((a[i] - mn), 2);
        
        T sqr_mean = mean(a, size, sample);
        return sqrt(sqr_mean);
    }
    
    template <class T>
    size_t count_for_item(T a[], size_t size, T item)
    {
        size_t count(0);
        
        for (size_t i = 0; i < size; i++)
            if (a[i] == item) count++;
        
        return count;
    }
    
    template <class T>
    size_t count_for_item(std::vector<T> v, T item)
    {
        size_t count(0);
        
        for (typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++)
            if (*it == item) count++;
        
        return count;
    }
    
    template <class T>
    double standard_deviation_of_matching_items(T a[], size_t size, T item, bool sample)
    {
        std::vector<double> v;
        
        for (size_t i = 0; i < size; i++)
            if (a[i] == item) v.push_back(i);
        
        return standard_deviation(v, sample);
    }
    
    template <class T>
    double standard_deviation_of_matching_items(std::vector<T> v, T item, bool sample)
    {
        std::vector<double> numVec;
        
        for (size_t i = 0; i < v.size(); i++)
            if (v[i] == item) numVec.push_back(i);
        
        return standard_deviation(numVec, sample);
    }
}

#endif /* nr_stats_hpp */
