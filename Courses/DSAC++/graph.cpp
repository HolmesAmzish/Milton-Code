template<class T>
class graph {
    public:
    virtual ~graph() {}

    virtual int NumberOfVertices() const = 0;
    virtual int NumberOfEdges() const = 0;
    virtual bool existsEdges(int, int) const = 0;
    virtual void insertEdge(edge<T>*) = 0;
    virtual void eraseEdge(int, int) = 0;
    virtual int degree(int) const = 0;
    virtual int inDegree(int) const = 0;
    virtual int outDegree(int) const = 0;

    virtual bool directed() const = 0;
    virtual bool weighted() const = 0;
    virtual vertexIterator<T>* iterator(int) = 0;
};