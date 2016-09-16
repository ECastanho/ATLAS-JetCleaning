#ifndef JetCleaningAnalysis_HIHI_TMVA_H
#define JetCleaningAnalysis_HIHI_TMVA_H

#include <EventLoop/Algorithm.h>
#include "xAODEventInfo/EventInfo.h"
#include "GoodRunsLists/GoodRunsListSelectionTool.h"
#include "JetCleaningAnalysisHI/AtlasStyle.h"
#include "TrigConfxAOD/xAODConfigTool.h"
#include "TrigDecisionTool/TrigDecisionTool.h"
#include "JetCalibTools/JetCalibrationTool.h"
#include "MuonSelectorTools/MuonSelectionTool.h"

#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TTree.h>
#include <vector>

class HIHI_TMVA : public EL::Algorithm
{

  GoodRunsListSelectionTool *m_grl; //!

  // trigger tools member variables
  Trig::TrigDecisionTool *m_trigDecisionTool; //!
  TrigConf::xAODConfigTool *m_trigConfigTool; //!

  JetCalibrationTool *m_jetCalibration; //!

  CP::MuonSelectionTool *m_muonSelection; //!
  // put your configuration variables here as public variables.
  // that way they can be set directly from CINT and python.
 public:

  bool doCaloJets;
  bool doFakes;

  bool GoodJet; //fakes

  // variables that don't get filled at submission time should be
  // protected from being send from the submission node to the worker
  // node (done by the //!)
 public:

  int nCentBins, ih;
  int m_eventCounter; //!
  int m_backgroundFlags; //!

  TH2F **h2_Jet_Pt; //!
  TH2F **h2_Jet_fr_Pt; //!
  TH1 *h2_Jet_DeltaEta; //!
  TH1 *h2_Jet_DeltaPhi; //!
  TH1 *h1_Jet_NegMass; //!
  TH2 *h2_Jet_EtaPhi; //!
  TH2 *h2_Jet_PtNconst; //!
  TH2 *h2_Jet_PtMass; //!
  TH2 *h2_Jet_Etconst; //!

  TH3F** h3_pt_jetkin; //!
  TH3F** h3_pt_hmiss; //!
  TH3F** h3_pt_deltaphi; //!

  TH3F** h3_pt_fr_jetkin; //!
  TH3F** h3_pt_fr_deltaphi; //!
  TH3F** h3_pt_fr_FracSamplingMaxIndex; //! 
  TH3F** h3_pt_fr_FracSamplingMax; //! 
  TH3F** h3_pt_fr_AverageLArQF; //! 
  TH3F** h3_pt_fr_HECQuality; //! 
  TH3F** h3_pt_fr_Width; //! 
  TH3F** h3_pt_fr_fch; //! 
  TH3F** h3_pt_fr_fchFracSamplingMax; //! 
  TH3F** h3_pt_fr_fchEMFrac; //! 
  TH3F** h3_pt_fr_EMFrac; //! 
  TH3F** h3_pt_fr_HECFrac; //! 
  TH3F** h3_pt_fr_Timing; //! 
  TH3F** h3_pt_fr_LArQuality; //! 
  TH3F** h3_pt_fr_LArQualityEMFrac; //! 

  TH3F** h3_pt_FracSamplingMax; //! 
  TH3F** h3_pt_AverageLArQF; //! 
  TH3F** h3_pt_HECQuality; //! 
  TH3F** h3_pt_Width; //! 
  TH3F** h3_pt_fch; //! 
  TH3F** h3_pt_fchFracSamplingMax; //! 
  TH3F** h3_pt_fchEMFrac; //! 
  TH3F** h3_pt_EMFrac; //! 
  TH3F** h3_pt_HECFrac; //! 
  TH3F** h3_pt_Timing; //! 
  TH3F** h3_pt_LArQuality; //! 
  TH3F** h3_pt_LArQualityEMFrac; //! 

// defining the output file name and tree that we will put in the output ntuple, also the one branch that will be in that tree 
  std::string outputName;
  TTree *TreeS; //!
  TTree *TreeB; //!
  TTree *TreePhB; //!
  TTree *TreeMB; //!
  int EventNumber; //!
  int FracSamplingMaxIndex; //! 
  float FracSamplingMax; //! 
  float AverageLArQF; //! 
  float HECQuality; //! 
  float Width; //! 
  float fch; //! 
  float EMFrac; //! 
  float HECFrac; //! 
  float Timing; //! 
  float LArQuality; //! 
  float NegativeE; //! 
  float Pt; //! 
  float Eta; //! 
  float Phi; //! 
  float Mass; //! 
  float N90Constituents; //!
  float BchCorrCell; //!
  float Jvt; //!
  float JvtJvfcorr; //!
  float JvtRpt; //!
  float LArBadHVNcell; //!
  float LArBadHVEnergyFrac; //!
  float MaxOverMean; //!
  float MaxConstituentET; //!
  float OotFracClusters10; //!
  float OotFracClusters5; //!
  float Ph_Pt; //! 
  float Ph_Eta; //! 
  float Ph_Phi; //! 
  float M_Pt; //! 
  float M_Eta; //! 
  float M_Phi; //! 

  // this is a standard constructor
  HIHI_TMVA ();

  Float_t DeltaEta(Float_t Eta1, Float_t Eta2);
  Float_t DeltaPhi(Float_t Phi1, Float_t Phi2);
  Float_t DeltaR(Float_t Phi1, Float_t Eta1, Float_t Phi2, Float_t Eta2);

  // these are the functions inherited from Algorithm
  virtual EL::StatusCode setupJob (EL::Job& job);
  virtual EL::StatusCode fileExecute ();
  virtual EL::StatusCode histInitialize ();
  virtual EL::StatusCode changeInput (bool firstFile);
  virtual EL::StatusCode initialize ();
  virtual EL::StatusCode execute ();
  virtual EL::StatusCode postExecute ();
  virtual EL::StatusCode finalize ();
  virtual EL::StatusCode histFinalize ();

  // this is needed to distribute the algorithm to the workers
  ClassDef(HIHI_TMVA, 1);
};

#endif
