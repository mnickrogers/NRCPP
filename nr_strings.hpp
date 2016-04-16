//
//  nr_strings.hpp
//  Copyright © 2016 Nicholas Rogers.
//

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
    bool isGenericIgnorableCharacter(char c)
    {
        return ((c >= '!' && c <= '/') ||
                (c >= ':' && c <= '@') ||
                (c >= '[' && c <= '`') ||
                (c >= '{' && c <= '~'));
    }
}

#endif /* nr_strings_hpp */
