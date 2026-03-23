#include "KarchTargetMachine.h"
#include "Karch.h"
#include "TargetInfo/KarchTargetInfo.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeKarchTarget() {
  // Register the target.
  KARCH_DUMP_CYAN
  RegisterTargetMachine<KarchTargetMachine> A(getTheKarchTarget());
}

KarchTargetMachine::KarchTargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(
          T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32", TT, CPU, FS, Options,
          Reloc::Static, getEffectiveCodeModel(CM, CodeModel::Small), OL) {
  KARCH_DUMP_CYAN
  initAsmInfo();
}

namespace {

/// Karch Code Generator Pass Configuration Options.
class KarchPassConfig : public TargetPassConfig {
public:
  KarchPassConfig(KarchTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  bool addInstSelector() override {
    KARCH_DUMP_CYAN
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *KarchTargetMachine::createPassConfig(PassManagerBase &PM) {
  KARCH_DUMP_CYAN
  return new KarchPassConfig(*this, PM);
}