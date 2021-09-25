#include  <iostream>
#include  "RandomNumber.h"

int GssNumFn(int MinGssNum, int MaxGssNum) {
  
  int GssUsrNum = 0, GssAtmps = 0, GssScr;
  int GssRdNum = RdNumFn(MinGssNum,MaxGssNum);
  
  std::cout << "Guess the random number between " << MinGssNum << " and " << MaxGssNum << " (included) with the fewest attemps\n\n";
  std::cin >> GssUsrNum;
  GssAtmps++;
  
  while (GssUsrNum != GssRdNum) {
    
    if (GssUsrNum < GssRdNum) {
      std::cout << "Too low, try again\n";
    }
    else {
      std::cout << "Too High, try again\n";
    }
    
    std::cin >> GssUsrNum;
    
    GssAtmps++;
    
  }
  
  GssScr = 1/(GssAtmps * 0.0002);
    
  std::cout << "congratulations you guessed the number in " << GssAtmps << " attemps, try to do better\n\n";

  return GssScr;
}