#ifndef EXAM2_LIST_H
#define EXAM2_LIST_H

//
// Created by blagoi on 22.06.19.
//

template <typename T>
struct list {
private:
    struct base_node {
        base_node *_prev, *_next;
    };

    struct node : base_node {
        node() = default;
        explicit node(T const &element) {
            _value = new T(element);
            base_node();
        }
        ~node() {
            delete(_value);
        };

        T* _value;

        friend void swap(node *&a, node *&b) {
            std::swap(a->_value, b->_value);
        }
    };

public:

    list(list const &other) {
        _fake_node = new base_node();
        _fake_node->_prev = _fake_node;
        _fake_node->_next = _fake_node;

        _front_pointer = static_cast<node*>(_fake_node);

        for (auto it = other.begin(); it != other.end(); ++it) {
            try {
                push_back(*it);
            } catch (...) {
                clear();
                delete(_fake_node);
                throw;
            }
        }
    }

    ~list() {
        clear();
        delete(_fake_node);
    };

    list& operator=(list const &other) {
        if (*this == other) {
            return *this;
        }

        list tmp;

        for (auto it = other.begin(); it != other.end(); ++it)
            tmp.push_back(*it);

        swap(*this, tmp);
        return *this;
    }

    bool operator==(list const &other) {
        auto it1 = begin(), it2 = other.begin();
        for (; it1 != end() && it2 != other.end(); ++it1, ++it2) {
            if (*it1 != *it2) return false;
        }

        return !(it1 != end() || it2 != other.end());
    }

    void push_back(T const &element) {
//        T& copy_elem = new T(element);
        node* _new = new node(element);

        if (empty()) {
            _front_pointer = _new;
            _front_pointer->_next = _fake_node;
            _front_pointer->_prev = _fake_node;

            _fake_node->_prev = _front_pointer;
            _fake_node->_next = _front_pointer;
            return;
        }

        (_fake_node->_prev)->_next = _new;
        _new->_prev = _fake_node->_prev;
        _new->_next = _fake_node;
        _fake_node->_prev = _new;
    }

    void push_front(T const &element) {
        if (empty()) {
            push_back(element);
            return;
        }

        node* _new = new node(element);

        _new->_next = _front_pointer;
        _front_pointer->_prev = _new;
        _front_pointer = _new;
        _front_pointer->_prev = _fake_node;
    }

    void pop_back() {
        if (contains_only_one()) {
            node *tmp = static_cast<node*>(_front_pointer);

            _fake_node->_prev = _fake_node;
            _fake_node->_next = _fake_node;
            _front_pointer = static_cast<node*>(_fake_node);

            delete (tmp);
        } else {
            node *tmp = static_cast<node*>(_fake_node->_prev);
            _fake_node->_prev = _fake_node->_prev->_prev;
            _fake_node->_prev->_next = _fake_node;
            _front_pointer->_prev = _fake_node;
            delete(tmp);
        }
    }

    void pop_front() {
        if (contains_only_one()) {
            pop_back();
        } else {
            node *tmp = static_cast<node*>(_front_pointer);
            _front_pointer = static_cast<node*>(_front_pointer->_next);
            _front_pointer->_prev = _fake_node;
            delete(tmp);
        }
    }

    T& front() {
        return *_front_pointer->_value;
    }

    T& back() {
        return *static_cast<node *>(_fake_node->_prev)->_value;
    }

    T const &front() const {
        return *_front_pointer->_value;
    }

    T const &back() const {
        return *static_cast<node *>(_fake_node->_prev)->_value;
    }

    void clear() {
        while (!empty())
            pop_back();
    }

    bool empty() {
        return _fake_node == _front_pointer;
    }

    template<typename V>
    struct list_iterator : std::iterator<std::bidirectional_iterator_tag, V> {

        friend list;

        list_iterator() : _data(nullptr) {}

        ~list_iterator() = default;

        template <typename X>
        list_iterator(X* _data) : _data(_data) {}

        template <typename X>
        list_iterator(list_iterator<X> const &other) : _data(other._data) {}

        template <typename X>
        bool operator==(list_iterator<X> const &other) const {
            return _data == other._data;
        }

        template <typename X>
        bool operator!=(list_iterator<X> const &other) const {
            return _data != other._data;
        }

        list_iterator &operator++() {
            _data = _data->_next;
            return *this;
        }

        const list_iterator operator++(int) {
            list_iterator tmp = list_iterator(*this);
            ++(*this);
            return tmp;
        }

        list_iterator &operator--() {
            _data = _data->_prev;
            return *this;
        }

        const list_iterator operator--(int) {
            list_iterator tmp = list_iterator(*this);
            --(*this);
            return tmp;
        }

        V& operator*() {
            return *static_cast<node*>(_data)->_value;
        }

        V &operator*() const {
            return *static_cast<node*>(_data)->_value;
        }

        V* operator->() {
            return static_cast<node*>(_data)->_value;
        }

        V *operator->() const {
            return static_cast<node*>(_data)->_value;
        }

    private:
        base_node* _data;
    };

    typedef list_iterator<T> iterator;
    typedef list_iterator<T const> const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    template<typename InputIterator>
    list(InputIterator first, InputIterator last) {
        for (auto it = first; it != last; ++it) {
            push_back(*it);
        }
    }

