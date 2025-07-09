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

    bool
    Seek(int64_t offset) override;

    size_t
    Tell() const override;

    size_t
    Read(void* ptr, size_t size) override;

    size_t
    ReadAt(void* ptr, size_t offset, size_t size) override;

    size_t
    ReadAtAsync(std::vector<void*>& data, const std::vector<size_t>& offset, const std::vector<size_t>& size) override;

    size_t
    ReadToFileAsync(const std::vector<size_t>& offset, const std::vector<size_t>& size,
        const std::string& local_file_path, const std::vector<int64_t>& ids, const std::function<void(int)>& callback) override;

    template <typename T>
    size_t
    Read(T& value) {
        return Read(&value, sizeof(T));
    }

    bool
    Eof() const override;

private:
    mutable std::ifstream stream_;
    size_t size_;
    std::string filename_;
};

}  // namespace milvus