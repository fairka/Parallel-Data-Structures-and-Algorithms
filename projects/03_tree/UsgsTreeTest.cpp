/*************************************************************************
 *
 * Project: UsgsTree header
 *
 * File Name: UsgsTreeTest.h
 * Course:    CPTR 242
 * Date:      May 24, 2021
 */

#include "UsgsTree.h"
#include "BSTElement.h"
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/EarthquakeUSGS.h"
#include <queue>
#include <string>
#include <vector>

using namespace bridges;

bool UsgsTree::checkDefaultVisulization(
    BSTElement<float, EarthquakeUSGS> *root) {
  if (root != nullptr) {
    if (root->getVisualizer()->getColor() != Color("steelblue") &&
        root->getVisualizer()->getSize() != 10.0) {
      return false;
    }
    return checkDefaultVisulization(root->getLeft()) &&
           checkDefaultVisulization(root->getRight());
  }
  return true;
}