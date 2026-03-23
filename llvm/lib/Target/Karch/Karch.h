#ifndef LLVM_LIB_TARGET_Karch_Karch_H
#define LLVM_LIB_TARGET_Karch_Karch_H

#include "MCTargetDesc/KarchMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

#define KARCH_DUMP(Color)                                                        \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define KARCH_DUMP(Color) {}

#define KARCH_DUMP_RED KARCH_DUMP(llvm::raw_ostream::RED)
#define KARCH_DUMP_GREEN KARCH_DUMP(llvm::raw_ostream::GREEN)
#define KARCH_DUMP_YELLOW KARCH_DUMP(llvm::raw_ostream::YELLOW)
#define KARCH_DUMP_CYAN KARCH_DUMP(llvm::raw_ostream::CYAN)
#define KARCH_DUMP_MAGENTA KARCH_DUMP(llvm::raw_ostream::MAGENTA)
#define KARCH_DUMP_WHITE KARCH_DUMP(llvm::raw_ostream::WHITE)

namespace llvm {
class KarchTargetMachine;
class FunctionPass;

class KarchSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerKarchMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                  AsmPrinter &AP);
bool LowerKarchMachineOperandToMCOperand(const MachineOperand &MO,
                                       MCOperand &MCOp, const AsmPrinter &AP);

FunctionPass *createKarchISelDag(KarchTargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm

#endif // LLVM_LIB_TARGET_Karch_Karch_H