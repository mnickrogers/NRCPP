//
//  nr_strings.hpp
//  Copyright © 2016 Nicholas Rogers.
//

#pragma once

#ifndef nr_strings_hpp
#define nr_strings_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

namespace nr
{
    bool isPunctuation(char c)
    {
        return (c == '.' || c == ',' || c == '!' || c == '?');
    }
    bool isNotAlphanumeric(char c)
    {
        return ((c >= '!' && c <= '/') ||
                (c >= ':' && c <= '@') ||
                (c >= '[' && c <= '`') ||
                (c >= '{' && c <= '~'));
    }
    
    std::vector<std::string> get_words_in_string(const std::string & s)
    {
        std::vector<std::string> results;
        std::istringstream ss(s);
        
        char c;
        std::string str;
        while (ss >> c)
        {
            if (ss.peek() == ' ')
            {
                str += c;
                results.push_back(str);
                str = "";
            }
            else
                if (!isNotAlphanumeric(c))
                    str += c;
        }
        if (!str.empty())
            results.push_back(str);
        
        return results;
    }
    
    size_t get_word_count_from_string_matching_string(const std::string & input, std::string & matching)
    {
        size_t found(0);
        size_t pos(0);
        size_t results(0);
        
        while (pos < input.size() && found + 1 < input.size())
        {
            found = input.find(matching, found + 1);
            if (found != std::string::npos)
            {
                results++;
                pos += found;
            }
            pos++;
        }
        
        return results;
    }
    
    size_t get_word_count_from_string_matching_vector(const std::string & input, std::vector<std::string> & matching)
    {
        size_t count(0);
        
        std::vector<std::string> words = get_words_in_string(input);
        
        for (std::vector<std::string>::iterator it = matching.begin(); it != matching.end(); it++)
            for (std::vector<std::string>::iterator it2 = words.begin(); it2 != words.end(); it2++)
                if (std::string(*it) == std::string(*it2))
                    count++;
        
        return count;
    }
    
    size_t get_word_count_from_string_matching_array(const std::string & input, const std::string a[], size_t size)
    {
        size_t count(0);
        
        std::vector<std::string> words = get_words_in_string(input);
        
        for (size_t i = 0; i < size; i++)
            for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); it++)
                if (std::string(a[i]) == std::string(*it))
                    count++;
        
        return count;
    }
}

#endif /* nr_strings_hpp */
