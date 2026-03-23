add_llvm_component_library(LLVMKarchDesc
  KarchMCTargetDesc.cpp
  KarchMCAsmInfo.cpp
  KarchInstPrinter.cpp
  KarchMCCodeEmitter.cpp

  LINK_COMPONENTS
  MC
  Support
  KarchInfo

  ADD_TO_COMPONENT
  Karch
 )