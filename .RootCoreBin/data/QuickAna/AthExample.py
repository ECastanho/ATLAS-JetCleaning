import AthenaPoolCnvSvc.ReadAthenaPool

theApp.EvtMax = 5
testFile = os.getenv("ASG_TEST_FILE_MC")
svcMgr.EventSelector.InputCollections = [testFile]

algSeq = CfgMgr.AthSequencer("AthAlgSeq")

quickAna = CfgMgr.ana__QuickAna()
quickAna.electronDef = "default"
quickAna.muonDef = "default"
quickAna.tauDef = "default"
quickAna.photonDef = "default"
quickAna.jetDef = "default"
quickAna.metDef = "default"
quickAna.orDef = "default"
ToolSvc += quickAna

alg = CfgMgr.ana__AthExample()
alg.quickAna = quickAna
algSeq += alg

# Some log suppression
include("AthAnalysisBaseComps/SuppressLogging.py")
