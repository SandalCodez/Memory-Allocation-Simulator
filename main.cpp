#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

const int PAGECAPACITY = 100;
const int PAGESIZEMB = 160;
const int STARTING = 2000;
int pageSizeCap = 80;

int processSize = 0;
int processID = 0;
int numOfPages = 0;
int unusedSpace = 0;
int nextAddress;
int currentAddress;

void userMemoryAllocation();
int pageArray[PAGECAPACITY] = {0};

int main() {
    std::srand(std::time(0));

  userMemoryAllocation();
    }
void userMemoryAllocation() {
int pageCount = 0;
        for (int i = 0; i < PAGECAPACITY; i++) {

            processID = i;

            int numPages = rand() %30 + 1;

            processSize = numPages * pageSizeCap;

            numOfPages = std::ceil((double)processSize/PAGESIZEMB);

            pageCount += numOfPages;

            unusedSpace = (numOfPages * PAGESIZEMB) - processSize;

            if (pageCount > PAGECAPACITY) {
                std::cout << "Memory full! Cannot allocate process " << processID << std::endl;
                break;
            }

            if (i ==0) {
                currentAddress = STARTING;
                nextAddress = currentAddress + (numOfPages * PAGESIZEMB);

            }else{
                currentAddress = nextAddress;
                nextAddress = currentAddress + (numOfPages * PAGESIZEMB);
            }
            std::cout << "ProcessID: " << " StartingMemory: " <<  " Size of the Process: "<< "Unused Space: " <<  std::endl;
            std::cout << "        "<<processID<<"            " <<currentAddress<<"                   "<< processSize<< "           "<<unusedSpace<< std::endl;
        }
    }



