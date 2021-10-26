void CrypScrFn(int CrntNumScr,char CrntCharScr[][6], int Difficulty) {
  
  int i;
  int ReversedScore = 0;
  int n = sizeof(CrntNumScr);

  for (i=0; i<=n; i++) {

    ReversedScore = (ReversedScore * 10) + (CrntNumScr % 10);

    CrntNumScr /= 10;

  }

  for (i=0; i<=n; i++) {
    
    CrntCharScr[Difficulty][i] = (ReversedScore % 10) + 33;

    ReversedScore /= 10;

  }
}

void DecrypHiScrFn(char HiScrCryp[][6], char DecrypHiScr[][4]) {
  
  int i, j;

  for (i=0; i<5; i++) {

    for (j=0; j<4 && HiScrCryp[i][j] != 10; j++) {

      DecrypHiScr[i][j] = (HiScrCryp[i][j] + 15);
    
    }
  }
}