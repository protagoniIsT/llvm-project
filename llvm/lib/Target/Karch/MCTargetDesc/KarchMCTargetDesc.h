#ifndef LLVM_LIB_TARGET_KARCH_MCTARGETDESC_KARCHMCTARGETDESC_H
#define LLVM_LIB_TARGET_KARCH_MCTARGETDESC_KARCHMCTARGETDESC_H

#include <memory>

namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createKarchMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
MCAsmBackend *createKarchAsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                  const MCRegisterInfo &MRI,
                                  const MCTargetOptions &Options);
std::unique_ptr<MCObjectTargetWriter> createKarchELFObjectWriter(bool Is64Bit,
                                                               uint8_t OSABI);
} // namespace llvm

// Defines symbolic names for Karch registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "KarchGenRegisterInfo.inc"

#endif // LLVM_LIB_TARGET_KARCH_MCTARGETDESC_KARCHMCTARGETDESC_H