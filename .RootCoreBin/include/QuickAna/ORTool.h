#ifndef QUICK_ANA__OR_TOOL_H
#define QUICK_ANA__OR_TOOL_H

/// This file defines the overlap removal tool: ORTool

#include <QuickAna/Global.h>

#include <QuickAna/AnaTool.h>
#include <AsgTools/AnaToolHandle.h>
#include <QuickAna/xAODInclude.h>

// Forward declarations
namespace ORUtils
{
  class IOverlapRemovalTool;
  class IOverlapTool;
}

namespace ana
{

  /// @brief QuickAna tool for applying standard overlap removal.
  ///
  /// This AnaTool uses the overlap removal tools from AssociationUtils.
  /// It is able to apply either the harmonization note recommendations or the
  /// updated overlap removal recommendations via the RecommendationSet
  /// configuration property.
  ///
  /// For more details on the overlap removal recommendations, see the
  /// AssociationUtils documentation:
  /// https://svnweb.cern.ch/trac/atlasoff/browser/PhysicsAnalysis/AnalysisCommon/AssociationUtils/trunk/doc/README.rst
  ///
  /// @author Steve Farrell <Steven.Farrell@cern.ch>
  ///
  class ORTool : public AnaTool
  {

    ASG_TOOL_CLASS(ORTool, ana::IAnaTool)

  public:

    /// Enum for broad configuration settings
    enum RecommendationSet
    {
      /// Undefined
      RECS_UNDEFINED = -1,
      /// The latest and greatest recommendations
      RECS_CURRENT = 0,
      /// The harmonization note recommendations (now outdated)
      RECS_HARMONIZATION
    };

    /// @brief Standard constructor
    ///
    /// @par guarantee: strong
    /// @par failures: out of memory II
    ORTool(const std::string& name);

    /// \copydoc IAnaTool::setObjectType
    virtual StatusCode
    setObjectType(ObjectType type, const std::string& workingPoint) override;

    /// @brief Initialize this tool
    ///
    /// @par guarantee: basic
    /// @par failures: configuration errors
    StatusCode initialize() override;

    /// @brief Returns the processing step we are working on
    ///
    /// @par guarantee: no-fail
    virtual AnalysisStep step() const override;

    /// \copydoc IAnaTool::inputTypes
    virtual unsigned inputTypes() const override;

    /// \copydoc IAnaTool::outputTypes
    virtual unsigned outputTypes() const override;

    /// @brief Apply overlap removal to the objects.
    ///
    /// @par guarantee: basic
    /// @par failures: tool dependent
    virtual StatusCode execute(IEventObjects& objects) override;

  private:

    // Configuration

    /// the master OverlapRemoval tool
    asg::AnaToolHandle<ORUtils::IOverlapRemovalTool> m_orTool;
    /// The ele-mu overlap tool
    asg::AnaToolHandle<ORUtils::IOverlapTool> m_eleMuTool;
    /// The ele-jet overlap tool
    asg::AnaToolHandle<ORUtils::IOverlapTool> m_eleJetTool;
    /// The mu-jet overlap tool
    asg::AnaToolHandle<ORUtils::IOverlapTool> m_muJetTool;
    /// The tau-ele overlap tool
    asg::AnaToolHandle<ORUtils::IOverlapTool> m_tauEleTool;
    /// The tau-mu overlap tool
    asg::AnaToolHandle<ORUtils::IOverlapTool> m_tauMuTool;
    /// The tau-jet overlap tool
    asg::AnaToolHandle<ORUtils::IOverlapTool> m_tauJetTool;
    /// The pho-ele overlap tool
    asg::AnaToolHandle<ORUtils::IOverlapTool> m_phoEleTool;
    /// The pho-mu overlap tool
    asg::AnaToolHandle<ORUtils::IOverlapTool> m_phoMuTool;
    /// The pho-jet overlap tool
    asg::AnaToolHandle<ORUtils::IOverlapTool> m_phoJetTool;

    /// OR recommendation set
    //RecommendationSet m_recSet;

    /// OR recommendation set. Allowed values are:
    /// - current
    /// - harmonization
    std::string m_recSet;

    /// OR input decoration name
    std::string m_orInputLabel;

    /// OR output decoration name
    std::string m_orOutputLabel;

  }; // class ORTool

} // namespace ana

#endif
