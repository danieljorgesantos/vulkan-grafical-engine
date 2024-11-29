#ifndef VERTEX_H
#define VERTEX_H

#include <vulkan/vulkan.h>

#include <array>
#include <functional>  // For std::hash

#include "glm_includes.h"

// Vertex structure for Vulkan
struct Vertex {
    glm::vec3 pos;       // Position
    glm::vec3 color;     // Color
    glm::vec2 texCoord;  // Texture coordinates

    // Provides binding description for Vulkan vertex input
    static VkVertexInputBindingDescription getBindingDescription();

    // Provides attribute descriptions for Vulkan vertex input
    static std::array<VkVertexInputAttributeDescription, 3>
    getAttributeDescriptions();

    // Equality operator for comparing vertices
    bool operator==(const Vertex& other) const;
};

// Specialization of std::hash for Vertex
namespace std {
template <>
struct hash<Vertex> {
    size_t operator()(Vertex const& vertex) const;
};
}  // namespace std

#endif  // VERTEX_H
