# MNXB11-Project

In this project, the program takes data from the Swedish Meteorological and Hydrological Institute (SMHI), and produces three plots for analysis. Each plot uses data from different cities in Sweden. The cities chosen were Umeå, Uppsala, Lund.

# About code

## Reading Data files

At the start of the Uppsala.cxx, UMEA.cxx, Lund.cxx files, the functions read the .csv of the data. It does it as follows:

```cpp

// Defining our variables, and vectors
string line;
vector<string> DataStore;
vector<string> Date;
vector<string> Time;
vector<double> Air_Temp;
vector<string> Quality;

// Opening data file
ifstream file{"DataFile.csv"};

// While loop going through a line, stops at '\n' or in other words at the end of the line. This is done for each line
while( getline(file, line, '\n') ) {

  istringstream sline(line);
  string word;

// While loop doing a similar thing, but stopping at ',' then appending the sequence of characters to the vector DataStore
  while( getline(sline, word, ',') ) {
    DataStore.push_back(word);
  }
}
```

Instructions on how the Uppsala.cxx, UMEA.cxx, and Lund.cxx generate plots are available as comments in the respective source files.

# How to use program

The program is simple to use. To generate the plots all that is required is to run 'make' in the terminal and be sure to be in the same directory as the MakeFile.