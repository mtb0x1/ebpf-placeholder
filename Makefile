all: demo_ebpf funny_ebpf

demo_ebpf:
	$(MAKE) -f Makefile.demo_ebpf

funny_ebpf:
	$(MAKE) -f Makefile.funny_ebpf
