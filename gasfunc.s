.text
	.global _write_mem,_get_mem,_mem_refresh, _mem_copy
_write_mem:
	pushq %rbx
	movq 0x4(%rsp), %rbx
	movq 0x8(%rsp), %rdx
	movq %rdx, (%rbx)
	popq %rbx
	ret
_get_mem:
	pushq %rbx
	movq 0x4(%rsp), %rbx
	movq (%rbx), %rax
	ret
_mem_refresh:
	pushq %rbx
	movq 0x4(%rsp), %rax
	movq 0x8(%rsp), %rcx
	movq 0xc(%rsp), %rdx
loop:
	movq %rax, %rbx
	movq (%rbx), %rdx
	inc %rax
	cmp %rax, %rcx
	jbe loop
	popq %rbx
	ret
_mem_copy:
	pushq %rbx
	movq 0x4(%rsp), %rax
	movq 0x8(%rsp), %rcx
	movq %rax, %rbx
	movq (%rbx), %rdx
	movq %rcx, %rbx
	movq %rdx, (%rbx)
	popq %rbx
	ret