#ifndef LOAD_MODEL_H
#define LOAD_MODEL_H

#include <cstdint>
#include <vector>

#include "Vertex.h"

namespace LoadModel {

// Stores vertices for the loaded model
extern std::vector<Vertex> vertices;

// Stores indices for the loaded model
extern std::vector<uint32_t> indices;

// Function to load a 3D model
void loadModel();

// Function to clean up model resources
void cleanup();
}  // namespace LoadModel

#endif  // LOAD_MODEL_H
