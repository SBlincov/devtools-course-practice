//
//  Costs.h
//  Costs
//
//  Created by Блинцов Сергей on 20.06.17.
//  Copyright © 2017 Блинцов Сергей. All rights reserved.
//

#ifndef MODULES_COST_MANAGER_INCLUDE_COSTS_H_
#define MODULES_COST_MANAGER_INCLUDE_COSTS_H_

#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Costs {
 public:
  int quantityOfRecords = 0;
  int lastRecord = 0;
  int** records;  // list of costs
  explicit Costs(int qRecords) {
    quantityOfRecords = qRecords;  // Make a global
    records = new int*[5];         // Memory allocation
    for (int i = 0; i < qRecords; i++) records[i] = new int[qRecords];
    for (int j = 0; j < 5; j++)  // Initialize costs
      for (int i = 0; i < 1000; i++) records[j][i] = 0;
  }
  Costs(const Costs &v);
  void addCost(int groupID, int cost);
  void showCostsForGroup(int groupID);
  void showAllCosts();
  int getLastCost(int groupID);
  // Getters
  int getLastRecord() const { return lastRecord; }
  int getQuantityOfRecords() const { return quantityOfRecords; }

 private:
};

#endif  // MODULES_COST_MANAGER_INCLUDE_COSTS_H_
