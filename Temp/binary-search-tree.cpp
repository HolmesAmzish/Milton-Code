template<class K, class E>
pair<const K, E>* binarySearchTree<K,E>::find(const K& theKey) const {
    binaryTreeNode<pair<const K, E> > *p = root;
    while (p != NULLA)
        if (theKey < p->element.first)
            p = p->leftChild;
        else
            if (theKey > p->element.first)
                p = p->rightChild;
            else
                return &p->element;
    return NULL;
}