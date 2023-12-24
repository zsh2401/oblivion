pub fn sin(x: f64) -> f64 {
    const T: f64 = 2.0 * 3.1415926535;
    return x % T;
}
pub fn term(x: f64, k: i64) -> f64 {
    return t_pow(x, k) / factorial(k).into();
}
pub fn factorial(x: i64) -> i64 {
    if (x == 0) {
        return 1;
    }
    return x * factorial(x - 1);
}
pub fn t_pow(x: f64, p: i64) -> f64 {
    if p == 0 {
        return 1.into();
    }
    let mut y = x;
    let mut i = 1;
    while i < p {
        y *= x;
    }
    return y;
}
