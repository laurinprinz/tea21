#include <fmt/chrono.h>
#include <fmt/format.h>

#include "linkedlist.h"

void printer(const std::string &name)
{
    fmt::print("Printer: {}\n", name);
}

auto main(int argc, char **argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", "World");

    const std::vector<std::string> names{"Hugo", "Franz", "Elisabeth", "Anton", "Gerhard", "Maria", "Hannelore"};
    const std::vector<std::string> names2{"Ulf", "Ole", "Sepp", "Norton", "Kai", "Uschi", "Gert"};
    {
        LinkedList list;
        fmt::print("------------------------------\n");
        for (auto &name : names)
        {
            auto elem = new LinkedListNode(name);
            // elem->print();
            list.insert_tail(elem);
        }
        list.traverse(printer);
        fmt::print("------------------------------\n");
        for (auto &name : names2)
        {
            auto elem = new LinkedListNode(name);
            // elem->print();
            list.insert_head(elem);
        }
        fmt::print("------------------------------\n");
        list.traverse(printer);
        fmt::print("------------------------------\n");
        fmt::print("Elements in the list: {}\n", list.size());
        fmt::print("------------------------------\n");
        list.traverse(printer);
    }         /* this calls the DTOR of the list*/
    return 0; /* exit gracefully*/
}
