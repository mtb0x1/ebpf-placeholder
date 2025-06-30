#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>

#pragma clang diagnostic ignored "-Wunknown-attributes"


char LICENSE[] SEC("license") = "GPL";

SEC("tracepoint/syscalls/sys_enter_execve")
int funny_ebpf(struct pt_regs *ctx) {
    const char *filename = (const char *)PT_REGS_PARM1(ctx);
    
    if (filename == NULL) 
        return 0;

    char fname[128];
    if (bpf_probe_read_str(fname, sizeof(fname), filename) < 0)
        return 0;

    

    // Snark based on command
    if (__builtin_memcmp(fname, "/usr/bin/vi", 11) == 0) {
        bpf_trace_printk("funny_ebpf =>Still clinging to tradition, eh?\\n", sizeof("funny_ebpf =>Still clinging to tradition, eh?\\n"));
    } else if (__builtin_memcmp(fname, "/bin/vim", 8) == 0) {
        bpf_trace_printk("funny_ebpf =>The OG escape room.\\n", sizeof("funny_ebpf =>The OG escape room.\\n"));
    } else if (__builtin_memcmp(fname, "/bin/rm", 7) == 0) {
        bpf_trace_printk("funny_ebpf =>That's not how we debug.\\n", sizeof("funny_ebpf =>That's not how we debug.\\n"));
    } else if (__builtin_memcmp(fname, "/usr/bin/make", 13) == 0) {
        bpf_trace_printk("funny_ebpf =>Building hope. Again.\\n", sizeof("funny_ebpf =>Building hope. Again.\\n"));
    } else if (__builtin_memcmp(fname, "/usr/bin/gcc", 12) == 0) {
        bpf_trace_printk("funny_ebpf =>Ah, the segfault generator.\\n", sizeof("funny_ebpf =>Ah, the segfault generator.\\n"));
    }else if (__builtin_memcmp(fname, "/usr/local/bin/code", 17) == 0) {
        bpf_trace_printk("funny_ebpf =>VS Code detected. Productivity mode: questionable.\\n", sizeof("funny_ebpf =>VS Code detected. Productivity mode: questionable.\\n"));
    } else if (__builtin_memcmp(fname, "/usr/local/bin/git", 16) == 0) {
        bpf_trace_printk("funny_ebpf =>Committing to something?\\n", sizeof("funny_ebpf =>Committing to something?\\n"));
    } else if (__builtin_memcmp(fname, "/usr/bin/clang", 13) == 0) {
        bpf_trace_printk("funny_ebpf =>for when you want warnings as errors.\\n", sizeof("funny_ebpf =>for when you want warnings as errors.\\n"));
    } else if (__builtin_memcmp(fname, "/usr/local/cargo", 14) == 0) {
        bpf_trace_printk("funny_ebpf =>shipping bugs at scale.\\n", sizeof("funny_ebpf =>shipping bugs at scale.\\n"));
    } else if (__builtin_memcmp(fname, "/usr/local/cargo/bin/rustc", 23) == 0) {
        bpf_trace_printk("funny_ebpf =>borrow checker intensifies.\\n", sizeof("funny_ebpf =>borrow checker intensifies.\\n"));
    } else if (__builtin_memcmp(fname, "/usr/local/cargo/bin/rust-gdb", 27) == 0) {
        bpf_trace_printk("funny_ebpf =>debugging the impossible.\\n", sizeof("funny_ebpf =>debugging the impossible.\\n"));
    } else if (__builtin_memcmp(fname, "/usr/local/cargo/bin/rust-lldb", 28) == 0) {
        bpf_trace_printk("funny_ebpf =>re-write it in Rust they said.\\n", sizeof("funny_ebpf =>re-write it in Rust they said.\\n"));
    } else if (__builtin_memcmp(fname, "/usr/bin/perf", 11) == 0) {
        bpf_trace_printk("funny_ebpf =>perf ? who cares ship it.\\n", sizeof("funny_ebpf =>perf ? who cares ship it\\n"));
    }

    return 0;
}
