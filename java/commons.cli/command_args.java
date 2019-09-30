package com.marek;

import org.apache.commons.cli.DefaultParser;
import org.apache.commons.cli.HelpFormatter;
import org.apache.commons.cli.Options;
import org.apache.commons.cli.ParseException;


public class Main {

    static final private Options options;

    static {
        // create the Options
        options = new Options();
        options.addOption( "h", "help", false, "Show this help." );
    }

    private static void help() {
        var formatter = new HelpFormatter();
        formatter.printHelp("app [OPTIONS] <FILE>", options);
    }

    public static void main(String[] args) {
        var parser = new DefaultParser();
        var cmd = parser.parse(options, args);

        if (cmd.hasOption('h')) {
            // Handle help option
            help();
            System.exit(0);
        }

        InputStream inputStream = null;
        if (cmd.getArgs().length >= 1) {
            // If file is specified open it.
            var path = cmd.getArgs()[0];
        } else {
            // Handle missing the only required positional argument.
            System.err.println("Missing argument: FILE or STDIN");
            help();
            System.exit(1);
        }

    }
}
