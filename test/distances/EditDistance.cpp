//
// Created by PC on 2018/2/9.
//

#include "EditDistance.h"

/**
 * Sets the two inputs to compare
 * @param setInput1, setInput2 - the inputs to compare
 * @return - True if the input is valid and False otherwise
 */
bool EditDistance::setInput(const string& setInput1, const string& setInput2)
{ 	// validate the input, check if its empty
    if ((!setInput1.empty() && !setInput2.empty()))
    {
        input1 = setInput1;
        input2 = setInput2;

        return true;
    }
    else
        return false;
}

/**
 * Calculate the edit distance
 * @param input1, input2 - the two inputs to be compared
 * @return - the edit distance
 */
void EditDistance::calculate()
{
    vector< vector<int> > matrix (input1.size()+1, vector<int> (input2.size()+1, 0));
    vector< vector<int> > alignmentMatrix (input1.size()+1, vector<int> (input2.size()+1, 0));

    // input2 are columns of the matrix, initialize the first row from 0 to size of input2
    for (unsigned int i = 0; i < input2.size()+1; i++)
    {
        matrix[0][i] = i;
        alignmentMatrix[0][i] = 1;
    }

    // input1 are rows of the matrix, initialize the first column from 0 to size of input1
    for (unsigned int i = 0; i < input1.size()+1; i++)
    {
        matrix[i][0] = i;
        alignmentMatrix[i][0] = 0;
    }

    //Edit Distance algorithm
    for (unsigned int i = 1; i < input1.size()+1; i++)
    {
        for (unsigned int j = 1; j < input2.size()+1; j++)
        {
            // Check if its a match
            if (input1.compare(i-1,1,input2,j-1,1) == 0)
            {
                matrix[i].at(j) = matrix[i-1].at(j-1);
                alignmentMatrix[i].at(j) = 2;
            }
            else
            {
                // Check if left element is lowest
                if (matrix[i].at(j-1) <= matrix[i-1].at(j) && matrix[i].at(j-1) <= matrix[i-1].at(j-1))
                {
                    matrix[i].at(j) = matrix[i].at(j-1) + 1;
                    alignmentMatrix[i].at(j) = 1;
                }
                    // Check if top element lowest
                else if (matrix[i-1].at(j) <= matrix[i].at(j-1) && matrix[i-1].at(j) <= matrix[i-1].at(j-1))
                {
                    matrix[i].at(j) = matrix[i-1].at(j) + 1;
                    alignmentMatrix[i].at(j) = 0;
                }
                    // Else its a diagonal
                else
                {
                    matrix[i].at(j) = matrix[i-1].at(j-1) + 1;
                    alignmentMatrix[i].at(j) = 2;
                }
            }
        }
    }

    //store the distance which is at the bottom right corner of the matrix
    distance = matrix[input1.size()].at(input2.size());

    //Alignment Up = 0, Left = 1, Diagonal = 2
    int x = input1.size();
    int y = input2.size();
    string align1, align2 = "";

    while (x != 0 || y != 0)
    {
        //Up = Deletion
        if (alignmentMatrix[x].at(y) == 0)
        {
            align1 = input1.at(x-1) + align1;
            align2 = "-" + align2;
            x -= 1;
        }

            //Left = Insertion
        else if (alignmentMatrix[x].at(y) == 1)
        {
            align1 = "-" + align1;
            align2 = input2.at(y-1)+ align2;
            y -= 1;
        }
            //Diagonal = Match or Mismatch
        else if (alignmentMatrix[x].at(y) == 2)
        {
            align1 = input1.at(x-1) + align1;
            align2 = input2.at(y-1) + align2;
            x -= 1;
            y -= 1;
        }
    }

    // Concatenate the Alignment string and store it
    alignment = align1 + "\n" + align2;

    //Drawing the awful matrix
    drawMatrix = "       ";

    for (unsigned int i = 0; i < input2.size()+1; i++)
    {
        ostringstream convert;
        convert << i;

        if (i < 10)
        {
            drawMatrix = drawMatrix + "   " + convert.str() + "   ";
        }
        else
        {
            drawMatrix = drawMatrix + "  " + convert.str() + "   ";
        }
    }

    drawMatrix = drawMatrix + "\n" + "      -";

    for (unsigned int i = 0; i < input2.size()+1; i++)
    {
        drawMatrix = drawMatrix + "-------";
    }

    drawMatrix = drawMatrix + "\n" + "   0  |";

    for (unsigned int i = 0; i < input2.size()+1; i++)
    {
        ostringstream convert;
        convert << i;
        if (i < 10)
        {
            drawMatrix = drawMatrix + "   " + convert.str() + "  |";
        }
        else
        {
            drawMatrix = drawMatrix + "  " + convert.str() + "  |";
        }
    }

    for (unsigned int i = 1; i < input1.size()+1; i++)
    {
        ostringstream convert;
        convert << i;

        if (i < 10)
        {
            drawMatrix = drawMatrix + "\n" + "   " + convert.str() + "  |";
        }
        else
        {
            drawMatrix = drawMatrix + "\n" + "  " + convert.str() + "  |";
        }

        for (unsigned int j = 0; j < input2.size()+1; j++)
        {
            ostringstream convert;
            convert << matrix[i].at(j);

            if (matrix[i].at(j) < 10)
            {
                drawMatrix = drawMatrix + "   " + convert.str() + "  |";
            }
            else
            {
                drawMatrix = drawMatrix + "  " + convert.str() + "  |";
            }
        }
    }
}

/**
 * Prints out the Distance, or Alignment
 * @param None
 * @return - the text requested
 */
string EditDistance::printMatrix()
{
    return drawMatrix;
}

int EditDistance::returnDistance()
{
    return distance;
}

string EditDistance::returnAlignment()
{
    return alignment;
}