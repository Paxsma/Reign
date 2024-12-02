#pragma once
#include <deque>
#include <memory>

namespace reign {

      template <typename T>
      class container_cache {
          public:
            class wrap {
                public:
                  explicit wrap(T obj, container_cache<T> &cache)
                      : object(std::move(obj)), cache(cache) {
                  }
                  ~wrap() {
                        this->cache.return_object(this->object);
                  }
                  T &get() {
                        return this->object;
                  }

                private:
                  T object;
                  container_cache<T> &cache;
            };

            explicit container_cache() {
            }

            ~container_cache() {
                  while (!this->cache.empty()) {
                        auto container = this->cache.back();
                        this->cache.pop_back();
                  }
            }

            inline wrap get() {
                  if (!this->cache.empty()) {
                        auto container = this->cache.back();
                        this->cache.pop_back();
                        return wrap(container, *this);
                  } else {
                        return wrap(T(), *this);
                  }
            }

          private:
            std::vector<T> cache;
            inline void return_object(T &container) {
                  container.clear();
                  this->cache.emplace_back(container);
            }
      };

} // namespace reign