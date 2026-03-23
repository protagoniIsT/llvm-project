#ifndef LLVM_LIB_TARGET_KARCH_MCTARGETDESC_KARCHMCASMINFO_H
#define LLVM_LIB_TARGET_KARCH_MCTARGETDESC_KARCHMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class KarchELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit KarchELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_KARCH_MCTARGETDESC_KARCHMCASMINFO_H