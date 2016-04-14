//
//  nr_files.hpp
//  Copyright © 2016 Nicholas Rogers.
//

#ifndef nr_files_hpp
#define nr_files_hpp

#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <cassert>

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
    
    std::vector<std::string> get_words_from_file(const std::string & filename)
    {
        std::vector<std::string> v;
        std::ifstream is(filename);
        
        assert(!is.fail());
        
        std::string s;
        while (is >> s)
            v.push_back(s);
        
        return v;
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

}

#endif /* nr_files_hpp */
