#pragma once

#include <ReadableBTreeInterface.hpp>

class WritableBTreeInterface: public ReadableBTreeInterface {

    using _RNode = ReadableBNodeInterface;
    //using _WNode = WritableBNodeInterface;

    public: virtual NodeId  SetRoot(NodeId)     = 0;
    public: virtual NodeId  New(_RNode& node)   = 0;
    public: virtual void    Del(NodeId id)      = 0;
};