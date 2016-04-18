//
//  nr_scanner.hpp
//  Copyright © 2016 Nicholas Rogers.
//

#pragma once

#ifndef nr_scanner_hpp
#define nr_scanner_hpp

#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <iostream>

#include "nr_strings.hpp"

namespace nr
{
    class scanner
    {
    public:
        
        typedef size_t size_type;
        
        //  PRE:
        //          None
        //  POST:
        //          Empty string
        scanner()
        {
            _string = "";
            _current_index = 0;
            _length = 0;
        }
        
        //  PRE:
        //          String to scan
        //  POST:
        //          Scanner with string to scan set as target string
        scanner(std::string & s)
        {
            _string = s;
            _current_index = 0;
            _length = s.size();
        }
        
        //  PRE:
        //          Another scanner s object
        //  POST:
        //          Scanner with the target string of scanner s
        scanner(scanner & s)
        {
            _string = s._string;
            _current_index = s._current_index;
            _length = s._length;
        }
        
        //  PRE:
        //          Any string to be scanned
        //  POST:
        //          Sets private implementation of string to the desired target string
        void set_scan_string(std::string & s)
        {
            _string = s;
            _current_index = 0;
            _length = s.size();
        }
        
        //  PRE:
        //          None
        //  POST:
        //          Number of words occurring in set input string.
        size_type word_count() const;
        
        //  PRE:
        //          String
        //  POST:
        //          Number of times word occurs in string
        size_type count_for_word(std::string &) const;
        
        //  PRE:
        //          Vector of words for which to test in string
        //  POST:
        //          Number of times words occur in string
        size_type count_for_words(std::vector<std::string> &) const;
        
        //  PRE:
        //          Array of strings for which to test in input string
        //          Size of array
        //  POST:
        //          Number of times strings occur in input string
        size_type count_for_words(std::string a[], size_type size) const;
        
        //  PRE:
        //          String s as target
        //  POST:
        //          From  _string[_current_index], _string[_current_index + 1], ... string matching s
        std::string scan_up_to_string(const std::string &);
        
        //  PRE:
        //          String s as target
        //  POST:
        //          String matching s from _string[_current_index], _string[_current_index + 1], ... _string[_length - 1]
        std::string scan_string(const std::string &);
        
        //  PRE:
        //          None
        //  POST:
        //          Resets the scanned index
        void reset_index()
        {
            _current_index = 0;
        }
        
        //  PRE:
        //          None
        //  POST:
        //          Returns current index of scanner
        size_type get_current_index () const
        {
            return _current_index;
        }
        
        //  PRE:
        //          None
        //  POST:
        //          Returns true if the scanner is at the end of the string.
        //          Returns false if the scanner is not at the end of the string.
        bool is_at_end() const
        {
            return _current_index >= _length - 1;
        }
        
        //  PRE:
        //          Fully initialized scanner s
        //  POST:
        //          Sets this scanner's target string to s scanner's target string
        void operator =(scanner & s)
        {
            _string = s._string;
            _current_index = s._current_index;
            _length = s._length;
        }
        
        //  PRE:
        //          Fully initialized scanner s
        //  POST:
        //          Returns true if this _string equals s scanner's _string
        bool operator ==(scanner & s)
        {
            return _string == s._string;
        }
        
        //  PRE:
        //          Fully initialized scanner s
        //  POST:
        //          Adds s scanner's _string onto this _string with a space in-between
        void operator +=(scanner & s)
        {
            _string += " ";
            _string += s._string;
            _length = _string.size();
        }
        
    private:
        
        std::string     _string;
        size_type       _length;
        size_type       _current_index;
        
        //  INVARIANTS:
        //      _string - the target string to scan
        //      _length - length of the target string
        //      _current_index - the current scan index of _string
        
    };
    
    typename scanner::size_type scanner::word_count() const
    {
        std::vector<std::string> v = get_words_in_string(_string);
        return v.size();
    }
    
    typename scanner::size_type scanner::count_for_word(std::string & s) const
    {
        return get_word_count_from_string_matching_string(_string, s);
    }
    
    typename scanner::size_type scanner::count_for_words(std::vector<std::string> & v) const
    {
        return get_word_count_from_string_matching_vector(_string, v);
    }
    
    typename scanner::size_type scanner::count_for_words(std::string a[], size_type size) const
    {
        return get_word_count_from_string_matching_array(_string, a, size);
    }
    
    std::string scanner::scan_up_to_string(const std::string & s)
    {
        std::string result("");
        bool found(false);
        
        for (; _current_index + s.size() < _length && !found; _current_index++)
        {
            std::string temp("");
            result += _string[_current_index];
            
            if (_string[_current_index] == s[0] && _current_index + s.size() < _length)
            {
                found = true;
                for (size_type u = 0; u < s.size() && found && _current_index + u < _length; u++)
                {
                    if (_string[_current_index + u] != s[u])
                    {
                        temp = "";
                        found = false;
                    }
                }
            }
            result += temp;
        }
        
        if (result.size() > 1)
            result.erase(result.end() - 1, result.end());
        
        if (_current_index + s.size() >= _length)
            _current_index = _length;
        
        _current_index--;
        
        return result;
    }
    
    std::string scanner::scan_string(const std::string & s)
    {
        std::string result("");
        bool scanned(false);
        
        for (; _current_index + s.size() < _length && !scanned; _current_index++)
        {
            std::string temp("");
            
            if (_current_index + s.size() >= _length)
                break;
            
            if (_string[_current_index] == s[0] && _current_index + (s.size() - 1) < _length)
            {
                scanned = true;
                for (size_type u = 0; u < s.size() && scanned && _current_index + u < _length; u++)
                {
                    temp = s[u];
                    if (_string[_current_index + u] != s[u])
                    {
                        temp = "";
                        result = "";
                        scanned = false;
                    }
                    else
                    {
                        result += temp;
                    }
                }
            }
            if (scanned)
                _current_index += result.length();
        }
        return result;
    }
}

#endif /* nr_scanner_hpp */
