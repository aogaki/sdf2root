#ifndef TSDFBLOCKPLAINMESH
#define TSDFBLOCKPLAINMESH 1

#include <fstream>
#include <vector>

#include <TString.h>

#include "TSDFBlock.hpp"


class TSDFBlockPlainMesh: public TSDFBlock
{
public:
   TSDFBlockPlainMesh(std::ifstream *, Long_t, Int_t, Int_t);
   
   void ReadMetadata();
   void PrintMetadata();

private:
   Double_t fNormFactor[3];
   TString fAxisLabel[3];
   TString fUnits[3];
   Int_t fGeoType;
   Double_t fMinVal[3];
   Double_t fMaxVal[3];
   Int_t fNGrids[3];
   
};

#endif
