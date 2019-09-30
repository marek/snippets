package com.marek;

import jnr.posix.POSIXFactory;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

public void readInput(String path) {
    var parser = new DefaultParser();

    try {
        InputStream inputStream = null;
        if (path != null) {
            // If file is specified open it.
            inputStream = new FileInputStream(path);
        } else if (!POSIXFactory.getPOSIX().isatty(FileDescriptor.in)) {
            // Otherwise check if we have STDIN available. (isTTY == false)
            inputStream = System.in;
        } else {
            System.err.println("Missing argument: FILE or STDIN");
            System.exit(1);
        }

        // Do stuff with data
        func(inputStream);

    } catch (FileNotFoundException e) {
        System.err.println("Error opening file");
        e.printStackTrace();
        System.exit(1);
    }
}
