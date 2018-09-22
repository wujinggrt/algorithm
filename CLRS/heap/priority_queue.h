#ifndef PRIORITY_QUEUE_H__
#define PRIORITY_QUEUE_H__

template<typename T>
class MinPriorityQueue
{
public:
    template<typename Iter>
    MinPriorityQueue(Iter first, Iter end)
        : values_(first, end)
    {
        build();
    }

    MinPriorityQueue(const std::vector<T> &vec)
        : values_(vec.begin(), vec.end())
    {
        build();
    }

    bool insert(const T &v);

    T minimum() const
    {
        return values_[0];
    }

    T extract_min()
    {
        auto ret = values_[0];
        values_[0] = values_[values_.size() - 1];
        heapify(0);
        values_.pop_back();

        return ret;
    }
    
    bool decrease_key(const T &x, const T &k);

private:
    void heapify(int i)
    {
        // left (i + 1) * 2 - 1
        int l = i * 2 + 1;
        T key = values_[i];
        if (l >= values_.size())
        {
            return;
        }
        if (l + 1 < values_.size() && values_[l + 1] < values_[l])
        {
            ++l;
        }
        if (values_[l] < values_[i])
        {
            std::swap(values_[l], values_[i]);
            heapify(l);
        }
    }

    void build()
    {
        for (int i = values_.size() / 2 - 1; i >= 0; --i)
        {
            heapify(i);
        }
    }

    // v <> finded
    int find(const T &v);
private:
    std::vector<T> values_;
};

#endif