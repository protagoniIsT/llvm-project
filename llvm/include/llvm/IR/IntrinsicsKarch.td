let TargetPrefix = "karch" in {  // All intrinsics start with "llvm.karch.".
 
 def int_karch_putpixel:
   Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
 
 def int_karch_flush:
   Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;
 
 } // TargetPrefix = "karch"