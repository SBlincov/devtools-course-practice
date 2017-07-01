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
  explicit Costs(int qRecords);
  Costs(const Costs &v);
  void addCost(int groupID, int cost);
  void showCostsForGroup(int groupID);
  void showAllCosts();
  int getLastCost(int groupID);

  int getLastRecord() const { return lastRecord_; }
  int getQuantityOfRecords() const { return quantityOfRecords_; }

 private:
  int quantityOfRecords_ = 0;
  int lastRecord_ = 0;
  int** records_;  // list of costs
};

#endif  // MODULES_COST_MANAGER_INCLUDE_COSTS_H_
