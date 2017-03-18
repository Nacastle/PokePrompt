#pragma once
#include "BTreeNode.h"
#include "BTree.h"
#include <iostream>
#include <vector>
using namespace std;

class BTreePrinter
{
   struct NodeInfo
   {
      std::string text;
      unsigned text_pos, text_end;
   };

   typedef std::vector<NodeInfo> LevelInfo;

   std::vector<LevelInfo> levels;

   std::string node_text (int const keys[], unsigned key_count);

   void before_traversal ()
   {
      levels.resize(0);
      levels.reserve(10);
   }

   void visit (BTreeNode const *node, unsigned level = 0, unsigned child_index = 0);

   void after_traversal ();

public:
   void print(BTree const &tree){
      before_traversal();
      visit(tree.root);
      after_traversal();
   }
};