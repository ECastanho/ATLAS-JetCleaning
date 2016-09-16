
// Dear emacs, this is -*-c++-*-
#ifndef __ASGELECTRONISEMSELECTRONCONFIGHELPER__
#define __ASGELECTRONISEMSELECTRONCONFIGHELPER__

/**
   @brief Tool to simplify the configuration of the cut based IsEM based on TEnv input

   @author Christos Anastopoulos
*/
#include <string>
#include <vector>
#include "TEnv.h"

namespace AsgConfigHelper{

  std::vector<double> HelperDouble(const std::string& input,  TEnv& env);  
  std::vector<float> HelperFloat(const std::string& input,  TEnv& env);  
  std::vector<int> HelperInt(const std::string& input, TEnv& env);
}


#endif
