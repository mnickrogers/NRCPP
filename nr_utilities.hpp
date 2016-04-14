//
//  nr_utilities.hpp
//  Copyright © 2016 Nicholas Rogers.
//

#ifndef nr_utilities_hpp
#define nr_utilities_hpp

#include <stdio.h>
#include <vector>

namespace nr
{
    void convert_array_string_to_double(std::string s[], double d[], size_t size)
    {
        for (size_t i = 0; i < size; i++)
            d[i] = std::stod(s[i]);
    }
    
    std::vector<double> convert_vector_string_to_double(const std::vector<std::string> & v)
    {
        std::vector<double> newV;
        
      for (size_t i = 0; i < v.size(); i++)
            newV.push_back(std::stod(v[i]));
        
        return newV;
    }
}

#endif /* nr_utilities_hpp */
