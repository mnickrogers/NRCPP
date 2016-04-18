//
//  nr_files.hpp
//  Copyright © 2016 Nicholas Rogers.
//

#pragma once

#ifndef nr_files_hpp
#define nr_files_hpp

#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <cassert>

#include "nr_strings.hpp"

namespace nr
{
    std::vector<std::string> put_file_in_vector(const std::string & filename, const char separator)
    {
        std::vector<std::string> v;
        std::ifstream is(filename);
        
        assert(!is.fail());
        
        std::string masterS;
        while (!is.eof())
        {
            std::string s;
            std::getline(is, s);
            
            std::istringstream ss(s);
            
            char c;
            while (ss.get(c))
            {
                if (c != separator)
                    masterS += c;
                else
                {
                    v.push_back(masterS);
                    masterS = "";
                }
            }
        }
        v.push_back(masterS);
        
        return v;
    }
    
    std::vector<std::string> get_words_from_file(const std::string & filename, bool exclude_punctuation)
    {
        std::vector<std::string> v;
        std::ifstream is(filename);
        
        assert(!is.fail());
        
        std::string s;
        if (exclude_punctuation)
        {
            while (is >> s)
            {
                std::string insert("");
                std::istringstream ss(s);
                char c;
                while (ss.get(c))
                    if (!isNotAlphanumeric(c))
                        insert += c;
                if (!insert.empty())
                    v.push_back(insert);
            }
        }
        else
        {
            while (is >> s)
            {
                if (!s.empty())
                    v.push_back(s);
            }
        }
        
        return v;
    }
    
    /*! Returns a set of unique words from a file where there are no duplicates */
    std::unordered_set<std::string> get_unique_word_set_from_file(const std::string & filename, bool exclude_punctuation)
    {
        std::unordered_set<std::string> set;
        
        std::ifstream is(filename);
        if (is.fail())
        {
            std::cout << "Could not open file" << std::endl;
            assert(0);
        }
        
        std::string s;
        if (exclude_punctuation)
        {
            while (is >> s)
            {
                std::string insert("");
                std::istringstream ss(s);
                char c;
                while (ss.get(c))
                    if (!isNotAlphanumeric(c))
                        insert += c;
                if (!insert.empty())
                    set.insert(insert);
            }
        }
        else
        {
            while (is >> s)
            {
                if (!s.empty())
                    set.insert(s);
            }
        }
        
        return set;
    }
    
    std::string string_from_file(const std::string & filename)
    {
        std::string result;
        
        assert(!filename.empty());
        
        std::fstream is(filename);
        if (is.fail())
        {
            std::cout << "Could not open file" << std::endl;
            assert(0);
        }
        
        while (!is.eof())
        {
            std::string s;
            std::getline(is, s);
            std::istringstream ss(s);
            
            char c;
            while (ss >> c)
                if (ss.peek() == '\n' || ss.peek() == ' ')
                {
                    result += c;
                    result += ' ';
                }
                else
                    result += c;
            result += ' ';
        }
        
        return result;
    }
    
    std::vector<std::string> get_lines_from_file(const std::string & filename)
    {
        std::vector<std::string> v;
        
        std::ifstream is(filename);
        if (is.fail())
        {
            std::cout << "Could not open file" << std::endl;
            assert(0);
        }
        
        while (!is.eof())
        {
            std::string s;
            std::getline(is, s);
            v.push_back(s);
        }
        
        return v;
    }
    
    size_t get_word_count_in_file(const std::string & filename, const std::string & targetWord)
    {
        std::vector<std::string> v = get_words_from_file(filename, true);
        size_t count(0);
        
        for (size_t i = 0; i < v.size(); i++)
            if (v[i] == targetWord)
                count++;
        return count;
    }
    
    size_t get_word_count_from_unordered_set_in_file(const std::string & filename, const std::unordered_set<std::string> & s)
    {
        size_t count(0);
        
        std::vector<std::string> words = get_words_from_file(filename, true);
        
        for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); it++)
            for (std::unordered_set<std::string>::iterator it2 = s.begin(); it2 != s.end(); it2++)
                if ((*it) == (*it2))
                    count++;
        
        return count;
    }
    
    size_t get_word_count_from_vector_in_file(const std::string & filename, std::vector<std::string> & v)
    {
        size_t count(0);
        
        std::vector<std::string> words = get_words_from_file(filename, true);
        
        for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); it++)
            for (std::vector<std::string>::iterator it2 = v.begin(); it2 != v.end(); it2++)
                if ((*it) == (*it2))
                    count++;
        
        return count;
    }

}

#endif /* nr_files_hpp */
