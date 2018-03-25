//
// Created by PC on 2018/2/9.
//

#ifndef UNTITLED_EDITDISTANCE_H
#define UNTITLED_EDITDISTANCE_H

#include <string>   /* For C++ strings */
#include <stdio.h>  /* For standard I/O */
#include <stdlib.h> /* For miscellenous C functions */
#include <vector>
#include <sstream>

using namespace std;

class EditDistance {
    /** The public members **/
public:

    /**
     * The default constructor
     */
    EditDistance(){}

    /**
     * Sets the two inputs to compare
     * @param setInput1, setInput2 - the inputs to compare
     * @return - True if the input is valid and False otherwise
     */
    bool setInput(const string&, const string&);

    /**
     * Calculate the edit distance
     * @param none
     * @return - none
     */
    void calculate();

    /**
     * Returns Matrix, Distance, or Alignment
     * @param None
     * @return - the text requested
     */
    string printMatrix();
    int returnDistance();
    string returnAlignment();

    /* The protected members */
protected:
    string input1, input2, alignment, drawMatrix;
    unsigned int distance;

};


#endif //UNTITLED_EDITDISTANCE_H
