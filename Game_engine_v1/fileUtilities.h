#ifndef FILEUTILITIES_H
#define FILEUTILITIES_H

#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

/*
 * Header file for the FileUtilities namespace.
 * Provides utility functions for reading files and other file operations.
 */

namespace FileUtilities {

/**
 * Reads the contents of a file into a `std::vector<char>`.
 *
 * @param filename The path to the file to be read.
 * @return A `std::vector<char>` containing the file's contents.
 * @throws std::runtime_error if the file cannot be opened.
 */
std::vector<char> readFile(const std::string& filename);

}  // namespace FileUtilities

#endif  // FILEUTILITIES_H
