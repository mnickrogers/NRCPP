# NRCPP
Useful C++ functions for tasks from stats to file IO.

##NR Stats
###Basic
All basic functions accept arrays or vectors where appropriate.

* mean - allows specification of value to substract with when averaging. This is useful for standard deviation calculations.
* median
* mode

###Less basic but still kinda basic
* standard_deviation - accepts a vector / array and you can specificy sample or population (population is default)
* count_for_item - accepts a vector / array and returns the times a given item appears in it
* standard_deviation_of_matching_items - accepts a vector / array and returns the standard deviation of indices for matching items

##NR Files
* put_file_in_vector - converts elements separated by a specified character into a vector
* get_words_from_file - extracts individual words from a file and places them into a vector
* get_lines_from_file - extracts individual lines from a file and places them into a vector
* get_unique_word_set_from_file - returns a set of unique words from a file where there are no duplicates
* get_string_from_file - turns a file into one string
* get_word_count_in_file - returns the number of times a word appears in a file
* get_word_count_from_unordered_set_in_file - returns the number of times items in a set appear in a file
* get_word_count_from_vector_in_file - returns the number of times items in a vector appear in a file

##NR Utilities
* convert_array_string_to_double - converts an array of strings into an array of doubles
* convert_vector_string_to_double - converts a vector of strings into a vector of doubles

##NR Strings
* isPunctuation - returns true if character is a puncuation mark (currently highly restrictive)
* isNotAlphanumeric - returns true if the character is not alphanumeric
* get_words_in_string - tokenizes a string into words
* get_word_count_from_string_matching_string - returns the number of times a string appears as a substring of another string
* get_word_count_from_string_matching_vector - returns the number of times strings in a vector appear as substrings of another string
* get_word_count_from_string_matching_array - returns the number of times strings in an array appear as substrings of another string

##NR Scanner
This class is inspired by Apple's Foundation NSScanner.
#####Extracting parts of a string until a match:

    std::string testString("This string is a string and this is more data in-between a string");
    nr::scanner s(testString);
    
    std::string targetString("string");
    std::string result = s.scan_up_to_string(targetString);
    
    std::cout << result << std::endl;
Outputs: "This "

#####Extracting multiple values in-between matching strings:

    std::string testString("This string is a string and this is more data in-between a string");
    nr::scanner s(testString);
    
    std::string targetString("string");
    std::string result("");
    
    while (!s.is_at_end())
    {
        s.scan_up_to_string(targetString);
        s.scan_string(targetString);
        result += s.scan_up_to_string(targetString);
    }
    
    std::cout << result << std::endl;
Outputs: "is a and this is more data in-between a"

C++ has built-in, optimized functions for finding matches in strings just as Foundation's NSString has class methods for the like, but the hope here was to expose a more customizable interface to give granular control over how, for example, special characters, numbers and spaces are considered when scanning.
