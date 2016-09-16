
/*
 *  IMuonTriggerScaleFactors.h
 *
 *  Created on: Oct. 22, 2014
 *      Author: Kota Kasahara <kota.kasahara@cern.ch>
 */

#ifndef IMUONTRIGGERSCALEFACTORS_H_
#define IMUONTRIGGERSCALEFACTORS_H_

#include "AsgTools/IAsgTool.h"
#include "PATInterfaces/CorrectionCode.h"
#include "PATInterfaces/ISystematicsTool.h"
#include "xAODMuon/Muon.h"
#include "xAODMuon/MuonContainer.h"

#include "PATInterfaces/CorrectionCode.h"
#include <string>
#include <vector>
#include <map>
  
namespace TrigMuonEff {

  /**
   *  strcuture to hold variables to configure behaviour of the tool
   */
  struct Configuration {
    mutable bool isData;
    bool setByUser;       /**<  true if the structure is set by user */
    int replicaIndex;     /**<  index of replicated histograms to access */
    int runNumber;        /**<  run number */
    std::string trigger;  /**<  trigger */
    std::string period;   /**<  data taking period */
    std::string binning;  /**<  binning of the scale factor map */

    Configuration(const bool isData_ = true,
		  const bool setByUser_ = false,
                  const int replicaIndex_ = -1,
                  const int runNumber_ = 0,
                  const std::string& trigger_ = "",
                  const std::string& period_ = "",
                  const std::string& binning_ = "") :
      isData(isData_),
      setByUser(setByUser_),
      replicaIndex(replicaIndex_),
      runNumber(runNumber_),
      trigger(trigger_), 
      period(period_),
      binning(binning_) {}
  };

  /**
   *  Helper enumeration defining the data periods understood by the tool
   */

  typedef enum DataPeriod {
    period_undefined = -1,            perUnDefined      = -1,
    
    // 2015
    period_2015_AC = 0,     per2015AC = 0,
    period_2015_D = 1,     per2015D = 1,
    period_2015_E = 2,     per2015E = 2,
    period_2015_F = 3,     per2015F = 3,
    period_2015_G = 4,     per2015G = 4,
    period_2015_H = 5,     per2015H = 5,
    period_2015_I = 6,     per2015I = 6,
    period_2015_J = 7,     per2015J = 7,
    
    period_runnumber_zero = -2
  } SFDataPeriod;
}

/**
 * Helper enumeration for systematics study
 */

namespace CP {
  
  class IMuonTriggerScaleFactors : public virtual asg::IAsgTool, virtual public CP::ISystematicsTool {
    //class IMuonTriggerScaleFactors : public virtual asg::IAsgTool {
    
    ASG_TOOL_INTERFACE( CP::IMuonTriggerScaleFactors )
      
      public:
    virtual StatusCode initialize(void) = 0;

    virtual CorrectionCode setRunNumber(Int_t runNumber) = 0;


    virtual CorrectionCode getTriggerScaleFactor(const xAOD::MuonContainer& mucont,
						 Double_t& triggersf,
						 const std::string& trigger) = 0;

    virtual CorrectionCode getTriggerEfficiency(const xAOD::Muon& mu,
						Double_t& efficiency,
						const std::string& trigger,
						Bool_t dataType) = 0;
    /*
    virtual CorrectionCode getTriggerScaleFactor(const xAOD::MuonContainer& mucont,
						 Double_t& triggersf,
						 std::string trigger) = 0;

    virtual CorrectionCode getTriggerEfficiency(const xAOD::Muon& mu,
						std::pair<double,double>& efficiency,
						std::string trigger) = 0;
    */
  }; // class IMuonEfficiencyTool
  
} // namespace CP

#endif /* IMUONTRIGGERSCALEFACTORS_H_ */