include "llvm/Target/Target.td"
include "KarchRegisterInfo.td"
include "KarchInstrInfo.td"

def KarchInstrInfo : InstrInfo;
def Karch : Target {
  let InstructionSet = KarchInstrInfo;
}