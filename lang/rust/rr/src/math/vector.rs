pub struct Vector<T, const N: usize> {
    raw: [T; N],
}

impl Vector {
    pub fn new<T, const N: usize>(raw: &[T; N]) -> Vector<T, N> {
        // let mut copied:[T;N] = [];
        // copied[0] = 1;
        // raw.
        let k:&[T;N] = raw.clone();
        Vector {
            raw: *k
        }
    }
}