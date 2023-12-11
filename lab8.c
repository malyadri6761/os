// #include <stdio.h>
// #include<time.h>
// #include<stdlib.h>
// #define PAGE_SIZE 4096 // Assuming a page size of 4 KB

// void logicalToPageOffsetAndNumber(int logicalAddress, int *pageNumber, int *pageOffset) {
//     *pageNumber = abs(logicalAddress) / PAGE_SIZE;
//     *pageOffset = abs(logicalAddress) % PAGE_SIZE;
// }

// int pageOffsetAndNumberToLogical(int pageNumber, int pageOffset) {
//     return pageNumber * PAGE_SIZE + pageOffset;
// }

// unsigned int generateRandom32BitNumber() {
//     // Seed the random number generator with the current time
//     srand((unsigned int)time(NULL));

//     // Generate four 8-bit random numbers and concatenate them
//     unsigned int random32BitNumber =
//         (rand() & 0xFF) | ((rand() & 0xFF) << 8) | ((rand() & 0xFF) << 16) | ((rand() & 0xFF) << 24);

//     return random32BitNumber;
// }
// int main() {
//     int logicalAddress, pageNumber, pageOffset;

//     // Example: Assuming a 32-bit logical address               
//     logicalAddress=generateRandom32BitNumber();

//     logicalToPageOffsetAndNumber(logicalAddress, &pageNumber, &pageOffset);

//     printf("Page Number: %d\n", pageNumber);
//     printf("Page Offset: %d\n", pageOffset);

//     // Example: Convert page number and page offset back to logical address
//     int newLogicalAddress = pageOffsetAndNumberToLogical(pageNumber, pageOffset);
//     printf("Converted Logical Address: %d\n", newLogicalAddress);

//     return 0;
// }


#include<stdio.h>
#include<stdlib.h>