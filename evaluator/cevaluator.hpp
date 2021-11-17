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

#define LINE_DAT_SIZE 76 // size of line.dat
#define LINE_DAT "data/line.dat" // name of line.dat
#define LINE_DAT_DEFAULT 3

/*
initialize data of AI:
first argument is a path of file
behavior depending on second argument
    - true  : delete data in the file in the path and create new data,
              return true
    - false : if the path don't exist, create new file and data,
              return true if the path exists, or false if else
*/
bool data_init(std::string, bool);