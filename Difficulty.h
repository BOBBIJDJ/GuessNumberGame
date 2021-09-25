#include <iostream>
  
int SelDiffFn(int MinMaxDiff[]) {
  
  int UsrDiff, CstmMax;
  
  std::cout << "please select the difficulty (enter the corresponding number):\n";
  std::cout << "0 - easy (0 to 50)\n";
  std::cout << "1 - medium (0 to 200)\n";
  std::cout << "2 - hard (0 to 500)\n";
  std::cout << "3 - extreme (0 to 1000)\n";
  std::cout << "4 - custom (0 to custom)\n";
  std::cin >> UsrDiff;
  
  while (UsrDiff != 0 && UsrDiff != 1 && UsrDiff != 2 && UsrDiff != 3 && UsrDiff != 4) {
    std::cout << "input not allowed, try again:\n";
    std::cin >> UsrDiff;
  }
  
  switch(UsrDiff) {
    case 0:
      MinMaxDiff[1] = 50;
    break;
    case 1:
      MinMaxDiff[1] = 200;
    break;
    case 2:
      MinMaxDiff[1] = 500;
    break;
    case 3:
      MinMaxDiff[1] = 1000;
    break;
    case 4:
      std::cout << "please enter the maximum value of the random number:\n";
      std::cin >> CstmMax;
      MinMaxDiff[1] = CstmMax;
    break;
  }
  
  return UsrDiff;
}