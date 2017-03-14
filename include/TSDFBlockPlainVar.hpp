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

private:
   Double_t fNormFactor;
   TString fUnits;
   TString fMeshID;
   Int_t fNGrids[3];
   Int_t fStagger;
};

#endif
