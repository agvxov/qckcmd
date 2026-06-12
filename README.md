# Qckcmd

> QuiCK CoMmanDs

    qckcmd [options]
        -h        : print this help message
        -i <file> : specify config file

Utility to launch pre-defined commands quickly
by mapping them to characters.

It could conceptually be called a command bookmark system.

Qckcmd has the benefit over regular short-cuts that:
* You are echod a list of your short-cuts which helps remembering.
* By introducing a leader key, your terminal/shell -especially Bash-
   won't steal your perfect mnemonic.

The config file should contain entries separated by newlines:
    <KEY>: <COMMAND>

Qckcmd is not supposed to be ran by hand,
instead you are supposed to configure your shell such that Qckcmd is bound to a short-cut.
(Small) wrappers for Bash and Fish are vendored to you in the project root.
The wrappers assume the short-cut `ctrl+p` and the config file `~/.qckcmd`.
Note that qckcmd does not actually execute commands, it echos the selected one
and the wrappers eval the result.
This has the benefit that they can modify the shell (e.g. use `source`).

Homepage: https://github.com/agvxov/qckcmd
