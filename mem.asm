[BITS 64]
[section .text]
	global _write_mem, _get_mem,_push_data,_pop_data
_write_mem:
	mov rbx, [rsp+4]
	mov rax, [rsp+8]
	mov [rbx], rax
	ret
_get_mem:
	mov rbx, [rsp+4]
	mov rax, [rbx]
	ret
_push_data:
	mov rax, [rsp+4]
	push rax
	ret
_pop_data:
	pop rax
	ret