#ifndef LLVM_LIB_TARGET_KARCH_MCTARGETDESC_KARCHINFO_H
#define LLVM_LIB_TARGET_KARCH_MCTARGETDESC_KARCHINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace KarchOp {
enum OperandType : unsigned {
  OPERAND_KARCHM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace KarchOp

} // end namespace llvm

#endif