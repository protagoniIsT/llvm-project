include "llvm/Target/Target.td"
include "KarchRegisterInfo.td"
include "KarchInstrInfo.td"

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def KarchInstrInfo : InstrInfo;
def Karch : Target {
  let InstructionSet = KarchInstrInfo;
}