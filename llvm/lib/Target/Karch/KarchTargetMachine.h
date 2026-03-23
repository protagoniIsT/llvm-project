#ifndef LLVM_LIB_TARGET_KARCH_KARCHTARGETMACHINE_H
#define LLVM_LIB_TARGET_KARCH_KARCHTARGETMACHINE_H

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include "KarchSubtarget.h"
#include <optional>

namespace llvm {
extern Target TheKarchTarget;

class KarchTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  KarchSubtarget Subtarget;

public:
  KarchTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);

  const KarchSubtarget *getSubtargetImpl(const Function &) const override {
    KARCH_DUMP_CYAN
    return &Subtarget;
  }

  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_KARCH_KARCHTARGETMACHINE_H