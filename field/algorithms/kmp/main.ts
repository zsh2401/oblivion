function randomStr(len: number = 1000): string {
    const chars = ["a", "b", "c", "d", "e", "f", "g"]
    const result = []
    for (let i = 0; i < len; i++) {
        const i = Math.floor(Math.random() * chars.length)
        const selected = chars[i]
        result.push(selected)
    }
    return result.join("")
}
console.log(randomStr())