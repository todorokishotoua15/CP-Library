template<typename T>
void output_vector(const T &v, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++) {
        cout << v[i] <<  (i < end -1 ? ' ' : '\n');
    } 
}