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
            if (avail == limit)
                grow();
            unchecked_append(t);
        }

};