#include "../include/Uppsala.h"

void Uppsala() {
    // Defining our variables, and vectors
    string line;
    vector<string> DataStore;
    vector<string> Date;
    vector<string> Time;
    vector<double> Air_Temp;
    vector<string> Quality;

    // Opening data file
    ifstream file{"../datasets/rawdata_smhi-opendata_1_97530_20231007_155803_Uppsala.csv"};

    // While loop going through a line, stops at '\n' or in other words at the end of the line. This is done for each line
    while( getline(file, line, '\n') ) {
        
        istringstream sline(line);
        string word;

        // While loop doing a similar thing, but stopping at ',' then appending the sequence of characters to the vector DataStore
        while( getline(sline, word, ',') ) {
            DataStore.push_back(word);
        }
    }

    // Loops through DataStore and appends specific elements to their respective vectors.
    int i{0};
    while (i < DataStore.size()/4) {
        Date.push_back(DataStore[4*i]);
        Time.push_back(DataStore[4*i + 1]);
        auto Temp = atof(DataStore[4*i + 2].c_str());
        Air_Temp.push_back(Temp);
        Quality.push_back(DataStore[4*i + 3]);
        i += 1;
    }

    // Creating an empty 1D histogram with title "Count vs Temperature", x-axis label "T (c)", y-axis label "Count",
    // with a bin size of 50, and x-axis bounds [-20, 30].
    TH1D* graph = new TH1D("graph", "Count vs Temperature; T (C); Data Count", 50, -20, 30);

    // Filling histogram with values from vector Air_Temp
    for (int i=0; i < Date.size(); i++) {
        graph->Fill(Air_Temp[i]);
    }

    // Creating a canvas, setting a marker style to 20, removing histogram info and drawing the histogram.
    TCanvas* c1 = new TCanvas("c1", "Plot", 900, 600);
    graph->SetMarkerStyle(20);
    gStyle->SetOptStat(0); // Removes the histogram info
    graph->Draw();
};