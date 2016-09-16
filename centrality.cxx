#include <EventLoop/Job.h>
#include <EventLoop/StatusCode.h>
#include <EventLoop/Worker.h>
#include <MyAnalysis/centrality.h>
#include "xAODRootAccess/Init.h"
#include "xAODRootAccess/TEvent.h"
#include "xAODRootAccess/tools/Message.h"
#include "xAODJet/JetContainer.h"
#include "xAODCaloEvent/CaloClusterContainer.h"
#include "xAODTracking/VertexContainer.h"
#include "xAODForward/ForwardEventInfo.h"
#include "xAODForward/ForwardEventInfoContainer.h"
#include "xAODCore/ShallowCopy.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include <TSystem.h>

#define private public
#include "xAODHIEvent/HIEventShapeAuxContainer.h"
#undef private
#include "xAODHIEvent/HIEventShapeContainer.h"

using namespace std;

// this is needed to distribute the algorithm to the workers
ClassImp(centrality)


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




centrality :: centrality ()
//@ constructor
{
  // Here you put any code for the base initialization of variables,
  // e.g. initialize all pointers to 0.  Note that you should only put
  // the most basic initialization here, since this method will be
  // called on both the submission and the worker node.  Most of your
  // initialization code will go into histInitialize() and
  // initialize().

  doCentrality = true;
}



EL::StatusCode centrality :: setupJob (EL::Job& job)
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



