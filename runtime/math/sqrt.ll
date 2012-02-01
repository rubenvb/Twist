; sqrt function

define i8 @sqrt(i8 %x) {
entry:
  %tmp = uitofp i8 %x to double
  %tmp2 = call double @llvm.sqrt.fp64( double %tmp)
  %tmp3 = fptoui double %tmp2 to i8
  ret i8 %tmp3
}