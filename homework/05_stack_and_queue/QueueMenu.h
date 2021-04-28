/*************************************************************************
 *
 * Assignment: Test driver for Queue
 *
 * File Name: QueueMenu.h
 * Course:    CPTR 242
 */
#include "QueueType.h"
#include <fstream>
#include <string>

void PrintQueue(std::ostream &dataFile, QueueType &queue);

void QueueMenu(std::istream &inStream, std::ostream &outStream,
               std::string outputLabel);
