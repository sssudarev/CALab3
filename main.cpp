#include <iostream>
#include <vector>

#include <getopt.h>

std::vector<std::string>* h = new std::vector<std::string>();

void handleHelp()
{
    std::cout << "Option --help (-h) was used." << std::endl;
}

void handleFirst(char *arg)
{
    std::cout << "Option --first (-f) with value " << arg << " was used." << std::endl;
}

void handleSecond(char *arg)
{
    std::cout << "Option --second (-s) with value " << arg << " was used." << std::endl;
}

void handleDetailed()
{
    std::cout << "Option --detailed (-d) was used." << std::endl;
}

bool isHandled(const std::string& n_option)
{
    for(auto &arg : *h)
    {
        if (n_option == arg)
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    int c_option, i_option = 0;;

    const char* shorts = "hdf:s:";

    struct option longs[] = {
            {"help",     no_argument, nullptr, 'h'},
            {"first",    required_argument, nullptr, 'f'},
            {"second",   required_argument, nullptr, 's'},
            {"detailed", no_argument, nullptr, 'd'},
            {nullptr, 0, nullptr, 0}
    };

    while((c_option = getopt_long(argc, argv, shorts, longs, &i_option)) != -1)
    {
        std::string n_option;

        for(struct option &e : longs)
        {
            if(e.val == c_option)
            {
                n_option = e.name;
                break;
            }
        }

        if(isHandled(n_option))
        {
            continue;
        }

        h->push_back(n_option);

        switch(c_option)
        {
            case 'h':
                handleHelp();
                break;

            case 'f':
                handleFirst(optarg);
                break;

            case 's':
                handleSecond(optarg);
                break;

            case 'd':
                handleDetailed();
                break;

            case '?':
                break;

            default:
                abort();
        }
    }

    if(optind < argc)
    {
        std::cout << "Non-option argument values:" << std::endl;
        while(optind < argc)
        {
            std::cout << argv[optind++] << std::endl;
        }
    }

    return 0;
}
