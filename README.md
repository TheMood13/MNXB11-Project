# MNXB11-Project

In this project, the program takes data from the Swedish Meteorological and Hydrological Institute (SMHI), and produces three plots for analysis. Each plot uses data from different cities in Sweden. The cities chosen were Umeå, Uppsala, Lund.

# About code

## Reading Data files

The first step is to clean the data as to be useable, and this is done by using the BASH script 'smhicleaner.sh.solution' found in the datasets/ directory in the repository. The code to run in the terminal is as follows:
```sh
./smhicleaner.sh.solution DataSet.csv
```

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

The program is simple to use. Go into the src/ directory, go into root and type '.L FileName.cxx'. Choose which city you would like to have a generated plot for (Uppsala.cxx, UMEA.cxx or Lund.cxx). Uppsala.cxx generates a plot for Counts vs Temperature, UMEA.cxx generates a plot for Average Temperature Per Year, and Lund.cxx generates a plot for Average Temperature Per Day for the year 1986 (year of Chernobyl accident).

# Directory to ignore

Ignore the directory 'Backupfiles' as it just includes files for the developers which were scrapped from the final work.