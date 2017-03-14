#ifndef TSDFBLOCKPLAINVAR
#define TSDFBLOCKPLAINVAR 1

#include <fstream>
#include <vector>

#include <TString.h>

#include "TSDFBlock.hpp"


class TSDFBlockPlainVar: public TSDFBlock
{
public:
   TSDFBlockPlainVar(std::ifstream *, Long_t, Int_t, Int_t);
      
   void ReadMetadata();
   void PrintMetadata();

   void ReadData();

   Double_t GetData(Int_t i);
   void PrintData(){for(auto v: fData) std::cout << v << std::endl;};
   
private:
   Double_t fNormFactor;
   TString fUnits;
   TString fMeshID;
   Int_t fNGrid[3];
   Int_t fStagger;

   void ReadData64();
   void ReadData32();
   std::vector<Double_t> fData;

};

#endif
