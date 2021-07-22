import bayesian, { Record } from "./bayesian"
import { util, StopWatch } from "tdscore"

export default function () {
    interface Data {
        weather: string
        temp: string
        wet: string
        windSpeed: string
    }
    const record: Record<Data, string>[] = [
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
    ];
    const currentCondition: Data = { weather: "晴天", temp: "冷", wet: "大", windSpeed: "强" }

    const sw = new StopWatch()
    sw.start()
    for (let i = 0; i < 1000; i++) {
        const result = bayesian<Data, string>(record, currentCondition)
    }
    sw.end()
    console.log(`it costs ${sw.totalMs}ms`)


}