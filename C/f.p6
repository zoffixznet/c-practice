sub z {
    sub bar {
        say $CALLER::foo
    }

    sub foo {
        my $foo = 42;
        {
            bar
        }
    }

    sub meow {
        say foo
    }

    meow
}

z
