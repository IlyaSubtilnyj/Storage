#pragma once

#include <cstdint>
#include <utils.hpp>

typedef uint64_t NodeId;

enum class BNodeType : uint8_t {
    BNODE_NODE = 1,
    BNODE_LEAF = 2,
};

enum class BNodeRestriction : uint16_t {
    HEADER = 4,
    BTREE_PAGE_SIZE = 4096,
    BTREE_MAX_KEY_SIZE = 1000,
    BTREE_MAX_VAL_SIZE = 3000,
};