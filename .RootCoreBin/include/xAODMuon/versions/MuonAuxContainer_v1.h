#ifndef XAODMUON_VERSIONS_MUONAUXCONTAINER_V1_H
#define XAODMUON_VERSIONS_MUONAUXCONTAINER_V1_H
 
// System include(s):
#include <stdint.h>
#include <vector>

// Core include(s):
#include "AthLinks/ElementLink.h"
#include "xAODCore/AuxContainerBase.h"
 
// xAOD include(s):
#include "xAODTracking/TrackParticleContainer.h" 
#include "xAODCaloEvent/CaloClusterContainer.h" 
#include "xAODMuon/MuonSegmentContainer.h" 
 
namespace xAOD {
 
   /// Temporary container used until we have I/O for AuxStoreInternal
   ///
   /// This class is meant to serve as a temporary way to provide an auxiliary
   /// store with Athena I/O capabilities for the Muon EDM. Will be exchanged for
   /// a generic auxiliary container type (AuxStoreInternal) later on.
   ///
   /// @author Edward Moyse
   ///
   class MuonAuxContainer_v1 : public AuxContainerBase {
 
   public:
      /// Default constructor
      MuonAuxContainer_v1();
 
   private:
      /// @name iParticle values
      /// @{                          
     std::vector< float >             pt;
     std::vector< float >             eta;
     std::vector< float >             phi;
     std::vector< float >             charge;
     /// @}  
			                       	
     /// @name Muon summary information
     /// @{                                      	
     std::vector< uint16_t >          allAuthors;
     std::vector< uint16_t>           author;
     std::vector< uint16_t>           muonType;
     std::vector< uint8_t>            quality; //quality, passesIDCuts and passesHighPtCuts are packed in here.

      /// @}  

      /// @name TrackSummary and MuonTrackSummary information
      /// @{
      std::vector< uint8_t >          numberOfPrecisionLayers;
      std::vector< uint8_t >          numberOfPrecisionHoleLayers;
      std::vector< uint8_t >          numberOfPhiLayers;
      std::vector< uint8_t >          numberOfPhiHoleLayers;
      std::vector< uint8_t >          numberOfTriggerEtaLayers;
      std::vector< uint8_t >          numberOfTriggerEtaHoleLayers;
      std::vector< uint8_t >          primarySector;
      std::vector< uint8_t >          secondarySector;
      
      std::vector< uint8_t >          innerSmallHits;
      std::vector< uint8_t >          innerLargeHits;
      std::vector< uint8_t >          middleSmallHits;
      std::vector< uint8_t >          middleLargeHits;
      std::vector< uint8_t >          outerSmallHits;
      std::vector< uint8_t >          outerLargeHits;
      std::vector< uint8_t >          extendedSmallHits;
      std::vector< uint8_t >          extendedLargeHits;
      
      std::vector< uint8_t >          innerSmallHoles;
      std::vector< uint8_t >          innerLargeHoles;
      std::vector< uint8_t >          middleSmallHoles;
      std::vector< uint8_t >          middleLargeHoles;
      std::vector< uint8_t >          outerSmallHoles;
      std::vector< uint8_t >          outerLargeHoles;
      std::vector< uint8_t >          extendedSmallHoles;
      std::vector< uint8_t >          extendedLargeHoles;
      
      std::vector< uint8_t >          phiLayer1Hits;
      std::vector< uint8_t >          phiLayer2Hits;
      std::vector< uint8_t >          phiLayer3Hits;
      std::vector< uint8_t >          phiLayer4Hits;
      
      std::vector< uint8_t >          etaLayer1Hits;
      std::vector< uint8_t >          etaLayer2Hits;
      std::vector< uint8_t >          etaLayer3Hits;
      std::vector< uint8_t >          etaLayer4Hits;
      
      std::vector< uint8_t >          phiLayer1Holes;
      std::vector< uint8_t >          phiLayer2Holes;
      std::vector< uint8_t >          phiLayer3Holes;
      std::vector< uint8_t >          phiLayer4Holes;
      
      std::vector< uint8_t >          etaLayer1Holes;
      std::vector< uint8_t >          etaLayer2Holes;
      std::vector< uint8_t >          etaLayer3Holes;
      std::vector< uint8_t >          etaLayer4Holes;
      /// @}   
      
      /// @name Isolation values
      /// @{
      std::vector< float >            etcone20;
      std::vector< float >            etcone30;
      std::vector< float >            etcone40;
      std::vector< float >            ptcone20;
      std::vector< float >            ptcone30;
      std::vector< float >            ptcone40;
      /// @}
      
      /// @name Links 
      /// @{    
      std::vector<ElementLink< TrackParticleContainer > >                 inDetTrackParticleLink;
      std::vector<ElementLink< TrackParticleContainer > >                 muonSpectrometerTrackParticleLink;
      std::vector<ElementLink< TrackParticleContainer > >                 combinedTrackParticleLink;
      std::vector<ElementLink< CaloClusterContainer   > >                 clusterLink;
      std::vector<std::vector<ElementLink< MuonSegmentContainer   > > >   muonSegmentLinks;
      /// @}
      
      /// @name Energy loss 
      /// @{
      std::vector< uint8_t>            energyLossType;
      /// @}
 
   }; // class MuonAuxContainer_v1
 
} // namespace xAOD
 
#include "xAODCore/BaseInfo.h"
SG_BASE( xAOD::MuonAuxContainer_v1, xAOD::AuxContainerBase ); 
 
#endif // XAODJET_VERSIONS_JETAUXCONTAINER_V1_H