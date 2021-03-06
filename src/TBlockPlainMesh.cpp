/*
 For block manupilating class
*/

#include <iostream>

#include "TBlockPlainMesh.hpp"


using std::cout;
using std::endl;

TBlockPlainMesh::TBlockPlainMesh(std::ifstream *file, Long_t location,
                                       Int_t stringLength, Int_t headerLength)
   :TBlock()
{
   fInputFile = file;
   fBlockLocation = location;
   fStringLength = stringLength;
   fHeaderLength = headerLength;
   fMetadataLocation = fBlockLocation + fHeaderLength;

   fDataSize = 0;

   fGeoType = 0;
   for(Int_t i = 0; i < 3; i++){// These have 3 dimensions
      fNormFactor[i] = 0.;
      fAxisLabel[i] = "";
      fUnits[i] = "";
      fMinVal[i] = 0.;
      fMaxVal[i] = 0.;
      fNGrids[i] = 0;
   }
   
   ReadHeader();

   if(fDataType == 4) fDataSize = fDataLength / sizeof(Double_t);
   else if(fDataType == 3) fDataSize = fDataLength / sizeof(Float_t);
   else{
      cout << "DataType error in GetHeader@BlockPlainMesh" << endl;
      cout << "Now, only double and float data types are implemented" << endl;
      exit(0);
   }
}

void TBlockPlainMesh::ReadMetadata()
{
   fInputFile->seekg(fMetadataLocation, std::ios::beg);
   fInputFile->read((Char_t *)fNormFactor, sizeof(Double_t) * fNDims);
   for(Int_t i = 0; i < fNDims; i++){
      Char_t *buf = new Char_t[32];
      fInputFile->read(buf, sizeof(Char_t) * 32);
      fAxisLabel[i] = buf;
      delete[] buf;
   }
   for(Int_t i = 0; i < fNDims; i++){
      Char_t *buf = new Char_t[32];
      fInputFile->read(buf, sizeof(Char_t) * 32);
      fUnits[i] = buf;
      delete[] buf;  
   }
   fInputFile->read((Char_t *)&fGeoType, sizeof(Int_t));
   fInputFile->read((Char_t *)fMinVal, sizeof(Double_t) * fNDims);
   fInputFile->read((Char_t *)fMaxVal, sizeof(Double_t) * fNDims);
   fInputFile->read((Char_t *)fNGrids, sizeof(Int_t) * fNDims);
}

void TBlockPlainMesh::PrintMetadata()
{
   cout << "Normalization factor: "
        << fNormFactor[0] <<"\t"
        << fNormFactor[1] <<"\t"
        << fNormFactor[2] << endl;
   cout << "Axis label: "
        << fAxisLabel[0] <<"\t"
        << fAxisLabel[1] <<"\t"
        << fAxisLabel[2] << endl;
   cout << "Units: "
        << fUnits[0] <<"\t"
        << fUnits[1] <<"\t"
        << fUnits[2] << endl;
   cout << "Geometry type: " << fGeoType << endl;
   cout << "Min value: "
        << fMinVal[0] <<"\t"
        << fMinVal[1] <<"\t"
        << fMinVal[2] << endl;
   cout << "Max value: "
        << fMaxVal[0] <<"\t"
        << fMaxVal[1] <<"\t"
        << fMaxVal[2] << endl;
   cout << "No. Grids: "
        << fNGrids[0] <<"\t"
        << fNGrids[1] <<"\t"
        << fNGrids[2] << endl;
}
