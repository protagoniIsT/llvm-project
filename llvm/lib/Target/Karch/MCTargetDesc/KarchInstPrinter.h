#ifndef LLVM_LIB_TARGET_KARCH_INSTPRINTER_KARCHINSTPRINTER_H
#define LLVM_LIB_TARGET_KARCH_INSTPRINTER_KARCHINSTPRINTER_H

#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCRegister.h"

namespace llvm {

class KarchInstPrinter : public MCInstPrinter {
public:
  KarchInstPrinter(const MCAsmInfo &MAI, const MCInstrInfo &MII,
                 const MCRegisterInfo &MRI)
      : MCInstPrinter(MAI, MII, MRI) {}

  std::pair<const char *, uint64_t>
  getMnemonic(const MCInst &MI) const override {}

  // Override MCInstPrinter.
  void printRegName(raw_ostream &O, MCRegister Reg) override {}
  void printInst(const MCInst *MI, uint64_t Address, StringRef Annot,
                 const MCSubtargetInfo &STI, raw_ostream &O) override {}
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_KARCH_INSTPRINTER_KARCHINSTPRINTER_H