    iterator begin() {
        return iterator(_front_pointer);
    }

    iterator end() {
        return iterator(_fake_node);
    }

    const_iterator begin() const {
        return const_iterator(_front_pointer);
    }

    const_iterator end() const {
        return const_iterator(_fake_node);
    }

    list() {
        _fake_node = new base_node();
        _fake_node->_prev = _fake_node;
        _fake_node->_next = _fake_node;

        _front_pointer = static_cast<node*>(_fake_node);
    }

    reverse_iterator rbegin() {
        return reverse_iterator(end());
    }

    reverse_iterator rend() {
        return reverse_iterator(begin());
    }

    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(end());
    }

    const_reverse_iterator rend() const {
        return const_reverse_iterator(begin());
    }

    iterator insert(iterator const &it, T const &x) {
        if (it == begin()) {
            push_front(x);
            return iterator(begin());
        }

        if (it == end()) {
            push_back(x);
            return iterator(--end());
        }

        node * _new_node = new node(x);
        node *a = static_cast<node*>(it._data->_prev);
        node *b = static_cast<node*>(it._data);

        b->_prev = _new_node;
        a->_next = _new_node;

        _new_node->_prev = a;
        _new_node->_next = b;

        return iterator(_new_node);
    }

    iterator erase(iterator const &it) {
        if (it == begin()) {
            pop_front();
            return iterator(++begin());
        }

        if (it == end()) {
            pop_back();
            return iterator(end());
        }

        node* tmp = static_cast<node*>(it._data);
        auto res = iterator(it._data->_next);
        if (contains_only_one()) {
            pop_back();

            delete(tmp);
            return res;
        }

        node *a = static_cast<node*>(it._data->_prev);
        node *b = static_cast<node*>(it._data->_next);
        b->_prev = a;
        a->_next = b;
        delete(tmp);
        return res;
    }

    void splice(const_iterator pos, list &other, const_iterator first, const_iterator last) {
        if (first == last)
            return;

        if (pos == begin() && first != other.begin()) {
            pos._data->_prev = last._data->_prev;
            last._data->_prev->_next = pos._data;
            _front_pointer = static_cast<node *>(first._data);
            first._data->_prev->_next = last._data;
            last._data->_prev = first._data->_prev;
            _front_pointer->_prev = nullptr;
        } else if (pos == begin() && first == other.begin()) {
            pos._data->_prev = last._data->_prev;
            last._data->_prev->_next = pos._data;
            _front_pointer = static_cast<node *>(first._data);
            other._front_pointer = static_cast<node *>(last._data);

            last._data->_prev = nullptr;
        } else if (pos != begin() && first != other.begin()) {
            base_node* a = pos._data->_prev, *b = pos._data;
            base_node* c = first._data, *d = last._data->_prev;
            base_node* e = c->_prev, *f = last._data;

            a->_next = c;
            c->_prev = a;
            d->_next = b;
            b->_prev = d;

            e->_next = f;
            f->_prev = e;
        } else if (pos != begin() && first == other.begin()) {
            pos._data->_prev->_next = first._data;
            first._data->_prev = pos._data->_prev;
            pos._data->_prev = last._data->_prev;
            last._data->_prev->_next = pos._data;
            other._front_pointer = static_cast<node *>(last._data);
            other._front_pointer->_prev = nullptr;
        }
    }

    friend void swap(list &a, list &b) {
        if (a.empty() && b.empty()) {
            return;
        } else if (a.empty() && !b.empty()) {
            node* tmp = a._front_pointer;
            node* after_begin = static_cast<node*>(b._front_pointer->_next);
            node* before_end = static_cast<node*>(b._fake_node->_prev);

            a._front_pointer = b._front_pointer;
            a._fake_node = b._fake_node;

            b._front_pointer = tmp;
            b._fake_node = tmp;

            after_begin->_prev = a._front_pointer;
            before_end->_next = a._fake_node;
        } else if (!a.empty() && b.empty()) {
            node* tmp = b._front_pointer;
            node* after_begin = static_cast<node*>(a._front_pointer->_next);
            node* before_end = static_cast<node*>(a._fake_node->_prev);

            b._front_pointer = a._front_pointer;
            b._fake_node = a._fake_node;

            a._front_pointer = tmp;
            a._fake_node = tmp;

            after_begin->_prev = b._front_pointer;
            before_end->_next = b._fake_node;
        }  else {
            auto tmp1 = a._fake_node->_prev;
            auto tmp2 = b._fake_node->_prev;

            b._fake_node->_prev->_next = a._fake_node;
            a._fake_node->_prev->_next = b._fake_node;

            b._fake_node->_prev = tmp1;
            a._fake_node->_prev = tmp2;

            tmp1 = a._front_pointer->_next;
            tmp2 = b._front_pointer->_next;

            b._front_pointer->_next->_prev = a._front_pointer;
            a._front_pointer->_next->_prev = b._front_pointer;

            b._front_pointer->_next = tmp1;
            a._front_pointer->_next = tmp2;

            swap(a._front_pointer, b._front_pointer);
        }
    }

private:

    bool contains_only_one() {
        return ++begin() == end();
    }

    node *_front_pointer;
    base_node *_fake_node;
};

#endif //EXAM2_LIST_H