EL::StatusCode centrality :: histInitialize ()
{
  // Here you do everything that needs to be done at the very
  // beginning on each worker node, e.g. create histograms and output
  // trees.  This method gets called before any input files are
  // connected.



  nCentBins           = 7;

  for (Int_t j=0; j<nCentBins; j++) {
    stringstream ss;
    string str;
    ss << std::setw(2) << std::setfill('0') << j;
    ss >> str;
    const std::string h3_Jet_Pt_eta_phi_tight_numStr       = "h3_Jet_Pt_eta_phi_tight_num_" + str;
    h3_Jet_Pt_eta_phi_tight_num[j] = new TH3F(h3_Jet_Pt_eta_phi_tight_numStr.c_str(), ";p_{T,jet} [GeV];#eta;", 200, 0, 1000, 120, -6., 6., 64, -TMath::Pi(), TMath::Pi());//efficiency
    const std::string h3_Jet_Pt_eta_phi_loose_numStr       = "h3_Jet_Pt_eta_phi_loose_num_" + str;
    h3_Jet_Pt_eta_phi_loose_num[j] = new TH3F(h3_Jet_Pt_eta_phi_loose_numStr.c_str(), ";p_{T,jet} [GeV];#eta;", 200, 0, 1000, 120, -6., 6., 64, -TMath::Pi(), TMath::Pi());//efficiency
    const std::string h3_Jet_Pt_eta_phi_tight_fake_numStr       = "h3_Jet_Pt_eta_phi_tight_fake_num_" + str;
    h3_Jet_Pt_eta_phi_tight_fake_num[j] = new TH3F(h3_Jet_Pt_eta_phi_tight_fake_numStr.c_str(), ";p_{T,jet} [GeV];#eta;", 200, 0, 1000, 120, -6., 6., 64, -TMath::Pi(), TMath::Pi());//efficiency
    const std::string h3_Jet_Pt_eta_phi_loose_fake_numStr       = "h3_Jet_Pt_eta_phi_loose_fake_num_" + str;
    h3_Jet_Pt_eta_phi_loose_fake_num[j] = new TH3F(h3_Jet_Pt_eta_phi_loose_fake_numStr.c_str(), ";p_{T,jet} [GeV];#eta;", 200, 0, 1000, 120, -6., 6., 64, -TMath::Pi(), TMath::Pi());//efficiency
    const std::string h3_Jet_Pt_eta_phi_tight_hmiss_numStr       = "h3_Jet_Pt_eta_phi_tight_hmiss_num_" + str;
    h3_Jet_Pt_eta_phi_tight_hmiss_num[j] = new TH3F(h3_Jet_Pt_eta_phi_tight_hmiss_numStr.c_str(), ";p_{T,jet} [GeV];#eta;", 200, 0, 1000, 120, -6., 6., 64, -TMath::Pi(), TMath::Pi());//efficiency
    const std::string h3_Jet_Pt_eta_phi_loose_hmiss_numStr       = "h3_Jet_Pt_eta_phi_loose_hmiss_num_" + str;
    h3_Jet_Pt_eta_phi_loose_hmiss_num[j] = new TH3F(h3_Jet_Pt_eta_phi_loose_hmiss_numStr.c_str(), ";p_{T,jet} [GeV];#eta;", 200, 0, 1000, 120, -6., 6., 64, -TMath::Pi(), TMath::Pi());//efficiency


    const std::string h3_Jet_Pt_eta_phi_denStr       = "h3_Jet_Pt_eta_phi_den_" + str;
    h3_Jet_Pt_eta_phi_den[j] = new TH3F(h3_Jet_Pt_eta_phi_denStr.c_str(), ";p_{T,jet} [GeV];#eta;", 200, 0, 1000, 120, -6., 6., 64, -TMath::Pi(), TMath::Pi());//efficiency
    const std::string h2_Jet_PtStr       = "h2_Jet_Pt_" + str;
    h2_Jet_Pt[j] = new TH2F(h2_Jet_PtStr.c_str(), ";p_{T,jet} [GeV];#eta;", 200, 0, 1000, 120, -6., 6.); // jet pt [GeV]
    const std::string h2_Multi_eta_phiStr       = "h2_Multi_eta_phi_" + str; 
    h2_Multi_eta_phi[j] = new TH2F(h2_Multi_eta_phiStr.c_str(), ";#eta;#phi;", 120, -6., 6., 64, -TMath::Pi(), TMath::Pi());
    const std::string h2_Multi_eta_phi_ptStr       = "h2_Multi_eta_phi_pt_" + str; 
    h2_Multi_eta_phi_pt[j] = new TH2F(h2_Multi_eta_phi_ptStr.c_str(), ";#eta;#phi;", 120, -6., 6., 64, -TMath::Pi(), TMath::Pi());
    const std::string h3_Multi_eta_ptStr       = "h3_Multi_eta_pt_" + str; 
    h3_Multi_eta_pt[j]  = new TH3F(h3_Multi_eta_ptStr.c_str(), ";#eta;N^{jets};p_{T,jet} [GeV];", 120, -6., 6.,100,0,99, 200, 0, 1000); //
    const std::string h3_Multi_phi_ptStr       = "h3_Multi_phi_pt_" + str; 
    h3_Multi_phi_pt[j]  = new TH3F(h3_Multi_phi_ptStr.c_str(), ";#phi;N^{jets};p_{T,jet} [GeV];", 64, -TMath::Pi(), TMath::Pi(),100,0,99, 200, 0, 1000); //
    const std::string h1_FracSamplingMaxIndexStr       = "h1_FracSamplingMaxIndex_" + str;
    h1_FracSamplingMaxIndex[j] = new TH1F(h1_FracSamplingMaxIndexStr.c_str(), ";FracSamplingMaxIndex;", 24,0,24);
    const std::string h1_FracSamplingMaxStr       = "h1_FracSamplingMax_" + str;
    h1_FracSamplingMax[j] = new TH1F(h1_FracSamplingMaxStr.c_str(), ";f_{max};", 100,-0.1, 2);
    const std::string h1_AverageLArQFStr       = "h1_AverageLArQF_" + str;
    h1_AverageLArQF[j] = new TH1F(h1_AverageLArQFStr.c_str(), ";Jet <Q>;", 100,-0.1, 300.);
    const std::string h1_HECQualityStr       = "h1_HECQuality_" + str;
    h1_HECQuality[j] = new TH1F(h1_HECQualityStr.c_str(), ";f^{HEC}_{Q};", 50,-0.1, 1.4);
    const std::string h1_WidthStr       = "h1_Width_" + str;
    h1_Width[j] = new TH1F(h1_WidthStr.c_str(), ";Jet Width;", 50, 0, 1.0);
    const std::string h1_EMFracStr       = "h1_EMFrac_" + str;
    h1_EMFrac[j] = new TH1F(h1_EMFracStr.c_str(), ";f_{EM};", 50, -1, 2);
    const std::string h1_TimingStr       = "h1_Timing_" + str;
    h1_Timing[j] = new TH1F(h1_TimingStr.c_str(), ";Timing;", 40, -20, 20);
    const std::string h1_LArQualityStr       = "h1_LArQuality_" + str;
    h1_LArQuality[j] = new TH1F(h1_LArQualityStr.c_str(), ";f^{LAr}_{Q};", 50, -0.4, 1.2);
    const std::string h2_Multi_FracSamplingMaxIndexStr       = "h2_Multi_FracSamplingMaxIndex_" + str;
    h2_Multi_FracSamplingMaxIndex[j] = new TH2F(h2_Multi_FracSamplingMaxIndexStr.c_str(), ";FracSamplingMaxIndex;N^{jets};", 24,0,24,100,0,99);
    const std::string h2_Multi_FracSamplingMaxStr       = "h2_Multi_FracSamplingMax_" + str;
    h2_Multi_FracSamplingMax[j] = new TH2F(h2_Multi_FracSamplingMaxStr.c_str(), ";f_{max};N^{jets};", 100,-0.1, 2,100,0,99);
    const std::string h2_Multi_AverageLArQFStr       = "h2_Multi_AverageLArQF_" + str;
    h2_Multi_AverageLArQF[j] = new TH2F(h2_Multi_AverageLArQFStr.c_str(), ";Jet <Q>;N^{jets};", 100,-0.1, 300.,100,0,99);
    const std::string h2_Multi_HECQualityStr       = "h2_Multi_HECQuality_" + str;
    h2_Multi_HECQuality[j] = new TH2F(h2_Multi_HECQualityStr.c_str(), ";f^{HEC}_{Q};N^{jets};", 50,-0.1, 1.4,100,0,99);
    const std::string h2_Multi_WidthStr       = "h2_Multi_Width_" + str;
    h2_Multi_Width[j] = new TH2F(h2_Multi_WidthStr.c_str(), ";Jet Width;N^{jets};", 50, 0, 1.0,100,0,99);
    const std::string h2_Multi_EMFracStr       = "h2_Multi_EMFrac_" + str;
    h2_Multi_EMFrac[j] = new TH2F(h2_Multi_EMFracStr.c_str(), ";f_{EM};N^{jets};", 100, -1, 2,100,0,99);
    const std::string h2_Multi_TimingStr       = "h2_Multi_Timing_" + str;
    h2_Multi_Timing[j] = new TH2F(h2_Multi_TimingStr.c_str(), ";Timing;N^{jets};", 40, -20, 20,100,0,99);
    const std::string h2_Multi_LArQualityStr       = "h2_Multi_LArQuality_" + str;
    h2_Multi_LArQuality[j] = new TH2F(h2_Multi_LArQualityStr.c_str(), ";f^{LAr}_{Q};N^{jets};", 50, -0.4, 1.2,100,0,99);

    const std::string h3_pt_jetkinStr       = "h3_pt_jetkin_" + str;
    h3_pt_jetkin[j] = new TH3F(h3_pt_jetkinStr.c_str(), ";#phi; #eta; p_{T,jet} [GeV];", 64, -TMath::Pi(), TMath::Pi(),120, -6., 6.,200, 0, 1000);
    const std::string h3_pt_hmissStr       = "h3_pt_hmiss_" + str;
    h3_pt_hmiss[j] = new TH3F(h3_pt_hmissStr.c_str(), ";#phi; #eta; p_{T,jet} [GeV];", 64, -TMath::Pi(), TMath::Pi(),120, -6., 6.,200, 0, 1000);
    const std::string h3_pt_deltaphiStr       = "h3_pt_deltaphi_" + str;
    h3_pt_deltaphi[j] = new TH3F(h3_pt_deltaphiStr.c_str(), ";deltaphi;#eta; p_{T,jet} [GeV];", 64, -TMath::Pi(), TMath::Pi(),120, -6., 6.,200, 0, 1000);
    const std::string h3_pt_FracSamplingMaxIndexStr       = "h3_pt_FracSamplingMaxIndex_" + str;
    h3_pt_FracSamplingMaxIndex[j] = new TH3F(h3_pt_FracSamplingMaxIndexStr.c_str(), ";FracSamplingMaxIndex;#eta; p_{T,jet} [GeV];", 24,0,24,120, -6., 6.,200,0,1000);
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



    const std::string h2_Jet_fr_PtStr       = "h2_Jet_fr_Pt_" + str;
    h2_Jet_fr_Pt[j] = new TH2F(h2_Jet_fr_PtStr.c_str(), ";p_{T,jet} [GeV];#eta;", 200, 0, 1000, 120, -6., 6.); // jet pt [GeV]
    const std::string h3_pt_fr_jetkinStr       = "h3_pt_fr_jetkin_" + str;
    h3_pt_fr_jetkin[j] = new TH3F(h3_pt_fr_jetkinStr.c_str(), ";#phi;#eta; p_{T,jet} [GeV];", 64, -TMath::Pi(), TMath::Pi(),120, -6., 6.,200, 0, 1000);
    const std::string h3_pt_fr_LjetkinStr       = "h3_pt_fr_Ljetkin_" + str;
    h3_pt_fr_Ljetkin[j] = new TH3F(h3_pt_fr_LjetkinStr.c_str(), ";#phi;#eta; p_{T,Ljet} [GeV];", 64, -TMath::Pi(), TMath::Pi(),120, -6., 6.,200, 0, 1000);
    const std::string h3_pt_fr_SLjetkinStr       = "h3_pt_fr_SLjetkin_" + str;
    h3_pt_fr_SLjetkin[j] = new TH3F(h3_pt_fr_SLjetkinStr.c_str(), ";#phi;#eta; p_{T,SLjet} [GeV];", 64, -TMath::Pi(), TMath::Pi(),120, -6., 6.,200, 0, 1000);
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
  }

 

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode centrality :: fileExecute ()
{
  // Here you do everything that needs to be done exactly once for every
  // single file, e.g. collect a list of all lumi-blocks processed
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode centrality :: changeInput (bool firstFile)
{
  // Here you do everything you need to do when we change input files,
  // e.g. resetting branch addresses on trees.  If you are using
  // D3PDReader or a similar service this method is not needed.
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode centrality :: initialize ()
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


  return EL::StatusCode::SUCCESS;
}



EL::StatusCode centrality :: execute ()
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
  
  int lbn = eventInfo->lumiBlock();
  int runNumber = eventInfo->runNumber();
  int eventNumber = eventInfo->eventNumber();


  //----------------------------
  // Container with clusters
  //--------------------------- 
  const xAOD::CaloClusterContainer* cls = 0;
  //https://twiki.cern.ch/twiki/bin/view/AtlasProtected/HeavyIon2015EventShape
  c0                  =2.38; 
  c1                  =1.22; 
  c2                  =0.56; 
  c3                  =0.22; 
  c4                  =0.02; 

  double FCal_Et = 0;
  if (doCentrality) {
    //Centrality
    const xAOD::HIEventShapeContainer* calos = 0;
    EL_RETURN_CHECK("execute()",event->retrieve( calos, "CaloSums" ));
    int x = 0;
    xAOD::HIEventShapeContainer::const_iterator calo_itr = calos->begin();
    xAOD::HIEventShapeContainer::const_iterator calo_end = calos->end();
   // for( ; calo_itr != calo_end; ++calo_itr ) {
   //   if (x == 5) {
   //     FCal_Et = ((*calo_itr)->et() * 0.001 * 0.001 );
   //   }
   //   x++;
   // }
    ih = 1000;
    if (FCal_Et >= c0)       ih=0;
    else if (FCal_Et >= c1 && FCal_Et < c0)  ih=1;
    else if (FCal_Et >= c2 && FCal_Et < c1)  ih=2;
    else if (FCal_Et >= c3 && FCal_Et < c2)  ih=3;
    else if (FCal_Et >= c4 && FCal_Et < c3)  ih=4;
    if (FCal_Et < c4)       ih=5;
    // if (FCal_Et >= c4) ih=6; //~0-90%
  }

 

  h3_pt_fr_Ljetkin[ih]->Fill(firstJetPhi,firstJetEta,firstJetPt);



  return EL::StatusCode::SUCCESS;
}



EL::StatusCode centrality :: postExecute ()
{
  // Here you do everything that needs to be done after the main event
  // processing.  This is typically very rare, particularly in user
  // code.  It is mainly used in implementing the NTupleSvc.
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode centrality :: finalize ()
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

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode centrality :: histFinalize ()
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
  if (doTracks) h2_Rtrk_EtaPhi->Divide(h2_Jet_EtaPhi);

  return EL::StatusCode::SUCCESS;
}
