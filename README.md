
From http://lars-lab.jpl.nasa.gov/JPL_Coding_Standard_C.pdf

Rule  1. ISO/IEC 9899-1999(E) C standard, no reliance on undefined/unspecified
        behavior.

Rule  2.  Recommended compilation command:

    gcc -Wall -Wtraditional -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align \
        -Wstrict-prototype -Wmissing-prototypes -Wconversion -Wformatsecurity \
        -Wstack-protector -Werror -pedantic \
        -fstack-protector-all --param ssp-buffer-size=4 -pedantic -pie -fPIE \
        -ftrapv -D_FORTIFY_SOURCE=2 O2 -Wl,-z,relro,-z,now -Wl,dynamicbase \
        -Wl,nxcompat -std=iso9899:1999

Rule  3. All loops will have a statically determinable upper-bound on maximum
         number of loop iterations except for non-terminating loop per task which
         should be annotated with /* @non-terminating */

Rule  4. No recursion.

Rule  5. No dynamic allocation (malloc(), sbrk(), alloca(), etc.) after
         initialization.

Rule  6. IPC is preferred over callbacks, sharing code, sharing data.  All IPC
         messages are received at a single point in a task.

Rule  7. No task delays.

Rule  8. A given data object in memory should have a single owning task.  Only
         the owner can modify it.  Ownership should be passed explicitly.

Rule  9. Avoid semaphores/locks.  Nested semaphores/locks especially should be
         avoided.  If unavoidable, should occur in a single predetermined and
         documented order.  Unlock will always appear in the body of the same
         function that locks.

Rule 10. Memory protection shall be used (rule 2 has flags for this).

Rule 11. Don't use ogot.  Don't use setjmp/longjmp.

Rule 12. In an enum, = will not be used to initialize members other than the
         first, unless all are explicity initialized.

Rule 13. Declare data at the smallest scope.  No declaration in an inner scope
         will hide a declaration in an outer scope.

Rule 14. Callers will always check values of non-void functions, or explicitly
         cast them to (void).

Rule 15. A public function will always check its parameteres.  Otherwise they
         shall be checked by either the caller or callee.

Rule 16. Use assertions.  A function of more than 10 lines should have at least
         one.

Rule 17. Typedefs that indicate size and signedness should be used in place of
         the basic types.

Rule 18. Be explicit with parentheses.

Rule 19. Boolan expression shall not have side effects.

Rule 20. C preprocessor shall be limited to file inclusion and simple macros.

Rule 21. Macros shall not be #define'd within a function or block.

Rule 22. #undef shall not be used.

Rule 23. All #else, #elif, #endif shall reside in the same file as the
         corresponding #if/#ifdef.

Rule 24. No more than one statement or variable declaration per line, except the
         for loop.

Rule 25. Functions should be no longer than 60 lines of text and define no more
         than 6 parameters.

Rule 26. No more than two * in a pointer declaration.

Rule 27. No more than two * in dereferencing.

Rule 28. Pointer dereferences should not be hidden in macro definitions or
         typedef.

Rule 29. Non-constant pointers to functions should not be used.

Rule 30. Conversions shall not be performed between a function pointer and
         any type other than an integral type.

Rule 31. #include directives in a file shall only be preceded by other
         preprocessor directives or comments.

