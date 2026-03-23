#include "KarchRegisterInfo.h"
#include "Karch.h"
#include "KarchFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "KarchGenRegisterInfo.inc"

KarchRegisterInfo::KarchRegisterInfo() : KarchGenRegisterInfo(Karch::R0) {
  KARCH_DUMP_GREEN
}