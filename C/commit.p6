#!/usr/bin/env perl6

qx/find . -type f -perm -u+x/.lines».IO.grep({
    .get.starts-with("#!").not with .open: :enc<latin1>
})».unlink;

qx/git add --all; git commit -mx; git push --all/;
