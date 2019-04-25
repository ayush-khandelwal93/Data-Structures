class union_find{
private:
    int dim;
    int *par;
    int *height;
public:
    union_find(int n);
    int find(int x);
    bool isconnected(int x, int y);
    void union_(int x, int y);
};
