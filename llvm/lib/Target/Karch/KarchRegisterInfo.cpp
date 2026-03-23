#include "KarchRegisterInfo.h"
#include "Karch.h"
#include "KarchFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "KarchGenRegisterInfo.inc"

KarchRegisterInfo::KarchRegisterInfo() : KarchGenRegisterInfo(Karch::R0) {
  KARCH_DUMP_GREEN
}
const MCPhysReg *
KarchRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  KARCH_DUMP_GREEN
  return CSR_Karch_SaveList;
}

BitVector KarchRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  KARCH_DUMP_GREEN
  KarchFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(Karch::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(Karch::R2);
  }
  return Reserved;
}

bool KarchRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool KarchRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *RS) const {
  KARCH_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register KarchRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  KARCH_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? Karch::R2 : Karch::R1;
}

const uint32_t *
KarchRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                      CallingConv::ID CC) const {
  KARCH_DUMP_GREEN
  return CSR_Karch_RegMask;
}