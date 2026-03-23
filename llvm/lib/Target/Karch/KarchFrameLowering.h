#ifndef LLVM_LIB_TARGET_KARCH_KARCHFRAMELOWERING_H
#define LLVM_LIB_TARGET_KARCH_KARCHFRAMELOWERING_H

#include "Karch.h"
#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {

class KarchSubtarget;

class KarchFrameLowering : public TargetFrameLowering {
public:
   KarchFrameLowering(const KarchSubtarget &STI)
      : TargetFrameLowering(TargetFrameLowering::StackGrowsDown, Align(4), 0),
        STI(STI) {
    KARCH_DUMP_GREEN
  }

  /// emitProlog/emitEpilog - These methods insert prolog and epilog code into
  /// the function.
  void emitPrologue(MachineFunction &MF,
                    MachineBasicBlock &MBB) const override {}
  void emitEpilogue(MachineFunction &MF,
                    MachineBasicBlock &MBB) const override {}

  /// hasFP - Return true if the specified function should have a dedicated
  /// frame pointer register. For most targets this is true only if the function
  /// has variable sized allocas or if frame pointer elimination is disabled.
  bool hasFPImpl(const MachineFunction &MF) const override { return false; }


private:
  const KarchSubtarget &STI;
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_KARCH_KARCHFRAMELOWERING_H