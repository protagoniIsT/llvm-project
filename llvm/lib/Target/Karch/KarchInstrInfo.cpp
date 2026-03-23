#include "KarchInstrInfo.h"
#include "Karch.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "KarchGenInstrInfo.inc"

#define DEBUG_TYPE "Karch-inst-info"

KarchInstrInfo::KarchInstrInfo() : KarchGenInstrInfo() { KARCH_DUMP_GREEN }