// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIxdIcalodIjgoncalvesdIJetCleaningHIdIRootCoreBindIobjdIx86_64mIslc6mIgcc49mIoptdIPhotonVertexSelectiondIobjdIPhotonVertexSelection_Reflex

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
#include "/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.8/PhotonVertexSelection/PhotonVertexSelection/PhotonVertexSelectionDict.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *CPcLcLIPhotonVertexSelectionTool_Dictionary();
   static void CPcLcLIPhotonVertexSelectionTool_TClassManip(TClass*);
   static void delete_CPcLcLIPhotonVertexSelectionTool(void *p);
   static void deleteArray_CPcLcLIPhotonVertexSelectionTool(void *p);
   static void destruct_CPcLcLIPhotonVertexSelectionTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CP::IPhotonVertexSelectionTool*)
   {
      ::CP::IPhotonVertexSelectionTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CP::IPhotonVertexSelectionTool));
      static ::ROOT::TGenericClassInfo 
         instance("CP::IPhotonVertexSelectionTool", "PhotonVertexSelection/IPhotonVertexSelectionTool.h", 17,
                  typeid(::CP::IPhotonVertexSelectionTool), DefineBehavior(ptr, ptr),
                  &CPcLcLIPhotonVertexSelectionTool_Dictionary, isa_proxy, 0,
                  sizeof(::CP::IPhotonVertexSelectionTool) );
      instance.SetDelete(&delete_CPcLcLIPhotonVertexSelectionTool);
      instance.SetDeleteArray(&deleteArray_CPcLcLIPhotonVertexSelectionTool);
      instance.SetDestructor(&destruct_CPcLcLIPhotonVertexSelectionTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CP::IPhotonVertexSelectionTool*)
   {
      return GenerateInitInstanceLocal((::CP::IPhotonVertexSelectionTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::CP::IPhotonVertexSelectionTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CPcLcLIPhotonVertexSelectionTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CP::IPhotonVertexSelectionTool*)0x0)->GetClass();
      CPcLcLIPhotonVertexSelectionTool_TClassManip(theClass);
   return theClass;
   }

   static void CPcLcLIPhotonVertexSelectionTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CPcLcLPhotonVertexSelectionTool_Dictionary();
   static void CPcLcLPhotonVertexSelectionTool_TClassManip(TClass*);
   static void delete_CPcLcLPhotonVertexSelectionTool(void *p);
   static void deleteArray_CPcLcLPhotonVertexSelectionTool(void *p);
   static void destruct_CPcLcLPhotonVertexSelectionTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CP::PhotonVertexSelectionTool*)
   {
      ::CP::PhotonVertexSelectionTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CP::PhotonVertexSelectionTool));
      static ::ROOT::TGenericClassInfo 
         instance("CP::PhotonVertexSelectionTool", "PhotonVertexSelection/PhotonVertexSelectionTool.h", 27,
                  typeid(::CP::PhotonVertexSelectionTool), DefineBehavior(ptr, ptr),
                  &CPcLcLPhotonVertexSelectionTool_Dictionary, isa_proxy, 0,
                  sizeof(::CP::PhotonVertexSelectionTool) );
      instance.SetDelete(&delete_CPcLcLPhotonVertexSelectionTool);
      instance.SetDeleteArray(&deleteArray_CPcLcLPhotonVertexSelectionTool);
      instance.SetDestructor(&destruct_CPcLcLPhotonVertexSelectionTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CP::PhotonVertexSelectionTool*)
   {
      return GenerateInitInstanceLocal((::CP::PhotonVertexSelectionTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::CP::PhotonVertexSelectionTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CPcLcLPhotonVertexSelectionTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CP::PhotonVertexSelectionTool*)0x0)->GetClass();
      CPcLcLPhotonVertexSelectionTool_TClassManip(theClass);
   return theClass;
   }

   static void CPcLcLPhotonVertexSelectionTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CPcLcLIPhotonPointingTool_Dictionary();
   static void CPcLcLIPhotonPointingTool_TClassManip(TClass*);
   static void delete_CPcLcLIPhotonPointingTool(void *p);
   static void deleteArray_CPcLcLIPhotonPointingTool(void *p);
   static void destruct_CPcLcLIPhotonPointingTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CP::IPhotonPointingTool*)
   {
      ::CP::IPhotonPointingTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CP::IPhotonPointingTool));
      static ::ROOT::TGenericClassInfo 
         instance("CP::IPhotonPointingTool", "PhotonVertexSelection/IPhotonPointingTool.h", 14,
                  typeid(::CP::IPhotonPointingTool), DefineBehavior(ptr, ptr),
                  &CPcLcLIPhotonPointingTool_Dictionary, isa_proxy, 0,
                  sizeof(::CP::IPhotonPointingTool) );
      instance.SetDelete(&delete_CPcLcLIPhotonPointingTool);
      instance.SetDeleteArray(&deleteArray_CPcLcLIPhotonPointingTool);
      instance.SetDestructor(&destruct_CPcLcLIPhotonPointingTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CP::IPhotonPointingTool*)
   {
      return GenerateInitInstanceLocal((::CP::IPhotonPointingTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::CP::IPhotonPointingTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CPcLcLIPhotonPointingTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CP::IPhotonPointingTool*)0x0)->GetClass();
      CPcLcLIPhotonPointingTool_TClassManip(theClass);
   return theClass;
   }

   static void CPcLcLIPhotonPointingTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CPcLcLPhotonPointingTool_Dictionary();
   static void CPcLcLPhotonPointingTool_TClassManip(TClass*);
   static void delete_CPcLcLPhotonPointingTool(void *p);
   static void deleteArray_CPcLcLPhotonPointingTool(void *p);
   static void destruct_CPcLcLPhotonPointingTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CP::PhotonPointingTool*)
   {
      ::CP::PhotonPointingTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CP::PhotonPointingTool));
      static ::ROOT::TGenericClassInfo 
         instance("CP::PhotonPointingTool", "PhotonVertexSelection/PhotonPointingTool.h", 23,
                  typeid(::CP::PhotonPointingTool), DefineBehavior(ptr, ptr),
                  &CPcLcLPhotonPointingTool_Dictionary, isa_proxy, 0,
                  sizeof(::CP::PhotonPointingTool) );
      instance.SetDelete(&delete_CPcLcLPhotonPointingTool);
      instance.SetDeleteArray(&deleteArray_CPcLcLPhotonPointingTool);
      instance.SetDestructor(&destruct_CPcLcLPhotonPointingTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CP::PhotonPointingTool*)
   {
      return GenerateInitInstanceLocal((::CP::PhotonPointingTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::CP::PhotonPointingTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CPcLcLPhotonPointingTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CP::PhotonPointingTool*)0x0)->GetClass();
      CPcLcLPhotonPointingTool_TClassManip(theClass);
   return theClass;
   }

   static void CPcLcLPhotonPointingTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CPcLcLIElectronRemovalTool_Dictionary();
   static void CPcLcLIElectronRemovalTool_TClassManip(TClass*);
   static void delete_CPcLcLIElectronRemovalTool(void *p);
   static void deleteArray_CPcLcLIElectronRemovalTool(void *p);
   static void destruct_CPcLcLIElectronRemovalTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CP::IElectronRemovalTool*)
   {
      ::CP::IElectronRemovalTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CP::IElectronRemovalTool));
      static ::ROOT::TGenericClassInfo 
         instance("CP::IElectronRemovalTool", "PhotonVertexSelection/IElectronRemovalTool.h", 14,
                  typeid(::CP::IElectronRemovalTool), DefineBehavior(ptr, ptr),
                  &CPcLcLIElectronRemovalTool_Dictionary, isa_proxy, 0,
                  sizeof(::CP::IElectronRemovalTool) );
      instance.SetDelete(&delete_CPcLcLIElectronRemovalTool);
      instance.SetDeleteArray(&deleteArray_CPcLcLIElectronRemovalTool);
      instance.SetDestructor(&destruct_CPcLcLIElectronRemovalTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CP::IElectronRemovalTool*)
   {
      return GenerateInitInstanceLocal((::CP::IElectronRemovalTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::CP::IElectronRemovalTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CPcLcLIElectronRemovalTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CP::IElectronRemovalTool*)0x0)->GetClass();
      CPcLcLIElectronRemovalTool_TClassManip(theClass);
   return theClass;
   }

   static void CPcLcLIElectronRemovalTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CPcLcLElectronRemovalTool_Dictionary();
   static void CPcLcLElectronRemovalTool_TClassManip(TClass*);
   static void delete_CPcLcLElectronRemovalTool(void *p);
   static void deleteArray_CPcLcLElectronRemovalTool(void *p);
   static void destruct_CPcLcLElectronRemovalTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CP::ElectronRemovalTool*)
   {
      ::CP::ElectronRemovalTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CP::ElectronRemovalTool));
      static ::ROOT::TGenericClassInfo 
         instance("CP::ElectronRemovalTool", "PhotonVertexSelection/ElectronRemovalTool.h", 21,
                  typeid(::CP::ElectronRemovalTool), DefineBehavior(ptr, ptr),
                  &CPcLcLElectronRemovalTool_Dictionary, isa_proxy, 0,
                  sizeof(::CP::ElectronRemovalTool) );
      instance.SetDelete(&delete_CPcLcLElectronRemovalTool);
      instance.SetDeleteArray(&deleteArray_CPcLcLElectronRemovalTool);
      instance.SetDestructor(&destruct_CPcLcLElectronRemovalTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CP::ElectronRemovalTool*)
   {
      return GenerateInitInstanceLocal((::CP::ElectronRemovalTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::CP::ElectronRemovalTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CPcLcLElectronRemovalTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CP::ElectronRemovalTool*)0x0)->GetClass();
      CPcLcLElectronRemovalTool_TClassManip(theClass);
   return theClass;
   }

   static void CPcLcLElectronRemovalTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR_Dictionary();
   static void pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR_TClassManip(TClass*);
   static void *new_pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR(void *p = 0);
   static void *newArray_pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR(Long_t size, void *p);
   static void delete_pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR(void *p);
   static void deleteArray_pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR(void *p);
   static void destruct_pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const pair<const xAOD::Vertex_v1*,float>*)
   {
      pair<const xAOD::Vertex_v1*,float> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(pair<const xAOD::Vertex_v1*,float>));
      static ::ROOT::TGenericClassInfo 
         instance("pair<const xAOD::Vertex_v1*,float>", "string", 96,
                  typeid(pair<const xAOD::Vertex_v1*,float>), DefineBehavior(ptr, ptr),
                  &pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR_Dictionary, isa_proxy, 0,
                  sizeof(pair<const xAOD::Vertex_v1*,float>) );
      instance.SetNew(&new_pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR);
      instance.SetNewArray(&newArray_pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR);
      instance.SetDelete(&delete_pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR);
      instance.SetDeleteArray(&deleteArray_pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR);
      instance.SetDestructor(&destruct_pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR);

      ::ROOT::AddClassAlternate("pair<const xAOD::Vertex_v1*,float>","pair<const xAOD::Vertex*,float>");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const pair<const xAOD::Vertex_v1*,float>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const pair<const xAOD::Vertex_v1*,float>*)0x0)->GetClass();
      pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_CPcLcLIPhotonVertexSelectionTool(void *p) {
      delete ((::CP::IPhotonVertexSelectionTool*)p);
   }
   static void deleteArray_CPcLcLIPhotonVertexSelectionTool(void *p) {
      delete [] ((::CP::IPhotonVertexSelectionTool*)p);
   }
   static void destruct_CPcLcLIPhotonVertexSelectionTool(void *p) {
      typedef ::CP::IPhotonVertexSelectionTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CP::IPhotonVertexSelectionTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_CPcLcLPhotonVertexSelectionTool(void *p) {
      delete ((::CP::PhotonVertexSelectionTool*)p);
   }
   static void deleteArray_CPcLcLPhotonVertexSelectionTool(void *p) {
      delete [] ((::CP::PhotonVertexSelectionTool*)p);
   }
   static void destruct_CPcLcLPhotonVertexSelectionTool(void *p) {
      typedef ::CP::PhotonVertexSelectionTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CP::PhotonVertexSelectionTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_CPcLcLIPhotonPointingTool(void *p) {
      delete ((::CP::IPhotonPointingTool*)p);
   }
   static void deleteArray_CPcLcLIPhotonPointingTool(void *p) {
      delete [] ((::CP::IPhotonPointingTool*)p);
   }
   static void destruct_CPcLcLIPhotonPointingTool(void *p) {
      typedef ::CP::IPhotonPointingTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CP::IPhotonPointingTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_CPcLcLPhotonPointingTool(void *p) {
      delete ((::CP::PhotonPointingTool*)p);
   }
   static void deleteArray_CPcLcLPhotonPointingTool(void *p) {
      delete [] ((::CP::PhotonPointingTool*)p);
   }
   static void destruct_CPcLcLPhotonPointingTool(void *p) {
      typedef ::CP::PhotonPointingTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CP::PhotonPointingTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_CPcLcLIElectronRemovalTool(void *p) {
      delete ((::CP::IElectronRemovalTool*)p);
   }
   static void deleteArray_CPcLcLIElectronRemovalTool(void *p) {
      delete [] ((::CP::IElectronRemovalTool*)p);
   }
   static void destruct_CPcLcLIElectronRemovalTool(void *p) {
      typedef ::CP::IElectronRemovalTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CP::IElectronRemovalTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_CPcLcLElectronRemovalTool(void *p) {
      delete ((::CP::ElectronRemovalTool*)p);
   }
   static void deleteArray_CPcLcLElectronRemovalTool(void *p) {
      delete [] ((::CP::ElectronRemovalTool*)p);
   }
   static void destruct_CPcLcLElectronRemovalTool(void *p) {
      typedef ::CP::ElectronRemovalTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CP::ElectronRemovalTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) pair<const xAOD::Vertex_v1*,float> : new pair<const xAOD::Vertex_v1*,float>;
   }
   static void *newArray_pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) pair<const xAOD::Vertex_v1*,float>[nElements] : new pair<const xAOD::Vertex_v1*,float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR(void *p) {
      delete ((pair<const xAOD::Vertex_v1*,float>*)p);
   }
   static void deleteArray_pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR(void *p) {
      delete [] ((pair<const xAOD::Vertex_v1*,float>*)p);
   }
   static void destruct_pairlEconstsPxAODcLcLVertex_v1mUcOfloatgR(void *p) {
      typedef pair<const xAOD::Vertex_v1*,float> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class pair<const xAOD::Vertex_v1*,float>

namespace ROOT {
   static TClass *vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR_Dictionary();
   static void vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR(void *p = 0);
   static void *newArray_vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR(Long_t size, void *p);
   static void delete_vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR(void *p);
   static void deleteArray_vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR(void *p);
   static void destruct_vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<pair<const xAOD::Vertex_v1*,float> >*)
   {
      vector<pair<const xAOD::Vertex_v1*,float> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<pair<const xAOD::Vertex_v1*,float> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<pair<const xAOD::Vertex_v1*,float> >", -2, "vector", 214,
                  typeid(vector<pair<const xAOD::Vertex_v1*,float> >), DefineBehavior(ptr, ptr),
                  &vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<pair<const xAOD::Vertex_v1*,float> >) );
      instance.SetNew(&new_vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR);
      instance.SetNewArray(&newArray_vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR);
      instance.SetDelete(&delete_vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR);
      instance.SetDestructor(&destruct_vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<pair<const xAOD::Vertex_v1*,float> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<pair<const xAOD::Vertex_v1*,float> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<pair<const xAOD::Vertex_v1*,float> >*)0x0)->GetClass();
      vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<pair<const xAOD::Vertex_v1*,float> > : new vector<pair<const xAOD::Vertex_v1*,float> >;
   }
   static void *newArray_vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<pair<const xAOD::Vertex_v1*,float> >[nElements] : new vector<pair<const xAOD::Vertex_v1*,float> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR(void *p) {
      delete ((vector<pair<const xAOD::Vertex_v1*,float> >*)p);
   }
   static void deleteArray_vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR(void *p) {
      delete [] ((vector<pair<const xAOD::Vertex_v1*,float> >*)p);
   }
   static void destruct_vectorlEpairlEconstsPxAODcLcLVertex_v1mUcOfloatgRsPgR(void *p) {
      typedef vector<pair<const xAOD::Vertex_v1*,float> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<pair<const xAOD::Vertex_v1*,float> >

namespace {
  void TriggerDictionaryInitialization_PhotonVertexSelection_Reflex_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.8/PhotonVertexSelection/Root",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.8/PhotonVertexSelection",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/x/calo/jgoncalves/JetCleaningHI/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.8/PhotonVertexSelection/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace CP{class __attribute__((annotate("$clingAutoload$PhotonVertexSelection/IPhotonVertexSelectionTool.h")))  IPhotonVertexSelectionTool;}
namespace CP{class __attribute__((annotate("$clingAutoload$PhotonVertexSelection/PhotonVertexSelectionTool.h")))  PhotonVertexSelectionTool;}
namespace CP{class __attribute__((annotate("$clingAutoload$PhotonVertexSelection/IPhotonPointingTool.h")))  IPhotonPointingTool;}
namespace CP{class __attribute__((annotate("$clingAutoload$PhotonVertexSelection/PhotonPointingTool.h")))  PhotonPointingTool;}
namespace CP{class __attribute__((annotate("$clingAutoload$PhotonVertexSelection/IElectronRemovalTool.h")))  IElectronRemovalTool;}
namespace CP{class __attribute__((annotate("$clingAutoload$PhotonVertexSelection/ElectronRemovalTool.h")))  ElectronRemovalTool;}
namespace xAOD{class __attribute__((annotate("$clingAutoload$PhotonVertexSelection/IPhotonVertexSelectionTool.h")))  Vertex_v1;}
namespace std{template <class _T1, class _T2> struct __attribute__((annotate("$clingAutoload$string")))  pair;
}
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$string")))  allocator;
}
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
  #define ROOTCORE_PACKAGE "PhotonVertexSelection"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#ifndef PhotonVertexSelection_PhotonVertexSelectionDict_H
#define PhotonVertexSelection_PhotonVertexSelectionDict_H

#include "PhotonVertexSelection/IPhotonVertexSelectionTool.h"
#include "PhotonVertexSelection/PhotonVertexSelectionTool.h"

#include "PhotonVertexSelection/IPhotonPointingTool.h"
#include "PhotonVertexSelection/PhotonPointingTool.h"

#include "PhotonVertexSelection/IElectronRemovalTool.h"
#include "PhotonVertexSelection/ElectronRemovalTool.h"

#include "PhotonVertexSelection/PhotonVertexHelpers.h"

namespace {
  struct GCCXML_DUMMY_INSTANTIATION_PhotonVertexSelection {
    std::pair<const xAOD::Vertex*, float> pair1;
    std::vector<std::pair<const xAOD::Vertex*, float> > vector1;
  };
}

#ifdef ASGTOOL_STANDALONE

// Helper macro for declaring the setProperty functions to the dictionary:
#define SETPROPERTY_INSTAN( TYPE )                                            \
   template StatusCode asg::AsgTool::setProperty< TYPE >( const std::string&, \
                                                          const TYPE& )

// Declare all possible setProperty template instantiations to Reflex:
SETPROPERTY_INSTAN( ToolHandle<CP::IPhotonPointingTool > );

// Make the compiler forget about this macro now...
#undef SETPROPERTY_INSTAN

#endif // ASGTOOL_STANDALONE


#endif // PhotonVertexSelection_PhotonVertexSelectionDict_H

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"CP::ElectronRemovalTool", payloadCode, "@",
"CP::IElectronRemovalTool", payloadCode, "@",
"CP::IPhotonPointingTool", payloadCode, "@",
"CP::IPhotonVertexSelectionTool", payloadCode, "@",
"CP::PhotonPointingTool", payloadCode, "@",
"CP::PhotonVertexSelectionTool", payloadCode, "@",
"xAOD::PVHelpers::getHardestVertex", payloadCode, "@",
"xAOD::PVHelpers::getTrackAtFirstMeasurement", payloadCode, "@",
"xAOD::PVHelpers::getVertexMomentum", payloadCode, "@",
"xAOD::PVHelpers::getVertexSumPt", payloadCode, "@",
"xAOD::PVHelpers::getZCommonAndError", payloadCode, "@",
"xAOD::PVHelpers::passConvSelection", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("PhotonVertexSelection_Reflex",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_PhotonVertexSelection_Reflex_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T> class DataVectorBase;", 1},{"template <typename T, typename BASE> class DataVector;", 1},{"namespace DataVector_detail { template <typename T> class DVLEltBaseInit; }", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_PhotonVertexSelection_Reflex_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_PhotonVertexSelection_Reflex() {
  TriggerDictionaryInitialization_PhotonVertexSelection_Reflex_Impl();
}
