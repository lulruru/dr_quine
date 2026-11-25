;colleen
global main
extern printf

section .text

main:
    ;inside comment
    push rbx
    call print_source
    pop rbx
    xor eax, eax
    ret

print_source:
    push rbx
    lea rdi, [rel format]
    lea rsi, [rel format]
    mov rdx, 10
    mov rcx, 34
    xor rax, rax
    call printf wrt ..plt
    pop rbx
    ret

section .rodata
format:
    db ";colleen%2$cglobal main%2$cextern printf%2$c%2$csection .text%2$c%2$cmain:%2$c    ;inside comment%2$c    push rbx%2$c    call print_source%2$c    pop rbx%2$c    xor eax, eax%2$c    ret%2$c%2$cprint_source:%2$c    push rbx%2$c    lea rdi, [rel format]%2$c    lea rsi, [rel format]%2$c    mov rdx, 10%2$c    mov rcx, 34%2$c    xor rax, rax%2$c    call printf wrt ..plt%2$c    pop rbx%2$c    ret%2$c%2$csection .rodata%2$cformat:%2$c    db %3$c%1$s%3$c, 0%2$c%2$csection .note.GNU-stack noalloc noexec nowrite progbits%2$c", 0

section .note.GNU-stack noalloc noexec nowrite progbits
