#include <string>

void CrypScrFn(int CrntNumScr,char CrntCharScr[]) {
  
  int k;
  
  for (k=0; k<=3; k++) {
    
    CrntCharScr[k] = (CrntNumScr % 10)+33;
    
    CrntNumScr /= 10;

  }
}

void DecrypHiScrFn(std::string CrypHiScr, int DecrypHiScr[]) {
  
  int k;

  for (k=0; k<(sizeof(CrypHiScr)/sizeof(CrypHiScr[0])); k++) {

    DecrypHiScr[k] = (CrypHiScr[k] - 33);

  }
}