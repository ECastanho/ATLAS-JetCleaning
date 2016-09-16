""" AssociationUtils/config.py
    This file contains the configuration helper code for the overlap removal
    tools in Athena. It is a work in progress. It may in fact be possible to
    utilize some of this code also in RootCore with some PyROOT magic, but for
    now you should just use the C++ helper code in OverlapRemovalInit if you're
    working in RootCore.
"""

from AthenaCommon.Constants import INFO

from AssociationUtils.AssociationUtilsConf import (
    ORUtils__OverlapRemovalTool as OverlapRemovalTool,
    ORUtils__DeltaROverlapTool as DeltaROverlapTool,
    ORUtils__EleJetOverlapTool as EleJetOverlapTool,
    ORUtils__EleMuSharedTrkOverlapTool as EleMuSharedTrkOverlapTool,
    ORUtils__MuJetOverlapTool as MuJetOverlapTool,
    ORUtils__TauLooseEleOverlapTool as TauLooseEleOverlapTool,
    ORUtils__TauLooseMuOverlapTool as TauLooseMuOverlapTool
)

#-------------------------------------------------------------------------------
def recommended_tools(name='OverlapRemovalTool',
                      input_label='selected', output_label='overlaps',
                      bjet_label='', boosted_leptons=False,
                      output_pass_value=False,
                      link_overlap_objects=False,
                      do_electrons=True, do_muons=True, do_jets=True,
                      do_taus=True, do_photons=True, do_fatjets=False,
                      **kwargs):
    """
    Provides the pre-configured overlap removal recommendations.
    All overlap tools will be (private) added to the master tool
    which is then returned by this function.

    Arguments:
      name                  - set the name of the master tool.
      input_label           - set the InputLabel property for all tools.
      output_label          - set the OutputLabel property for all tools.
      bjet_label            - set user bjet decoration name. Leave blank to
                              disable btag-aware overlap removal.
      boosted_leptons       - enable sliding dR cones for boosted lepton
                              analyses.
      output_pass_value     - set the OutputPassValue property for all tools
                              which determines whether passing objects are
                              marked with true or false.
      link_overlap_oobjects - enable ElementLinks to overlap objects.
      do_XXXX               - these flags enable/disable object types to
                              configure tools for: do_electrons, do_muons,
                              do_jets, do_taus, do_photons, do_fatjets.
      kwargs                - additional properties to be applied to all tools.
                              For example: OutputLevel.
    """

    # These properties can be applied to all tools
    common_args = {
        'InputLabel' : input_label,
        'OutputLabel' : output_label,
        'OutputPassValue' : output_pass_value
    }
    # Extend with additional user-defined global properties
    common_args.update(kwargs)

    # Configure the master tool
    orTool = OverlapRemovalTool(name, **common_args)

    # Overlap tools share an additional common property for object linking
    common_args['LinkOverlapObjects'] = link_overlap_objects

    # Electron-muon
    if do_electrons and do_muons:
        orTool.EleMuORT = EleMuSharedTrkOverlapTool('EleMuORT', **common_args)
    # Electron-jet
    if do_electrons and do_jets:
        orTool.EleJetORT = EleJetOverlapTool('EleJetORT',
                                             BJetLabel=bjet_label,
                                             UseSlidingDR=boosted_leptons,
                                             **common_args)
    # Muon-jet
    if do_muons and do_jets:
        orTool.MuJetORT = MuJetOverlapTool('MuJetORT',
                                            BJetLabel=bjet_label,
                                            UseSlidingDR=boosted_leptons,
                                            **common_args)

    # Tau-electron
    if do_taus and do_electrons:
        orTool.TauEleORT = TauLooseEleOverlapTool('TauEleORT', **common_args)
    # Tau-muon
    if do_taus and do_muons:
        orTool.TauMuORT = TauLooseMuOverlapTool('TauMuORT', **common_args)
    # Tau-jet
    if do_taus and do_jets:
        orTool.TauJetORT = DeltaROverlapTool('TauJetORT', DR=0.2, **common_args)

    # Photon-electron
    if do_photons and do_electrons:
        orTool.PhoEleORT = DeltaROverlapTool('PhoEleORT', **common_args)
    # Photon-muon
    if do_photons and do_muons:
        orTool.PhoMuORT = DeltaROverlapTool('PhoMuORT', **common_args)
    # Photon-jet
    if do_photons and do_jets:
        orTool.PhoJetORT = DeltaROverlapTool('PhoJetORT', **common_args)

    # Electron-fatjet
    if do_electrons and do_fatjets:
        orTool.EleFatJetORT = DeltaROverlapTool('EleFatJetORT', DR=1.0, **common_args)
    # Jet-fatjet
    if do_jets and do_fatjets:
        orTool.JetFatJetORT = DeltaROverlapTool('JetFatJetORT', DR=1.0, **common_args)

    return orTool


#-------------------------------------------------------------------------------
def harmonized_tools(name='OverlapRemovalTool', OutputLevel=INFO,
                     input_label='selected', output_label='overlaps',
                     output_pass_value=False, do_taus=True, do_photons=True):
    """
    Provides the pre-configured overlap removal tools according to the
    recommendations of the harmonization document. The recommended_tools
    function gives the updated recommendations.
    """

    # Call the above function for standard pre-configured tools
    orTool = recommended_tools(name, OutputLevel, input_label, output_label,
                               output_pass_value=output_pass_value,
                               do_taus=do_taus, do_photons=do_photons)

    # Override properties
    orTool.EleMuORT.RemoveCaloMuons = False
    orTool.EleJetORT.ApplyJVT = False
    orTool.MuJetORT.ApplyJVT = False
    orTool.MuJetORT.MuJetPtRatio = 1e20
    orTool.MuJetORT.MuJetTrkPtRatio = 1e20
    orTool.MuJetORT.UseGhostAssociation = False
    orTool.MuJetORT.InnerDR = 0.4

    return orTool
