#pragma once

/*
"cevaluator.hpp" created by grkon(Twitter: @progblog_note)
About :
    Evaluation calculator for the 3 dimensions yonmoku in a board of 4 * 4 * 4 squares.
    Usage is commented out.
*/

#include "csquares.hpp"
#include <string>
#include <fstream>

// definition of constant

#define LINE_DAT_ID 1 // id of line.dat
#define LINE_DAT_SIZE 76 // size of line.dat
#define LINE_DAT_FILE "data/line.dat" // file name of line.dat
#define LINE_DAT_DEFAULT 3 // default value of line.dat
#define LINE_DAT_TYPE double // data type of line.dat

/*
translator from ID to constant
argument is {dataname}_DAT_ID
dataname:
    - LINE
return {dataname}'s size/file name/default value/data type
*/

int datasize_byID(int);
std::string datafile_byID(int);
template <typename T> T datadefault_byID(int);

/*
initialize data of AI:
first argument is id of data file
second argument is the size of data
behavior depending on third argument
    - true  : delete data in the file and create new data,
              return true
    - false : if the file don't exist, create new file and data,
              return true if the path exists, or false if else
typename is type of value
*/
template <typename T> bool data_init(int, bool);

/*
get data of AI:
first argument is id of data file
second argument is the pointer of data container
    (*) you must put the pointer, not array
return true if success, or false if else
typename is type of value
*/
template <typename T> bool data_get(int, T *);

/*
put data of AI:
first argument is id of data file
second argument is the array of data
return true if success, or false if else
typename is type of value
*/
template <typename T> bool data_put(int, T []);