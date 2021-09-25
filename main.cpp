#include  <iostream>
#include  <cstdlib>
#include  <fstream>
#include  "Difficulty.h"
#include  "De-Encrypt.h"
#include  "GuessNumber.h"

int main()
{
  
  int CrntNumScr, HiScr[5][4], MinMaxNum[2] = {0,0}, play = 1, i, j, GssDiff;
  char CrntCharScr[4];
  std::string HiScrChar;

  for (i=0; i<5; i++) {
    for (j=0; j<4; j++) {
      HiScr[i][j]=0;
    }
  }
  
  std::fstream HiScrFile;
  HiScrFile.open("HighScore.HGSC", std::ios::in);

  for (i=0; i<=4; i++) {
    getline(HiScrFile, HiScrChar);

    DecrypHiScrFn(HiScrChar,/*decrypted array to return*/);
  }

  while (play == 1) {
  
    std::cout << "Welcome to Guess the number!\n\n";
    
    GssDiff = SelDiffFn(MinMaxNum);

    std::cout << "your high score for this difficulty is " << HiScr[GssDiff] << "\n\n";
  
    CrntNumScr = GssNumFn(MinMaxNum[0], MinMaxNum[1]);
    
    std::cout << "your score is: " << CrntNumScr << " \n\n";
    
    std::cout << "would you like to play again?\n";
    std::cout << "0 - close the game\n";
    std::cout << "1 - try again\n";
    scanf("%d", &play);
    
    CrypScrFn(CrntNumScr, CrntCharScr);
    
    for (i=0; i<=3; i++) {
      
      std::cout <<  CrntCharScr[i];
      
    }
    
   /* if (CrntNumScr > HiScr[GssDiff]) {
    
    } */
    
  } 

    return 0;
}
