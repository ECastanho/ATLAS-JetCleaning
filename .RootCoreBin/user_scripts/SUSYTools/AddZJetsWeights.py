#!/usr/bin/env python

import os,sys,subprocess,datetime,copy,math,array,shutil,ROOT,re,string
from ROOT import gROOT
from subprocess import call
from array import array

__author__ = "John Anders"
__doc__    = """Script to add Sherpa Systematic Weight branches to existing file."""   
def generateZpTMapping(dictionary):
    
    # 0-70, bin 1, 70-140 bin 2 etc.
    print "Adding Z--> nunu to the dictionary"
    print "Range 0-70"
    for i in range(361444, 361447):
        dictionary[i] = 1
        print i
        
    print "Range 70-140"
    for i in range(361447, 361450):
        dictionary[i] = 2
        print i
    
    print "Range 140-280"
    for i in range(361450, 361453):
        dictionary[i] = 3
        print i
    

    print "Range 280-500"
    for i in range(361453, 361456):
        dictionary[i] = 4
        print i
    
    print "Range 500-700"
    for i in range(361456, 361459):
        dictionary[i] = 5
        print i
    
    print "Range 700-1000"
    for i in range(361459, 361462):
        dictionary[i] = 6
        print i
    
    print "Range 1000-2000"
    for i in range(361462, 361465):
        dictionary[i] = 7
        print i
    
    print "Range 2000-ECMS"
    for i in range(361465, 361468):
        dictionary[i] = 8
        print i
    


    print "Adding Z--> ee to the dictionary"
    print "Range 0-70"
    for i in range(361372, 361375):
        dictionary[i] = 1
        print i
        
    print "Range 70-140"
    for i in range(361375, 361378):
        dictionary[i] = 2
        print i
    
    print "Range 140-280"
    for i in range(361378, 361381):
        dictionary[i] = 3
        print i
    

    print "Range 280-500"
    for i in range(361381, 361384):
        dictionary[i] = 4
        print i
    
    print "Range 500-700"
    for i in range(361384, 361387):
        dictionary[i] = 5
        print i
    
    print "Range 700-1000"
    for i in range(361387, 361390):
        dictionary[i] = 6
        print i
    
    print "Range 1000-2000"
    for i in range(361390, 361393):
        dictionary[i] = 7
        print i
    
    print "Range 2000-ECMS"
    for i in range(361393, 361396):
        dictionary[i] = 8
        print i
    


    print "Adding Z--> mumu to the dictionary"
    print "Range 0-70"
    for i in range(361396, 361399):
        dictionary[i] = 1
        print i
        
    print "Range 70-140"
    for i in range(361399, 361402):
        dictionary[i] = 2
        print i
    
    print "Range 140-280"
    for i in range(361402, 361405):
        dictionary[i] = 3
        print i
    

    print "Range 280-500"
    for i in range(361405, 361408):
        dictionary[i] = 4
        print i
    
    print "Range 500-700"
    for i in range(361408, 361411):
        dictionary[i] = 5
        print i
    
    print "Range 700-1000"
    for i in range(361411, 361414):
        dictionary[i] = 6
        print i
    
    print "Range 1000-2000"
    for i in range(361414, 361417):
        dictionary[i] = 7
        print i
    
    print "Range 2000-ECMS"
    for i in range(361417, 361420):
        dictionary[i] = 8
        print i
    

    print "Adding Z--> tautau to the dictionary"
    print "Range 0-70"
    for i in range(361420, 361423):
        dictionary[i] = 1
        print i
        
    print "Range 70-140"
    for i in range(361423, 361426):
        dictionary[i] = 2
        print i
    
    print "Range 140-280"
    for i in range(361426, 361429):
        dictionary[i] = 3
        print i
    

    print "Range 280-500"
    for i in range(361429, 361432):
        dictionary[i] = 4
        print i
    
    print "Range 500-700"
    for i in range(361432, 361435):
        dictionary[i] = 5
        print i
    
    print "Range 700-1000"
    for i in range(361435, 361438):
        dictionary[i] = 6
        print i
    
    print "Range 1000-2000"
    for i in range(361438, 361441):
        dictionary[i] = 7
        print i
    
    print "Range 2000-ECMS"
    for i in range(361441, 361444):
        dictionary[i] = 8
        print i
    

    print "Adding W+Jets MCIDs"
    print "Adding W--> enu to the dictionary"
    print "Range 0-70"
    for i in range(361300, 361303):
        dictionary[i] = 1
        print i
        
    print "Range 70-140"
    for i in range(361303, 361306):
        dictionary[i] = 2
        print i
    
    print "Range 140-280"
    for i in range(361306, 361309):
        dictionary[i] = 3
        print i
    

    print "Range 280-500"
    for i in range(361309, 361312):
        dictionary[i] = 4
        print i
    
    print "Range 500-700"
    for i in range(361312, 361315):
        dictionary[i] = 5
        print i
    
    print "Range 700-1000"
    for i in range(361315, 361318):
        dictionary[i] = 6
        print i
    
    print "Range 1000-2000"
    for i in range(361318, 361321):
        dictionary[i] = 7
        print i
    
    print "Range 2000-ECMS"
    for i in range(361321, 361324):
        dictionary[i] = 8
        print i
    

    print "Adding W--> munu to the dictionary"
    print "Range 0-70"
    for i in range(361324, 361327):
        dictionary[i] = 1
        print i
        
    print "Range 70-140"
    for i in range(361327, 361330):
        dictionary[i] = 2
        print i
    
    print "Range 140-280"
    for i in range(361330, 361333):
        dictionary[i] = 3
        print i
    

    print "Range 280-500"
    for i in range(361333, 361336):
        dictionary[i] = 4
        print i
    
    print "Range 500-700"
    for i in range(361336, 361339):
        dictionary[i] = 5
        print i
    
    print "Range 700-1000"
    for i in range(361339, 361342):
        dictionary[i] = 6
        print i
    
    print "Range 1000-2000"
    for i in range(361342, 361345):
        dictionary[i] = 7
        print i
    
    print "Range 2000-ECMS"
    for i in range(361345, 361348):
        dictionary[i] = 8
        print i
    

    print "Adding W--> taunu to the dictionary"
    print "Range 0-70"
    for i in range(361348, 361351):
        dictionary[i] = 1
        print i
        
    print "Range 70-140"
    for i in range(361351, 361354):
        dictionary[i] = 2
        print i
    
    print "Range 140-280"
    for i in range(361354, 361357):
        dictionary[i] = 3
        print i
    

    print "Range 280-500"
    for i in range(361357, 361360):
        dictionary[i] = 4
        print i
    
    print "Range 500-700"
    for i in range(361360, 361363):
        dictionary[i] = 5
        print i
    
    print "Range 700-1000"
    for i in range(361363, 361366):
        dictionary[i] = 6
        print i
    
    print "Range 1000-2000"
    for i in range(361366, 361369):
        dictionary[i] = 7
        print i
    
    print "Range 2000-ECMS"
    for i in range(361369, 361372):
        dictionary[i] = 8
        print i

    return dictionary
    

