#pragma once

/*
"cevaluator.hpp" created by grkon(Twitter: @progblog_note)
About :
    Evaluation calculator for the 3 dimensions 4 in A Row in a board of 4 * 4 * 4 squares.
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
typedef double LINE_DAT_TYPE; // data type of line.dat

//// data handler

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

//// evaluator

class CEVALUATOR {
    private:
    //variable

    /*
    line evaluation data
    */
    LINE_DAT_TYPE line_data[LINE_DAT_SIZE];


    /*
    board which is analayzed latter
    */
    CSQUARES now_analyzed_squares;

    /*
    best move of "now_analyzed_squares"
    In the unanalyzed index, the variable is assigned -1
    */
    int bestmove[64];
    /*
    evaluation of "now_analyzed_squares"
    */
    int now_evaluation;

    public:
    // constructor

    CEVALUATOR(); // no data set (using default value)
    CEVALUATOR(LINE_DAT_TYPE [LINE_DAT_SIZE]); // use data set

    public:
    // functions


    private:
    // private functions

    /*
    calculate temporary evaluation:
    calculate temporary evaluation of board of first argument
    return evaluation
    */
    double temporary_evaluator(CSQUARES);

    /*
    search by alpha beta prunning:
    search board of first argument
    second, third argument is alpha, beta
    fourth argument is depth/node
    fifth argument is max depth/max node
    return evaluation
    */
    double evaluator_main(CSQUARES, int, int, int, int);
};