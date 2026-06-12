#!/usr/bin/perl

use strict;
use warnings;

my $output = qx(highlight-md-for-script-help-message.out README.md);
my @lines = split /\n/, $output;

# delete first 2 lines
splice(@lines, 0, 2);

for my $line (@lines) {
    $line =~ s/`/\\`/g;      # escape backticks
    $line = "echo \"$line\""; # wrap with echo
}

print join("\n", @lines), "\n";
