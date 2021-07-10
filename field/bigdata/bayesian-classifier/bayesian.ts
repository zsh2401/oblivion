import { IMap, HashMap, DSObject, dsEquals } from "tdscore"
import forEach from "tdscore/lib/ixa/forEach"
import hashCode from "tdscore/lib/util/hashing"

/**
 * 朴素贝叶斯分类
 * 
 * @param data  已有观测数据
 * @param condition 当前条件
 * @returns 各种结果发生的可能性
 */
export default function f<C, R>(data: Record<C, R>[], condition: C):
    IMap<R, Probability> {

    const pp = getPrioriProbability(data)
    const cp = getConditionalProbability(data, pp, condition)
    return getFinalResult<C, R>(pp, cp, data, condition)
}

/**
 * 获取对象中的所有键
 * @param obj 
 * @returns 
 */
function keysOf(obj: any): string[] {
    const keys: string[] = []
    for (const key in obj) {
        keys.push(key)
    }
    return keys;
}
/**
 * 一条数据记录
 */
export interface Record<TCondition, TResult> {
    condition: TCondition
    result: TResult
}
/**
 * 可能性 ∈[0,1]
 */
export type Probability = number

/**
 * 内部运算时使用的条件对
 */
class ConditionPair<R> extends DSObject {
    readonly key: string
    readonly value: any
    readonly result: R
    constructor(key: string, value: any, result: R) {
        super()
        this.key = key
        this.value = value
        this.result = result
    }
    getHashCode() {
        return hashCode(this.key) ^ hashCode(this.value) ^ hashCode(this.result)
    }

    equals(other: ConditionPair<R>): boolean {
        if (other instanceof ConditionPair) {
            return this.getHashCode() === other.getHashCode()
        } else {
            return super.equals(other)
        }
    }

    toString() {
        return `P(${this.key}=${this.value} | ${this.result})`
    }

}


function getFinalResult<C, R>(
    pp: IMap<R, number>,
    cp: IMap<ConditionPair<R>, number>,
    history: Record<C, R>[],
    condition: C): IMap<R, Probability> {

    const result: IMap<R, number> = new HashMap()

    let total = 0

    forEach(pp, ({ key: _presult, value }) => {
        let p = value / history.length //先验概率

        //独立条件相乘
        forEach(cp, kv => {
            if (dsEquals(kv.key.result, _presult)) {
                p *= kv.value
            }
        })

        total += p
        result.mapPut(_presult, p)
    })

    forEach(result, kv => {
        result.mapPut(kv.key, kv.value / total)
    })
    return result
}



/**
 * 计算先验概率
 * @param history 
 * @returns 
 */
function getPrioriProbability<C, R>(history: Record<C, R>[]): IMap<R, number> {
    const map: IMap<R, number> = new HashMap()
    for (let { condition: c, result: r } of history) {
        let count: number = map.mapGet(r) ?? 0
        map.mapPut(r, count + 1)
    }
    return map;
}

/**
 * 计算条件概率
 * O(n^2)
 * @param data 已有数据
 * @param keys 
 * @param pp 
 * @returns 
 */
function getConditionalProbability<C, R>(
    data: Record<C, R>[],
    pp: IMap<R, number>,
    condition: C
):
    IMap<ConditionPair<R>, number> {

    const keys = keysOf(condition)

    const result: IMap<ConditionPair<R>, number> = new HashMap()

    forEach(data, (record) => {
        forEach(keys, key => {
            //@ts-ignore
            const value = record.condition[key]
            //@ts-ignore
            if (dsEquals(value, condition[key])) {

                const condition = new ConditionPair<R>(key, value, record.result)
                let p = (result.mapGet(condition) ?? 0) + 1
                result.mapPut(condition, p)

            }
        })
    })

    forEach(result, kv => {
        const c = kv.key
        const p = kv.value
        const resultRate = pp.mapGet(c.result)!
        result.mapPut(c, p / resultRate)
    })

    return result;
}