export default interface Book {
    isbn: string
    name: string
    author: string
    guidedPriceUSD: number;
}
export function newRandomBook(): Book {
    const guidedPriceUSD = Math.random() * 10;
    const name = Math.random() * 20;
    const isbn = Math.random() * 20_000_000;
    return {
        isbn: isbn.toString(),
        name: name.toString(),
        author: name.toString(),
        guidedPriceUSD,
    }
}