add_llvm_component_group(Karch)

add_llvm_target(KarchCodeGen
  KarchTargetMachine.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  KarchInfo

  ADD_TO_COMPONENT
  Karch
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)