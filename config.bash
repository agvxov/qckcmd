function qckcmd_wrapper() {
	READLINE_LINE="$(qckcmd -i ${VHOME}/.qckcmd)"
	READLINE_POINT="${#READLINE_LINE}"
}
bind -x '"\C-p": qckcmd_wrapper'
