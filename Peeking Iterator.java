import java.util.Iterator;

class PeekingIterator implements Iterator<Integer> {
    private Iterator<Integer> iterator;
    private Integer peekedValue;

    public PeekingIterator(Iterator<Integer> iterator) {
        this.iterator = iterator;
        // Initialize peekedValue to the first element if available
        if (iterator.hasNext()) {
            peekedValue = iterator.next();
        }
    }

    // Returns the next element in the iteration without advancing the iterator.
    public Integer peek() {
        return peekedValue;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    @Override
    public Integer next() {
        // Save the current peekedValue before moving the iterator
        Integer result = peekedValue;
        
        // Move to the next element in the iterator, if possible
        if (iterator.hasNext()) {
            peekedValue = iterator.next();
        } else {
            peekedValue = null; // No more elements
        }
        
        return result;
    }

    @Override
    public boolean hasNext() {
        return peekedValue != null;
    }
}
