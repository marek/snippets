#include <iostream>
#include <vector>
#include <string>
#include <boost/program_options.hpp>


using namespace boost::program_options;

int main(int argc, char** argv)
{
    options_description desc("Allowed options");

    // switch based arguments
    desc.add_options()
        ("help", "produce help message")
        ("input-file", value<std::vector<std::string>>()->required(), "Input File")
        ("custom-arg", value<unsigned>()->default_value(123), "My custom argument (default: 123)")
        ;

    // positional arguments
    // note: arguments are not printed by help.
    positional_options_description pd;
    pd.add("input-file", -1);

    variables_map vm{};

    try
    {
        store(command_line_parser(argc, argv).options(desc).positional(pd).run(), vm);
        notify(vm);
    }
    catch(const error & e)
    {
        std::cerr << "Couldn't parse command line arguments properly:" << std::endl;
        std::cerr << e.what() << std::endl << std::endl;
        std::cerr << desc << std::endl;
        return 1;
    }

    if (vm.size() == 0 || vm.count("help"))
    {
        // Need to handle positional arguments manualyl for auto-generated
        // help output
        std::cout << "Example: " << argv[0] << "INPUT_FILE" << std::endl;
        std::cout << desc << std::endl;
        return 1;
    }

    if(vm.count("input-file"))
    {
        for(auto& it : vm["input-file"].as<std::vector<std::string>>())
        {
            // do stuff with file
            some::func(it);
        }
    }

    return 0;
}