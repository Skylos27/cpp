#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main(int ac, char **av)
{
    std::ifstream file;
    std::vector<std::string> words;
    std::string current;
    std::int16_t counter = 0;

    if (ac != 3)
        return EXIT_FAILURE;

    const std::string motive(av[2]);
    file.open(av[1]);

    if (!file.is_open()) {
        std::cerr << "The file " << av[1] << " could not be opened." << std::endl;
        return EXIT_FAILURE;
    }

    while (file >> current)
        words.push_back(current);

    std::for_each(words.begin(), words.end(), [&counter, &motive] (const std::string &word) {
        if (word.find(motive) != std::string::npos)
            counter += 1;
    });

    std::cout << "The file " << av[1] << " contains " << counter << " words containing the motive " << motive << std::endl;

    return EXIT_SUCCESS;
}
