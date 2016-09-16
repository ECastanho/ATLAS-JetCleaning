#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wunused-private-field"
#endif
// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIxdIcalodIjgoncalvesdIJetCleaningHIdIRootCoreBindIobjdIx86_64mIslc6mIgcc49mIoptdIJetCleaningAnalysisHIdIobjdIJetCleaningAnalysisHICINT

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "JetCleaningAnalysisHI/HIHI_TMVA.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_HIHI_TMVA(void *p = 0);
   static void *newArray_HIHI_TMVA(Long_t size, void *p);
   static void delete_HIHI_TMVA(void *p);
   static void deleteArray_HIHI_TMVA(void *p);
   static void destruct_HIHI_TMVA(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HIHI_TMVA*)
   {
      ::HIHI_TMVA *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::HIHI_TMVA >(0);
      static ::ROOT::TGenericClassInfo 
         instance("HIHI_TMVA", ::HIHI_TMVA::Class_Version(), "JetCleaningAnalysisHI/HIHI_TMVA.h", 19,
                  typeid(::HIHI_TMVA), DefineBehavior(ptr, ptr),
                  &::HIHI_TMVA::Dictionary, isa_proxy, 4,
                  sizeof(::HIHI_TMVA) );
      instance.SetNew(&new_HIHI_TMVA);
      instance.SetNewArray(&newArray_HIHI_TMVA);
      instance.SetDelete(&delete_HIHI_TMVA);
      instance.SetDeleteArray(&deleteArray_HIHI_TMVA);
      instance.SetDestructor(&destruct_HIHI_TMVA);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HIHI_TMVA*)
   {
      return GenerateInitInstanceLocal((::HIHI_TMVA*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::HIHI_TMVA*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr HIHI_TMVA::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *HIHI_TMVA::Class_Name()
{
   return "HIHI_TMVA";
}

//______________________________________________________________________________
const char *HIHI_TMVA::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HIHI_TMVA*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int HIHI_TMVA::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HIHI_TMVA*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *HIHI_TMVA::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HIHI_TMVA*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *HIHI_TMVA::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HIHI_TMVA*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void HIHI_TMVA::Streamer(TBuffer &R__b)
{
   // Stream an object of class HIHI_TMVA.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(HIHI_TMVA::Class(),this);
   } else {
      R__b.WriteClassBuffer(HIHI_TMVA::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_HIHI_TMVA(void *p) {
      return  p ? new(p) ::HIHI_TMVA : new ::HIHI_TMVA;
   }
   static void *newArray_HIHI_TMVA(Long_t nElements, void *p) {
      return p ? new(p) ::HIHI_TMVA[nElements] : new ::HIHI_TMVA[nElements];
   }
   // Wrapper around operator delete
   static void delete_HIHI_TMVA(void *p) {
      delete ((::HIHI_TMVA*)p);
   }
   static void deleteArray_HIHI_TMVA(void *p) {
      delete [] ((::HIHI_TMVA*)p);
   }
   static void destruct_HIHI_TMVA(void *p) {
      typedef ::HIHI_TMVA current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HIHI_TMVA

namespace {
  void TriggerDictionaryInitialization_JetCleaningAnalysisHICINT_Impl() {
    static const char* headers[] = {
"JetCleaningAnalysisHI/HIHI_TMVA.h",
0
    };
    static const char* includePaths[] = {
"/x/calo/jgoncalves/JetCleaningHI/JetCleaningAnalysisHI/Root",
"/x/calo/jgoncalves/JetCleaningHI/JetCleaningAnalysisHI",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/x/calo/jgoncalves/JetCleaningHI/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/x/calo/jgoncalves/JetCleaningHI/JetCleaningAnalysisHI/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$/x/calo/jgoncalves/JetCleaningHI/JetCleaningAnalysisHI/Root/LinkDef.h")))  HIHI_TMVA;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif
#ifndef ROOTCORE
  #define ROOTCORE 1
#endif
#ifndef ROOTCORE_RELEASE_SERIES
  #define ROOTCORE_RELEASE_SERIES 24
#endif
#ifndef ROOTCORE_TEST_FILE
  #define ROOTCORE_TEST_FILE "/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.AOD.e3698_s2608_s2183_r7725_r7676/AOD.07915862._000100.pool.root.1"
#endif
#ifndef ROOTCORE_TEST_DATA
  #define ROOTCORE_TEST_DATA "/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725"
#endif
#ifndef ASG_TEST_FILE_DATA
  #define ASG_TEST_FILE_DATA "/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7562/data15_13TeV.00284154.physics_Main.merge.AOD.r7562_p2521/AOD.07687819._000382.pool.root.1"
#endif
#ifndef ASG_TEST_FILE_MC
  #define ASG_TEST_FILE_MC "/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.AOD.e3698_s2608_s2183_r7725_r7676/AOD.07915862._000100.pool.root.1"
#endif
#ifndef ASG_TEST_FILE_MCAFII
  #define ASG_TEST_FILE_MCAFII ""
#endif
#ifndef XAOD_STANDALONE
  #define XAOD_STANDALONE 1
#endif
#ifndef XAOD_ANALYSIS
  #define XAOD_ANALYSIS 1
#endif
#ifndef ASGTOOL_STANDALONE
  #define ASGTOOL_STANDALONE 1
#endif
#ifndef ROOTCORE_PACKAGE
  #define ROOTCORE_PACKAGE "JetCleaningAnalysisHI"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "JetCleaningAnalysisHI/HIHI_TMVA.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"HIHI_TMVA", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("JetCleaningAnalysisHICINT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_JetCleaningAnalysisHICINT_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T> class DataVectorBase;", 1},{"template <typename T, typename BASE> class DataVector;", 1},{"namespace DataVector_detail { template <typename T> class DVLEltBaseInit; }", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_JetCleaningAnalysisHICINT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_JetCleaningAnalysisHICINT() {
  TriggerDictionaryInitialization_JetCleaningAnalysisHICINT_Impl();
}
