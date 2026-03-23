#include "Karch.h"
#include "TargetInfo/KarchTargetInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "KarchGenRegisterInfo.inc"

static MCRegisterInfo *createSimMCRegisterInfo(const Triple &TT) {
  SIM_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitSimMCRegisterInfo(X, Sim::R0);
  return X;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeSimTargetMC() {
  SIM_DUMP_MAGENTA
  Target &TheSimTarget = getTheSimTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheSimTarget, createSimMCRegisterInfo);
}