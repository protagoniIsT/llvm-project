#ifndef LLVM_LIB_TARGET_KARCH_KARCHISELLOWERING_H
#define LLVM_LIB_TARGET_KARCH_KARCHISELLOWERING_H

#include "Karch.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class KarchSubtarget;
class KarchTargetMachine;

namespace KarchISD {

enum NodeType : unsigned {
  // Start the numbering where the builtin ops and target ops leave off.
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,
  CALL,
  BR_CC,
};

} // namespace KarchISD

class KarchTargetLowering : public TargetLowering {
public:
  explicit KarchTargetLowering(const TargetMachine &TM, const KarchSubtarget &STI);

  /// This method returns the name of a target specific DAG node.
  const char *getTargetNodeName(unsigned Opcode) const override;

  KarchSubtarget const &getSubtarget() const { return STI; }

private:
  const KarchSubtarget &STI;
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_KARCH_KARCHISELLOWERING_H