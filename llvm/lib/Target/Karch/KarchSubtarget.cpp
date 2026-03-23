#include "KarchSubtarget.h"
#include "Karch.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "sim-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "KarchGenSubtargetInfo.inc"

KarchSubtarget::KarchSubtarget(const Triple &TT, const std::string &CPU,
                           const std::string &FS, const TargetMachine &TM)
    : KarchGenSubtargetInfo(TT, CPU, /*TuneCPU=*/CPU, FS), TLInfo(TM, *this) {
  KARCH_DUMP_CYAN
}