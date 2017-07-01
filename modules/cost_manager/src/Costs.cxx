//  Costs.cpp
//
//  Created by Блинцов Сергей on 27.06.17.
//  Copyright © 2017 Блинцов Сергей. All rights reserved.
//

#include "../include/Costs.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int **records;  // list of costs
explicit Costs::Costs(int qRecords) {
  if (qRecords < 1)
      throw(std::string)"Number of records should be > 0";
  quantityOfRecords = qRecords;  // Make a global
  records = new int*[5];  // Memory allocation
  for (int i = 0; i < qRecords; i++) records[i] = new int[qRecords];
  for (int j = 0; j < 5; j++)  // Initialize costs
    for (int i = 0; i < 1000; i++) records[j][i] = 0;
}
void Costs::addCost(int groupID, int cost) {
  lastRecord = getLastCost(groupID);
  if (lastRecord != quantityOfRecords) {
    records[groupID][lastRecord] = cost;
  }  else {
    throw "List of costs are overflow";
  }
}
void Costs::showCostsForGroup(int groupID) {
  int i = 1;
  while (records[groupID][i] != 0) {
    std::cout << records[groupID][i] << std::endl;
    i++;
  }
}
void Costs::showAllCosts() {
  std::cout << "Category 0: \n \n";
  showCostsForGroup(0);
  std::cout << "Category 1: \n \n";
  showCostsForGroup(1);
  std::cout << "Category 2: \n \n";
  showCostsForGroup(2);
  std::cout << "Category 3: \n \n";
  showCostsForGroup(3);
  std::cout << "Category 4: \n \n";
  showCostsForGroup(4);
}
int Costs::getLastCost(int groupID) {
  for (int i = 1; i < quantityOfRecords; i++)
    if (records[groupID][i] == 0) return i;
  return 0;
}
