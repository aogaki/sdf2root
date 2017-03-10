#ifndef TSDFBLOCK
#define TSDFBLOCK 1

#include <fstream>

#include <TString.h>


class TSDFBlock
{
public:
   TSDFBlock();
   TSDFBlock(std::ifstream *, Long_t, Int_t, Int_t);
   virtual ~TSDFBlock();

   virtual Long_t GetNextLocation() {return fNextLocation;};
   
   virtual void ReadHeader();
   virtual void PrintHeader();

   virtual void ReadMetadata();
   virtual void PrintMetadata();

   virtual void ReadData();

   Int_t GetDataSize(){return fDataSize;};

   TString GetName(){return TString(fBlockName);};
   TString GetID(){return TString(fBlockID);};
   
protected:
   // For header and general information
   std::ifstream *fInputFile;
   Long_t fBlockLocation;
   Long_t fMetadataLocation;
   Long_t fDataLocation;
   Long_t fNextLocation;
   Char_t fBlockID[33];
   Long_t fDataLength;
   Int_t fBlockType;
   Int_t fDataType;
   Int_t fNDims;
   Char_t fBlockName[256];
   Int_t fBlockInfoLength;
   
   Int_t fHeaderLength;
   Int_t fStringLength;

   Int_t fDataSize;
};

#endif
