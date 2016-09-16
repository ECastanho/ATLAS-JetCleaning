##===============================================================================
## Name:        TrigEgammaElectronIsEMCutDefs_medium1.py
##
## Author:      Ryan Mackenzie White
## Created:     June 2013
##
## Description: Photon cut definitions for 2012. 
##              Use Electron selector with calo only cuts 
##===============================================================================

import cppyy
try :
    cppyy.loadDictionary('ElectronPhotonSelectorToolsDict')
except :
    pass

from ROOT import egammaPID

# Import a needed helper
from PATCore.HelperUtils import *

# Define GeV
GeV = 1000.0


def TrigPhotonIsEMLooseCaloCutsOnlySelectorConfig2012(theTool) :
    '''
    This is for the Loose isEM definitions for the Trigger.
    '''
    
    theTool = GetTool(theTool)
            
    # range of eta bins for e-ID
    theTool.CutBinEta = [0.1, 0.6, 0.8, 1.15, 1.37, 1.52, 1.81, 2.01, 2.37, 2.47]

    # range of ET bins for e-ID
    theTool.CutBinET = [5.0*GeV, 10.0*GeV, 15.0*GeV, 20.0*GeV, 30.0*GeV, 40.0*GeV, 50.0*GeV, 60.0*GeV, 70.0*GeV, 80.0*GeV]

    # cut on fraction of energy deposited in 1st sampling
    theTool.CutF1 = [0.005]

    # cut on hadronic energy
    theTool.CutHadLeakage  = [0.12800, 0.15600, 0.15200, 0.11600, 0.15600, 0.04275, 0.13200, 0.15200, 0.15600, 0.14000,# < 5
            0.12800, 0.15600, 0.15200, 0.11600, 0.15600, 0.04275, 0.13200, 0.15200, 0.15600, 0.14000, # 5-10
            0.03225, 0.03225, 0.03075, 0.03575, 0.02575, 0.04275, 0.04325, 0.04525, 0.04325, 0.03675,  # 10-15
            0.02925, 0.02925, 0.02775, 0.03175, 0.02375, 0.03875, 0.04025, 0.03425, 0.03825, 0.02975,  # 15-20
            0.02425, 0.02425, 0.02275, 0.02575, 0.01975, 0.01975, 0.02725, 0.02725, 0.02725, 0.01975,  # 20-30
            0.02275, 0.02275, 0.02125, 0.01975, 0.01825, 0.01825, 0.02425, 0.02575, 0.02425, 0.01675,  # 30-40
            0.01825, 0.01825, 0.01975, 0.01525, 0.01675, 0.01675, 0.02125, 0.02275, 0.01975, 0.01675,  # 40-50
            0.01825, 0.01825, 0.01975, 0.01525, 0.01675, 0.01675, 0.02125, 0.02275, 0.01975, 0.01675,  # 50-60
            0.01825, 0.01825, 0.01975, 0.01525, 0.01675, 0.01675, 0.02125, 0.02275, 0.01975, 0.01675,  # 60-70
            0.01825, 0.01825, 0.01975, 0.01525, 0.01675, 0.01675, 0.02125, 0.02275, 0.01975, 0.01675,  # 70-80
            0.01825, 0.01825, 0.01975, 0.01525, 0.01675, 0.01675, 0.02125, 0.02275, 0.01975, 0.01675 # >80
            ]  
     
                 
    # cut on ratio e237/e277
    theTool.CutReta37 = [0.6800, 0.5600, 0.6000, 0.6800, 0.7200, 0.440, 0.7600, 0.7200, 0.7600, 0.7475,  # < 5
            0.6800, 0.5600, 0.6000, 0.6800, 0.7200, 0.440, 0.7600, 0.7200, 0.7600, 0.7475,  # 5-10
            0.8475, 0.8475, 0.8425, 0.8175, 0.8475, 0.740, 0.8275, 0.8675, 0.8675, 0.7475, # 10-15
            0.8675, 0.8675, 0.8675, 0.8475, 0.8725, 0.740, 0.8525, 0.8775, 0.8775, 0.7575, # 15-20
            0.8825, 0.8825, 0.8825, 0.8575, 0.8875, 0.750, 0.8725, 0.9025, 0.8875, 0.7575, # 20-30
            0.9075, 0.9075, 0.8975, 0.8875, 0.8875, 0.790, 0.8925, 0.9075, 0.8975, 0.8075, # 30-40
            0.9175, 0.9175, 0.9125, 0.9075, 0.9025, 0.790, 0.8975, 0.9125, 0.9025, 0.8625, # 40-50
            0.9175, 0.9175, 0.9125, 0.9075, 0.9025, 0.790, 0.8975, 0.9125, 0.9025, 0.8625, # 50-60
            0.9175, 0.9175, 0.9125, 0.9075, 0.9025, 0.790, 0.8975, 0.9125, 0.9025, 0.8625, # 60-70
            0.9175, 0.9175, 0.9125, 0.9075, 0.9025, 0.790, 0.8975, 0.9125, 0.9025, 0.8625, # 70-80
            0.9175, 0.9175, 0.9125, 0.9075, 0.9025, 0.790, 0.8975, 0.9125, 0.9025, 0.8625 # >80          
            ]
                          

    # cut on shower width in 2nd sampling
    theTool.CutWeta2c = [0.017, 0.016, 0.018, 0.016, 0.019, 0.031, 0.017, 0.016, 0.015, 0.0145,    # < 5
            0.017, 0.016, 0.018, 0.016, 0.019, 0.031, 0.017, 0.016, 0.015, 0.0145,  # 5-10
            0.014 ,0.014 ,0.015 ,0.016 ,0.017 ,0.025 ,0.017 ,0.015 ,0.015 ,0.0145,  #10-15
            0.0135 ,0.0135 ,0.0145 ,0.016 ,0.017 ,0.025 ,0.017 ,0.015 ,0.015 ,0.0145,  #15-20
            0.013 ,0.013 ,0.014 ,0.015 ,0.015 ,0.025 ,0.016 ,0.015 ,0.015 ,0.014 ,  #20-30
            0.012 ,0.012 ,0.013 ,0.013 ,0.013 ,0.025 ,0.015 ,0.014 ,0.014 ,0.013 ,  #30-40
            0.011 ,0.011 ,0.012 ,0.013 ,0.013 ,0.025 ,0.015 ,0.014 ,0.014 ,0.013 ,  #40-50
            0.011 ,0.011 ,0.012 ,0.013 ,0.013 ,0.025 ,0.015 ,0.014 ,0.014 ,0.013, # 50-60
            0.011 ,0.011 ,0.012 ,0.013 ,0.013 ,0.025 ,0.015 ,0.014 ,0.014 ,0.013, # 60-70
            0.011 ,0.011 ,0.012 ,0.013 ,0.013 ,0.025 ,0.015 ,0.014 ,0.014 ,0.013, # 70-80
            0.011 ,0.011 ,0.012 ,0.013 ,0.013 ,0.025 ,0.015 ,0.014 ,0.014 ,0.013 # 80<  
            ]           

    
    # cut on total width in 1st sampling
    theTool.CutWtot  = [3.48, 3.48, 3.78, 3.96, 4.20, 9999., 4.02, 2.70, 1.86,  9999., # < 5    GeV
            3.18, 3.18, 3.54, 3.90, 4.02, 9999., 3.96, 2.70, 1.80,  9999., # 5-10
            2.81, 2.81, 2.97, 3.36, 3.48, 9999., 3.72, 2.42, 1.76,  9999., # 10-15
            2.76, 2.76, 2.92, 3.24, 3.41, 9999., 3.67, 2.35, 1.72,  9999., # 15-20
            2.50, 2.50, 2.70, 3.14, 3.23, 9999., 3.58, 2.32, 1.59,  9999., # 20-30
            2.45, 2.45, 2.70, 2.98, 3.17, 9999., 3.52, 2.25, 1.58,  9999., # 30-40
            2.27, 2.27, 2.61, 2.90, 3.17, 9999., 3.36, 2.25, 1.55,  9999., # 40-50
            2.27, 2.27, 2.61, 2.90, 3.17, 9999., 3.36, 2.25, 1.55,  9999., # 50-60
            2.27, 2.27, 2.61, 2.90, 3.17, 9999., 3.36, 2.25, 1.55,  9999., # 60-70
            2.27, 2.27, 2.61, 2.90, 3.17, 9999., 3.36, 2.25, 1.55,  9999., # 70-80
            2.27, 2.27, 2.61, 2.90, 3.17, 9999., 3.36, 2.25, 1.55,  9999.  # 80<
            ]
            
    # cut on (Emax - Emax2)/(Emax + Emax2) in 1st sampling 
    theTool.CutDEmaxs1 = [0.39,  0.39,  0.20,  0.07, 0.06,  -9999.,  0.07,  0.43,   0.75,  -9999.,  # < 5  GeV
            0.61,  0.61,  0.32,  0.11, 0.13,  -9999.,  0.12,  0.51,   0.62,  -9999.,  # 5-10
            0.67,  0.67,  0.61,  0.43, 0.32,  -9999.,  0.36,  0.82 ,  0.82,  -9999.,  # 10-15
            0.75,  0.75,  0.67,  0.51, 0.47,  -9999.,  0.43,  0.86 ,  0.84,  -9999.,  # 15-20
            0.835,  0.835,  0.835,  0.73, 0.70,  -9999.,  0.8,  0.9 ,  0.9,  -9999.,  # 20-30
            0.835,  0.835,  0.835,  0.73, 0.70,  -9999.,  0.8,  0.9 ,  0.9,  -9999.,  # 30-40
            0.835,  0.835,  0.835,  0.73, 0.70,  -9999.,  0.8,  0.9 ,  0.9,  -9999.,  # 40-50
            0.835,  0.835,  0.835,  0.73, 0.70,  -9999.,  0.8,  0.9 ,  0.9,  -9999.,  # 50-60
            0.835,  0.835,  0.835,  0.73, 0.70,  -9999.,  0.8,  0.9 ,  0.9,  -9999.,  # 60-70
            0.835,  0.835,  0.835,  0.73, 0.70,  -9999.,  0.8,  0.9 ,  0.9,  -9999.,  # 70-80
            0.835,  0.835,  0.835,  0.73, 0.70,  -9999.,  0.8,  0.9 ,  0.9,  -9999.   # 80< 
            ]
 
    # cut on Delta Emax2 in 1st sampling 
    theTool.CutDeltaEmax2  = []
        
    # cut on Emax2 - Emin in 1st sampling 
    theTool.CutDeltaE  = []
        
    # cut on width in 1st sampling
    theTool.CutWeta1c  = []
        
    # cut on Fside in 1st sampling
    theTool.CutFracm = []
        
    # cut on Energy in cone of 0.20
    # not available
    # theTool.CutClusterIsolation = []
        
    # cut on Track quality cut
        
    # cut on pixel-layer hits
    theTool.CutPi  = []
        
    # cut on precision hits
    theTool.CutSi  = []
        
    # cut on transverse impact parameter
    theTool.CutA0  = []
        
    # cut on transverse impact parameter for tight selection   	 	 
    theTool.CutA0Tight  = []
        
    # cut on delta eta
    theTool.CutDeltaEta = []
        
    # cut on delta eta for tight selection
    theTool.CutDeltaEtaTight = []
        
    theTool.useTRTOutliers  = True
    #use outliers for BL, Pix and SCT tracks
    theTool.useBLOutliers   = True
    theTool.usePIXOutliers  = True
    theTool.useSCTOutliers  = True
        

    # cut on b-layer hits
    theTool.CutBL  = []

    # cut on min delta phi
    theTool.CutminDeltaPhi  = []

    # cut on max delta phi
    theTool.CutmaxDeltaPhi  = []

    # cut min on E/P
    theTool.CutminEp  = []
        
    # cut max on E/P
    theTool.CutmaxEp  = []
        
    # cuts on TRT
    # range of eta bins for e-ID for TRT
    theTool.CutBinEta_TRT = []
    # cuts on Number of TRT hits with Outliers
    theTool.CutNumTRT  = []
    # cuts on TRT ratio with Outliers
    theTool.CutTRTRatio  = []
    # cuts on TRT ratio with Outliers for 90% efficiency
    theTool.CutTRTRatio90  = []
     
