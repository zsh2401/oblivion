import ArgumentError from "tdscore/lib/ArgumentError"
export default function entropy(s: number) {
    if (s <= 0 || s > 1) {
        throw new ArgumentError("the s must be in [0,1]")
    }
    return -s * Math.log2(s) - (1 - s) * Math.log2(1 - s)
}
console.log(entropy(3 / 7))
