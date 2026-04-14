#include "Karch.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"

using namespace clang;
using namespace clang::targets;

void KarchTargetInfo::getTargetDefines(const LangOptions &Opts,
                                     MacroBuilder &Builder) const {
  Builder.defineMacro("__karch__");
}

ArrayRef<Builtin::Info> KarchTargetInfo::getTargetBuiltins() const {
  return std::nullopt;
}