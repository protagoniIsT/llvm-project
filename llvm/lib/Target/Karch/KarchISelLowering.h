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

} // end namespace llvm

#endif // LLVM_LIB_TARGET_KARCH_KARCHISELLOWERING_H