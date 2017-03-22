#ifndef TMAKETREE
#define TMAKETREE 1

/*
Making tree class
*/

#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>

#include "TSDFReader.hpp"
#include "TBlockPlainMesh.hpp"


class TMakeTree
{
public:
   TMakeTree(TSDFReader *reader);
   ~TMakeTree();

   void GetData();
   
private:
   TSDFReader *fReader;

   void SaveTree();
   
   Int_t GetBlockIndex(TString ID);

   void ReadFieldGrid();

   void GetFieldData();
   TH1 *GetFieldHis(TString blockName, TString hisName, TString hisTitle);
   // Using template is better?
   TH1 *fEx{nullptr}; 
   TH1 *fEy{nullptr}; 
   TH1 *fEz{nullptr}; 
   
   TH1 *fBx{nullptr}; 
   TH1 *fBy{nullptr}; 
   TH1 *fBz{nullptr}; 

   TH1 *fJx{nullptr}; 
   TH1 *fJy{nullptr}; 
   TH1 *fJz{nullptr};

   // Parameters for histogram.  Its will be generated by grid information
   Double_t fHisMin[3];
   Double_t fHisMax[3];
   Int_t fHisNbins[3];
   TString fHisLabel[3];
   TString fHisUnit[3];
   Double_t fHisBinWidth[3];
};


#endif

