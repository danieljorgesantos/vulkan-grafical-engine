#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>

#include <iostream>
#include <unordered_map>

#include "CreateTextureImage.h"
#include "Vertex.h"

/*
 * This file serves as the primary entry point for managing all model-loading
 * operations, including loading, handling, and managing model data.
 *
 * Key responsibilities of this file:
 * - Loading 3D model data for use in rendering.
 * - Managing resources related to model data.
 * - Providing a namespace (`LoadModel`) to encapsulate all
 * model-loading functionalities.
 */

namespace LoadModel {

std::vector<Vertex> vertices;
std::vector<uint32_t> indices;

// Function to load a model
void loadModel() {
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn, err;

    if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err,
                          CreateTextureImage::MODEL_PATH.c_str())) {
        throw std::runtime_error(warn + err);
    }

    std::unordered_map<Vertex, uint32_t> uniqueVertices{};

    for (const auto& shape : shapes) {
        for (const auto& index : shape.mesh.indices) {
            Vertex vertex{};

            vertex.pos = {attrib.vertices[3 * index.vertex_index + 0],
                          attrib.vertices[3 * index.vertex_index + 1],
                          attrib.vertices[3 * index.vertex_index + 2]};

            vertex.texCoord = {
                attrib.texcoords[2 * index.texcoord_index + 0],
                1.0f - attrib.texcoords[2 * index.texcoord_index + 1]};

            vertex.color = {1.0f, 1.0f, 1.0f};

            if (uniqueVertices.count(vertex) == 0) {
                uniqueVertices[vertex] = static_cast<uint32_t>(vertices.size());
                vertices.push_back(vertex);
            }

            indices.push_back(uniqueVertices[vertex]);
        }
    }
}

// Function to clean up model resources
void cleanup() {
    // Placeholder for cleanup logic
    std::cout << "LoadModel Cleaned up successfully." << std::endl;
}

}  // namespace LoadModel
