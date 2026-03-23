add_llvm_component_group(Karch)

set(LLVM_TARGET_DEFINITIONS Sim.td)

tablegen(LLVM SimGenRegisterInfo.inc -gen-register-info)

add_public_tablegen_target(SimCommonTableGen)


add_llvm_target(KarchCodeGen
  KarchTargetMachine.cpp
  KarchRegisterInfo.cpp

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