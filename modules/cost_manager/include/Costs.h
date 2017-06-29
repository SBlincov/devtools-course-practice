//
//  Costs.h
//  Costs
//
//  Created by Блинцов Сергей on 20.06.17.
//  Copyright © 2017 Блинцов Сергей. All rights reserved.
//

#ifndef Costs_h
#define Costs_h

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;

class Costs {
public:
    int **records; // list of costs
    Costs(int qRecords) {
        quantityOfRecords = qRecords; // Make a global
        records = new int* [5]; // Memory allocation
        for (int i = 0; i < qRecords; i++)
            records[i] = new int[qRecords];
        for (int j = 0; j<5; j++) // Initialize costs
            for (int i = 0; i<1000; i++)
                records[j][i] = 0;
    }
    void addCost(int groupID, int cost);
    void showCostsForGroup(int groupID);
    void showAllCosts();
    int getLastCost(int groupID);
    // Getters
    int getLastRecord() const{
        return lastRecord;
    }
    int getQuantityOfRecords() const{
        return quantityOfRecords;
    }
private:
    int quantityOfRecords = 0;
    int lastRecord = 0;
};


#endif /* Costs_h */
