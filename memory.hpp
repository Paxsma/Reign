namespace reign {

      template <typename T>
      class shared_ptr {
          public:

            explicit shared_ptr(T *ptr)
                : data(ptr) {
            }

            T &operator*() {
                  return *this->data;
            }
            const T &operator*() const {
                  return *this->data;
            }
            T *operator->() {
                  return this->data;
            }
            const T *operator->() const {
                  return this->data;
            }
            bool operator==(const shared_ptr &other) const {
                  return this->data == other.data;
            }
            bool operator!=(const shared_ptr &other) const {
                  return this->data != other.data;
            }

          private:
            T *data; 
      };

      template <typename T>
      constexpr shared_ptr<T> make_shared(T* ptr) {
            return shared_ptr<T>(ptr);
      }
}