// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful


template <class it>
void swap(it &a, it &b)
{
    it tmp = a;
    a = b;
    b = tmp;
}

template <class it>
it min_elem(it begin, it end)
{
    it smallest;

    if (begin == end)
        return end;
    smallest = begin;
    begin++;

    for (; begin != end; begin++)
    {
        if(std::is_same<typename it::value_type,int>::value){
            if (*begin < *smallest)
                smallest = begin;
        }
        else{
            if (*begin > *smallest)
                smallest = begin;
        }
    }
    return smallest;
}

template <class it>
void my_selection_sort(it begin, it end)
{
    for (it i = begin; i != end; ++i)
    {
        swap(*i, *min_elem(i, end));
    }
}
