#include "TargetInfo/KarchTargetInfo.h"
#include "Karch.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheKarchTarget() {
  KARCH_DUMP_YELLOW
  static Target TheKarchTarget;
  return TheKarchTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeKarchTargetInfo() {
  KARCH_DUMP_YELLOW
  RegisterTarget<Triple::karch> X(getTheKarchTarget(), "karch",
                                "Karch target for LLVM course", "KARCH");
}