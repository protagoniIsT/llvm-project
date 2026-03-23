#ifndef LLVM_LIB_TARGET_KARCH_KARCHREGISTERINFO_H
#define LLVM_LIB_TARGET_KARCH_KARCHREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "KarchGenRegisterInfo.inc"

namespace llvm {

struct KarchRegisterInfo : public KarchGenRegisterInfo {
public:
  KarchRegisterInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_KARCH_KARCHREGISTERINFO_H