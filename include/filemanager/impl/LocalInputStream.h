#pragma once

#include <fstream>
#include "filemanager/InputStream.h"

namespace milvus {

class LocalInputStream : public InputStream {
public:
    LocalInputStream(const std::string& filename);
    ~LocalInputStream() override;

    size_t
    Size() const override;

    size_t
    Tell() override;

    size_t
    Read(void* ptr, size_t size) override;

    template <typename T>
    size_t
    Read(T& value) {
        return Read(&value, sizeof(T));
    }

    bool
    Eof() const override;

private:
    std::ifstream stream_;
    size_t size_;
    std::string filename_;
};

}  // namespace milvus