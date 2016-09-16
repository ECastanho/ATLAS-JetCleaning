#include "xAODRootAccess/Init.h"
#include "SampleHandler/SampleHandler.h"
#include "SampleHandler/ScanDir.h"
#include "SampleHandler/ToolsDiscovery.h"
#include "EventLoop/Job.h"
#include "EventLoop/DirectDriver.h"
#include "EventLoop/LocalDriver.h"
#include <EventLoopAlgs/NTupleSvc.h>
#include <EventLoop/OutputStream.h>
#include "SampleHandler/DiskListLocal.h"
#include <TSystem.h>

#include "JetCleaningAnalysisHI/HIHI_TMVA.h"

using namespace std;

int  main( int argc, char* argv[] ) {
cout<<"Starting the code"<<endl;
  // Take the submit directory from the input if provided:
  std::string submitDir = "submitDir";
  if( argc > 1 ) submitDir = argv[ 1 ];

  // Set up the job for xAOD access:
 cout << "Setting up the job for xAOD access" << endl;
  xAOD::Init().ignore();

  // Construct the samples to run on:
cout << "Constructing the samples to run on" << endl;
  SH::SampleHandler sh;

  // use SampleHandler to scan all of the subdirectories of a directory for particular MC single file:
  //  const char* inputFilePath = gSystem->ExpandPathName ("/lstore/calo/HI/data2015/pp/input/data15_5TeV.00286474.physics_Main.recon.AOD.r7744_tid07928661_00/");
cout << "Scanning for data files" << endl;
  const char* inputFilePath = gSystem->ExpandPathName ("/lstore/calo/HI/data2015/PbPb/Aaron/user.angerami.data15_hi.AllYear.express_express.DAOD_HION7.AA004_EXT0.62071608/");
  SH::ScanDir().filePattern("*").scan(sh, inputFilePath);


  // Set the name of the input TTree. It's always "CollectionTree"
  // for xAOD files.
  sh.setMetaString( "nc_tree", "CollectionTree" );

  // Print what we found:
  sh.print();

  // Create an EventLoop job:
  EL::Job job;
  job.sampleHandler( sh );
  //job.options()->setDouble (EL::Job::optMaxEvents, 50);
  job.options()->setString (EL::Job::optXaodAccessMode, EL::Job::optXaodAccessMode_athena);

  // define an output and an ntuple associated to that output
  EL::OutputStream output  ("myOutput");
  job.outputAdd (output);
  EL::NTupleSvc *ntuple = new EL::NTupleSvc ("myOutput");
  job.algsAdd (ntuple);

  // Add our analysis to the job:
  HIHI_TMVA* alg = new HIHI_TMVA();

  job.algsAdd( alg );

  alg->outputName = "myOutput"; // give the name of the output to our algorithm for TMVA mode

  // Run the job using the local/direct driver:
  EL::DirectDriver driver;
  //EL::LocalDriver driver;
  driver.submit( job, submitDir );

  return 0;
}
 
