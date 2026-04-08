function qckcmd_wrapper
    echo ""
    commandline (qckcmd -i $VHOME/.qckcmd)
    commandline --function repaint
end
bind \cp qckcmd_wrapper
