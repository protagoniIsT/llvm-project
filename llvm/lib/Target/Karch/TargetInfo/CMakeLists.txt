add_llvm_component_library(LLVMKarchInfo
  KarchTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  Karch
  )