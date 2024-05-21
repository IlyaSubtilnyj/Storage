#pragma once

#include <memory>
#include <type_traits>
#include <vector>
#include <BNode.hpp>
#include <WritableBNodeInterface.hpp>

using namespace std;

class BNodeImpl : public WritableBNodeInterface {

    private: vector<uint8_t> _data;

    public: shared_ptr<const uint8_t*> Get() const override {

        return make_shared<const uint8_t*>(_data.data());
    }

    //header
    public: BNodeType Type() const override {

        return read<BNodeType>(_data);
    }

    public: _M_NKeysCount Keys() const override {

        return read<_M_NKeysCount>(_data, 2);
    }

    public: void SetHeader(BNodeType type, _M_NKeysCount keys_count) override {

        write(_data, 0, type);
        write(_data, 2, keys_count);
    }

    // pointers
    public: _M_Pointer GetPtr(_M_Index idx) const override {
        assert(idx < Keys());
        auto pos = static_cast<_M_Index>(BNodeRestriction::HEADER) + 8*idx;
        return read<_M_Pointer>(_data, pos);
    }

    public: void SetPtr(_M_Index idx, _M_Pointer val) override {
        assert(idx < Keys());
        auto pos = static_cast<_M_Index>(BNodeRestriction::HEADER) + 8*idx;
        write(_data, pos, val);
    }

    //offset list
    public: _M_Offset OffsetPos(_M_Index idx) const override {
        assert(1 <= idx && idx <= Keys());
        return static_cast<_M_Index>(BNodeRestriction::HEADER) + 8*Keys() + 2*(idx-1);
    }

    public: _M_Offset GetOffset(_M_Index idx) const override {
        if (idx == 0) {
            return 0;
        }
        return read<_M_Offset>(_data, OffsetPos(idx));
    }

    public: void SetOffset(_M_Index idx, _M_Offset offset) override {
        write(_data, OffsetPos(idx), offset);
    }

    // key-values
    public: _M_Offset KVPos(_M_Index idx) const override {
        assert(idx <= Keys());
        return static_cast<_M_Index>(BNodeRestriction::HEADER) + 8*Keys() + 2*Keys() + GetOffset(idx);
    }

    public: vector<uint8_t> GetKey(_M_Index idx) const override {
        assert(idx < Keys());
        auto pos = KVPos(idx);
        auto klen = read<_M_KeyLength>(_data, pos);

        vector<uint8_t> result(klen);
        result.assign(_data.begin() + pos + 4, _data.begin() + pos + 4 + klen);
        return result;
    }

    public: vector<uint8_t> GetVal(_M_Index idx) const override {
        assert(idx < Keys());
        auto pos = KVPos(idx);

        auto klen = read<_M_KeyLength>(_data, 0);
        auto vlen = read<_M_ValLength>(_data, 2);

        vector<uint8_t> result(vlen);
        result.assign(_data.begin() + pos + 4 + klen, _data.begin() + pos + 4 + klen + vlen);
        return result;
    }

    // node size in bytes
    public: _M_Offset Bytes() const override {
        assert(_data.size() == KVPos(Keys()));
        return KVPos(Keys());
    }

};