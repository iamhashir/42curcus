/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 00:33:50 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/25 02:55:05 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <fstream>

static std::string my_replace(std::string buffer,
                              const std::string& search,
                              const std::string& repl)
{
    if (search.empty()) return buffer; 

    const size_t s_len = search.length();
    const size_t r_len = repl.length();
    size_t pos = buffer.find(search);

    while (pos != std::string::npos) {
        buffer.erase(pos, s_len);
        buffer.insert(pos, repl);
        pos = buffer.find(search, pos + r_len); 
    }
    return buffer;
}

int main(int argc, char** argv)
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <file_name> <search> <replace>\n";
        return 1;
    }

    const std::string filename = argv[1];
    const std::string search   = argv[2];
    const std::string repl     = argv[3];

    if (search.empty()) {
        std::cerr << "Error: <search> (s1) cannot be empty.\n";
        return 1;
    }

    std::ifstream in(filename.c_str());
    if (!in) {
        std::cerr << "Error: cannot open input file: " << filename << "\n";
        return 1;
    }

    std::ofstream out((filename + ".replace").c_str(), std::ios::out | std::ios::trunc);
    if (!out) {
        std::cerr << "Error: cannot create output file: " << filename << ".replace\n";
        return 1;
    }

    std::string line;
    while (std::getline(in, line)) {
        out << my_replace(line, search, repl);
        if (in.peek() != EOF) out << '\n'; 
    }

    return 0;
}
