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

/*
translator from ID to constant
argument is {dataname}_DAT_ID
dataname:
    - LINE
return {dataname}'s size/file name/default value
*/

int datasize_byID(int);
std::string datafile_byID(int);
int datadefault_byID(int);

/*
initialize data of AI:
first argument is a path of file
second argument is the size of data
behavior depending on third argument
    - true  : delete data in the file in the path and create new data,
              return true
    - false : if the path don't exist, create new file and data,
              return true if the path exists, or false if else
*/
bool data_init(int, bool);