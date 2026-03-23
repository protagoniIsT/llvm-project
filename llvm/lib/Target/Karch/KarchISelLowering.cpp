#include "KarchISelLowering.h"
#include "Karch.h"
#include "KarchRegisterInfo.h"
#include "KarchSubtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#define DEBUG_TYPE "Karch-lower"

using namespace llvm;

KarchTargetLowering::KarchTargetLowering(const TargetMachine &TM,
                                     const KarchSubtarget &STI)
    : TargetLowering(TM), STI(STI) {
  KARCH_DUMP_RED
  addRegisterClass(MVT::i32, &Karch::GPRRegClass);
}

const char *KarchTargetLowering::getTargetNodeName(unsigned Opcode) const {
  KARCH_DUMP_RED
  switch (Opcode) {
  case KarchISD::CALL:
    return "KarchISD::CALL";
  case KarchISD::RET:
    return "KarchISD::RET";
  }
  return nullptr;
}