def TrigPhotonIsEMMediumCaloCutsOnlySelectorConfig2012(theTool) :
    '''
    This is for the Medium++ isEM definitions for the Trigger.
    '''
    
    theTool = GetTool(theTool)
            
    # range of eta bins for e-ID
    theTool.CutBinEta = [0.1, 0.6, 0.8, 1.15, 1.37, 1.52, 1.81, 2.01, 2.37, 2.47]

    # range of ET bins for e-ID
    theTool.CutBinET = [5.0*GeV, 10.0*GeV, 15.0*GeV, 20.0*GeV, 30.0*GeV, 40.0*GeV, 50.0*GeV, 60.0*GeV, 70.0*GeV, 80.0*GeV]

    # cut on fraction of energy deposited in 1st sampling
    theTool.CutF1 = [0.005]

    # cut on hadronic energy
    theTool.CutHadLeakage  = [0.12800, 0.15600, 0.15200, 0.11600, 0.15600, 0.04275, 0.13200, 0.15200, 0.15600, 0.14000,# < 5
            0.12800, 0.15600, 0.15200, 0.11600, 0.15600, 0.04275, 0.13200, 0.15200, 0.15600, 0.14000, # 5-10
            0.03225, 0.03225, 0.03075, 0.03575, 0.02575, 0.04275, 0.04325, 0.04525, 0.04325, 0.03675,  # 10-15
            0.02925, 0.02925, 0.02775, 0.03175, 0.02375, 0.03875, 0.04025, 0.03425, 0.03825, 0.02975,  # 15-20
            0.02425, 0.02425, 0.02275, 0.02575, 0.01975, 0.01975, 0.02725, 0.02725, 0.02725, 0.01975,  # 20-30
            0.02275, 0.02275, 0.02125, 0.01975, 0.01825, 0.01825, 0.02425, 0.02575, 0.02425, 0.01675,  # 30-40
            0.01825, 0.01825, 0.01975, 0.01525, 0.01675, 0.01675, 0.02125, 0.02275, 0.01975, 0.01675,  # 40-50
            0.01825, 0.01825, 0.01975, 0.01525, 0.01675, 0.01675, 0.02125, 0.02275, 0.01975, 0.01675,  # 50-60
            0.01825, 0.01825, 0.01975, 0.01525, 0.01675, 0.01675, 0.02125, 0.02275, 0.01975, 0.01675,  # 60-70
            0.01825, 0.01825, 0.01975, 0.01525, 0.01675, 0.01675, 0.02125, 0.02275, 0.01975, 0.01675,  # 70-80
            0.01825, 0.01825, 0.01975, 0.01525, 0.01675, 0.01675, 0.02125, 0.02275, 0.01975, 0.01675 # >80
            ]  
     
                 
    # cut on ratio e237/e277
    theTool.CutReta37 = [0.6800, 0.5600, 0.6000, 0.6800, 0.7200, 0.440, 0.7600, 0.7200, 0.7600, 0.7475,  # < 5
            0.6800, 0.5600, 0.6000, 0.6800, 0.7200, 0.440, 0.7600, 0.7200, 0.7600, 0.7475,  # 5-10
            0.8475, 0.8475, 0.8425, 0.8175, 0.8475, 0.740, 0.8275, 0.8675, 0.8675, 0.7475, # 10-15
            0.8675, 0.8675, 0.8675, 0.8475, 0.8725, 0.740, 0.8525, 0.8775, 0.8775, 0.7575, # 15-20
            0.8825, 0.8825, 0.8825, 0.8575, 0.8875, 0.750, 0.8725, 0.9025, 0.8875, 0.7575, # 20-30
            0.9075, 0.9075, 0.8975, 0.8875, 0.8875, 0.790, 0.8925, 0.9075, 0.8975, 0.8075, # 30-40
            0.9175, 0.9175, 0.9125, 0.9075, 0.9025, 0.790, 0.8975, 0.9125, 0.9025, 0.8625, # 40-50
            0.9175, 0.9175, 0.9125, 0.9075, 0.9025, 0.790, 0.8975, 0.9125, 0.9025, 0.8625, # 50-60
            0.9175, 0.9175, 0.9125, 0.9075, 0.9025, 0.790, 0.8975, 0.9125, 0.9025, 0.8625, # 60-70
            0.9175, 0.9175, 0.9125, 0.9075, 0.9025, 0.790, 0.8975, 0.9125, 0.9025, 0.8625, # 70-80
            0.9175, 0.9175, 0.9125, 0.9075, 0.9025, 0.790, 0.8975, 0.9125, 0.9025, 0.8625 # >80          
            ]


    # cut on Weta2 in 2st sampling for 2g20_medium
    theTool.CutWeta2c = [0.014,  0.014,  0.015,  0.016, 0.017, 0.025, 0.017, 0.015, 0.015, 0.0145,   # < 5
            0.014,  0.014,  0.015,  0.016, 0.017, 0.025, 0.017, 0.015, 0.015, 0.0145,   # 5-10
            0.014,  0.014,  0.015,  0.016, 0.017, 0.025, 0.017, 0.015, 0.015, 0.0145,  # 10-15
            0.0135, 0.0135, 0.0145, 0.016, 0.017, 0.025, 0.017, 0.015, 0.015, 0.0145,  # 15-20
            0.011,  0.011,  0.012,  0.012, 0.0125, 0.025, 0.013, 0.012, 0.0128, 0.0128,   # 20-30
            0.011,  0.011,  0.012,  0.012, 0.0125, 0.025, 0.013, 0.012, 0.0128, 0.0128,   # 30-40
            0.011,  0.011,  0.012,  0.012, 0.0125, 0.025, 0.013, 0.012, 0.0128, 0.0128,   # 40-50
            0.011,  0.011,  0.012,  0.012, 0.0125, 0.025, 0.013, 0.012, 0.0128, 0.0128,   # 50-60
            0.011,  0.011,  0.012,  0.012, 0.0125, 0.025, 0.013, 0.012, 0.0128, 0.0128,   # 60-70
            0.011,  0.011,  0.012,  0.012, 0.0125, 0.025, 0.013, 0.012, 0.0128, 0.0128,   # 70-80
            0.011,  0.011,  0.012,  0.012, 0.0125, 0.025, 0.013, 0.012, 0.0128, 0.0128    # 80<
            ]
    
    # cut on total width in 1st sampling
    theTool.CutWtot  = [3.48, 3.48, 3.78, 3.96, 4.20, 9999., 4.02, 2.70, 1.86,  9999., # < 5    GeV
            3.18, 3.18, 3.54, 3.90, 4.02, 9999., 3.96, 2.70, 1.80,  9999., # 5-10
            2.81, 2.81, 2.97, 3.36, 3.48, 9999., 3.72, 2.42, 1.76,  9999., # 10-15
            2.76, 2.76, 2.92, 3.24, 3.41, 9999., 3.67, 2.35, 1.72,  9999., # 15-20
            2.50, 2.50, 2.70, 3.14, 3.23, 9999., 3.58, 2.32, 1.59,  9999., # 20-30
            2.45, 2.45, 2.70, 2.98, 3.17, 9999., 3.52, 2.25, 1.58,  9999., # 30-40
            2.27, 2.27, 2.61, 2.90, 3.17, 9999., 3.36, 2.25, 1.55,  9999., # 40-50
            2.27, 2.27, 2.61, 2.90, 3.17, 9999., 3.36, 2.25, 1.55,  9999., # 50-60
            2.27, 2.27, 2.61, 2.90, 3.17, 9999., 3.36, 2.25, 1.55,  9999., # 60-70
            2.27, 2.27, 2.61, 2.90, 3.17, 9999., 3.36, 2.25, 1.55,  9999., # 70-80
            2.27, 2.27, 2.61, 2.90, 3.17, 9999., 3.36, 2.25, 1.55,  9999.  # 80<
            ]

    # cut on (Emax - Emax2)/(Emax + Emax2) in 1st sampling for 2g20_medium
    theTool.CutDEmaxs1 = [0.39,  0.39,  0.20,  0.07, 0.06,  -9999.,  0.07,  0.43,   0.75,  -9999.,  # < 5  GeV
            0.60,  0.60,  0.32,  0.11, 0.13,  -9999.,  0.12,  0.51,   0.75,  -9999.,  # 5-10
            0.60,  0.60,  0.61,  0.43, 0.32,  -9999.,  0.36,  0.51 ,  0.75,  -9999.,  # 10-15
            0.60,  0.60,  0.61,  0.51, 0.47,  -9999.,  0.43,  0.51 ,  0.75,  -9999.,  # 15-20
            0.60,  0.60,  0.76,  0.70, 0.67,  0.68  ,  0.65,  0.68 ,  0.75,  0.78  ,  # 20-30
            0.60,  0.60,  0.76,  0.70, 0.67,  0.68  ,  0.65,  0.68 ,  0.75,  0.78  ,  # 30-40
            0.60,  0.60,  0.76,  0.70, 0.67,  0.68  ,  0.65,  0.68 ,  0.75,  0.78  ,  # 40-50
            0.60,  0.60,  0.76,  0.70, 0.67,  0.68  ,  0.65,  0.68 ,  0.75,  0.78  ,  # 50-60
            0.60,  0.60,  0.76,  0.70, 0.67,  0.68  ,  0.65,  0.68 ,  0.75,  0.78  ,  # 60-70
            0.60,  0.60,  0.76,  0.70, 0.67,  0.68  ,  0.65,  0.68 ,  0.75,  0.78  ,  # 70-80
            0.60,  0.60,  0.76,  0.70, 0.67,  0.68  ,  0.65,  0.68 ,  0.75,  0.78     # 80< 
            ]
    # cut on Delta Emax2 in 1st sampling 
    theTool.CutDeltaEmax2  = []
        
    # cut on Emax2 - Emin in 1st sampling 
    theTool.CutDeltaE  = []
        
    # cut on width in 1st sampling
    theTool.CutWeta1c  = []
        
    # cut on Fside in 1st sampling
    theTool.CutFracm = []
        
    # cut on Energy in cone of 0.20
    # not available
    # theTool.CutClusterIsolation = []
        
    # cut on Track quality cut
        
    # cut on pixel-layer hits
    theTool.CutPi  = []
        
    # cut on precision hits
    theTool.CutSi  = []
        
    # cut on transverse impact parameter
    theTool.CutA0  = []
        
    # cut on transverse impact parameter for tight selection   	 	 
    theTool.CutA0Tight  = []
        
    # cut on delta eta
    theTool.CutDeltaEta = []
        
    # cut on delta eta for tight selection
    theTool.CutDeltaEtaTight = []
        
    theTool.useTRTOutliers  = True
    #use outliers for BL, Pix and SCT tracks
    theTool.useBLOutliers   = True
    theTool.usePIXOutliers  = True
    theTool.useSCTOutliers  = True
        

    # cut on b-layer hits
    theTool.CutBL  = []

    # cut on min delta phi
    theTool.CutminDeltaPhi  = []

    # cut on max delta phi
    theTool.CutmaxDeltaPhi  = []

    # cut min on E/P
    theTool.CutminEp  = []
        
    # cut max on E/P
    theTool.CutmaxEp  = []
        
    # cuts on TRT
    # range of eta bins for e-ID for TRT
    theTool.CutBinEta_TRT = []
    # cuts on Number of TRT hits with Outliers
    theTool.CutNumTRT  = []
    # cuts on TRT ratio with Outliers
    theTool.CutTRTRatio  = []
    # cuts on TRT ratio with Outliers for 90% efficiency
    theTool.CutTRTRatio90  = []

