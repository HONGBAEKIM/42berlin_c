/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:22:23 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/02 20:10:09 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

void    erase_and_insert(int *i, std::string *s1, std::string *s2, std::string *content)
{
    (*i) = (*content).find(*s1);
    while ((*i) != -1)
    {
        (*content).erase((*i), (*s1).length());
        (*content).insert((*i), (*s2));
        (*i) = (*content).find(*s1);
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Command : ./replace [filename] [s1] [s2]" << std::endl;
        return (1);
    }
    std::ifstream infile(argv[1]); //Open argv[1] file for reading
    std::string s1(argv[2]);
    std::string s2(argv[3]);
    if (std::string(argv[1]).empty() || s1.empty() || s2.empty() || !infile.good())
    {
        std::cout << "Command : ./replace [filename] [s1] [s2]" << std::endl;
        return (1);
    }
    //std::ofstream     is output file stream
    std::string content;
    std::ofstream    outfile(std::string(argv[1]) + ".replace");
    char c;
    int i = 0;
    //get function reads characters from the input file stream. 
    while (infile.get(c))
    {
        //push_back function adds the character at the end of the string'
        content.push_back(c);
    }
    erase_and_insert(&i, &s1, &s2, &content);
    outfile << content;
    infile.close();
    outfile.close();
    return (0);
}

/* int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Command : ./replace [filename] [s1] [s2]" << std::endl;
        return (1);
    }
    //std::cout << "0" << std::endl;
    std::ifstream infile(argv[1]); //Open argv[1] file for reading
    std::string s1(argv[2]);
    std::string s2(argv[3]);
    //std::cout << "1" << std::endl;
    

    if (std::string(argv[1]).empty() || s1.empty() || s2.empty() || !infile.good())
    {
        std::cout << "Command : ./replace [filename] [s1] [s2]" << std::endl;
        //std::cout << "1-1" << std::endl;
        return (1);
    }
    
    //std::cout << "2" << std::endl;

    //std::ofstream     is output file stream
    std::string content;
    std::ofstream    outfile(std::string(argv[1]) + ".replace");
    char c;
    int i = 0;
    //get function reads characters from the input file stream.
    //std::cout << "3" << std::endl;
   
    while (infile.get(c))
    {
        //push_back function adds the character at the end of the string'
        content.push_back(c);
    }
    //std::cout << "4" << std::endl;

    erase_and_insert(&i, &s1, &s2, &content);
    //std::cout << "5" << std::endl;

    outfile << content;
    //std::cout << "6" << std::endl;
    
    infile.close();
    outfile.close();
    //std::cout << "7" << std::endl;

    
    return (0);
} */

/* 
for example of ifstream

int main() 
{
    std::ifstream inputFile("example.txt");  // Open a file for reading

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;  // Print each line from the file
    }

    inputFile.close();  // Close the file when done

    return 0;
} 
*/
