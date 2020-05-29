# csci-241-ch13-5
C_Assembly_Mixed_Call

This is the same logic and UI as the previous one. Three steps are required as follows:

Step 1, Two module basics: Let your C++ code call an assembly procedure named isPrimeASM in .ASM file. The procedure isPrimeASM accepts an integer and returns a value of true (1) if the integer is prime, and false (0) if nonprime. Still attention: avoid PUSH/POP and if really wanted, add the USES operator here:
isPrimeASM PROC, intVal:DWORD
Now you don't need Irvine32.inc or smallWin.inc. In the .ASM file, declare by yourself as C calling convention:
.model flat, C
While in the CPP file, make a forward declaration as an external C prototype of isPrimeASM that is necessary for main() to call.

Step 2, Square root upper bound: The divisor to check doesn't have to go n/2, and the largest one only need to be the square root of n (see Primality test). So next, try to call a square root function from C++. Since C Runtime sqrt() only accepts an argument of floating point numbers, you have to simply create an integer square root function like this:
int intSqrt(int n);
Now you can easily call this intSqrt() in your assembly procedure isPrimeASM.

Step 3, Odd divisors: Consider odd numbers as the divisor in iterations. Reasonably, you should only use even number 2 and odd numbers as divisors.
- A good example to refer is MultiplicationTable. You can use its CPP/ASM project as a template. But when you want to manually create a CPP project and add a .ASM file, you may meet the Link error: LNK2019: unresolved external symbol _isPrimeASM referenced in function _main. Click AddAssemblyFileToCppProjectVS for help.

Just in case you meet some unknown crash, try the workaround either way:
With USES like:
isPrimeASM PROC USES ebx ecx edx, inVal:DWORD
Without testing isPrimeC and others by commenting out like:
 // cout << "isPrimeC:   the number is " << (isPrimeC(N)?  "" : "NOT ") << "prime\n";
Please turn in both .ASM and .CPP files.
