#include "MCTargetDesc/KarchInfo.h"
#include "Karch.h"
#include "KarchInstPrinter.h"
#include "KarchMCAsmInfo.h"
#include "TargetInfo/KarchTargetInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "KarchGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "KarchGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "KarchGenSubtargetInfo.inc"

static MCRegisterInfo *createKarchMCRegisterInfo(const Triple &TT) {
  KARCH_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitKarchMCRegisterInfo(X, Karch::R0);
  return X;
}

static MCInstrInfo *createKarchMCInstrInfo() {
  KARCH_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitKarchMCInstrInfo(X);
  return X;
}

static MCSubtargetInfo *createKarchMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  KARCH_DUMP_MAGENTA
  return createKarchMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCAsmInfo *createKarchMCAsmInfo(const MCRegisterInfo &MRI,
                                     const Triple &TT,
                                     const MCTargetOptions &Options) {
  KARCH_DUMP_MAGENTA
  MCAsmInfo *MAI = new KarchELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(Karch::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

static MCInstPrinter *createKarchMCInstPrinter(const Triple &T,
                                             unsigned SyntaxVariant,
                                             const MCAsmInfo &MAI,
                                             const MCInstrInfo &MII,
                                             const MCRegisterInfo &MRI) {
  KARCH_DUMP_MAGENTA
  return new KarchInstPrinter(MAI, MII, MRI);
}



extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeKarchTargetMC() {
  KARCH_DUMP_MAGENTA
  Target &TheKarchTarget = getTheKarchTarget();
  RegisterMCAsmInfoFn X(TheKarchTarget, createKarchMCAsmInfo);
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheKarchTarget, createKarchMCRegisterInfo);

  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheKarchTarget, createKarchMCInstrInfo);
  
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheKarchTarget, createKarchMCSubtargetInfo);

  // Register the MCInstPrinter
  TargetRegistry::RegisterMCInstPrinter(TheKarchTarget, createKarchMCInstPrinter);

  // Register the MC Code Emitter.
  TargetRegistry::RegisterMCCodeEmitter(TheKarchTarget, createKarchMCCodeEmitter);
}