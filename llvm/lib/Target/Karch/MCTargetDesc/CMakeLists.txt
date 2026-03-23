add_llvm_component_library(LLVMKarchDesc
  KarchMCTargetDesc.cpp
  KarchMCAsmInfo.cpp

  LINK_COMPONENTS
  MC
  Support
  KarchInfo

  ADD_TO_COMPONENT
  Karch
 )