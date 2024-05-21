#pragma once

#include <BNode.hpp>
#include <ReadableBNodeInterface.hpp>

class ReadableBTreeInterface {

    // Declaration of the Node with a different name using 'using'
    using _RNode = ReadableBNodeInterface;

    public:     virtual NodeId GetRoot() const = 0;
    public:     virtual _RNode const& Get(NodeId id) const = 0;
};