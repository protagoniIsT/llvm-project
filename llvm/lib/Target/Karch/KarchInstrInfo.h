#ifndef LLVM_LIB_TARGET_KARCH_KARCHINSTRINFO_H
#define LLVM_LIB_TARGET_KARCH_KARCHINSTRINFO_H

#include "KarchRegisterInfo.h"
#include "MCTargetDesc/KarchInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "KarchGenInstrInfo.inc"

namespace llvm {

class KarchSubtarget;

class KarchInstrInfo : public KarchGenInstrInfo {
public:
  KarchInstrInfo();

};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_KARCH_KARCHINSTRINFO_H