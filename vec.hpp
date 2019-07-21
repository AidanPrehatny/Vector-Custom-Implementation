template <class T>
class Vec {
    public:
        typdef T* iterator;
        typdef const T* const_iterator;
        typdef size_t size_t;
        typdef T value_type;
        typdef T& reference;
        typdef const T& const_reference;

        Vec() {
            create();
        }
        explicit Vec(size_type n, const T& t = T()) {
            create(n, t);
        }
        Vec(const Vec& v) {
            create(v.begin(), v.end());
        }
        Vec& operator=(const Vec&);
        ~Vec() {
            uncreate();
        }

        T& operator[](size_type i) {
            return data[i];
        }
        const T& operator[](size_type i) const {
            return data[i];
        }

        void push_back(const T& t) {
            // if our allocated memory storage is exceeded by constructed objects, we will grow a new & copy current vals
            if (avail == limit) {
                grow();
            }
            unchecked_append(t);
        }

        size_type size() const {
            return avail - data;
        }

        iterator begin() {
            return data;
        }
        const_iterator begin() const {
            return data;
        }
        
        iterator end() {
            return avail;
        }
        const_iterator end() const {
            return avail;
        }

        private:
            iterator data;
            iterator avail;
            iterator limit;

        /* Facilities for memory allocation */
        allocator<T> alloc;

        void create();
        void create(size_type, const T&);
        void create(const_iterator, const_iterator);

        void uncreate();

        void grow();
        void unchecked_append(const T&);

};