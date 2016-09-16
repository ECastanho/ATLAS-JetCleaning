// Dear emacs, this is -*- c++ -*-
#ifndef  TAUANALYSISTOOLS_TAUTRUTHTRACKMATCHINGTOOL_H
#define  TAUANALYSISTOOLS_TAUTRUTHTRACKMATCHINGTOOL_H

/*
  author: Dirk Duschinger
  mail: dirk.duschinger@cern.ch
  documentation in: ../README.rst
                    or
                    https://svnweb.cern.ch/trac/atlasoff/browser/PhysicsAnalysis/TauID/TauAnalysisTools/tags/TauAnalysisTools-<tag>/README.rst
		    or
                    https://svnweb.cern.ch/trac/atlasoff/browser/PhysicsAnalysis/TauID/TauAnalysisTools/trunk/README.rst
*/

// Framework include(s):
#include "AsgTools/AsgTool.h"

// Local include(s):
#include "TauAnalysisTools/ITauTruthTrackMatchingTool.h"


namespace TauAnalysisTools
{
enum TrackSpuriousType_t
{
  UnclassifiedTrack     = 0, // Track is unclassified
  ConversionTrack       = 1, // Track is from conversion
  PileupTrack           = 2, // Track is from pileup
  UnderlyingEventTrack  = 3, // Track is from underlying event
  FakeTrack             = 4  // Track is a fake
};


class TauTruthTrackMatchingTool
  : public TauAnalysisTools::ITauTruthTrackMatchingTool
  , public asg::AsgTool
{
  /// Create a proper constructor for Athena
  ASG_TOOL_CLASS( TauTruthTrackMatchingTool,
                  TauAnalysisTools::ITauTruthTrackMatchingTool )

public:

  TauTruthTrackMatchingTool( const std::string& name );

  virtual ~TauTruthTrackMatchingTool();

  virtual StatusCode initialize();

  // classify vector of tracks
  virtual StatusCode classifyTracks(std::vector<const xAOD::TrackParticle*>& vTracks);

  // classify a single track
  virtual StatusCode classifyTrack(const xAOD::TrackParticle& xTrackParticle);

private:

  void checkTrackSpuriousType(const xAOD::TrackParticle& xTrackParticle);
  void checkTrackIsTauInheritant(const xAOD::TrackParticle& xTrackParticle);
  bool checkTruthParent(const xAOD::TruthParticle& xTruthParticle, int& iDepth, std::string& sHistory);
  const xAOD::TruthParticle* getTruthParticle(const xAOD::TrackParticle& xTrackParticle);

private:
  bool m_bIsHadronicTrackAvailable;
  bool m_bIsHadronicTrackAvailableChecked;

}; // class TauTruthTrackMatchingTool

}
#endif // TAUANALYSISTOOLS_TAUTRUTHTRACKMATCHINGTOOL_H

