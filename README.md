# NRCPP
Useful C++ functions for tasks from stats to file IO

##NR Stats
###Basic
All basic functions accept arrays or vectors where appropriate.

* mean - allows specification of value to substract with when averaging. This is useful for standard deviation calculations.
* median
* mode

##Less basic but still kinda basic
* standard_deviation - accepts a vector / array and you can specificy if you want to calculate population or sample

##NR Files
* put_file_in_vector - converts elements separated by a character into a vector
* get_words_from_file - extracts individual words from a file and places them into a vector
* get_lines_from_file - extracts individual lines from a file and places them into a vector

##NR Utilities
* convert_array_string_to_double - converts an array of strings into an array of doubles
* convert_vector_string_to_double - converts a vector of strings into a vector of doubles