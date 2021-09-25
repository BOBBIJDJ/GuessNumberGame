#include <cstdlib>
#include <ctime>

int RdNumFn(int MinRdNum, int MaxRdNum) {
  
  int RdNum;
  
  srand(time(NULL));
  
  MaxRdNum++;
  
  RdNum = (MinRdNum + (rand() % (MaxRdNum - MinRdNum)));
  
  return RdNum;
}
