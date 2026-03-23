#include "KarchSubtarget.h"
#include "Karch.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "sim-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "KarchGenSubtargetInfo.inc"

KarchSubtarget::KarchSubtarget(const StringRef &CPU, const StringRef &TuneCPU,
                           const StringRef &FS, const TargetMachine &TM)
    : KarchGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  KARCH_DUMP_CYAN
}