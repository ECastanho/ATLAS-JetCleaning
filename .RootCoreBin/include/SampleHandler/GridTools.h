#ifndef SAMPLE_HANDLER__GRID_TOOLS_H
#define SAMPLE_HANDLER__GRID_TOOLS_H

//          Copyright Nils Krumnack 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// Please feel free to contact me (nils.erik.krumnack@iastate.edu) for
// bug reports, feature suggestions, praise and complaints.



#include <SampleHandler/Global.h>

#include <AsgTools/MessageCheck.h>

namespace SH
{
  ANA_MSG_HEADER (msgGridTools)

  /// \brief return whether we have a valid VOMS proxy available
  /// \par Guarantee
  ///   basic
  /// \par Failures
  ///   grid utility failures
  bool checkVomsProxy ();

  /// \brief ensure that we have a valid VOMS proxy available
  ///
  /// First this checks whether we have a valid PROXY, and if not it
  /// sets up a new certificate.
  ///
  /// \par Guarantee
  ///   basic
  /// \par Failures
  ///   grid utility failures\n
  ///   failure to set up new VOMS proxy
  void ensureVomsProxy ();
}

#endif
