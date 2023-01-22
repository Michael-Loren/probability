#include "dataframe.hpp"

using namespace pandas;

Dataframe::Dataframe(){

}

// Create a dataframe with a certain number of rows and columns
// Dataframe::Dataframe(int rowNum, int colNum, int valmax, int valmin) : colnum(colNum), rownum(rowNum)
// {
//     for(int i=0; i<colNum; i++){
//     }
// }

// From a 2d array of weights and a 2d array of values, produce a dataframe of columns of specified distribution and value

// ""
// ''


Dataframe::Dataframe(int rowNum, vector<vector<double>> weights, vector<vector<int>> values, vector<string> names) : colnum(weights.size()), rownum(rowNum)
{
    // iterators for the weights, values, and names vectors
    vector<vector<double>>::iterator w;
    vector<vector<int>>::iterator v;
    
    int i = 0;

    // The weights and values vectors must be of the same size.
    if (weights.size() != values.size()){
        throw std::logic_error("Values and Weights are not the same size");
        exit(1);
    }
    
    for(w = weights.begin(), v=values.begin(), i = 0; w != weights.end(), v != values.end(); w++, v++, i++)
    {
        // Index over each vector double of weights, each vector integer of values, and each string of names
        std::vector<double> currentWeights = *w;
        std::vector<int> currentValues = *v;

        // Check that the rows are not mishapen.
        if (currentWeights.size() != currentValues.size()){
            throw std::logic_error("Mishapen: Each value needs a specified weight and vice-versa.");
            exit(1);
        }

        // Create a default integer name for each column if names isn't supplied.
        if(names.empty()){
            // Add a new column using the column constructor with default names
            cols.push_back(Column(rowNum, currentWeights, currentValues, to_string(i)));
        }
        // If name is supplied, we iterate through it.
        else if(!names.empty()){
            vector<string>::iterator n;
            std::string currentName = *n;
            // Add a new column using the column constructor with specified names
            cols.push_back(Column(rowNum, currentWeights, currentValues, currentName));
            n++;
        }
    }
}


//create dataframe with same random col distribution
Dataframe::Dataframe(int rowNum, int colNum, vector<double> weights, vector<int> values) : colnum(colNum), rownum(rowNum)
{
    for (int i = 0; i < colnum; i++){
        Column c = Column(rownum, weights, values, to_string(i));
        cols.push_back(c);
    }
    
}

// Create a Dataframe from a vector of columns.
//potentially dangerous because columns could maybe be of different sizes?
Dataframe::Dataframe(vector<Column> newcols) : colnum(newcols.size()), rownum(newcols.at(0).getsize()), cols(newcols) {
    int currentsize = newcols.at(0).getsize();
    for (Column &c : newcols){
        if (c.getsize() != currentsize){
           // cout << c.getsize() << " : " << currentsize << endl;
            throw std::logic_error("Columns are not the same size");
            exit(1);
        }
    }
};


Dataframe::operator vector<Column>(){
    return cols;
}


Column Dataframe::operator[](string name)
{
    // We iterate across cols
    vector<Column>::iterator c;

    for(Column &col : cols){
        if(col.name() == name){
            return col;
        }
    }
    // Return empty column
    return Column();
}

// Apply a mask to index the rows that correspond to the boolean mask.
Dataframe Dataframe::operator[](unsigned int mask){
    vector<Column> selected;

    for(Column &c: cols){
        // Rows for which the mask evaluates true for any given column.
        selected.push_back(c[mask]);
    }
    // Call vector<Column> constructor and cast to Dataframe
    return Dataframe(selected);
    
    // For indexer i, if bool is true, we add that values from colvec to selected.
    // for(int i = 0; i < rownum; i++) if (mask[i]) selected.push_back(rows[i]);
    // return Column(selected);
}


void Dataframe::operator+=(Column column){
    if (column.getsize() != rownum){
        throw std::length_error("Added column with differing size to dataframe!");
        exit(1);
    }
    cols.push_back(column);
    colnum++;
}



void Dataframe::insert(int index, Column col){
    if (col.getsize() != rownum){
        throw std::length_error("Added column with differing size to dataframe!");
        exit(1);
    }
    cols.insert(cols.begin() + index, col);
    colnum++;
}

void Dataframe::remove(int index){
    cols.erase(cols.begin()+index);
    colnum--;
}

int Dataframe::getrows(){
    return rownum;
}

int Dataframe::getcols(){
    return colnum;
}

void Dataframe::print(){
    for (Column col : cols){
        if(!col.name().empty())
            cout << col.name() << ": ";
        col.print();
    }
    cout << endl;
}



