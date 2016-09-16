#include <EventLoop/Job.h>
#include <EventLoop/StatusCode.h>
#include <EventLoop/Worker.h>
#include <JetCleaningAnalysisHI/HIHI_TMVA.h>
#include "xAODRootAccess/Init.h"
#include "xAODRootAccess/TEvent.h"
#include "xAODRootAccess/tools/Message.h"
#include "xAODMuon/MuonContainer.h"
#include "MuonSelectorTools/MuonSelectionTool.h"
#include "xAODEgamma/PhotonContainer.h"
#include "xAODJet/JetContainer.h"
#include "xAODCaloEvent/CaloClusterContainer.h"
#include "xAODTracking/VertexContainer.h"
#include "xAODForward/ForwardEventInfo.h"
#include "xAODForward/ForwardEventInfoContainer.h"
#include "xAODCore/ShallowCopy.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include <TSystem.h>
#include <TFile.h>

#define private public
#include "xAODHIEvent/HIEventShapeAuxContainer.h"
#undef private
#include "xAODHIEvent/HIEventShapeContainer.h"

using namespace std;

// this is needed to distribute the algorithm to the workers
ClassImp(HIHI_TMVA)


/// Helper macro for checking xAOD::TReturnCode return values
#define EL_RETURN_CHECK( CONTEXT, EXP )			\
  do {							\
    if( ! EXP.isSuccess() ) {				\
      Error( CONTEXT,					\
	     XAOD_MESSAGE( "Failed to execute: %s" ),	\
	     #EXP );					\
      return EL::StatusCode::FAILURE;			\
    }							\
  } while( false )


Float_t HIHI_TMVA::DeltaEta(Float_t Eta1, Float_t Eta2)
{return (Eta2-Eta1);
}

Float_t HIHI_TMVA::DeltaPhi(Float_t Phi1, Float_t Phi2)
{
  Float_t dPhi = Phi2 - Phi1;
  while (dPhi < -TMath::Pi()) dPhi += 2*TMath::Pi();
  while (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi();
  return dPhi;
}
// Float_t HIHI_TMVA::DeltaPhi(Float_t phi1, Float_t phi2) {
//   TVector3 v1, v2;
//   v1.SetPtEtaPhi(1,0,phi1);
//   v2.SetPtEtaPhi(1,0,phi2);
//   return v1.Angle(v2);
// }


Float_t HIHI_TMVA::DeltaR(Float_t Phi1, Float_t Eta1, Float_t Phi2, Float_t Eta2)
{Float_t deltaR = sqrt( pow(this->DeltaEta(Eta1,Eta2),2) + pow(this->DeltaPhi(Phi1,Phi2),2) );
  return deltaR;
}


HIHI_TMVA :: HIHI_TMVA ()
//@ constructor
{
  // Here you put any code for the base initialization of variables,
  // e.g. initialize all pointers to 0.  Note that you should only put
  // the most basic initialization here, since this method will be
  // called on both the submission and the worker node.  Most of your
  // initialization code will go into histInitialize() and
  // initialize().

  doCaloJets = true;
  doFakes = true;
}



EL::StatusCode HIHI_TMVA :: setupJob (EL::Job& job)
{
  // Here you put code that sets up the job on the submission object
  // so that it is ready to work with your algorithm, e.g. you can
  // request the D3PDReader service or add output files.  Any code you
  // put here could instead also go into the submission script.  The
  // sole advantage of putting it here is that it gets automatically
  // activated/deactivated when you add/remove the algorithm from your
  // job, which may or may not be of value to you.

  // let's initialize the algorithm to use the xAODRootAccess package
  job.useXAOD ();

  EL_RETURN_CHECK( "setupJob()", xAOD::Init() ); // call before opening first file

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode HIHI_TMVA :: histInitialize ()
{
  // Here you do everything that needs to be done at the very
  // beginning on each worker node, e.g. create histograms and output
  // trees.  This method gets called before any input files are
  // connected.

  // get the output file, create a new TTree and connect it to that output
  // define what braches will go in that tree

  TFile *outputFile = wk()->getOutputFile (outputName);
  TreeS = new TTree ("TreeS", "TreeS");
  TreeS->SetDirectory (outputFile);
  TreeS->Branch("EventNumber", &EventNumber);
  TreeS->Branch("LArQuality", &LArQuality);
  TreeS->Branch("FracSamplingMaxIndex",&FracSamplingMaxIndex);  
  TreeS->Branch("FracSamplingMax",&FracSamplingMax);  
  TreeS->Branch("AverageLArQF",&AverageLArQF);  
  TreeS->Branch("HECQuality",&HECQuality);  
  TreeS->Branch("Width",&Width);  
  TreeS->Branch("fch",&fch);  
  TreeS->Branch("EMFrac",&EMFrac);  
  TreeS->Branch("HECFrac",&HECFrac);  
  TreeS->Branch("Timing",&Timing);
  TreeS->Branch("NegativeE",&NegativeE);
  TreeS->Branch("Pt",&Pt);
  TreeS->Branch("Eta",&Eta);
  TreeS->Branch("Phi",&Phi);
  TreeS->Branch("Mass",&Mass);
  TreeS->Branch("N90Constituents",&N90Constituents);
  TreeS->Branch("BchCorrCell",&BchCorrCell);
  TreeS->Branch("Jvt",&Jvt);
  TreeS->Branch("JvtJvfcorr",&JvtJvfcorr);
  TreeS->Branch("JvtRpt",&JvtRpt);
  TreeS->Branch("LArBadHVNcell",&LArBadHVNcell);
  TreeS->Branch("LArBadHVEnergyFrac",&LArBadHVEnergyFrac);
  TreeS->Branch("MaxOverMean",&MaxOverMean);
  TreeS->Branch("MaxConstituentET",&MaxConstituentET);
  TreeS->Branch("OotFracClusters10",&OotFracClusters10);
  TreeS->Branch("OotFracClusters5",&OotFracClusters5);

  TreeB = new TTree ("TreeB", "TreeB");
  TreeB->SetDirectory (outputFile);
  TreeB->Branch("EventNumber", &EventNumber);
  TreeB->Branch("LArQuality", &LArQuality);
  TreeB->Branch("FracSamplingMaxIndex",&FracSamplingMaxIndex);  
  TreeB->Branch("FracSamplingMax",&FracSamplingMax);  
  TreeB->Branch("AverageLArQF",&AverageLArQF);  
  TreeB->Branch("HECQuality",&HECQuality);  
  TreeB->Branch("Width",&Width);  
  TreeB->Branch("fch",&fch);  
  TreeB->Branch("EMFrac",&EMFrac);  
  TreeB->Branch("HECFrac",&HECFrac);  
  TreeB->Branch("Timing",&Timing);
  TreeB->Branch("NegativeE",&NegativeE);
  TreeB->Branch("Pt",&Pt);
  TreeB->Branch("Eta",&Eta);
  TreeB->Branch("Phi",&Phi);
  TreeB->Branch("Mass",&Mass);
  TreeB->Branch("N90Constituents",&N90Constituents);
  TreeB->Branch("BchCorrCell",&BchCorrCell);
  TreeB->Branch("Jvt",&Jvt);
  TreeB->Branch("JvtJvfcorr",&JvtJvfcorr);
  TreeB->Branch("JvtRpt",&JvtRpt);
  TreeB->Branch("LArBadHVNcell",&LArBadHVNcell);
  TreeB->Branch("LArBadHVEnergyFrac",&LArBadHVEnergyFrac);
  TreeB->Branch("MaxOverMean",&MaxOverMean);
  TreeB->Branch("MaxConstituentET",&MaxConstituentET);
  TreeB->Branch("OotFracClusters10",&OotFracClusters10);
  TreeB->Branch("OotFracClusters5",&OotFracClusters5);
 
  nCentBins           = 1;

  h2_Jet_Pt = new TH2F*[nCentBins];

  h3_pt_deltaphi = new TH3F*[nCentBins];
  h3_pt_jetkin = new TH3F*[nCentBins];
  h3_pt_hmiss = new TH3F*[nCentBins];
 
  h2_Jet_fr_Pt = new TH2F*[nCentBins];
  h3_pt_fr_deltaphi = new TH3F*[nCentBins];
  h3_pt_fr_jetkin = new TH3F*[nCentBins];
  h3_pt_fr_FracSamplingMaxIndex = new TH3F*[nCentBins];
  h3_pt_fr_FracSamplingMax = new TH3F*[nCentBins];
  h3_pt_fr_AverageLArQF = new TH3F*[nCentBins];
  h3_pt_fr_HECQuality = new TH3F*[nCentBins];
  h3_pt_fr_Width = new TH3F*[nCentBins];
  h3_pt_fr_fch = new TH3F*[nCentBins];
  h3_pt_fr_fchFracSamplingMax = new TH3F*[nCentBins];
  h3_pt_fr_fchEMFrac = new TH3F*[nCentBins];
  h3_pt_fr_EMFrac = new TH3F*[nCentBins];
  h3_pt_fr_HECFrac = new TH3F*[nCentBins];
  h3_pt_fr_Timing = new TH3F*[nCentBins];
  h3_pt_fr_LArQuality = new TH3F*[nCentBins];  
  h3_pt_fr_LArQualityEMFrac = new TH3F*[nCentBins];  

  h3_pt_FracSamplingMax = new TH3F*[nCentBins];
  h3_pt_AverageLArQF = new TH3F*[nCentBins];
  h3_pt_HECQuality = new TH3F*[nCentBins];
  h3_pt_Width = new TH3F*[nCentBins];
  h3_pt_fch = new TH3F*[nCentBins];
  h3_pt_fchFracSamplingMax = new TH3F*[nCentBins];
  h3_pt_fchEMFrac = new TH3F*[nCentBins];
  h3_pt_EMFrac = new TH3F*[nCentBins];
  h3_pt_HECFrac = new TH3F*[nCentBins];
  h3_pt_Timing = new TH3F*[nCentBins];
  h3_pt_LArQuality = new TH3F*[nCentBins];  
  h3_pt_LArQualityEMFrac = new TH3F*[nCentBins];  


  // calo jet HI
  h2_Jet_EtaPhi = new TH2F("h2_Jet_EtaPhi", ";#eta;#phi", 120, -6., 6., 64, -TMath::Pi(), TMath::Pi()); // jet pt [GeV]
  h2_Jet_PtNconst = new TH2F("h2_Jet_PtNconst", ";p_{T,jet} [GeV]; Number of constituents", 200, 0, 1000, 100, 0, 100);
  h2_Jet_PtMass   = new TH2F("h2_Jet_PtMass",   ";p_{T,jet} [GeV]; m [GeV]", 200, 0, 1000, 200, -50, 150);
  h2_Jet_Etconst  = new TH2F("h2_Jet_Etconst",   ";E_{T,ClRaw} [GeV]; ET_{T,ClAlt} [GeV]", 200, -20, 80, 200, -20, 80);

  for (Int_t j=0; j<nCentBins; j++) {
    stringstream ss;
    string str;
    ss << std::setw(2) << std::setfill('0') << j;
    ss >> str;

    const std::string h2_Jet_PtStr       = "h2_Jet_Pt_" + str;
    h2_Jet_Pt[j] = new TH2F(h2_Jet_PtStr.c_str(), ";p_{T,jet} [GeV];#eta;", 200, 0, 1000, 120, -6., 6.); // jet pt [GeV]

    const std::string h3_pt_jetkinStr       = "h3_pt_jetkin_" + str;
    h3_pt_jetkin[j] = new TH3F(h3_pt_jetkinStr.c_str(), ";A_{J}; p_{T,jet} [GeV]; p_{T,jet} [GeV];", 20,0,1,200,0,1000,200, 0, 1000);
    const std::string h3_pt_hmissStr       = "h3_pt_hmiss_" + str;
    h3_pt_hmiss[j] = new TH3F(h3_pt_hmissStr.c_str(), ";N_{jet}; p_{T,jet} [GeV]; p_{T,jet} [GeV];", 20,1,20,200, 0, 1000,200, 0, 1000);
    const std::string h3_pt_deltaphiStr       = "h3_pt_deltaphi_" + str;
    h3_pt_deltaphi[j] = new TH3F(h3_pt_deltaphiStr.c_str(), ";deltaphi;#eta; p_{T,jet} [GeV];", 64, -TMath::Pi(), TMath::Pi(),120, -6., 6.,200, 0, 1000);

    const std::string h2_Jet_fr_PtStr       = "h2_Jet_fr_Pt_" + str;
    h2_Jet_fr_Pt[j] = new TH2F(h2_Jet_fr_PtStr.c_str(), ";p_{T,jet} [GeV];#eta;", 200, 0, 1000, 120, -6., 6.); // jet pt [GeV]
    const std::string h3_pt_fr_jetkinStr       = "h3_pt_fr_jetkin_" + str;
    h3_pt_fr_jetkin[j] = new TH3F(h3_pt_fr_jetkinStr.c_str(), ";#phi;#eta; p_{T,jet} [GeV];", 64, -TMath::Pi(), TMath::Pi(),120, -6., 6.,200, 0, 1000);
    const std::string h3_pt_fr_deltaphiStr       = "h3_pt_fr_deltaphi_" + str;
    h3_pt_fr_deltaphi[j] = new TH3F(h3_pt_fr_deltaphiStr.c_str(), ";deltaphi;#eta; p_{T,jet} [GeV];", 64, -TMath::Pi(), TMath::Pi(),120, -6., 6.,200, 0, 1000);
    const std::string h3_pt_fr_FracSamplingMaxIndexStr       = "h3_pt_fr_FracSamplingMaxIndex_" + str;
    h3_pt_fr_FracSamplingMaxIndex[j] = new TH3F(h3_pt_fr_FracSamplingMaxIndexStr.c_str(), ";FracSamplingMaxIndex;#eta; p_{T,jet} [GeV];", 24,0,24,120, -6., 6.,200,0,1000);
    const std::string h3_pt_fr_FracSamplingMaxStr       = "h3_pt_fr_FracSamplingMax_" + str;
    h3_pt_fr_FracSamplingMax[j] = new TH3F(h3_pt_fr_FracSamplingMaxStr.c_str(), ";f_{max};#eta; p_{T,jet} [GeV];", 100,-0.1, 2,120, -6., 6.,200,0,1000);
    const std::string h3_pt_fr_AverageLArQFStr       = "h3_pt_fr_AverageLArQF_" + str;
    h3_pt_fr_AverageLArQF[j] = new TH3F(h3_pt_fr_AverageLArQFStr.c_str(), ";Jet <Q>;#eta; p_{T,jet} [GeV];", 100,-0.1, 1.2,120, -6., 6.,200,0,1000);
    const std::string h3_pt_fr_HECQualityStr       = "h3_pt_fr_HECQuality_" + str;
    h3_pt_fr_HECQuality[j] = new TH3F(h3_pt_fr_HECQualityStr.c_str(), ";f^{HEC}_{Q};#eta; p_{T,jet} [GeV];", 50,-0.1, 1.4,120, -6., 6.,200,0,1000);
    const std::string h3_pt_fr_WidthStr       = "h3_pt_fr_Width_" + str;
    h3_pt_fr_Width[j] = new TH3F(h3_pt_fr_WidthStr.c_str(), ";Jet Width;#eta; p_{T,jet} [GeV];", 50, 0, 1.0,120, -6., 6.,200,0,1000);
    const std::string h3_pt_fr_fchStr       = "h3_pt_fr_fch_" + str;
    h3_pt_fr_fch[j] = new TH3F(h3_pt_fr_fchStr.c_str(), ";Jet f_{ch};#eta; p_{T,jet} [GeV];", 50, 0, 3.0,120, -6., 6.,200,0,1000);
    const std::string h3_pt_fr_fchFracSamplingMaxStr       = "h3_pt_fr_fchFracSamplingMax_" + str;
    h3_pt_fr_fchFracSamplingMax[j] = new TH3F(h3_pt_fr_fchFracSamplingMaxStr.c_str(), ";Jet f_{ch}/f_{max};#eta; p_{T,jet} [GeV];", 50, 0, 6.0,120, -6., 6.,200, 0, 1000);
    const std::string h3_pt_fr_fchEMFracStr       = "h3_pt_fr_fchEMFrac_" + str;
    h3_pt_fr_fchEMFrac[j] = new TH3F(h3_pt_fr_fchEMFracStr.c_str(), ";Jet f_{EM}; Jet f_{ch}; #eta;", 100, -1, 2, 50, 0, 3.0,120, -6., 6.);
    const std::string h3_pt_fr_EMFracStr       = "h3_pt_fr_EMFrac_" + str;
    h3_pt_fr_EMFrac[j] = new TH3F(h3_pt_fr_EMFracStr.c_str(), ";f_{EM};#eta; p_{T,jet} [GeV];", 100, -1, 2,120, -6., 6.,200,0,1000);
    const std::string h3_pt_fr_HECFracStr       = "h3_pt_fr_HECFrac_" + str;
    h3_pt_fr_HECFrac[j] = new TH3F(h3_pt_fr_HECFracStr.c_str(), ";f_{HEC};#eta; p_{T,jet} [GeV];", 100, -1, 2,120, -6., 6.,200,0,1000);
    const std::string h3_pt_fr_TimingStr       = "h3_pt_fr_Timing_" + str;
    h3_pt_fr_Timing[j] = new TH3F(h3_pt_fr_TimingStr.c_str(), ";Timing;#eta; p_{T,jet} [GeV];", 40, -20, 20,120, -6., 6.,200,0,1000);
    const std::string h3_pt_fr_LArQualityStr       = "h3_pt_fr_LArQuality_" + str;
    h3_pt_fr_LArQuality[j] = new TH3F(h3_pt_fr_LArQualityStr.c_str(), ";f^{LAr}_{Q};#eta; p_{T,jet} [GeV];", 50, -0.4, 1.2,120, -6., 6.,200,0,1000);
    const std::string h3_pt_fr_LArQualityEMFracStr       = "h3_pt_fr_LArQualityEMFrac_" + str;
    h3_pt_fr_LArQualityEMFrac[j] = new TH3F(h3_pt_fr_LArQualityEMFracStr.c_str(), ";f_{EM};f^{LAr}_{Q}; #eta;", 100, -1, 2, 50, -0.4, 1.2,120, -6., 6.);

    const std::string h3_pt_FracSamplingMaxStr       = "h3_pt_FracSamplingMax_" + str;
    h3_pt_FracSamplingMax[j] = new TH3F(h3_pt_FracSamplingMaxStr.c_str(), ";f_{max};#eta; p_{T,jet} [GeV];", 100,-0.1, 2,120, -6., 6.,200,0,1000);
    const std::string h3_pt_AverageLArQFStr       = "h3_pt_AverageLArQF_" + str;
    h3_pt_AverageLArQF[j] = new TH3F(h3_pt_AverageLArQFStr.c_str(), ";Jet <Q>;#eta; p_{T,jet} [GeV];", 100,-0.1, 1.2,120, -6., 6.,200,0,1000);
    const std::string h3_pt_HECQualityStr       = "h3_pt_HECQuality_" + str;
    h3_pt_HECQuality[j] = new TH3F(h3_pt_HECQualityStr.c_str(), ";f^{HEC}_{Q};#eta; p_{T,jet} [GeV];", 50,-0.1, 1.4,120, -6., 6.,200,0,1000);
    const std::string h3_pt_WidthStr       = "h3_pt_Width_" + str;
    h3_pt_Width[j] = new TH3F(h3_pt_WidthStr.c_str(), ";Jet Width;#eta; p_{T,jet} [GeV];", 50, 0, 1.0,120, -6., 6.,200,0,1000);
    const std::string h3_pt_fchStr       = "h3_pt_fch_" + str;
    h3_pt_fch[j] = new TH3F(h3_pt_fchStr.c_str(), ";Jet f_{ch};#eta; p_{T,jet} [GeV];", 50, 0, 3.0,120, -6., 6.,200,0,1000);
    const std::string h3_pt_fchFracSamplingMaxStr       = "h3_pt_fchFracSamplingMax_" + str;
    h3_pt_fchFracSamplingMax[j] = new TH3F(h3_pt_fchFracSamplingMaxStr.c_str(), ";Jet f_{ch}/f_{max};#eta; p_{T,jet} [GeV];", 50, 0, 6.0,120, -6., 6.,200, 0, 1000);
    const std::string h3_pt_fchEMFracStr       = "h3_pt_fchEMFrac_" + str;
    h3_pt_fchEMFrac[j] = new TH3F(h3_pt_fchEMFracStr.c_str(), ";Jet f_{EM}; Jet f_{ch}; #eta;", 100, -1, 2, 50, 0, 3.0,120, -6., 6.);
    const std::string h3_pt_HECFracStr       = "h3_pt_HECFrac_" + str;
    h3_pt_HECFrac[j] = new TH3F(h3_pt_HECFracStr.c_str(), ";f_{HEC};#eta; p_{T,jet} [GeV];", 100, -1, 2,120, -6., 6.,200,0,1000);
    const std::string h3_pt_EMFracStr       = "h3_pt_EMFrac_" + str;
    h3_pt_EMFrac[j] = new TH3F(h3_pt_EMFracStr.c_str(), ";f_{EM};#eta; p_{T,jet} [GeV];", 100, -1, 2,120, -6., 6.,200,0,1000);
    const std::string h3_pt_TimingStr       = "h3_pt_Timing_" + str;
    h3_pt_Timing[j] = new TH3F(h3_pt_TimingStr.c_str(), ";Timing;#eta; p_{T,jet} [GeV];", 40, -20, 20,120, -6., 6.,200,0,1000);
    const std::string h3_pt_LArQualityStr       = "h3_pt_LArQuality_" + str;
    h3_pt_LArQuality[j] = new TH3F(h3_pt_LArQualityStr.c_str(), ";f^{LAr}_{Q};#eta; p_{T,jet} [GeV];", 50, -0.4, 1.2,120, -6., 6.,200,0,1000);
    const std::string h3_pt_LArQualityEMFracStr       = "h3_pt_LArQualityEMFrac_" + str;
    h3_pt_LArQualityEMFrac[j] = new TH3F(h3_pt_LArQualityEMFracStr.c_str(), ";f_{EM};f^{LAr}_{Q}; #eta;", 100, -1, 2, 50, -0.4, 1.2,120, -6., 6.);
  }

  if (doCaloJets) {
    wk()->addOutput (h2_Jet_EtaPhi );
    wk()->addOutput (h2_Jet_PtNconst );
    wk()->addOutput (h2_Jet_PtMass );
    wk()->addOutput (h2_Jet_Etconst );
  }

  if (doFakes) {
    for (Int_t j=0; j<nCentBins; j++) {
      wk()->addOutput (h2_Jet_Pt[j]);

      wk()->addOutput (h3_pt_deltaphi[j]);
      wk()->addOutput (h3_pt_jetkin[j]);
      wk()->addOutput (h3_pt_hmiss[j]);
      wk()->addOutput (h3_pt_FracSamplingMax[j]);
      wk()->addOutput (h3_pt_AverageLArQF[j]);
      wk()->addOutput (h3_pt_HECQuality[j]);
      wk()->addOutput (h3_pt_Width[j]);
      wk()->addOutput (h3_pt_fch[j]);
      wk()->addOutput (h3_pt_fchFracSamplingMax[j]);
      wk()->addOutput (h3_pt_fchEMFrac[j]);
      wk()->addOutput (h3_pt_EMFrac[j]);
      wk()->addOutput (h3_pt_HECFrac[j]);
      wk()->addOutput (h3_pt_Timing[j]);
      wk()->addOutput (h3_pt_LArQuality[j]);
      wk()->addOutput (h3_pt_LArQualityEMFrac[j]);

      wk()->addOutput (h2_Jet_fr_Pt[j]);
      wk()->addOutput (h3_pt_fr_deltaphi[j]);
      wk()->addOutput (h3_pt_fr_jetkin[j]);
      wk()->addOutput (h3_pt_fr_FracSamplingMaxIndex[j]);
      wk()->addOutput (h3_pt_fr_FracSamplingMax[j]);
      wk()->addOutput (h3_pt_fr_AverageLArQF[j]);
      wk()->addOutput (h3_pt_fr_HECQuality[j]);
      wk()->addOutput (h3_pt_fr_Width[j]);
      wk()->addOutput (h3_pt_fr_fch[j]);
      wk()->addOutput (h3_pt_fr_fchFracSamplingMax[j]);
      wk()->addOutput (h3_pt_fr_fchEMFrac[j]);
      wk()->addOutput (h3_pt_fr_EMFrac[j]);
      wk()->addOutput (h3_pt_fr_HECFrac[j]);
      wk()->addOutput (h3_pt_fr_Timing[j]);
      wk()->addOutput (h3_pt_fr_LArQuality[j]);
      wk()->addOutput (h3_pt_fr_LArQualityEMFrac[j]);


    }
  }



  return EL::StatusCode::SUCCESS;
}



EL::StatusCode HIHI_TMVA :: fileExecute ()
{
  // Here you do everything that needs to be done exactly once for every
  // single file, e.g. collect a list of all lumi-blocks processed
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode HIHI_TMVA :: changeInput (bool firstFile)
{
  // Here you do everything you need to do when we change input files,
  // e.g. resetting branch addresses on trees.  If you are using
  // D3PDReader or a similar service this method is not needed.
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode HIHI_TMVA :: initialize ()
{
  // Here you do everything that you need to do after the first input
  // file has been connected and before the first event is processed,
  // e.g. create additional histograms based on which variables are
  // available in the input files.  You can also create all of your
  // histograms and trees in here, but be aware that this method
  // doesn't get called if no events are processed.  So any objects
  // you create here won't be available in the output if you have no
  // input events.

  UseAtlasStyleCustom();

  // GRL
  m_grl = new GoodRunsListSelectionTool("GoodRunsListSelectionTool");
  const char* GRLFilePath = "$ROOTCOREBIN/data/JetCleaningAnalysisHI/data15_hi.periodAllYear_DetStatus-v75-repro20-01_DQDefects-00-02-02_PHYS_HeavyIonP_All_Good.xml";
  // const char* GRLFilePath = "$ROOTCOREBIN/data/JetCleaningAnalysisHI/data15_5TeV.periodVdM_DetStatus-v75-repro20-01_DQDefects-00-02-02_PHYS_HeavyIonP_All_Good.xml";

  const char* fullGRLFilePath = gSystem->ExpandPathName (GRLFilePath);
  std::vector<std::string> vecStringGRL;
  vecStringGRL.push_back(fullGRLFilePath);
  EL_RETURN_CHECK("initialize()",m_grl->setProperty( "GoodRunsListVec", vecStringGRL));
  //EL_RETURN_CHECK("initialize()",m_grl->setProperty("PassThrough", false)); // if true (default) will ignore result of GRL and will just pass all events
  EL_RETURN_CHECK("initialize()",m_grl->setProperty("PassThrough", true)); // if true (default) will ignore result of GRL and will just pass all events
  EL_RETURN_CHECK("initialize()",m_grl->initialize());

  // Initialize and configure trigger tools
  m_trigConfigTool = new TrigConf::xAODConfigTool("xAODConfigTool"); // gives us access to the meta-data
  EL_RETURN_CHECK( "initialize", m_trigConfigTool->initialize() );
  ToolHandle< TrigConf::ITrigConfigTool > trigConfigHandle( m_trigConfigTool );
  m_trigDecisionTool = new Trig::TrigDecisionTool("TrigDecisionTool");
  EL_RETURN_CHECK( "initialize", m_trigDecisionTool->setProperty( "ConfigTool", trigConfigHandle ) ); // connect the TrigDecisionTool to the ConfigTool
  EL_RETURN_CHECK( "initialize", m_trigDecisionTool->setProperty( "TrigDecisionKey", "xTrigDecision" ) );
  EL_RETURN_CHECK( "initialize", m_trigDecisionTool->initialize() );

  // count number of events
  m_eventCounter = 0;

  xAOD::TEvent* event = wk()->xaodEvent();

  // as a check, let's see the number of events in our xAOD
  Info("initialize()", "Number of events = %lli", event->getEntries() ); // print long long int

  //jet calibration
  //https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/JetEtmissRecommendationsMC15#JES_calibration
  const std::string name = "MyxAODAnalysis"; //string describing the current thread, for logging
  // TString jetAlgo = "AntiKt4EMTopo"; //String describing your jet collection, for example AntiKt4EMTopo or AntiKt4LCTopo (see above)
  // TString config = "JES_MC15Prerecommendation_April2015.config"; //Path to global config used to initialize the tool (see above)
  // TString calibSeq = "JetArea_Residual_Origin_EtaJES_GSC_Insitu"; //String describing the calibration sequence to apply (see above)

  TString jetAlgo = "AntiKt4HI"; //String describing your jet collection, for example AntiKt4EMTopo or AntiKt4LCTopo (see above)
  TString config = "JES_MC15CHI_042316.config"; //Path to global config used to initialize the tool (see above)
  TString calibSeq = "EtaJES_DEV"; //String describing the calibration sequence to apply (see above)
 

  bool isData = true; //bool describing if the events are data or from simulation
  
  //Call the constructor. The default constructor can also be used if the arguments are set with python configuration instead
  m_jetCalibration = new JetCalibrationTool(name, jetAlgo, config, calibSeq, isData);

  //Initialize the tool
  EL_RETURN_CHECK("initialize()",m_jetCalibration->initializeTool(name));

  //Muon Selection Tool
  m_muonSelection = new CP::MuonSelectionTool("muonSelection");
  //m_muonSelection->msg().setLevel( MSG::ERROR);
  EL_RETURN_CHECK("initialize",m_muonSelection->setProperty( "MaxEta", 2.4 ));
  EL_RETURN_CHECK("initialize",m_muonSelection->setProperty( "MuQuality", 1));
  EL_RETURN_CHECK("initialize",m_muonSelection->initialize());


  return EL::StatusCode::SUCCESS;
}



EL::StatusCode HIHI_TMVA :: execute ()
{
  // Here you do everything that needs to be done on every single
  // events, e.g. read input variables, apply cuts, and fill
  // histograms and trees.  This is where most of your actual analysis
  // code will go.
  xAOD::TEvent* event = wk()->xaodEvent();

  // print every 100 events, so we know where we are:
  if( (m_eventCounter % 100) ==0 ) Info("execute()", "Event number = %i", m_eventCounter );
  m_eventCounter++;

  ih=0;

  //----------------------------
  // Event information
  //--------------------------- 
  const xAOD::EventInfo* eventInfo = 0;
  EL_RETURN_CHECK("execute",event->retrieve( eventInfo, "EventInfo"));  
  
  int eventNumber = eventInfo->eventNumber();

  // fill the branches of our trees
  EventNumber = eventInfo->eventNumber();

  // get muon container of interest
  const xAOD::MuonContainer* muons = 0;
  EL_RETURN_CHECK("execute",event->retrieve( muons, "Muons"));
  //if (muons->size()>0) return EL::StatusCode::SUCCESS; // go to next event

  static SG::AuxElement::ConstAccessor< unsigned int > background_flags("backgroundFlags");
  if ( background_flags.isAvailable( *eventInfo ) )     { m_backgroundFlags = background_flags( *eventInfo ); } else { m_backgroundFlags = -999; }
  //if (m_backgroundFlags==1048576) return EL::StatusCode::SUCCESS; // go to next event (corresponds to the “Two-sided no-time” method)

  // check if the event is data or MC
  // (many tools are applied either to data or MC)
  bool isMC = false;
  // check if the event is MC
  if(eventInfo->eventType( xAOD::EventInfo::IS_SIMULATION ) ){
    isMC = true; // can do something with this later
  } 

  // if data check if event passes GRL
  if(!isMC){ // it's data!
    if(!m_grl->passRunLB(*eventInfo)){
      return EL::StatusCode::SUCCESS; // go to next event
    }
  } // end if not MC
  static int patt = 0;
  if(patt==0){
    //Print all the trigger Name
    auto chainGroup = m_trigDecisionTool->getChainGroup(".*");
    //for(auto trig_selc : TrigList) std::cout<<"We will Select and Save "<< trig_selc <<std::endl;
    //auto chainGroup = m_trigDecisionTool->getChainGroup("EF_.*|HLT_.*");
    //auto chainGroup = m_trigDecisionTool->getChainGroup("EF_.*");
 
    // for(auto &trig : chainGroup->getListOfTriggers()) {
    //   std::cout<<trig<<std::endl;
    // }
    patt++;
  }
  // if data check if event matches trigger
  bool pass_trigger_cuts = false;
  if(m_trigDecisionTool->isPassed("HLT_j75_L1J20")){ pass_trigger_cuts =true; }
  //if( !pass_trigger_cuts ) return EL::StatusCode::SUCCESS;

  //------------------------------------------------------  
  // Primary Vertex
  //------------------------------------------------------  
  const xAOD::VertexContainer *l_VertexContainer;
  EL_RETURN_CHECK("execute",event->retrieve( l_VertexContainer, "PrimaryVertices"));
  int nsize = l_VertexContainer->size();
 
  //****  Finish cutting on Primary Vertex ******
/*  if(nsize <2 ){
    Info("execute()", "Strange Event with vertex < 2 %i", eventNumber); //Just make sure it is a primary vertex event
    return EL::StatusCode::SUCCESS;
  }
*/
  // Reject events affected by noise bursts and tile corrupted events
  //https://twiki.cern.ch/twiki/bin/viewauth/Atlas/DataPreparationCheckListForPhysicsAnalysis#Rejection_of_bad_corrupted_event
  //if (eventInfo->errorState(xAOD::EventInfo::LAr)==xAOD::EventInfo::Error)     return EL::StatusCode::SUCCESS;
  //if (eventInfo->errorState(xAOD::EventInfo::Tile) == xAOD::EventInfo::Error ) return EL::StatusCode::SUCCESS;
  //if (eventInfo->errorState(xAOD::EventInfo::SCT) == xAOD::EventInfo::Error )  return EL::StatusCode::SUCCESS;
  //if (eventInfo->isEventFlagBitSet(xAOD::EventInfo::Core, 18) ) return EL::StatusCode::SUCCESS;

  //----------------------------
  // Jet container of calo jets
  //--------------------------- 
  // Create a transient object store. Needed for the tools.                                                                                
  xAOD::TStore store;
  const xAOD::JetContainer* jets = 0;
  if ( !event->retrieve(jets,"AntiKt4HIJets").isSuccess() ) { //Change the string to the jet collection of interest
    Error("execute()", "Failed to retrieve jet  collection. Exiting." );
    return EL::StatusCode::FAILURE;
  }
  // create a shallow copy of the jets container
  std::pair< xAOD::JetContainer*, xAOD::ShallowAuxContainer* > jets_shallowCopy = xAOD::shallowCopyContainer( *jets );
 
  // iterate over our shallow copy
  xAOD::JetContainer::iterator jet_itr = (jets_shallowCopy.first)->begin();
  xAOD::JetContainer::iterator jet_end = (jets_shallowCopy.first)->end();

  // loop over the jets in the container
  for( ; jet_itr != jet_end; ++jet_itr ) {
    m_jetCalibration->applyCalibration(**jet_itr);
    Float_t jetEta = (*jet_itr)->eta();
    Float_t jetPt = (*jet_itr)->pt() * 0.001; // GeV

    //if (fabs(jetEta) > 1.37 && fabs(jetEta) < 1.52) return EL::StatusCode::SUCCESS;
    Float_t jetPhi = (*jet_itr)->phi();
    Float_t jetM = (*jet_itr)->m() * 0.001; // GeV
 
    TLorentzVector vec; //calibrated
    vec.SetPtEtaPhiM( jetPt, jetEta, jetPhi, jetM );
    h2_Jet_PtMass->Fill( jetPt, jetM );
 
    Int_t numConst = (*jet_itr)->numConstituents();
    h2_Jet_PtNconst->Fill( jetPt, numConst );

    float sumETConst=0;
    const xAOD::JetConstituentVector constituents = (*jet_itr)->getConstituents();
    for (xAOD::JetConstituentVector::iterator itr = constituents.begin(); itr != constituents.end(); ++itr) {
      const xAOD::CaloCluster* cl=static_cast<const xAOD::CaloCluster*>(itr->rawConstituent());
      h2_Jet_Etconst->Fill(cl->rawE() * 0.001 / std::cosh( cl->rawEta() ), cl->altE() * 0.001 / std::cosh( cl->altEta() ) );
      sumETConst+= cl->rawE() * 0.001 / std::cosh( cl->rawEta() );
    }

    h2_Jet_EtaPhi->Fill( (*jet_itr)->eta(), (*jet_itr)->phi() );
  } // end for loop over jets
  
  //Jet quality study
  float firstJetPt=0.; float secondJetPt=0.;float firstJetEta=0.; float secondJetEta=0.;float firstJetPhi=0.;float firstJetM=0.; float secondJetPhi=0.; float firstJetLArQ=0.; float secondJetLArQ=0.; float firstJetAveLArQF=0.; float secondJetAveLArQF=0.;float firstJetHECQ=0.; float secondJetHECQ=0.;float firstJetTiming=0.; float secondJetTiming=0.;float firstJetfch=0.; float secondJetfch=0.; float firstJetEMFrac=0.; float secondJetEMFrac=0.; float firstJetHECFrac=0.; float secondJetHECFrac=0.;float firstJetfmax=0.; float secondJetfmax=0.; int firstJetfmaxindex=0; float firstJetWidth=0; float EtBal=0.;float dphiFS=0; std::vector<float>  sumpttrk; float hmiss=0;  float hmissdir=0;  float firstJetNegativeE=0.; float firstJetN90Constituents=0.; float firstJetBchCorrCell=0.; float firstJetJvt=0.; float firstJetJvtJvfcorr=0.; float firstJetJvtRpt=0.; float firstJetLArBadHVNcell=0.; float firstJetLArBadHVEnergyFrac=0.; float firstJetMaxOverMean=0.; float firstJetMaxConstituentET=0.; float firstJetOotFracClusters10=0.; float firstJetOotFracClusters5=0.;

  bool GoodJet = false;
  TLorentzVector vecsum;
  TLorentzVector vecfirst;
  // iterate over our shallow copy
  xAOD::JetContainer::iterator jetitr = (jets_shallowCopy.first)->begin();
  xAOD::JetContainer::iterator jetend = (jets_shallowCopy.first)->end();
  for(; jetitr != jetend; ++jetitr ) {
    m_jetCalibration->applyCalibration(**jetitr);
    Float_t jetPt = (*jetitr)->pt() * 0.001; // GeV
    Float_t jetEta = (*jetitr)->eta();
    Float_t jetPhi = (*jetitr)->phi();
    Float_t jetM = (*jetitr)->m() * 0.001; // GeV

    TLorentzVector vec; //calibrated
    vec.SetPtEtaPhiM( jetPt, jetEta, jetPhi, jetM );
    (*jetitr)->getAttribute("SumPtTrkPt500",sumpttrk);

    //finding the leading and sub-leading
//    if (jetPt>firstJetPt){
      secondJetPt=firstJetPt;
      secondJetEta=firstJetEta;
      secondJetPhi=firstJetPhi;
      secondJetLArQ=firstJetLArQ;
      secondJetAveLArQF=firstJetAveLArQF;
      secondJetHECQ=firstJetHECQ;
      secondJetfch=firstJetfch;
      secondJetEMFrac=firstJetEMFrac;
      secondJetHECFrac=firstJetHECFrac;
      secondJetTiming=firstJetTiming;
      firstJetPt=jetPt;
      firstJetEta=jetEta;
      firstJetPhi=jetPhi;
      firstJetM=jetM;
      firstJetLArQ=(*jetitr)->auxdata<float>("LArQuality");
      firstJetAveLArQF=((*jetitr)->auxdata<float>("AverageLArQF"))/65535.;
      firstJetHECQ=(*jetitr)->auxdata<float>("HECQuality");
      firstJetfch=(sumpttrk.size() > 0) ? sumpttrk[0]*0.001/jetPt : 0;
      firstJetEMFrac=(*jetitr)->auxdata<float>("EMFrac");
      firstJetHECFrac=(*jetitr)->auxdata<float>("HECFrac");
      firstJetfmax=(*jetitr)->auxdata<float>("FracSamplingMax");
      firstJetfmaxindex=(*jetitr)->auxdata<int>("FracSamplingMaxIndex");
      firstJetNegativeE=(*jetitr)->auxdata<float>("NegativeE") * 0.001;
      firstJetTiming=(*jetitr)->auxdata<float>("Timing");
      firstJetWidth=(*jetitr)->auxdata<float>("Width");
      firstJetN90Constituents=(*jetitr)->auxdata<float>("N90Constituents");
      firstJetBchCorrCell=(*jetitr)->auxdata<float>("BchCorrCell");
      firstJetJvt=(*jetitr)->auxdata<float>("Jvt");
      firstJetJvtJvfcorr=(*jetitr)->auxdata<float>("JvtJvfcorr");
      firstJetJvtRpt=(*jetitr)->auxdata<float>("JvtRpt");
      firstJetLArBadHVNcell=(*jetitr)->auxdata<float>("LArBadHVNcell");
      firstJetLArBadHVEnergyFrac=(*jetitr)->auxdata<float>("LArBadHVEnergyFrac");
      firstJetMaxOverMean=(*jetitr)->auxdata<float>("MaxOverMean");
      firstJetMaxConstituentET=(*jetitr)->auxdata<float>("MaxConstituentET");
      firstJetOotFracClusters10=(*jetitr)->auxdata<float>("OotFracClusters10");
      firstJetOotFracClusters5=(*jetitr)->auxdata<float>("OotFracClusters5");
      vecfirst.SetPtEtaPhiM( firstJetPt, firstJetEta, firstJetPhi, firstJetM );
/*    }
    else if (jetPt>secondJetPt){
      secondJetPt=jetPt;
      secondJetEta=jetEta;
      secondJetPhi=jetPhi;
      secondJetLArQ=(*jetitr)->auxdata<float>("LArQuality");
      secondJetAveLArQF=((*jetitr)->auxdata<float>("AverageLArQF"))/65535.;
      secondJetHECQ=(*jetitr)->auxdata<float>("HECQuality");
      secondJetfch=(sumpttrk.size() > 0) ? sumpttrk[0]*0.001/jetPt : 0;
      secondJetEMFrac=(*jetitr)->auxdata<float>("EMFrac");
      secondJetHECFrac=(*jetitr)->auxdata<float>("HECFrac");
      secondJetfmax=(*jetitr)->auxdata<float>("FracSamplingMax");
      secondJetTiming=(*jetitr)->auxdata<float>("Timing");
    }
*/
    vecsum-=vec;
  }//for(; jetitr != jetend; ++jetitr ) {

  hmissdir = vecsum.Phi();
  hmiss = vecsum.Pt();

//  if (firstJetPt+secondJetPt!=0) EtBal=(firstJetPt-secondJetPt)/(firstJetPt+secondJetPt);
//  if (EtBal<0.3 && firstJetPt>100 && secondJetPt>100) GoodJet=true;
cout<<"I'm Fillin'"<<endl;
//  if (GoodJet){
    dphiFS=DeltaPhi(firstJetPhi,secondJetPhi);
    h3_pt_fr_deltaphi[ih]->Fill(dphiFS,firstJetEta,firstJetPt);
    h3_pt_fr_jetkin[ih]->Fill(firstJetPhi,firstJetEta,firstJetPt);
    h3_pt_fr_jetkin[ih]->Fill(secondJetPhi,secondJetEta,secondJetPt);
    h2_Jet_fr_Pt[ih]->Fill( firstJetPt, firstJetEta );
    h2_Jet_fr_Pt[ih]->Fill( secondJetPt, secondJetEta );
//  }else{
    h3_pt_deltaphi[ih]->Fill(DeltaPhi(firstJetPhi,hmissdir),firstJetEta,hmiss);
    h2_Jet_Pt[ih]->Fill( firstJetPt, firstJetEta );
//  }

//  if (fabs(dphiFS) > 3.0 && GoodJet){
    h3_pt_fr_FracSamplingMax[ih]->Fill(firstJetfmax,firstJetEta,firstJetPt);
    h3_pt_fr_HECQuality[ih]->Fill(firstJetHECQ,firstJetEta,firstJetPt);
    h3_pt_fr_fch[ih]->Fill(firstJetfch,firstJetEta,firstJetPt);
    h3_pt_fr_fchFracSamplingMax[ih]->Fill((firstJetfch)/firstJetfmax,firstJetEta,firstJetPt);
    h3_pt_fr_fchEMFrac[ih]->Fill(firstJetEMFrac,firstJetfch,firstJetEta);
    h3_pt_fr_EMFrac[ih]->Fill(firstJetEMFrac,firstJetEta,firstJetPt);
    h3_pt_fr_HECFrac[ih]->Fill(firstJetHECFrac,firstJetEta,firstJetPt);
    h3_pt_fr_LArQuality[ih]->Fill(firstJetLArQ,firstJetEta,firstJetPt);
    h3_pt_fr_AverageLArQF[ih]->Fill(firstJetAveLArQF,firstJetEta,firstJetPt);
    h3_pt_fr_LArQualityEMFrac[ih]->Fill(firstJetEMFrac,firstJetLArQ,firstJetEta);
    h3_pt_fr_Timing[ih]->Fill(firstJetTiming,firstJetEta,firstJetPt);

    h3_pt_fr_FracSamplingMax[ih]->Fill(secondJetfmax,secondJetEta,secondJetPt);
    h3_pt_fr_HECQuality[ih]->Fill(secondJetHECQ,secondJetEta,secondJetPt);
    h3_pt_fr_fch[ih]->Fill(secondJetfch,secondJetEta,secondJetPt);
    h3_pt_fr_fchFracSamplingMax[ih]->Fill((secondJetfch)/secondJetfmax,secondJetEta,secondJetPt);
    h3_pt_fr_fchEMFrac[ih]->Fill(secondJetEMFrac,secondJetfch,secondJetEta);
    h3_pt_fr_EMFrac[ih]->Fill(secondJetEMFrac,secondJetEta,secondJetPt);
    h3_pt_fr_HECFrac[ih]->Fill(secondJetHECFrac,secondJetEta,secondJetPt);
    h3_pt_fr_LArQuality[ih]->Fill(secondJetLArQ,secondJetEta,secondJetPt);
    h3_pt_fr_AverageLArQF[ih]->Fill(secondJetAveLArQF,secondJetEta,secondJetPt);
    h3_pt_fr_LArQualityEMFrac[ih]->Fill(secondJetEMFrac,secondJetLArQ,secondJetEta);
    h3_pt_fr_Timing[ih]->Fill(secondJetTiming,secondJetEta,secondJetPt);
    // fill the branches of our trees
    LArQuality = firstJetLArQ;
    FracSamplingMaxIndex=firstJetfmaxindex;  
    FracSamplingMax=firstJetfmax;  
    AverageLArQF=firstJetAveLArQF;  
    HECQuality=firstJetHECQ;  
    Width=firstJetWidth;  
    fch=firstJetfch;  
    EMFrac=firstJetEMFrac;  
    HECFrac=firstJetHECFrac;  
    Timing=firstJetTiming;  
    NegativeE=firstJetNegativeE;
    Pt=firstJetPt;
    Eta=firstJetEta;
    Phi=firstJetPhi;
    Mass=firstJetM;
    N90Constituents=firstJetN90Constituents;		
    BchCorrCell=firstJetBchCorrCell;		
    Jvt=firstJetJvt;			
    JvtJvfcorr=firstJetJvtJvfcorr;		
    JvtRpt=firstJetJvtRpt;			
    LArBadHVNcell=firstJetLArBadHVNcell;		
    LArBadHVEnergyFrac=firstJetLArBadHVEnergyFrac;	
    MaxOverMean=firstJetMaxOverMean;		
    MaxConstituentET=firstJetMaxConstituentET;	
    OotFracClusters10=firstJetOotFracClusters10;	
    OotFracClusters5=firstJetOotFracClusters5;         
    TreeS->Fill();
 // } // if (fabs(dphiFS) > 3.0 && GoodJet){

  //background 
  //if (fabs(DeltaPhi(firstJetPhi,hmissdir)) > 3.0 && hmiss > 100 && firstJetPt > 100) {
   // if (jets->size() >1 && ((!(firstJetEMFrac < 0.05 || firstJetEMFrac >0.99 || firstJetfmax>0.99)) ||  (fabs(firstJetTiming) < 6 && fabs(secondJetTiming) < 6))) return EL::StatusCode::SUCCESS; // go to next event, most likely not a bad jet

    cout<<"bad jet "<<eventNumber<<" "<<firstJetEMFrac<<" "<<firstJetfmax<<" "<<EtBal<<endl;


   h3_pt_FracSamplingMax[ih]->Fill(firstJetfmax,firstJetEta,firstJetPt);
    h3_pt_HECQuality[ih]->Fill(firstJetHECQ,firstJetEta,firstJetPt);
    h3_pt_fch[ih]->Fill(firstJetfch,firstJetEta,firstJetPt);
    h3_pt_fchFracSamplingMax[ih]->Fill((firstJetfch)/firstJetfmax,firstJetEta,firstJetPt);
    h3_pt_fchEMFrac[ih]->Fill(firstJetEMFrac,firstJetfch,firstJetEta);
    h3_pt_EMFrac[ih]->Fill(firstJetEMFrac,firstJetEta,firstJetPt);
    h3_pt_HECFrac[ih]->Fill(firstJetHECFrac,firstJetEta,firstJetPt);
    h3_pt_LArQuality[ih]->Fill(firstJetLArQ,firstJetEta,firstJetPt);
    h3_pt_AverageLArQF[ih]->Fill(firstJetAveLArQF,firstJetEta,firstJetPt);
    h3_pt_LArQualityEMFrac[ih]->Fill(firstJetEMFrac,firstJetLArQ,firstJetEta);
    h3_pt_Timing[ih]->Fill(firstJetTiming,firstJetEta,firstJetPt);

    // fill the branches of our trees
    LArQuality = firstJetLArQ;
    FracSamplingMaxIndex=firstJetfmaxindex;  
    FracSamplingMax=firstJetfmax;  
    AverageLArQF=firstJetAveLArQF;  
    HECQuality=firstJetHECQ;  
    Width=firstJetWidth;  
    fch=firstJetfch;  
    EMFrac=firstJetEMFrac;  
    HECFrac=firstJetHECFrac;  
    Timing=firstJetTiming;  
    NegativeE=firstJetNegativeE;
    Pt=firstJetPt;
    Eta=firstJetEta;
    Phi=firstJetPhi;
    Mass=firstJetM;
    N90Constituents=firstJetN90Constituents;		
    BchCorrCell=firstJetBchCorrCell;		
    Jvt=firstJetJvt;			
    JvtJvfcorr=firstJetJvtJvfcorr;		
    JvtRpt=firstJetJvtRpt;			
    LArBadHVNcell=firstJetLArBadHVNcell;		
    LArBadHVEnergyFrac=firstJetLArBadHVEnergyFrac;	
    MaxOverMean=firstJetMaxOverMean;		
    MaxConstituentET=firstJetMaxConstituentET;	
    OotFracClusters10=firstJetOotFracClusters10;	
    OotFracClusters5=firstJetOotFracClusters5;  
    TreeB->Fill();
 // }

  delete jets_shallowCopy.first;
  delete jets_shallowCopy.second;
  
  //end of Jet quality study

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode HIHI_TMVA :: postExecute ()
{
  // Here you do everything that needs to be done after the main event
  // processing.  This is typically very rare, particularly in user
  // code.  It is mainly used in implementing the NTupleSvc.
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode HIHI_TMVA :: finalize ()
{
  // This method is the mirror image of initialize(), meaning it gets
  // called after the last event has been processed on the worker node
  // and allows you to finish up any objects you created in
  // initialize() before they are written to disk.  This is actually
  // fairly rare, since this happens separately for each worker node.
  // Most of the time you want to do your post-processing on the
  // submission node after all your histogram outputs have been
  // merged.  This is different from histFinalize() in that it only
  // gets called on worker nodes that processed input events.
  xAOD::TEvent* event = wk()->xaodEvent();

  // GRL
  if (m_grl) {
    delete m_grl;
    m_grl = 0;
  }

  // cleaning up trigger tools
  if( m_trigConfigTool ) {
    delete m_trigConfigTool;
    m_trigConfigTool = 0;
  }
  if( m_trigDecisionTool ) {
    delete m_trigDecisionTool;
    m_trigDecisionTool = 0;
  }

  // JetCalibration
  if (m_jetCalibration) {
    delete m_jetCalibration;
    m_jetCalibration = 0;
  }

  // muonSelection
  if (m_muonSelection) {
    delete m_muonSelection;
    m_muonSelection = 0;
  }

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode HIHI_TMVA :: histFinalize ()
{
  // This method is the mirror image of histInitialize(), meaning it
  // gets called after the last event has been processed on the worker
  // node and allows you to finish up any objects you created in
  // histInitialize() before they are written to disk.  This is
  // actually fairly rare, since this happens separately for each
  // worker node.  Most of the time you want to do your
  // post-processing on the submission node after all your histogram
  // outputs have been merged.  This is different from finalize() in
  // that it gets called on all worker nodes regardless of whether
  // they processed input events.


  return EL::StatusCode::SUCCESS;
}
