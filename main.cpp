#include  <iostream>
#include  <cstdlib>
#include  <fstream>
#include  "Difficulty.h"
#include  "De-Encrypt.h"
#include  "GuessNumber.h"

int main()
{
  
  int CrntNumScr, MinMaxNum[2] = {0,0}, play = 1, i, j, GssDiff, IntSelDiffHiScr;
  char CryptedHiScr[5][6], DecryptedHiScr[5][4], CharSelDiffHiScr[4];

  for (i=0; i<5; i++) {
    for (j=0; j<6; j++) {
      DecryptedHiScr[i][j] = 'E';
      CryptedHiScr[i][j] = '\0';
    }
    CharSelDiffHiScr[i] = '\0';
  }
  
  std::fstream HiScrFile;

  while (play == 1) {
  
    HiScrFile.open("HighScore.HGSC", std::ios::in);

    for (i=0; i<5; i++) {
    
      for (j=0; j<6 && CryptedHiScr[i][j-1]!=10; j++) {
      
        CryptedHiScr[i][j] = HiScrFile.get();

      }
    }

    HiScrFile.close();

    DecrypHiScrFn(CryptedHiScr,DecryptedHiScr);

    std::cout << "Welcome to Guess the number!\n\n";
    
    GssDiff = SelDiffFn(MinMaxNum);

    for (i=0; i<4 && DecryptedHiScr[GssDiff][i] != 69; i++) {
      CharSelDiffHiScr[i] = DecryptedHiScr[GssDiff][i];
    }

    IntSelDiffHiScr = std::atoi(CharSelDiffHiScr);

    std::cout << "your high score for this difficulty is: ";
    
    for (i=0; i<4 && DecryptedHiScr[GssDiff][i] != 69; i++) {
      std::cout << DecryptedHiScr[GssDiff][i];
    }

    std::cout << "\n\n";
  
    CrntNumScr = GssNumFn(MinMaxNum[0], MinMaxNum[1]);
    
    std::cout << "your score is: " << CrntNumScr << " \n\n";

    if (CrntNumScr > IntSelDiffHiScr) {
      std::cout << "Well Played, you've got a new High score\n\n";

      CrypScrFn(CrntNumScr, CryptedHiScr, GssDiff);

      HiScrFile.open("HighScore.HGSC", std::ios::out);
      
      for (i=0; i<5; i++) {
        for (j=0; j<6 && CryptedHiScr[i][j] != 0; j++) {
          HiScrFile.put(CryptedHiScr[i][j]);
        }
        HiScrFile.put('\n');
      }

      HiScrFile.close();
    }
    else {
      std::cout << "nice game but not enough, you didn't get a new High score\n\n";
    }
    
    std::cout << "would you like to play again?\n";
    std::cout << "0 - close the game\n";
    std::cout << "1 - try again\n";
    scanf("%d", &play);
  }
  return 0;
}
