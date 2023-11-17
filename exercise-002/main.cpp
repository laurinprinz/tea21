#include <fmt/chrono.h>
#include <fmt/format.h>

#include <vector>

#include "CLI/CLI.hpp"
#include "config.h"

#include <random>
#include <chrono>

auto main(int argc, char **argv) -> int
{
    auto count = 20;
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count",
            count, 
            fmt::format("Create a vector with the given size default: {}", count));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
    std::vector<int> data(count);

    
    fmt::print("Created a vector with {} elements\n",data.size());

    /*
     * Den Zufall einordnen
     * Erstellen Sie einen ``std::vector`` mit der Größe von ``count`` 
     * und füllen diesen mit zufälligen Werten von 1-100.
     */

    // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device randomDevice;   // a seed source for the random number engine
    std::mt19937 gen(randomDevice());  // mersenne_twister_engine seeded with randomDevice()
    std::uniform_int_distribution<> distrib(1, 100);

    // Use a range based for loop to fill the vector
    // See https://en.cppreference.com/w/cpp/language/range-for
    for (auto& value : data) {
        value = distrib(gen);
    }

    /*
     * Zeig es mir Baby
     * Damit Sie den Zufall kennen müssen Sie Ihn ausgeben können. 
     * Verwenden Sie hierzu die ``{fmt}`` Bibliothek und erstellen 
     * Sie eine Funktion um den Vektor auszugeben.
     */

    fmt::print("The vector:\n[{}]\n", fmt::join(data, ", "));

    /*
     * Der Zufall in geordneten Bahnen
     * Sortieren Sie nun den Vector der Reihe nach.
     * Das heißt die niedrigste Zahl zuerst. Das Ergebnis soll 
     * ebenfalls ausgegeben werden.
     */
    auto start{std::chrono::system_clock::now()};
    std::sort(data.begin(),data.end(),std::greater<>());
    auto end{std::chrono::system_clock::now()};

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    fmt::print("The sorted vector:\n[{}]\n", fmt::join(data, ", "));
    fmt::print("The sorting took {}\n", elapsed);
    return 0; /* exit gracefully*/
}
