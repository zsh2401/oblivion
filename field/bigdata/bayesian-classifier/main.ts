import bayesian from "./bayesian"
(() => {
    interface Data {
        weather: string
        temp: string
        wet: string
        windSpeed: string
    }
    const result = bayesian<Data, string>([
        { condition: { weather: "晴天", temp: "热", wet: "大", windSpeed: "弱" }, result: "不去" },
        { condition: { weather: "晴天", temp: "热", wet: "大", windSpeed: "强" }, result: "不去" },
        { condition: { weather: "阴天", temp: "热", wet: "大", windSpeed: "弱" }, result: "去" },
        { condition: { weather: "下雨", temp: "适中", wet: "大", windSpeed: "弱" }, result: "去" },
        { condition: { weather: "下雨", temp: "冷", wet: "适中", windSpeed: "弱" }, result: "去" },
        { condition: { weather: "下雨", temp: "冷", wet: "适中", windSpeed: "强" }, result: "不去" },
        { condition: { weather: "阴天", temp: "冷", wet: "适中", windSpeed: "强" }, result: "去" },
        { condition: { weather: "晴天", temp: "适中", wet: "大", windSpeed: "弱" }, result: "不去" },
        { condition: { weather: "晴天", temp: "冷", wet: "适中", windSpeed: "弱" }, result: "去" },
        { condition: { weather: "下雨", temp: "适中", wet: "适中", windSpeed: "弱" }, result: "去" },
        { condition: { weather: "晴天", temp: "适中", wet: "适中", windSpeed: "强" }, result: "去" },
        { condition: { weather: "阴天", temp: "适中", wet: "大", windSpeed: "强" }, result: "去" },
        { condition: { weather: "阴天", temp: "热", wet: "适中", windSpeed: "弱" }, result: "去" },
        { condition: { weather: "下雨", temp: "适中", wet: "大", windSpeed: "强" }, result: "不去" },
    ],
        { weather: "晴天", temp: "冷", wet: "大", windSpeed: "强" }
    )

    console.log(result.mapGet("不去"))
})();