def main(argv):

    # infile should be the ZJets file to add the weights to. 
    script, infile = argv

    print "Creating MCID, ZpT mapping"
    ZpTMapping = dict()
    generateZpTMapping(ZpTMapping)

    print "Loading histograms with weights"
    Histograms = []
    
    # Change here to the location of the variation file: 
    fileWithWeights = "rootFiles/AllVariations.root"

    g = ROOT.TFile(fileWithWeights)
    systList = ["ckkw15", "ckkw30", "fac025", "fac4", "renorm025", "renorm4", "qsf025", "qsf4"]
    
    for syst in systList:
        h = ROOT.TH2F(g.Get(syst))
        Histograms.append(h)

    print "Loading File"
    f = ROOT.TFile(infile,"update")
    
    # Change here to the name of your nominal tree:
    treeName = "CollectionTree_"

    print "Loading Tree"

    # empty arrays for adding branches
    ckkw15 = array('f', [0.])
    ckkw30 = array('f', [0.])
    fac025 = array('f', [0.])
    fac4 = array('f', [0.])
    renorm025 = array('f', [0.])
    renorm4 = array('f', [0.])
    qsf025 = array('f', [0.])
    qsf4 = array('f', [0.])
    
    # Add branches
    T = f.Get(treeName)
    ckkw15branch = T.Branch("ckkw15_Weight", ckkw15,"ckkw15_Weight/F")
    ckkw30branch = T.Branch("ckkw30_Weight", ckkw30,"ckkw30_Weight/F")
    fac025branch = T.Branch("fac025_Weight", fac025,"fac025_Weight/F")
    fac4branch = T.Branch("fac4_Weight", fac4,"fac4_Weight/F")
    renorm025branch = T.Branch("renorm025_Weight", renorm025,"renorm025_Weight/F")
    renorm4branch = T.Branch("renorm4_Weight", renorm4,"renorm4_Weight/F")
    qsf025branch = T.Branch("qsf025_Weight", qsf025,"qsf025_Weight/F")
    qsf4branch = T.Branch("qsf4_Weight", qsf4,"qsf4_Weight/F")
        
    print "Adding Weights"
    nEvts = T.GetEntries()
    for iEvt in range(nEvts):
        
        if iEvt%1000 == 0:
            print "Current Event being Processed is: ", iEvt
            
        T.GetEntry(iEvt)
            
            # change this to whatever the MCID and nTruthJet variables are saved as in your tree 
        MCID = T.mcID
        nTruthJets = T.nJets
        
            # find which ZpT bin we want
        ZpTBin = ZpTMapping.get(MCID)
        TruthJetBin = nTruthJets+1
        if nTruthJets >= 11:
            TruthJetBin = 12
        if ZpTBin == None:
                #this MCID isn't in the mapping, so skip and default to 1
            ckkw15[0] = 1 
            ckkw30[0] = 1
            fac025[0] = 1
            fac4[0] = 1
            renorm025[0] = 1
            renorm4[0] = 1
            qsf025[0] = 1
            qsf4[0] = 1

        else:
            ckkw15[0] = Histograms[0].GetBinContent(ZpTBin,TruthJetBin) 
            ckkw30[0] =  Histograms[1].GetBinContent(ZpTBin,TruthJetBin)
            fac025[0] =  Histograms[2].GetBinContent(ZpTBin,TruthJetBin)
            fac4[0] =  Histograms[3].GetBinContent(ZpTBin,TruthJetBin)
            renorm025[0] =  Histograms[4].GetBinContent(ZpTBin,TruthJetBin)
            renorm4[0] =  Histograms[5].GetBinContent(ZpTBin,TruthJetBin)
            qsf025[0] =  Histograms[6].GetBinContent(ZpTBin,TruthJetBin)
            qsf4[0] =  Histograms[7].GetBinContent(ZpTBin,TruthJetBin)
        
        ckkw15branch.Fill()
        ckkw30branch.Fill()
        fac025branch.Fill()
        fac4branch.Fill()
        renorm025branch.Fill()
        renorm4branch.Fill()
        qsf025branch.Fill()
        qsf4branch.Fill()
        
        
        
    T.Write()

    print "Done."
    
if __name__ == '__main__':
    main(sys.argv)




