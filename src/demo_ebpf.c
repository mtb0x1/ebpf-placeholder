#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>

#pragma clang diagnostic ignored "-Wunknown-attributes"



char LICENSE[] SEC("license") = "GPL";

SEC("xdp")
int demo_ebpf_pass(struct xdp_md *ctx) {
    bpf_trace_printk("demo_ebpf hit!\\n", sizeof("demo_ebpf hit!\\n"));
    return XDP_PASS;
}