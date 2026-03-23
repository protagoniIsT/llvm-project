add_llvm_component_group(Karch)

set(LLVM_TARGET_DEFINITIONS Karch.td)

tablegen(LLVM KarchGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM KarchGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM KarchGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM KarchGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM KarchGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM KarchGenCallingConv.inc -gen-callingconv)
tablegen(LLVM KarchGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM KarchGenMCCodeEmitter.inc -gen-emitter)

add_public_tablegen_target(KarchCommonTableGen)


add_llvm_target(KarchCodeGen
  KarchTargetMachine.cpp
  KarchRegisterInfo.cpp
  KarchInstrInfo.cpp
  KarchSubtarget.cpp
  KarchAsmPrinter.cpp
  KarchISelDagToDag.cpp
  KarchISelLowering.cpp
  KarchInstPrinter.cpp
  KarchMCInstLower.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  KarchInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  Karch
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)