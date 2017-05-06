// Copyright 2017 Kiparenko Ilya

#ifndef MODULES_KIPARENKO_ILYA_SYMBOLIC_DERIVATIVE_INCLUDE_SYMBOLIC_FUNCTION_H_
#define MODULES_KIPARENKO_ILYA_SYMBOLIC_DERIVATIVE_INCLUDE_SYMBOLIC_FUNCTION_H_

#include <string>
#include <vector>
#include <unordered_map>

#include "include/types_and_consts.h"

using std::vector;
using std::string;

class symbolic_function {
 public:
  explicit symbolic_function(string s);
  string to_string();
  symbolic_function();
  symbolic_function derivative(string variable);
  symbolic_function& operator=(const symbolic_function& sym);
  ~symbolic_function();

 private:
  Node* root;
  vector<string> symbols;

  Node* parse(string s);
  Node* to_postfix_form(Node* root);
  Node* postfix_to_AST(Node* root);
  Node* derivative(Node* root, string);
  void del_tree(Node* root);
  Node* copy_tree(Node* root);
  string print_tree(Node* root);
};

#endif  // MODULES_KIPARENKO_ILYA_SYMBOLIC_DERIVATIVE_INCLUDE_SYMBOLIC_FUNCTION_H_
